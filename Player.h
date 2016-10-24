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

<<<<<<< HEAD
   	 Player(Graphics* myDisplay, Board* myBoard );
      
     void makeMove(Board* gameBoard);
     void dealTileHand(vector<Tile> myHand);
     void roll(); 
     void checkActive(); 
   private:
=======
Player::Player(Graphics* myDisplay, Board* myBoard){
    gameBoard = myBoard;
    display = myDisplay;
    score = 0;
    isActive = false;
>>>>>>> 515a85e09975e776d1639e49ca1c3d456a56b052

}

<<<<<<< HEAD
};
Player(Graphics* myDisplay, Board* myBoard){
 gameBoard= myBoard;
 display = myDisplay;
=======
void Player::dealTileHand(vector<Tile> myHand){
    
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
>>>>>>> 515a85e09975e776d1639e49ca1c3d456a56b052
}

void Player::roll(){
    isActive = false;
}

<<<<<<< HEAD
void makeMove(Board* gameBoard){
   while (isActive){
   	  Tile choice = new Tile;
      choice = display->get_tile();
      int location;
      location = display->get_location();
      gameBoard->add_tile(choice, location);
      for(int i = 0; i<hand.size(); i++) {
       if(hand[i]->get_number() == choice->get_number() && hand[i]->get_color() == choice->get_color()){
       	 hand[i]->get_number(0);
       	 hand[i]->set_color(0);
         }
       }
=======
void Player::checkActive(){
    
    for(int i = 0; i<tileHand.size(); i++){
        if(tileHand[i].get_number() != 0 || tileHand[i].get_color() != 0 )
            roll();
    }
    
}
>>>>>>> 515a85e09975e776d1639e49ca1c3d456a56b052

void Player::set_board(Board* newBoard){
    gameBoard = newBoard;
}

void Player::set_display(Graphics* newDisplay){
    display = newDisplay;
}

void Player::set_score(const int& newScore){
    score = newScore;
}

<<<<<<< HEAD
void checkActive(){
	
	 for(int i = 0; i<hand.size(); i++){
	 	if(hand[i]->get_number() != 0 || hand[i]->get_color() != 0 )
	 	 roll();
	 }
=======
int Player::get_score() const{
    return score;
}
>>>>>>> 515a85e09975e776d1639e49ca1c3d456a56b052

void Player::increment_score(const int& addend){
    score += addend;
}
#endif
