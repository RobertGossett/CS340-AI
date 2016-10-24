#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

using namespace std;

#include "Tile.h"
#include "Board.h"
#include "Text.h"
#include "Player.h"
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
    
    //returns the score of the neighborhood myTiles
    int score_neighborhood(Neighborhood myHood);
    
    //returns true if all tiles are the same number
    bool hasSameNumber(Neighborhood myHood);
    
    //returns true if all tiles are the same color
    bool hasSameColor(Neighborhood myHood);
    
    //returns true if every tile has a different color
    bool hasEveryColor(Neighborhood myHood);

    //returns true if every tile has a different number
    bool hasEveryNumber(Neighborhood myHood);
    
    //returns true if there is are two pairs, having the same numbers and colors
    bool hasTwoPair(Neighborhood myHood);
    
    //returns true if there exists a pair of colors and of numbers
    bool hasPairColorNumber(Neighborhood myHood);
    
    //returns true if there exists a pair of colors
    bool hasPairColor(Neighborhood myHood);
    
    //returns true if there exists a pair of numbers
    bool hasPairNumber(Neighborhood myHood);

    
    
    
    
 private:   
    
    Player* playerOne; // pointer to the playey -- will become the AI
    Board*  gameBoard; // pointer to the board on which the player plays
    Graphics* Display; // pointer to the display
    bool active; // bool representing the status of the game manager. Active or inactive?
    struct scoreValues{
        int pairNumbers;
        int pairColors;
    } scoreGuide;

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
        playerOne->dealTileHand(tileHand);
        playerOne->makeMove(gameBoard);
        scoreBoard();
        isActive();
    }
    
}


void GameManager::scoreBoard(){
    
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


//returns the score of the neighborhood myTiles
int GameManager::score_neighborhood(Neighborhood myHood) {
    
    //***ORDER MATTERS FOR THESE IF STATEMENTS
    
    if (hasSameColor(myHood) && hasSameNumber(myHood)) //clears neighborhood
        return 400;
    else if (hasSameColor(myHood) && hasEveryNumber(myHood)) //clears neighborhood
        return 200;
    else if (hasEveryColor(myHood) && hasSameNumber(myHood)) //clears neighborhood
        return 200;
    else if (hasEveryColor(myHood) && hasEveryNumber(myHood)) //clears neighborhood
        return 100;
    //all the rest don't clear
    else if (hasTwoPair(myHood))
        return 60;
    else if (hasSameColor(myHood))
        return 40;
    else if (hasSameNumber(myHood))
        return 40;
    else if (hasPairColorNumber(myHood))
        return 20;
    else if (hasEveryColor(myHood))
        return 10;
    else if (hasPairColor(myHood))
        return 5;
    else if (hasPairNumber(myHood))
        return 5;
    
    return 0;
}

//returns true if all tiles are the same number
bool GameManager::hasSameNumber(Neighborhood myHood){
    vector<Tile> tempTiles = myHood.get_Neighborhood_Tiles();
    if (tempTiles[0].get_number() == tempTiles[1].get_number() ==
        tempTiles[2].get_number() == tempTiles[3].get_number() )
        return true;
    else
        return false;
}

//returns true if all tiles are the same color
bool GameManager::hasSameColor(Neighborhood myHood){
    vector<Tile> tempTiles = myHood.get_Neighborhood_Tiles();
    if (tempTiles[0].get_color() == tempTiles[1].get_number() ==
        tempTiles[2].get_color() == tempTiles[3].get_number() )
        return true;
    else
        return false;
}

//returns true if every tile has a different color
bool GameManager::hasEveryColor(Neighborhood myHood){
    bool hasRed = false;
    bool hasYellow = false;
    bool hasGreen = false;
    bool hasBlue = false;
    
    //for each tile in the neighborhood, if that's not the first time we've seen that color, return false
    for (int i = 0; i < 4; i++) {
        
        Tile tempTile = myHood.get_Neighborhood_Tiles()[i];                     //**NEED COPY CONSTRUCTOR
        
        //for each color we could have
        for (int j = 1; j <=4; j++) {
            //
            if (tempTile.get_color() == j) {
                
                //if someone doesn't already have a red piece and our piece is red, mark that we found a red piece and so on..
                if (j == 1 && hasRed == false)
                    hasRed = true;
                else if (j == 2 && hasYellow == false)
                    hasYellow = true;
                else if (j == 3 && hasGreen == false)
                    hasGreen = true;
                else if (j == 4 && hasBlue == false)
                    hasBlue = true;
                //else we have a piece that has already been marked, so return false
                else {
                    return false;
                }
            }
        }
    }
    
    //if we made it out of both for loops alive, then we hit exactly every color once
    return true;
}

//returns true if every tile has a different number
bool GameManager::hasEveryNumber(Neighborhood myHood){
    bool has1 = false;
    bool has2 = false;
    bool has3 = false;
    bool has4 = false;
    
    //for each tile in the neighborhood, if that's not the first time we've seen that color, return false
    for (int i = 0; i < 4; i++) {
        
        Tile tempTile = myHood.get_Neighborhood_Tiles()[i];                     //**NEED COPY CONSTRUCTOR
        
        //for each number we could have
        for (int j = 1; j <=4; j++) {
            //
            if (tempTile.get_number() == j) {
                
                //if someone doesn't already have a 1 and our piece's number is such, mark that we found a number 1 and so on..
                if (j == 1 && has1 == false)
                    has1 = true;
                else if (j == 2 && has2 == false)
                    has2 = true;
                else if (j == 3 && has3 == false)
                    has3 = true;
                else if (j == 4 && has4 == false)
                    has4 = true;
                //else we have a piece that has already been marked, so return false
                else {
                    return false;
                }
            }
        }
    }
    
    //if we made it out of both for loops alive, then we hit exactly every number once
    return true;
    

}

//returns true if there are two pairs, having the same numbers and colors
bool GameManager::hasTwoPair(Neighborhood myHood){
    vector<int> hashTiles;
    //hash tiles holds tile count for the hood
    //index of tile G3 = [ (color - 1) * 4 ] + number - 1
    hashTiles.resize(16, 0);
    
    vector<Tile> tempTiles;
    tempTiles = myHood.get_Neighborhood_Tiles();
    
    //counts how many of each tile are in the neighborhood
    for (int i = 0; i < tempTiles.size(); i++) {
        int tempColor = tempTiles[i].get_color();
        int tempNumber = tempTiles[i].get_number();
        
        //index of tile G3 = [ (color - 1) * 4 ] + number - 1
        int index = (tempColor - 1) * 4 + tempNumber - 1;
        hashTiles[index] += 1;
    }
    
    //now, we know how many of each tile we have, look in hashTiles and see
    //if we have a two pair for color and number. This would be
    int numberOfPairs = 0;
    for (int i = 0; i < hashTiles.size(); i++) {
        if (hashTiles[i] == 2) {
            numberOfPairs += 1;
        }
    }
    
    if (numberOfPairs == 2){
        return true;
    }
    else {
        return false;
    }
}

//returns true if there exists a pair of colors and of numbers
bool GameManager::hasPairColorNumber(Neighborhood myHood){
    if (hasPairColor(myHood) && hasPairNumber(myHood)){
        return true;
    }
    else {
        return false;
    }
}

//returns true if there exists a pair of colors
bool GameManager::hasPairColor(Neighborhood myHood){
    bool hasPair1 = false;
    bool hasPair2 = false;
    //numOfTiles1/2 is a variable to indicate how many of the tiles
    //have color1 and color2
    int numOfTiles1 = 0;
    int numOfTiles2 = 0;
    int color1 = -1;
    int color2 = -1;
    vector<Tile> tempTiles = myHood.get_Neighborhood_Tiles();
    //if we're looking at the first tile, set the color equal to that tile
    //now if any tiles color does not
    for (int i = 0; i < tempTiles.size(); i++) {
        
        int curColor = tempTiles[i].get_color();
        
        //if we're looking at the first tile, set the first
        //color = first tile's color
        if (color1 == -1 && color2 == -1) {
            numOfTiles1 += 1;
            color1 = curColor;
        }
        //if we've already assigned color1, and curColor != color1,
        //then assign color 2 = curColor
        else if ( color1 != -1 && curColor != color1 && color2 == -1) {
            numOfTiles2 += 1;
            color2 = curColor;
        }
        
        //if our current tiles color = color 1, and we haven't seen more
        //than one other tile with that color, we have a pair for that color
        else if (curColor == color1 && numOfTiles1 < 2) {
            hasPair1 = true;
        }
        //if our current tiles color = color 2, and we haven't seen more
        //than one other tile with that color, we have a pair for that color
        else if (curColor == color2 && numOfTiles2 < 2) {
            hasPair2 = true;
        }
        else if(curColor != color1 && curColor != color2){
            hasPair1 = false;
            hasPair2 = false;
        }
    }
    return (hasPair1 && hasPair2);
}

//returns true if there exists a pair of numbers
bool GameManager::hasPairNumber(Neighborhood myHood){
    
    bool hasPair1 = false;
    bool hasPair2 = false;
    //numOfTiles1/2 is a variable to indicate how many of the tiles
    //have color1 and color2
    int numOfTiles1 = 0;
    int numOfTiles2 = 0;
    int num1 = -1;
    int num2 = -1;
    vector<Tile> tempTiles = myHood.get_Neighborhood_Tiles();
    //if we're looking at the first tile, set the number equal to that tile
    //now if any tiles color does not
    
    for (int i = 0; i < tempTiles.size(); i++) {
        
        int curNum = tempTiles[i].get_number();
        
        //if we're looking at the first tile, set the first
        //number = first tile's number
        if (num1 == -1 && num2 == -1) {
            numOfTiles1 += 1;
            num1 = curNum;
        }
        //if we've already assigned number1, and curNumber != number1,
        //then assign number 2 = curNumber
        else if ( num1 != -1 && curNum != num1 && num2 == -1) {
            numOfTiles2 += 1;
            num2 = curNum;
        }
        
        //if our current tiles number = number 1, and we haven't seen more
        //than one other tile with that number, we have a pair for that number
        else if (curNum == num1 && numOfTiles1 < 2) {
            hasPair1 = true;
        }
        //if our current tiles number = number 2, and we haven't seen more
        //than one other tile with that number, we have a pair for that number
        else if (curNum == num2 && numOfTiles2 < 2) {
            hasPair2 = true;
        }
        else if(curNum != num1 && curNum != num2){
            hasPair1 = false;
            hasPair2 = false;
        }
    }
    return (hasPair1 && hasPair2);
    
    return false;
}




#endif
