#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

using namespace std;

#include "Tile.h"
#include "Board.h"
#include "Player.h"
#include "Text.h"
#include <vector>
#include "Game.h"
#include "Neighborhood.h"



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
    
    void generateNeighborhoods();
    void updateNeighborhoods();
    void generateRowNeighborhoods();
    void generateColumnNeighborhoods();
    void generateBoxNeighborhoods();

    void updateNeighborhoods();


 private:   
    
    Player* playerOne; // pointer to the playey -- will become the AI
    Board*  gameBoard; // pointer to the board on which the player plays
    Graphics* Display; // pointer to the display
    bool active; // bool representing the status of the game manager. Active or inactive?
    struct scoreValues{
        int pairNumbers;
        int pairColors;
    } scoreGuide;
    vector<neighborhood> neighborhoods;


};

GameManager::GameManager(){
    scoreGuide.pairNumbers = 5;
    scoreGuide.pairColors = 5;
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
        generateNeighborhoods();
        playerOne->dealTileHand(tileHand);

        playerOne->makeMove(gameBoard);
        
        scoreBoard();

        isActive();
    }
    
}
void GameManager::generateNeighborhoods(){
      
        generateRowNeighborhoods();
        generateColumnNeighborhoods();
        generateBoxNeighborhoods();

        Neighborhood myNeighborhood;
        myNeighborhood.add_tile(get_tile(11));
        myNeighborhood.add_tile(get_tile.(gameBoard.size()*10 + gameBoard.size()));
        myNeighborhood.add_tile(get_tile.(10+gameBoard.size()));
        myNeighborhood.add_tile(get_tile.(gameBoard.size()*10))
        myNeighborhood.set_type("Corner");

        neighborhoods.push_back(myNeighborhood);

}

void GameManager::generateRowNeighborhoods(){
      for(int i=1; i=<gameBoard.size(); i++){
        Neighborhood  myNeighborhood;
          for(int j=1; j=<gameBoard.size; j++){
            Tile  myTile= gameBoard.get_tile((i*10+j));
             myNeighborhood.add_tile(myTile);
          }
          myNeighborhood.set_type("Row");
          neighborhoods.push_back(myNeighborhood);
      }
}
void GameManager::generateColumnNeighborhoods(){
      for(int i=1; i=<gameBoard.size(); i++){
        Neighborhood  myNeighborhood;
          for(int j=1; j=<gameBoard.size; j++){
            Tile  myTile= gameBoard.get_tile((j*10+i));
             myNeighborhood.add_tile(myTile);
          }
          myNeighborhood.set_type("Column");
          neighborhoods.push_back(myNeighborhood);
      }
}
void GameManager::generateBoxNeighborhoods(){
     for(int i=0; i<gameBoard.size()-1; i++){
      for(int j=0; j<gameBoard.size()-1; j++){
        Neighborhood  myNeighborhood;
          

         myNeighborhood.add_tile(gameBoard.get_tile((i*10+j)));
            myNeighborhood.add_tile(gameBoard.get_tile((i*10+(j+1)));
             myNeighborhood.add_tile(gameBoard.get_tile(((i+1)*10+j))); 
              myNeighborhood.add_tile(gameBoard.get_tile(((i+1)*10+(j+1)));   

          
          myNeighborhood.set_type("Box");
          neighborhoods.push_back(myNeighborhood);
      }
    }

}
}
void GameManager::updateNeighborhoods(){
  
}


void GameManager::scoreBoard(){
    bool totalScore;
   for(int i=0; i<=neighborhoods.size()){
    if(!neighborhoods(i).isLocked()){
     totalScore += scoreNeighborhood(neighborhoods(i));
     neighborhoods(i).lock();
    } 
    
   }

  playerOne->set_score(totalScore);
    
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
