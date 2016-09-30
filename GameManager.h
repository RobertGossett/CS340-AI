#ifndef GAMEMANAGER_H
#define GAMAEMANAGER_H

using namespace std;

#include "Tile.h"
#include "Board.h"
#include <vector>
#include "Graphics.h"
#include "Player.h"



class GameManager{
 public:

 	GameManager();
    
    // set up the game
    void set_up(); // complete
    
    // start the game
    void start_game(); //complete
    
    
    // calculates the score of the gameBoard
    void scoreBoard(); // INCOMPLETE - will be changing dynamically
    
    // generates the playable tile hand of 4 tiles.
    vector<Tile> generateTileHand(); //complete
    

    // Getters & Setters
    
    // points the Board pointer to a Board* param
    void setBoard(const Board* board); // complete
    
    // points the Display pointer to a Graphics* param
    void setDisplay(const Graphics* display); // complete
    
    // set's the player
    void setPlayer(const Player* player); // complete
    
    // returns a pointer to the player
    Player* getPlayer() const; // complete
    
    // returns a pointer to the gameBoard
    Board* getBoard() const;
    
    // returns a pointer to the display
    Graphics* getDisplay() const;
 private:   
    
    Player* playerOne;
    Board*  gameBoard;
    Graphics* Display;
    bool active;

};



void GameManager::set_up(){

    display = new Graphics;
    playerOne = new Player;
    playerOne->init();
    gameBoard = new Board;
    active = true;
 
    start_game();
} 

void GameManager::start_game(){
    while(active){
        vector<Tile> tileHand = generateTileHand();
        playerOne->dealTileHand(const vector<Tile>& tileHand)
        playerOne->makeMove();
        scoreBoard();
        checkActive();
    }

}

void GameManager::scoreBoard(){
    // code here...
}

vector<Tile> GameManager::generateTileHand(){
    vector<Tile> randomTiles;
    Tile randomTile;
    for(int i = 0; i < 3; i++){
        randomTile.randomize();
        randomTiles.push_back(Tile);
    }
    return randomTiles
}

void GameManager::setBoard(const Board* board){
    gameBoard = board;
}

void GameManager::setDisplay(const Graphics* display){
    Display = display;
}

void GameManager::setPlayer(const Player* player){
    Player = player;
}

Player* GameManager::getPlayer() const{
    return playerOne;
}

Board* GameManager::getBoard() const {
    return gameBoard
}

Graphics* GameManager::getDisplay() const{
    return Display;
}
