#pragma once

#include <vector>
#include "Card.h"


class AI{
private:
public:
    AI()=default;
/*
    int aiStrategy(int score){
        if(score<17)
            return 1; //hit
        else
            return 0;

    }

    // 1  "hit", 0 "stand"
    int aiDecide(const std::vector<Card>& aiHand) {
        int total = calculateHandTotal(aiHand);


        return aiStrategy(total);
    }*/

    int aiDecide(const std::vector<Card>& aiHand, int playerScore);

    // calculates hand total of a hand
    int calculateHandTotal(const std::vector<Card>& hand);
};