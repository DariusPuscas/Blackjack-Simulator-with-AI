#include "Card.h"

int Card::get_value() const {
    return value;
}

string Card::get_suit() const {
    return suit;
}

void Card::set_value(int ot) {
    this->value=ot;
}

void Card::set_suit(string ot) {
    this->suit=std::move(ot);
}

std::string Card::getSymbol() const {
    switch (value) {

        case 11: return "J";
        case 12: return "Q";
        case 13: return "K";
        case 1:  return "A";
        default: return std::to_string(value);
        
    }
}
