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
    
    // constructor we still need to fill out. going to require sets and gets
    Player();
    
    // parameterized constructor
    Player(Graphics* myDisplay, Board* myBoard ); // complete
    
    // prints the prompt, gets the move choice, and makes the move on the board
    // based off of that given input.
    void makeMove(Board* gameBoard); // complete
    
    // deals the tile hand for the player
    void dealTileHand(vector<Tile> myHand);
    
    // roll will be used to end the players turn once we build out the scoring and play options
    void roll();
    
    // checks if the player is active
    void checkActive();
    
    // gets and sets for the board
    // set board
    void set_board(Board* newBoard);
    
    //gets and sets for display
    // set display
    void set_display(Graphics* newDisplay);
    
    // gets and sets for score
    // sets the score to a new value
    void set_score(int const& newScore);
    
    // gets the value of the players score
    int get_score() const;
    
    // increments the score by a certain number
    void increment_score(int const& addend);
private:
    
    Board* gameBoard; 
    vector<Tile> tileHand;
    int score;
    Graphics* display;
    bool isActive;
    
};

Player::Player(){
    gameBoard = NULL;
    display = NULL;
    score = 0;
    isActive = false;
    
}

Player::Player(Graphics* myDisplay, Board* myBoard){
    gameBoard = myBoard;
    display = myDisplay;
    score = 0;
    isActive = false;

}

void Player::dealTileHand(vector<Tile> myHand){
    
    for(int i = 0; i < 4; i++){ // check because internally, first element kept getting set to zero. idk why
        while(myHand[i].get_number() == 0)
            myHand[i].randomize();
    }
    
    tileHand = myHand;
    
    
}

void Player::makeMove(Board* gameBoard){
    isActive = true;
    while (isActive){
        Tile choice;
        display->print_Board(gameBoard->get_Board());
        display->print_score(score);
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

void Player::set_board(Board* newBoard){
    gameBoard = newBoard;
}

void Player::set_display(Graphics* newDisplay){
    display = newDisplay;
}

void Player::set_score(const int& newScore){
    score = newScore;
}

int Player::get_score() const{
    return score;
}

void Player::increment_score(const int& addend){
    score += addend;
}
#endif
