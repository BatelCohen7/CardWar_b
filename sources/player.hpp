#pragma once 
#include <iostream>
#include <string.h>
#include "card.hpp"
#include <vector>

namespace ariel{
   class Player
   {
     private:
        std::vector<Card> cardsStack;
        std::string name;
        int numOfWonRounds = 0;
        int playedRounds = 0;
        int numOfCardsTaken = 0;
    
    
    public:
        Player(const std::string& name);
        Player();
        int stacksize();
        int cardesTaken();
        void AddCard(const Card& card);
        Card PlayCard();
        std::string GetTurnForLog(Card card);
        std::string GetName();
        void PrintStats();
        void AddRound(int cards_numOfWonCards);
    };

 }


