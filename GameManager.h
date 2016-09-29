#ifndef GAMEMANAGER_H
#define GAMAEMANAGER_H

using namespace std;

#include "Tile.h"
#include "Board.h"
#include "Graphics.h"
#include "Player.h"


class GameManager{
 public:

 	GameManager();
   
    void set_up();
    void start_game();
    void setPlayer(Player* player);
    void scoreBoard();
    void generateTile();
    

    // Getters & Setters
    void setBoard(Board* board);
    void setDisplay(Graphics* display);
    Player* getPlayer();
    Board* getBoard();
    Graphics* getDisplay();
 private:   
    
    Player* playerOne;
    Board*  gameBoard;
    Graphics* display;
    bool active;

};


set_up(){

    display = new Graphics;
    playerOne = new Player;
    playerOne->init();
    gameBoard = new Board;
    active = true;
 
    start_game();
} 

start_game(){
    while(active){
        vector<Tile> generateTile();
        playerOne->dealTile()
        playerOne->makeMove();
        scoreBoard();
        checkActive();
    }

}