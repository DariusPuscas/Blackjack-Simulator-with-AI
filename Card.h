#pragma  once
#include <string>

using std::string;

class Card{
private:
    int value;
    string suit;
public:
    /*
     * Constructor
     */
    Card(int value, string suit):value{value},suit{std::move(suit)}{}

    /*
     * gets the value of the card
     * type return : unsigned int
     */
    [[nodiscard]] int get_value() const;

    /*
     * gets the suit of the card
     * type return: string
     */
    [[nodiscard]] string get_suit() const;

    [[nodiscard]] std::string getSymbol() const;

    void set_value(int ot);
    void set_suit(string ot);

};