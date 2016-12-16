//
//  Board.h
//  Final Project
//
//  Created by Robert Gossett on 9/28/16.
//  Copyright © 2016 Robert Gossett. All rights reserved.
//

#ifndef BOARD_H_INCLUDED_
#define BOARD_H_INCLUDED_

using namespace std;
#include <vector>
#include <iostream>
//#include "Game.h"
#include "Tile.h"

class Board{
public:
    
    // constructor for the board
    Board();
    
    // copy constructor
    Board(Board* oldBoard);
    
    // get set for the 2d vector holding the board
    void set_Board(const vector<vector<Tile> >& newBoard); // complete
    vector<vector<Tile> > get_Board() const; // complete
    
    // print board -- will be implemented in the graphics handler
    void printBoard(); // complete
    
    // lock and unlock the entire board
    void lock_Tiles(); // complete
    void unlock_Tiles(); // complete
    
    // lock and unlock a single piece
    void lock_Tile(const int& tileLocation); // complete
    void unlock_Tile(const int& tileLocation); // complete
    
    // adds a piece to the tile coordinates supplied by tile location.
    // adding tile to tileLocation 21 would add it to the row 2, column 1.
    bool add_Tile(const Tile& tile, const int& tileLocation); // complete
    
    // moves the tile from old location to a new location on the board
    // executable on unlocked tiles
    bool move_Tile(const int& tileLocation, const int& newLocation); //  complete
    
    // returns true if the board is full
    bool isFull() const; // complete
    
    Tile get_Tile(const int& tileLocation);
    void set_Tile(const int& location, const int& color, const int& number);
    
private:
    
    vector< vector<Tile> > gameBoard; // the gameBoard
    Tile baseTile; // the tile used for tile work within the board class
    
    
};

Board::Board() {
    
    vector<vector<Tile> > holder(4, vector<Tile>(4));
    for(int i = 0 ; i < 4; i++){
        for(int j = 0; j < 4; j++){
            baseTile.set_location((i+1)*10+j+1);
            holder[i][j] = baseTile;
        };
    };
    set_Board(holder);
}

Board::Board(Board* oldBoard){
    vector<vector<Tile> > holder(4, vector<Tile>(4));
    for(int i = 0 ; i < 4; i++){
        for(int j = 0; j < 4; j++){
            holder[i][j] = oldBoard->get_Tile((i+1)*10+j+1);
        };
    };
    set_Board(holder);
}
void Board::set_Board(const vector<vector<Tile> >& newBoard){
    gameBoard = newBoard;
}

vector<vector<Tile> > Board::get_Board() const{
    return gameBoard;
}

void Board::lock_Tiles(){
    for(int i = 0 ; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(gameBoard[i][j].get_number() != 0 && gameBoard[i][j].get_color() != 0)
                gameBoard[i][j].lock();
        };
    };
    
}

void Board::unlock_Tiles(){
    for(int i = 0 ; i < 4; i++){
        for(int j = 0; j < 4; j++){
            gameBoard[i][j].unlock();
        };
    };
    
}


void Board::lock_Tile(const int& tileLocation){
    int xPosition = (tileLocation - 11) / 10;
    int yPosition = (tileLocation - 11) % 10;
    gameBoard[xPosition][yPosition].lock();
    
}

void Board::unlock_Tile(const int& tileLocation){
    int xPosition = (tileLocation - 11) / 10;
    int yPosition = (tileLocation - 11) % 10;
    gameBoard[xPosition][yPosition].unlock();
}

bool Board::add_Tile(const Tile& tile, const int& tileLocation){
    int xPosition = (tileLocation - 11) / 10;
    int yPosition = (tileLocation - 11) % 10;
    
    if(!gameBoard[xPosition][yPosition].isLocked()){
        gameBoard[xPosition][yPosition].set_color(tile.get_color());
        gameBoard[xPosition][yPosition].set_number(tile.get_number());
        gameBoard[xPosition][yPosition].set_location(tileLocation);
        return true;
    }
    else return false;
}
Tile Board::get_Tile(const int& tileLocation){
    int xPosition = (tileLocation - 11) / 10;
    int yPosition = (tileLocation - 11) % 10;
    
    return gameBoard[xPosition][yPosition];
}

void Board::set_Tile(const int& location, const int& color, const int& number){
    int xPosition = (location - 11) / 10;
    int yPosition = (location - 11) % 10;
    
    gameBoard[xPosition][yPosition].set_number(number);
    gameBoard[xPosition][yPosition].set_color(color);
}

bool Board::move_Tile(const int& tileLocation, const int& newLocation){
    int xPosition = (tileLocation - 11) / 10;
    int yPosition = (tileLocation - 11) % 10;
    int newXPosition = (newLocation - 11) / 10;
    int newYPosition = (newLocation - 11) % 10;
    
    // conditions
    // if the space isn't taken
    if(!gameBoard[newXPosition][newYPosition].isLocked()){
        int col = gameBoard[xPosition][yPosition].get_color();
        int num = gameBoard[xPosition][yPosition].get_number();
        
        // set the new tile
        gameBoard[newXPosition][newYPosition].set_color(col);
        gameBoard[newXPosition][newYPosition].set_number(num);
        
        //clear the old tile
        gameBoard[xPosition][yPosition].set_color(0);
        gameBoard[xPosition][yPosition].set_number(0);
        
        
        return true;
    }
    else return false;
}

bool Board::isFull() const{
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(gameBoard[i][j].get_number() == 0 && gameBoard[i][j].get_color() == 0)
                return false;
        };
    };
    // if is full return true
    return true;
}

// prints the current board
void Board::printBoard(){
    cout << "---------------------" << endl;
    for(int i = 0; i < 4; i++){
        cout << "| ";
        for(int j = 0; j < 4; j++){
            cout << gameBoard[i][j].get_color() << gameBoard[i][j].get_number() << " | ";
            
        };
        
        cout << endl;
        cout << "---------------------" << endl;
    };
    
}




#endif /* Board_h */
