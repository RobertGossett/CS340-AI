//
//  Player.h
//  Final Project
//
//  Created by Robert Gossett on 12/10/16.
//  Copyright © 2016 Robert Gossett. All rights reserved.
//

#ifndef Player_h
#define Player_h

using namespace std;

#include "Tile.h"
#include "Board.h"
#include "Graphics.h"
//#include "GameManager.h"
#include "Game.h"

class Player {

public:
    
    
    // prints the prompt, gets the move choice, and makes the move on the board
    // based off of that given input.
    virtual void makeMove(Board* gameBoard) = 0; // complete
    
    // deals the tile hand for the Player
    virtual void dealTileHand(vector<Tile> myHand) = 0;
    
    // roll will be used to end the Player's turn once we build out the scoring and play options
    virtual void roll() = 0;
    
    // checks if the Player is active
    virtual void checkActive() = 0;
    
    // returns true if the Player is active
    virtual bool is_Active() const = 0;
    
    // gets and sets for the board
    // set board
    virtual void set_board(Board* newBoard) = 0;
    
    //gets and sets for display
    // set display
    virtual void set_display(Graphics* newDisplay) = 0;
    
    // gets and sets for score
    // sets the score to a new value
    virtual void set_score(int const& newScore) = 0;
    
    // gets the value of the Players score
    virtual int get_score() const = 0;
    
    // increments the score by a certain number
    virtual void increment_score(int const& addend) = 0;

    virtual bool has_joker()= 0;

    virtual void set_joker()= 0;

    virtual bool level_Up()= 0;
};

#endif /* Player_h */
