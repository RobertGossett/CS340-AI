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
#include <iostream>


class Board{
public:
    
    // constructor for the board
    Board();
    
    // get set for the 2d vector holding the board
    void set_Board(const vector<vector<Tile> >& newBoard);
    vector<vector<Tile> > get_Board() const;
    
    // print board
    void printBoard();
    
    // lock and unlock the pieces of the board
    bool lock_Tiles();
    bool unlock_Tiles();
    
    //adds a piece to the board during the users move
    //v[0] = color v[1] = number
    void add_Tile(const vector<int>& tileLocation, const Tile& tile);
    void move_Tile(const vector<int>& tileLocation, const vector<int>& newLocation, const Tile& tile);
    
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

void Board::add_Tile(const vector<int>& tileLocation, const Tile& tile){
    // add the tile
}

void Board::move_Tile(const vector<int>& tileLocation, const vector<int>& newLocation, const Tile& tile){
    // move tile
}

bool Board::isFull() const{
    // if is full return true
    return false;
}

// prints the current board
void Board::printBoard(){
    cout << "-----------------" << endl;
    for(int i = 0; i < 4; i++){
        cout << "| ";
        for(int j = 0; j < 4; j++){
            cout << gameBoard[i][j].get_color() << gameBoard[i][j].get_number() << " | ";
            
        };
        
        cout << endl;
        cout << "-----------------" << endl;
    };
    
}




#endif /* Board_h */
