#ifndef PLAYER_H
#define PLAYER_H

using namespace std;

#include "Tile.h"
#include "Board.h"
#include "Graphics.h"
#include "GameManager.h"
#include "Game.h"

class Player{
    
public:
    
    Player(Graphics* myDisplay, Board* myBoard );
    
    // issue with hand is in makeMove and maybe check active
    void makeMove(Board* gameBoard);
    void dealTileHand(vector<Tile> myHand);
    void roll();
    void checkActive();
private:
    
    Board* gameBoard;
    vector<Tile> tileHand;
    int score;
    Graphics* display;
    bool isActive;
    
};
Player::Player(Graphics* myDisplay, Board* myBoard){
    gameBoard = myBoard;
    display = myDisplay;

}

void Player::dealTileHand(vector<Tile> myHand){
    
    tileHand = myHand;
}

void Player::makeMove(Board* gameBoard){
    isActive = true;
    while (isActive){
        Tile choice;
        display->print_Board(gameBoard->get_Board());
        display->print_Hand(tileHand);
        choice = display->get_tile(tileHand);
        int location;
        location = display->get_location();
        gameBoard->add_Tile(choice, location);
        for(int i = 0; i<tileHand.size(); i++) {
            if(tileHand[i].get_number() == choice.get_number() && tileHand[i].get_color() == choice.get_color()){
                tileHand[i].set_number(0);
                tileHand[i].set_color(0);
            }
        }
        
        checkActive();
        
    }
}

void Player::roll(){
    isActive = false;
}

void Player::checkActive(){
    
    for(int i = 0; i<tileHand.size(); i++){
        if(tileHand[i].get_number() != 0 || tileHand[i].get_color() != 0 )
            roll();
    }
    
}
#endif
