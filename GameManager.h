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
    
    Player* playerOne; // pointer to the playey -- will become the AI
    Board*  gameBoard; // pointer to the board on which the player plays
    Graphics* Display; // pointer to the display
    bool active; // bool representing the status of the game manager. Active or inactive?
<<<<<<< HEAD
=======
    struct scoreValues{
        int pairNumbers;
        int pairColors;
    } scoreGuide;
>>>>>>> RobertsBranch

};

GameManager::GameManager(){
<<<<<<< HEAD
    
=======
    scoreGuide.pairNumbers = 5;
    scoreGuide.pairColors = 5;
>>>>>>> RobertsBranch
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
<<<<<<< HEAD
    // code here...
=======
    vector<vector<Tile> > scoreBoard;
    scoreBoard = gameBoard->get_Board();
    Tile currentTile;
    
    // lets score the S*@t out of this board baybay
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            currentTile = scoreBoard[i][j];
            if(currentTile.get_number() != 0){// first look for pairs of numbers
                int currentNumber = currentTile.get_number();
                if(j != 0 && currentNumber == scoreBoard[i][j - 1].get_number()){ // if we find pair left
                    playerOne->increment_score(scoreGuide.pairNumbers);
                }
                else if(j != 3 && currentNumber == scoreBoard[i][j + 1].get_number()){ // if we find pair right
                    playerOne->increment_score(scoreGuide.pairNumbers);
                }
                else if(i != 0 && currentNumber == scoreBoard[i - 1][j].get_number()){ // if we find pair up
                    playerOne->increment_score(scoreGuide.pairNumbers);
                }
                else if(i != 3 && currentNumber == scoreBoard[i + 1][j].get_number()){ // if we find pair down
                    playerOne->increment_score(scoreGuide.pairNumbers);
                }
                
            }
            
            if(currentTile.get_color() != 0){// now lets look a pairs of colors
                int currentColor = currentTile.get_color();
                if(j != 0 && currentColor == scoreBoard[i][j - 1].get_color()){ // if we find pair left
                    playerOne->increment_score(scoreGuide.pairNumbers);
                }
                else if(j != 3 && currentColor == scoreBoard[i][j + 1].get_color()){ // if we find pair right
                    playerOne->increment_score(scoreGuide.pairNumbers);
                }
                else if(i != 0 && currentColor == scoreBoard[i - 1][j].get_color()){ // if we find pair up
                    playerOne->increment_score(scoreGuide.pairNumbers);
                }
                else if(i != 3 && currentColor == scoreBoard[i + 1][j].get_color()){ // if we find pair down
                    playerOne->increment_score(scoreGuide.pairNumbers);
                }
                
            }

            
        }
    }
    
>>>>>>> RobertsBranch
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
