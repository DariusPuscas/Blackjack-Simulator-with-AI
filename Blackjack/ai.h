#pragma once

#include <vector>
#include <qdebug.h>
#include "Card.h"
#include "MCST.h"

class AI{
private:
public:
    AI()=default;

/// run function param: root and number of simulations
/// returns the leaf with the most promising choice
    static MCTSNode* run_MCTS(MCTSNode* root, int numSimulations) {
        for (int i = 0; i < numSimulations; ++i) {
            MCTSNode* node = root;

            // selects
            while (!node->children.empty()) {
                node = node->select();
            }

            // expands
            if (node->visits > 0 && node->state < 21) {
                node->expand();
                node = node->children[0];  // Select first option
            }

            // simulate the game
            bool win = node->simulate();

            // backtrack the node
            node->back_propagate(win);
        }

        // return the most visited child
        MCTSNode* bestChild = nullptr;
        double bestVisits = -1;
        for (auto& child : root->children) {
            if (child->visits > bestVisits) {
                bestVisits = child->visits;
                bestChild = child;
            }
        }

        return bestChild;
    }



    int aiDecide(const std::vector<Card>& aiHand, int playerScore, const std::string & difficulty);

    // calculates hand total of a hand
    int calculateHandTotal(const std::vector<Card>& hand);
};