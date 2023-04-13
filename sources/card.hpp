#pragma once
#include <iostream>
#include <string.h>

namespace ariel {

    class Card {
    private:
        std::string sign;
        int num;

        std::string getStringSign();
        std::string getStringNum();

    public:
        Card();
        Card(int num, std::string sign);

        std::string to_string();
        int getNum();
        std::string getSign();
    };
}
