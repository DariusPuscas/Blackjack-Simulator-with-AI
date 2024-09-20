
#include "ai.h"

int AI::aiDecide(const std::vector<Card> &aiHand, int playerScore, const std::string &difficulty) {
    int aiScore = calculateHandTotal(aiHand);

    if(difficulty=="Easy"){
        if(aiScore<17)
            return 1; //hit
        else
            return 0;
    }

    if(difficulty=="Medium") {

        // basic blackjack strategy
        if (aiScore < 17) {
            return 1;  // Hit if score < 17
        } else if (aiScore < 21) {
            // risks more if the player has a better hand
            if (playerScore > aiScore && playerScore <= 21) {
                return 1;
            } else {
                return 0;
            }
        }

        // more than 21
        return 0;
    }

    if(difficulty=="Hard"){
        auto root = new MCTSNode(nullptr,aiScore, true);

       /* if(aiScore<17){
            MCTSNode* bestMove = run_MCTS(root,5000);
            if(bestMove->state > aiScore){
                return 1;
            }
            else
                return 0;
        }
        else
            return  0;*/

        MCTSNode* bestMove = run_MCTS(root,1000);

        auto move = bestMove->state;
        //delete root;

        if(move > aiScore) {
            return 1;
        }
        else {
            return 0;
        }

    }

    return 0;
}

int AI::calculateHandTotal(const std::vector<Card> &hand) {
    int total = 0;
    int aceCount = 0;

    // iterate all cards
    for (const auto& card : hand) {
        total += card.get_value();
        if (card.get_value() == 1) {
            aceCount++;
        }
    }

    while (aceCount > 0 && total <= 11) {
        total += 10;  // Transform As from 1 in 11
        aceCount--;
    }

    return total;
}
