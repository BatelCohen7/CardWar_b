#include <iostream>
#include <string>
#include "card.hpp"

using namespace std;

namespace ariel{

    Card::Card(){
       // empty constructor
    }

    Card::Card(int num, std::string sign) {
        this->num=num;
        this->sign=sign;
    }

    string Card::getStringNum() {
        switch (this->num) {
            case 1:
                return "Ace";
            case 11:
                return "Jack";
            case 12:
                return "Queen";
            case 13:
                return "King";
            default:
                return std::to_string(this->num);
        }
    }

    string Card::getStringSign() {
        return this->sign;
    }

    string Card::to_string() {
        return Card::getStringNum() + " of " + Card::getStringSign();
    }

    int Card::getNum() {
        return this->num;
    }

    std::string Card::getSign() {
        return this->sign;
    }

}
