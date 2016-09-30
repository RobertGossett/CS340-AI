#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

using namespace std;

#include "Tile.h"
#include "Board.h"
#include "Text.h"
#include "Player.h"
#include <vector>
#include "Game.h"




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
    void setBoard(Board* board); // complete
    
    // points the Display pointer to a Graphics* param
    void setDisplay(Graphics* display); // complete
    
    // set's the player
    void setPlayer(Player* player); // complete
    
    // returns a pointer to the player
    Player* getPlayer() const; // complete
    
    // returns a pointer to the gameBoard
    Board* getBoard() const; // complete
    
    // returns a pointer to the display
    Graphics* getDisplay() const; // complete
    
    // returns true if the GameManager is active
    bool isActive() const; // complete
    
    // sets the game manager to active state
    void activate(); // complete
    
    // sets the game manager to inactive state
    void deactivate(); // complete
    
    
 private:   
    
    Player* playerOne;
    Board*  gameBoard;
    Graphics* Display;
    bool active;

};

GameManager::GameManager(){
    
}


void GameManager::set_up(){
    
    Display = new Text;
    playerOne = new Player(Display, gameBoard);
    gameBoard = new Board;
    active = true;
    
    start_game();
}

void GameManager::start_game(){
    while(active){
        Display->start_Game();
        vector<Tile> tileHand = generateTileHand();
        playerOne->dealTileHand(tileHand);
        playerOne->makeMove(gameBoard);
        scoreBoard();
        isActive();
    }
    
}

void GameManager::scoreBoard(){
    // code here...
}

vector<Tile> GameManager::generateTileHand(){
    vector<Tile> randomTiles;
    Tile randomTile;
    for(int i = 0; i < 4; i++){
        randomTile.randomize();
        randomTiles.push_back(randomTile);
    }
    return randomTiles;
}

void GameManager::setBoard(Board* board){
    gameBoard = board;
}

void GameManager::setDisplay(Graphics* display){
    Display = display;
}

void GameManager::setPlayer(Player* player){
    playerOne = player;
}

Player* GameManager::getPlayer() const{
    return playerOne;
}

Board* GameManager::getBoard() const {
    return gameBoard;
}

Graphics* GameManager::getDisplay() const{
    return Display;
}

bool GameManager::isActive() const{
    return active;
}

void GameManager::activate(){
    active = true;
}

void GameManager::deactivate(){
    active = false;
}

#endif
