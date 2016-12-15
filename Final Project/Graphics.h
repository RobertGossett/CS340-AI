//
//  Graphics.h
//  AI Project - Lock n Roll
//
//  Created by Richard Poutier on 9/28/16.
//  Copyright © 2016 Richard Poutier. All rights reserved.
//

#ifndef GRAPHICS_H_INCLUDED_
#define GRAPHICS_H_INCLUDED_

#include <string>
//#include "Tile.h"
//#include "Board.h"
#include "Game.h"
#include <vector>

/*
 ALL CONST INT

 red    = 1
 yellow = 2
 green  = 3
 blue   = 4
 */

using namespace std;

//
// Base class to allow for various display options in the future
//

class Graphics {

public:

    // function for starting the game
    virtual void start_Game() = 0;

    // returns a tile created by the user

    virtual Tile get_tile(vector <Tile> h, const bool& error) = 0;
    
    // returns an int representing the move location given by the user
    
    virtual int get_location(bool const& error) = 0;
    
    // prints the board
    virtual void print_Board(vector <vector <Tile> > board) = 0;

    // prints the hand
    virtual void print_Hand(vector <Tile> h) = 0;

    virtual void print_score(const int& score) = 0;
    virtual void end_game()=0;
};


#endif /* Graphics_h */
