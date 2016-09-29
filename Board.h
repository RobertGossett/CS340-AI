//
//  Board.h
//  Final Project
//
//  Created by Robert Gossett on 9/28/16.
//  Copyright © 2016 Robert Gossett. All rights reserved.
//

#ifndef Board_h
#define Board_h

using namespace std;
#include <vector>
#include "Tile.h"


class Board{
public:
    
    // constructor for the board
    Board();
    
    // get set for the 2d vector holding the board
    void set_Board(const vector<vector<Tile> >& newBoard);
    vector<vector<Tile> > get_Board() const;
    
    // lock and unlock the pieces of the board
    bool lock_Tiles();
    bool unlock_Tiles();
    
    //adds a piece to the board during the users move
    //v[0] = color v[1] = number
    void add_Tile(const vector<int>& tileLocation);
    void move_Tile(const vector<int>& tileLocation);
    
    // check if the board is full
    bool isFull() const;
    
    
    
private:
    
    vector<vector<Tile> > gameBoard;
    
// probably in the brain
//    struct tile {
//        int number;
//        int color;
//    };
//    vector<tile> tileQeue(4);
    
};

Board::Board() {
    vector<vector<char> > Board (3, vector<char>(3));
    
}

void Board::set_Board(const vector<vector<Tile> >& newBoard){
    gameBoard = newBoard;
}

vector<vector<Tile> > Board::get_Board() const{
    return gameBoard;
}

bool Board::lock_Tiles(){
    // lock the tiles up
    return false;
}

bool Board::unlock_Tiles(){
    // unlock the tiles
    return false;
}

void Board::add_Tile(const vector<int>& tile){
    // add the tile
}

void Board::move_Tile(const vector<int>& tileLocation){
    // move tile
}

bool isFull(){
    // if is full return true
}



#endif /* Board_h */
