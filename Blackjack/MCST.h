#pragma once

/*
 * Monte Carlo Tree Search
 */

#include <vector>
#include <cmath>
#include <cstdlib>  //  rand()

class MCTSNode {
public:
    MCTSNode *parent;
    std::vector<MCTSNode*> children;
    int visits;
    double wins;
    bool isAI;
    int state;  // game state ; current score

    MCTSNode(MCTSNode* parent, int state, bool isAI)
            : parent(parent), state(state), isAI(isAI), visits(0), wins(0) {}

    // Expand the game with all possibilities
    void expand() {
        // AI has 2 choices : hit or stand
        children.push_back(new MCTSNode(this, state + rand() % 10, !isAI));  // Hit random
        children.push_back(new MCTSNode(this, state, !isAI));  // Stand
    }

    // UCB1 formula (Upper Confidence Bound applied to trees)
    double getUCB1(double exploration = 0.7) const {
        if (visits == 0) return std::numeric_limits<double>::infinity();
        return (wins / visits) + exploration * std::sqrt(std::log(parent->visits) / visits);
    }

    // select the most promising node using  UCB1
    MCTSNode* select() {
        MCTSNode* bestChild = nullptr;
        double bestValue = -std::numeric_limits<double>::infinity();
        for (auto& child : children) {
            double ucb1Value = child->getUCB1();
            if (ucb1Value > bestValue) {
                bestValue = ucb1Value;
                bestChild = child;
            }
        }
        return bestChild;
    }

    // simulate the game from the starting point
    bool simulate() {
        int simulatedState = state;

        // simple choice; only HIT if it has less than 17 points
        while (simulatedState < 17) {
            int card = rand() % 10 + 1;  // random card
            simulatedState += card;

            if (simulatedState > 21) {
                return false;  // if it goes over 21; AI loses
            }
        }

        return true;
    }

    // Backpropagation: update scores all the way up to the root of the tree
    void back_propagate(bool win) {
        visits++;
        if (win) wins++;
        if (parent) parent->back_propagate(win);
    }
};

