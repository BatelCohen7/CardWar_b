#include <iostream>
#include <string>
#include "player.hpp"
#include "card.hpp"

using namespace std;

namespace ariel {
    Player::Player(const std::string& name){
        this->name=name,
        this->numOfCardsTaken=0;
        this->numOfWonRounds=0;
        this->cardsStack.clear();
        this->playedRounds=0;
      }

    Player::Player() {    
        this->numOfCardsTaken=0;
        this->numOfWonRounds=0;
        this->cardsStack.clear();
        this->playedRounds=0;
      }

    int Player::cardesTaken(){
      return numOfCardsTaken;
    }

    void Player::AddRound(int numOfWonCards) {
      playedRounds++;
      if (numOfWonCards) {
        numOfCardsTaken += numOfWonCards;
        numOfWonCards++;
      }
    }

    int Player::stacksize(){
      return cardsStack.size();
    }

    void Player::AddCard(const Card& card) {
      cardsStack.push_back(card);
    }

    Card Player::PlayCard() {
      Card card = cardsStack.back();
      cardsStack.pop_back();
      return card;
    }

    std::string Player::GetTurnForLog(Card card) {
      return this->name + " played: " + card.to_string();
    }

    std::string Player::GetName() {
      return this->name;
    }

    void Player::PrintStats() {
      std::cout << "__\n";
      std::cout << name << " stats report\n";
      std::cout << "__\n";
      std::cout << "num_of_cards_taken: " << numOfCardsTaken << "\n";
      std::cout << "rounds_won: " << numOfWonRounds << "\n";
      std::cout << "played_rounds: " << playedRounds << "\n";
      double winRate = static_cast<double>(numOfWonRounds) / playedRounds;
      std::cout << "win rate: " << winRate << "\n";
      std::cout << "cards won: " << numOfCardsTaken << "\n";
    }
}