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
    void lock_Tiles();
    void unlock_Tiles(); // might not need this
    
    //adds a piece to the board during the users move
    //v[0] = color v[1] = number
    void add_Tile(const int& tileLocation, const Tile& tile);
    void move_Tile(const int& tileLocation, const int& newLocation, const Tile& tile); // executable on unlocked tiles
    
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
    vector<vector<char> > Board (4, vector<char>(4));
    
}

void Board::set_Board(const vector<vector<Tile> >& newBoard){
    gameBoard = newBoard;
}

vector<vector<Tile> > Board::get_Board() const{
    return gameBoard;
}

void Board::lock_Tiles(){
    for(int i; i < 4; i++){
        for(int j; j < 4; j++){
            if(gameBoard[i][j].get_number() != 0 && gameBoard[i][j].get_color() != 0)
                gameBoard[i][j].lock();
        };
    };
 
}

void Board::unlock_Tiles(){ // might not need this
    // unlock the tiles

}

void Board::add_Tile(const int& tileLocation, const Tile& tile){
    int xPosition = tileLocation / 10;
    int yPosition = tileLocation % 10;
    
    gameBoard[xPosition][yPosition].set_color(tile.get_color());
    gameBoard[xPosition][yPosition].set_number(tile.get_number());
}

void Board::move_Tile(const int& tileLocation, const int& newLocation, const Tile& tile){
    int xPosition = tileLocation / 10;
    int yPosition = tileLocation % 10;
    int newXPosition = newLocation / 10;
    int newYPosition = newLocation % 10;
    
    // conditions
    // if the space isn't taken
    int col = gameBoard[xPosition][yPosition].get_color();
    int num = gameBoard[xPosition][yPosition].get_number();
    
    // set the new tile
    gameBoard[newXPosition][newYPosition].set_color(col);
    gameBoard[newXPosition][newYPosition].set_number(num);
    
    //clear the old tile
    gameBoard[xPosition][yPosition].set_color(0);
    gameBoard[xPosition][yPosition].set_number(0);
}

bool Board::isFull() const{
    for(int i; i < 4; i++){
        for(int j; j < 4; j++){
            if(gameBoard[i][j].get_number() == 0 && gameBoard[i][j].get_color() == 0)
                return false;
        };
    };
    // if is full return true
    return true;
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
