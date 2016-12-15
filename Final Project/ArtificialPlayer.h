//
//  ArtificialPlayer.h
//  Final Project
//
//  Created by Robert Gossett on 12/10/16.
//  Copyright © 2016 Robert Gossett. All rights reserved.
//

#ifndef ArtificialPlayer_h
#define ArtificialPlayer_h

#include "player.h"

using namespace std;

class ArtificialPlayer : public Player {

public:
    // constructor we still need to fill out. going to require sets and gets
    ArtificialPlayer();
    
    // parameterized constructor
    ArtificialPlayer(Graphics* myDisplay, Board* myBoard ); // complete
    
    //different than the Human players make move function. This will find the best move based off of our algorithm and execute that
    void makeMove(Board* gameBoard); // complete
    
    // deals the tile hand for the ArtificialPlayer
    void dealTileHand(vector<Tile> myHand);
    
    // roll will be used to end the ArtificialPlayers turn once we build out the scoring and play options
    void roll();
    
    // checks if the ArtificialPlayer is active
    void checkActive();
    
    // returns true if the ArtificialPlayer is active
    bool is_Active() const;
    
    // gets and sets for the board
    // set board
    void set_board(Board* newBoard);
    
    //gets and sets for display
    // set display
    void set_display(Graphics* newDisplay);
    
    // gets and sets for score
    // sets the score to a new value
    void set_score(int const& newScore);
    
    // gets the value of the ArtificialPlayers score
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

ArtificialPlayer::ArtificialPlayer(){
    gameBoard = NULL;
    display = NULL;
    score = 0;
    isActive = false;
    
}

ArtificialPlayer::ArtificialPlayer(Graphics* myDisplay, Board* myBoard){
    gameBoard = myBoard;
    display = myDisplay;
    score = 0;
    isActive = false;
    
}

void ArtificialPlayer::dealTileHand(vector<Tile> myHand){
    
    for(int i = 0; i < 4; i++){ // check because internally, first element kept getting set to zero. idk why
        while(myHand[i].get_number() == 0)
            myHand[i].randomize();
        
    }
    
    tileHand = myHand;
    isActive = true;
    
}


// make this function follow our alg
void ArtificialPlayer::makeMove(Board* gameBoard){
    isActive = true;
    if (isActive){
        Tile choice;
        display->print_Board(gameBoard->get_Board()); // maybe we don't include this
        display->print_score(score);
        display->print_Hand(tileHand);
        //brain find move
        choice = display->get_tile(tileHand, true); /// AI will choose the tile to play get_move
        while(choice.get_color() == 0)
            choice = display->get_tile(tileHand, false);
        int location;
        location = display->get_location(true); // AI will choose the location of the tile
        while(gameBoard->get_Tile(location).get_color() != 0)
            location = display->get_location(false);
        gameBoard->add_Tile(choice, location); // AI will add the tile to the board
        bool foundTile = false;
        for(int i = 0; (i<tileHand.size()) && !foundTile; i++) { // clears the tile just used in the tile hand
            if(tileHand[i].get_number() == choice.get_number() && tileHand[i].get_color() == choice.get_color()){
                tileHand[i].set_number(0);
                tileHand[i].set_color(0);
                foundTile = true;
            }
        }
        
        
        checkActive();
        
    }
}


void ArtificialPlayer::roll(){
    isActive = false;
}

void ArtificialPlayer::checkActive(){
    bool continueGame = false;
    for(int i = 0; i<tileHand.size(); i++){
        if(tileHand[i].get_number() != 0 || tileHand[i].get_color() != 0 )
            continueGame = true;
    }
    
    if(!continueGame)
        roll();
    
}
bool ArtificialPlayer::is_Active() const{
    return isActive;
}


void ArtificialPlayer::set_board(Board* newBoard){
    gameBoard = newBoard;
}

void ArtificialPlayer::set_display(Graphics* newDisplay){
    display = newDisplay;
}

void ArtificialPlayer::set_score(const int& newScore){
    score = newScore;
}

int ArtificialPlayer::get_score() const{
    return score;
}

void ArtificialPlayer::increment_score(const int& addend){
    score += addend;
}
    
#endif 
