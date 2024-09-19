#pragma once

#include <utility>
#include <vector>
#include <ctime>
#include <algorithm>
#include <random>
#include <string>
#include <iostream>
#include "ai.h"

class DeckManager{
private:
   // std::vector<Card> deck;
     AI ai;
public:
    explicit DeckManager(AI ai):ai{ai}{};
    /*
     * creates a deck
     * type return std::vector<Card>
     */
    std::vector<Card> create_deck();
    /*
     * console game; for testing
     */
    void playGame();
    void displayHand(const std::vector<Card>& hand, const std::string& playerName,bool hideFirstCard);
};