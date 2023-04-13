#pragma once 
#include <iostream>
#include <string>
#include "player.hpp"
#include "card.hpp"
using namespace std;

namespace ariel{
   class Game
   {
      Player& p1;
      Player& p2;
      int winner;
      int draws;
      int rounds;
      std::vector<std::string> logs;
   
   public:
      Game(Player& p1, Player& p2);
      void gamePrep(std::vector<Card>& cardPacket);
      void playTurn();
      void printLastTurn();
      void playAll();
      void printWiner();
      void printLog();
      void printStats();
   };
}