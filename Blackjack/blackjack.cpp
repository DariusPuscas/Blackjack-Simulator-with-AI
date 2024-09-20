#include "blackjack.h"

#include <utility>
#include <chrono>


void DeckManager:: displayHand(const std::vector<Card>& hand, const std::string& playerName, bool hideFirstCard=false) {
    std::cout << playerName << " has: ";
    for (size_t i = 0; i < hand.size(); ++i) {
        if (i == 0 && hideFirstCard) {
            std::cout << "[??] ";  // for dealer, hide the first card
        } else {
            std::cout << hand[i].getSymbol()<< hand[i].get_suit() << " ";  // print rest of the cards
        }
    }
    std::cout << "\n";
}

std::vector<Card> DeckManager::create_deck() {
    std:: vector<Card> deck;
    //for(string suit :{"♠", "♥", "♦", "♣"})
    for(string suit:{"spades","hearts","diamonds","clubs"})
        for (int i = 1; i <= 13; i++) {
            int value = i;
            if (value > 10) value = 10; // J, Q, K  10
            deck.emplace_back(value, suit);
        }
    auto seed=std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(deck.begin(), deck.end(), std::default_random_engine(seed));
    return deck;
}

void DeckManager::playGame() {
    std::vector<Card> deck = create_deck();   // Create deck
    std::vector<Card> playerHand;            // player hand
    std::vector<Card> aiHand;                // AI hand

    playerHand.push_back(deck.back()); deck.pop_back();
    playerHand.push_back(deck.back()); deck.pop_back();

    aiHand.push_back(deck.back()); deck.pop_back();
    aiHand.push_back(deck.back()); deck.pop_back();

    // show starting hand
    std::cout << "--------------------------\n";
    displayHand(playerHand, "Player");
    displayHand(aiHand, "AI-ul", true);  // hide the first card at the beginning

    // players turn
    bool playerStand = false;
    while (!playerStand) {
        std::cout << "\nAi " << ai.calculateHandTotal(playerHand) << " points.\n";
        std::cout << "Choose (1 = Hit, 0 = Stand): ";
        int choice;
        std::cin >> choice;

        if (choice == 1) {  // Hit
            playerHand.push_back(deck.back());
            deck.pop_back();
            int playerTotal = ai.calculateHandTotal(playerHand);
            displayHand(playerHand, "Player");

            if (playerTotal > 21) {
                std::cout << "You lost! Points: " << playerTotal << "\n";
                return;
            }
        } else {
            playerStand = true;
        }
    }

    // Separator
    std::cout << "--------------------------\n";
    std::cout << "AI starts...\n";

    // show full hand
    displayHand(aiHand, "AI-ul");

    // ai turn
    bool aiStand = false;
    while (!aiStand) {
        int aiAction =ai.aiDecide(aiHand,ai.calculateHandTotal(playerHand),"easy");

        if (aiAction == 1) {  // AI  Hit
            aiHand.push_back(deck.back());
            deck.pop_back();
            int aiTotal = ai.calculateHandTotal(aiHand);
            displayHand(aiHand, "AI-ul");

            if (aiTotal > 21) {
                std::cout << "AI lost! Points: " << aiTotal << "\n";
                return;
            }
        } else {
            aiStand = true;
        }
    }

    // Compare final hand
    std::cout << "--------------------------\n";
    int playerTotal = ai.calculateHandTotal(playerHand);
    int aiTotal = ai.calculateHandTotal(aiHand);

    std::cout << "Player points: " << playerTotal << "\n";
    std::cout << "AI points: " << aiTotal << "\n";

    if (playerTotal > aiTotal) {
        std::cout << "You won!\n";
    } else if (playerTotal < aiTotal) {
        std::cout << "AI won!\n";
    } else {
        std::cout << "Draw!\n";
    }
}

