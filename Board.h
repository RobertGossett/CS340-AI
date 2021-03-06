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
    void set_Board(const vector<vector<Tile> >& newBoard); // complete
    vector<vector<Tile> > get_Board() const; // complete
    
    // print board -- will be implemented in the graphics handler
    void printBoard(); // complete
    
    // lock and unlock the pieces on the  the board
    void lock_Tiles(); // complete
    void unlock_Tiles(); // complete
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
    
    
    
private:
    
    vector<vector<Tile> > gameBoard;
    Tile baseTile;

    
};

Board::Board() {

    vector<vector<Tile> > holder(4, vector<Tile>(4));
    for(int i = 0 ; i < 4; i++){
        for(int j = 0; j < 4; j++){
                holder[i][j] = baseTile;
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
        return true;
    }
    else return false;
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
