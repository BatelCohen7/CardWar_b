#include <iostream>
#include <string>
#include "player.hpp"
#include "card.hpp"
#include "game.hpp"


using namespace std;

namespace ariel {
        Game::Game(Player& p1, Player& p2): p1(&p1),p2(&p2) {
            vector<Card> cardPacket;
            gamePrep(cardPacket);
            this->rounds = 0;
            this->draws = 0;
            this->winner =nullptr;
        }

        void Game::gamePrep(vector<Card>& cardPacket){
            cardPacket.clear();
            string sign[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
            // Create all 52 cards and add them to the packet
                for (int i = 0; i < 4; i++) {
                    for (int j = 0; j < 13; j++) {
                        cardPacket.push_back(Card(j, sign[i]));
                    }
                }   
            //shuffle
                srand(time(NULL)); 
                std::random_shuffle(cardPacket.begin(), cardPacket.end());
            // deal cards
                for (unsigned long i = 0; i < 26; i++) {
                    p1->AddCard(cardPacket.at(i));
                    p2->AddCard(cardPacket.at(i+26));
                }
        }

        void Game::playTurn() {
            if (&p1 == &p2) {
                throw std::invalid_argument("Can't play with only one player");
            }

            if (p1->stacksize() == 0 || p2->stacksize() == 0) {
                throw std::invalid_argument("no more cards");
            }

            std::string log;
            int winnerCard = 0;

            while (true) {
                this->rounds++;

                if (p1->stacksize() == 0 || p2->stacksize() == 0) {
                    if (winnerCard == 0) {
                        throw std::invalid_argument("no more cards");
                    }

                    // no more card to draw everyone gets the card they threw
                    p1->AddRound(winnerCard / 2);
                    p2->AddRound(winnerCard / 2);
                    break;
                }

                Card cardP1 = p1->PlayCard();
                Card cardP2 = p2->PlayCard();
                winnerCard += 2;

                log += p1->GetTurnForLog(cardP1) + " " + p2->GetTurnForLog(cardP2) + ". ";

                if (cardP1.getNum()== cardP2.getNum()) {
                    draws++;
                    log += "Draw. ";

                    if (p1->stacksize() > 0 && p2->stacksize() > 0) {
                        cardP1 = p1->PlayCard();
                        cardP2 = p2->PlayCard();
                        winnerCard += 2;
                    } else {
                        // no more card to draw everyone gets the card they threw
                        p1->AddRound(winnerCard / 2);
                        p2->AddRound(winnerCard / 2);
                        break;
                    }
                } else if ((cardP1.getNum() == 1 && cardP2.getNum() != 2) || (cardP1.getNum() >cardP2.getNum())) {
                    log += p1->GetName() + " Is the winner ";
                    p1->AddRound(winnerCard);
                    p2->AddRound(0);
                } else {
                    //p2 wins
                    log += p2->GetName() + " Is the winner ";
                    p2->AddRound(winnerCard);
                    p1->AddRound(0);
                }
            }

            logs.push_back(log + "\n"); // round end
        }
        

        void Game::printLastTurn() {
            cout << this->logs.back();
        }

        void Game::playAll() {
            while (this->p1->stacksize() > 0 && this->p2->stacksize() > 0 ){
                this->playTurn();
            }
            // set winner
            if(p1->cardesTaken() < p2->cardesTaken()){
                this->winner = p2;
            }
            else if(p2->cardesTaken() < p1->cardesTaken()){
                this->winner = p1;
            }
        }

        void Game::printWiner() {
            if(p1->cardesTaken() > p2->cardesTaken()){
                cout <<"The winner is: " + p1->GetName() << endl;
            }
            else if(p1->cardesTaken() < p2->cardesTaken()){
                cout <<"The winner is: " +  p2->GetName() << endl;
            }
            else cout << "It's a Tie-no winner" << endl;
        }

        void Game::printLog() {
            for(unsigned long i = 0; i < this->logs.size() - 1; i++) {
                cout << this->logs.at(i) << "\n";
            }
        }

        void Game::printStats() {
            cout << this->logs.back() << "\n";
        }
};

