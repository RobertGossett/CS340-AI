#ifndef GAMEMANAGER_H_INCLUDED_
#define GAMEMANAGER_H_INCLUDED_

using namespace std;
/*
#include "Tile.h"
#include "Board.h"
#include "HumanPlayer.h"
#include "Text.h"*/
#include <vector>
#include "Game.h"
#include "Tile.h"
#include "Board.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "Graphics.h"
#include "Text.h"
#include "Neighborhood.h"
#include "ArtificialPlayer.h"
#include "WaitTile.h"

class ArtificialPlayer;

class GameManager{
public:


    GameManager();
    
    GameManager(const GameManager& gm);

    // set up the game
    void set_up(); // complete

    // start the game
    void start_game(); //complete

    // generates the playable tile hand of 4 tiles.
    vector<Tile> generateTileHand(); //complete

    // generates the neighborhoods
    vector<Neighborhood> generateNeighborhoods();

    // generates the row neighborhoods
    void generateRowNeighborhoods(vector<Neighborhood>& myNeighborhoods);

    // generates the column neighborhoods
    void generateColumnNeighborhoods(vector<Neighborhood>& myNeighborhoods);

    // generates the 2 x 2 neighborhoods
    void generateBoxNeighborhoods(vector<Neighborhood>& myNeighborhoods);

    void generateDiagonalNeighborhoods(vector<Neighborhood>& myNeighborhoods);



    void clearNeighborhood(Neighborhood& myNeighborhood);

    void clearRow(Neighborhood& myNeighborhood);
    void clearColumn(Neighborhood& myNeighborhood);
    void clearBox(Neighborhood& myNeighborhood);
    void clearDiagonal(Neighborhood& myNeighborhood);


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
    int score_neighborhood(const Neighborhood& myHood);


        // calculates the score of the gameBoard

    int scoreBoard(Board* thisBoard); // INCOMPLETE - will be changing dynamically

    // resets tge score of the neighborhoods
    void resetNeighborhoods();

    //returns true if all tiles are the same number
    bool hasSameNumber(const Neighborhood& myHood);

    //returns true if all tiles are the same color
    bool hasSameColor(const Neighborhood& myHood);

    //returns true if every tile has a different color
    bool hasEveryColor(const Neighborhood& myHood);

    //returns true if every tile has a different number
    bool hasEveryNumber(const Neighborhood& myHood);

    //returns true if there is are two pairs, having the same numbers and colors
    bool hasTwoPair(const Neighborhood& myHood);

    //returns true if there exists a pair of colors and of numbers
    bool hasPairColorNumber(const Neighborhood& myHood);

    //returns true if there exists a pair of colors
    bool hasPairColor(const Neighborhood& myHood);

    //returns true if there exists a pair of numbers
    bool hasPairNumber(const Neighborhood& myHood);

    //returns true if there are any zeros in the hood
    bool hasZeros(const Neighborhood& myHood);
    
    //returns the score of the neighborhood myTiles
    int score_neighborhood_with_joker(const Neighborhood& myHood);
    
    //returns true if all tiles are the same number
    bool hasSameNumberWithJoker(const Neighborhood& myHood);
    
    //returns true if all tiles are the same color
    bool hasSameColorWithJoker(const Neighborhood& myHood);
    
    //returns true if every tile has a different color
    bool hasEveryColorWithJoker(const Neighborhood& myHood);
    
    //returns true if every tile has a different number
    bool hasEveryNumberWithJoker(const Neighborhood& myHood);
    
    //returns true if there is are two pairs, having the same numbers and colors
    bool hasTwoPairWithJoker(const Neighborhood& myHood);
    
    //returns true if there exists a pair of colors and of numbers
    bool hasPairColorNumberWithJoker(const Neighborhood& myHood);
    
    //returns true if there exists a pair of colors
    bool hasPairColorWithJoker(const Neighborhood& myHood);
    
    //returns true if there exists a pair of numbers
    bool hasPairNumberWithJoker(const Neighborhood& myHood);

    
    // generates the local neighborhoods around a certain tile
    vector<Neighborhood> get_local_Neighborhoods(const int& location);
    
    // generates the wait list for peices on the board
    vector<WaitTile> generate_waitList(Board* boardToBuild);
    
    // gives each peice a priority score based off of it's clearing combinations and it's total score
    int getPriorityScore(const vector<Neighborhood>& town);

    // AI function that doen't work. get's the best move by trying to place 
    vector<Tile> getBestMoves(Board* myBoard, vector<WaitTile> WaitList, vector<Tile> TileHand);

    // gets the best tile form the wait list
    Tile getBestTileInWaitList(vector<WaitTile> wl, Tile myTile);
                                                                // these both pretty much do the same thing
    // gets the best wait tile from the wait list
    WaitTile getBestWaitTileInWaitList(vector<WaitTile> wl, Tile myTile);

private:

    Player* playerOne;// pointer to the playey -- will become the AI
    Player* artificialPlayerOne; // pointer to an artificial player

    Player* player; // the pointer we use to handle both.


    Board*  gameBoard; // pointer to the board on which the player plays
    Graphics* Display; // pointer to the display
    bool active; // bool representing the status of the game manager. Active or inactive?
    struct scoreValues{
        int pairNumbers;
        int pairColors;
    } scoreGuide;
    vector<Neighborhood> neighborhoods;
    vector<Neighborhood> previoushood; // keeps track of the previous neighborhood
    Tile randomTile;

    vector<WaitTile> waitlist;


};

GameManager::GameManager(){
    scoreGuide.pairNumbers = 5;
    scoreGuide.pairColors = 5;
    srand(time(NULL));
}

GameManager::GameManager(const GameManager& gm){
    scoreGuide.pairNumbers = 5;
    scoreGuide.pairColors = 5;
    srand(time(NULL));
}


void GameManager::set_up(){

    Display = new Text;

    playerOne = new HumanPlayer(Display, gameBoard);
    artificialPlayerOne = new ArtificialPlayer(Display, gameBoard);
    
    artificialPlayerOne->set_GM(this);
    
    previoushood.resize(20);
    gameBoard = new Board;
    active = true;
    
    start_game();
    randomTile.randomize();
}

void GameManager::start_game(){
    Display->start_Game();
    
    int playerType = -1;
    while(playerType != 0 && playerType !=1){
        cout << endl << "Which player type should we play the game with? AI (0) or Human(1): ";
        cin >> playerType;
        cout << endl;
    }
    // human player
    if(playerType == 1){
    player = playerOne;
        while(active){
            
            vector<Tile> tileHand = generateTileHand();
            
            
            player->dealTileHand(tileHand);
            
            // we want to call generate neighborhoods in make move after every move,
            // score this, and  then reset neighborhoods. about to impliment
            while(playerOne->is_Active()){
                
                player->makeMove(gameBoard, tileHand);
            }
                //neighborhoods= generateNeighborhoods();
                int currentScore = scoreBoard(gameBoard);
                player->set_score(currentScore + player->get_score());
                
                if(player->level_Up()){
                    if(!(player->has_joker()))
                        player->set_joker();
                    else
                        player->set_score(currentScore +500);
                
                
                //resetNeighborhoods();
                
                
            }
            
            if(!isActive())
            deactivate();
        }
        Display->end_game();
    }
    
    else{
    player = artificialPlayerOne;
    
    while(isActive()){

        vector<Tile> tileHand = generateTileHand();
        
        vector<Tile> aiChoice;
        aiChoice.resize(0);
        
        player->dealTileHand(tileHand);

        // we want to call generate neighborhoods in make move after every move,
        // score this, and  then reset neighborhoods. about to impliment
        
            
       
            waitlist = generate_waitList(gameBoard);
        aiChoice = getBestMoves(gameBoard, waitlist, tileHand);
        player->makeMove(gameBoard, aiChoice);
            
        //neighborhoods= generateNeighborhoods();
        int currentScore = scoreBoard(gameBoard);
        player->set_score(currentScore + player->get_score());
       
        if(player->level_Up()){
            if(!(player->has_joker()))
               player->set_joker();
        else
            player->set_score(currentScore +500);
        }

        //resetNeighborhoods();
        
        
    }
        if(!isActive())
            deactivate();
       

    }
    Display->end_game();
}

void GameManager::resetNeighborhoods(){
    previoushood = neighborhoods;
    neighborhoods.clear();
    neighborhoods.resize(0);
    
}
vector<Neighborhood> GameManager::generateNeighborhoods(){
    vector<Neighborhood> myNeighborhoods;
    generateRowNeighborhoods(myNeighborhoods);
    generateColumnNeighborhoods(myNeighborhoods);
    generateBoxNeighborhoods(myNeighborhoods);
    generateDiagonalNeighborhoods(myNeighborhoods);

    Neighborhood myNeighborhood;
    myNeighborhood.add_Tile(gameBoard->get_Tile(11), 1);
    myNeighborhood.add_Tile(gameBoard->get_Tile(gameBoard->get_Board().size()*10 + 1), 2);
    myNeighborhood.add_Tile(gameBoard->get_Tile(10 + gameBoard->get_Board().size()), 3);
    myNeighborhood.add_Tile(gameBoard->get_Tile(gameBoard->get_Board().size()*10 + 4), 4);

    myNeighborhood.set_type("Corner");
    
    if(previoushood[myNeighborhoods.size()].isLocked())
        myNeighborhood.lock();

    myNeighborhoods.push_back(myNeighborhood);

    return myNeighborhoods;

}

void GameManager::generateRowNeighborhoods(vector<Neighborhood>& myNeighborhoods){
    for(int i=0; i < gameBoard->get_Board().size(); i++){
        Neighborhood  myNeighborhood;
        for(int j=1; j<=gameBoard->get_Board().size(); j++){
            Tile  myTile= gameBoard->get_Tile(((i+1)*10+j));
            myNeighborhood.add_Tile(myTile, j);
        }
        myNeighborhood.set_type("Row");
        myNeighborhood.set_index(i+1);

        if(previoushood[neighborhoods.size()].isLocked())
        myNeighborhood.lock();
        myNeighborhoods.push_back(myNeighborhood);

    }
}
void GameManager::generateColumnNeighborhoods(vector<Neighborhood>& myNeighborhoods){
    for(int i=1; i<=gameBoard->get_Board().size(); i++){
        Neighborhood  myNeighborhood;
        for(int j=1; j <= gameBoard->get_Board().size(); j++){
            Tile  myTile= gameBoard->get_Tile((j*10+i));
            myNeighborhood.add_Tile(myTile, j);
        }
        myNeighborhood.set_type("Column");
        myNeighborhood.set_index(i);
        if(previoushood[myNeighborhoods.size()].isLocked())
            myNeighborhood.lock();
        myNeighborhoods.push_back(myNeighborhood);

    }
}
void GameManager::generateBoxNeighborhoods(vector<Neighborhood>& myNeighborhoods){
    for(int i=1; i < gameBoard->get_Board().size()-1; i++){
        for(int j=1; j < gameBoard->get_Board().size()-1; j++){
            Neighborhood  myNeighborhood;


            myNeighborhood.add_Tile(gameBoard->get_Tile((i*10+j)), 1);
            myNeighborhood.add_Tile(gameBoard->get_Tile((i*10+(j+1))), 2);
            myNeighborhood.add_Tile(gameBoard->get_Tile(((i+1)*10+j)), 3);
            myNeighborhood.add_Tile(gameBoard->get_Tile(((i+1)*10+(j+1))), 4);


            myNeighborhood.set_type("Box");
            myNeighborhood.set_index(i*10 + j);
            if(previoushood[myNeighborhoods.size()].isLocked())
                 myNeighborhood.lock();
            myNeighborhoods.push_back(myNeighborhood);

        }
    }

}
void GameManager::generateDiagonalNeighborhoods(vector<Neighborhood>& myNeighborhoods){
    Neighborhood diagonalOne;
    Neighborhood diagonalTwo;
    for(int i=1; i<=gameBoard->get_Board().size(); i++){
        for(int j=1; j <= gameBoard->get_Board().size(); j++){
         if(i==j){
            Tile  myTile= gameBoard->get_Tile((i*10+j));
            diagonalOne.add_Tile(myTile, j);
         }

         if(i+j==gameBoard->get_Board().size()+1){
            Tile  myTile= gameBoard->get_Tile((i*10+j));
            diagonalTwo.add_Tile(myTile, j);
         }


        }
        diagonalOne.set_type("Diagonal");
        diagonalOne.set_index(1);
        diagonalTwo.set_type("Diagonal");
        diagonalTwo.set_index(2);

        if(previoushood[myNeighborhoods.size()].isLocked())
            diagonalOne.lock();
        myNeighborhoods.push_back(diagonalOne);

        if(previoushood[myNeighborhoods.size()].isLocked())
            diagonalTwo.lock();
        myNeighborhoods.push_back(diagonalTwo);


    }
}



int GameManager::scoreBoard(Board* thisBoard ){
   vector<Neighborhood> localNeighborhood= generateNeighborhoods();
    int totalScore = 0;
    int currentScore = 0;
    for(int i=0; i < localNeighborhood.size(); i++){
        
        if(!localNeighborhood[i].isLocked()){
            
            currentScore = score_neighborhood(localNeighborhood[i]);
            if (currentScore >= 100){
                localNeighborhood[i].clear_Neighborhood_Tiles();
                localNeighborhood[i].unlock();
                totalScore += currentScore;
                clearNeighborhood(localNeighborhood[i]);
            }
            else{
                totalScore += currentScore;
                if(currentScore != 0)
                localNeighborhood[i].lock();
            }
        }
        else {
            cout << endl << i << " is locked: " << localNeighborhood[i].isLocked() << endl;
        }
        

    }
    previoushood = localNeighborhood;
    return totalScore;

}

void GameManager::clearNeighborhood(Neighborhood&  myNeighborhood){
    if(myNeighborhood.get_type() == "Corner"){


        gameBoard->set_Tile(11, 0, 0);
        gameBoard->set_Tile(gameBoard->get_Board().size()*10 + gameBoard->get_Board().size(), 0, 0);


        gameBoard->set_Tile(10 + gameBoard->get_Board().size(), 0, 0);

        gameBoard->set_Tile(gameBoard->get_Board().size()*10 +1, 0, 0);
    }
    else if(myNeighborhood.get_type()=="Row")
        clearRow(myNeighborhood);
    else if(myNeighborhood.get_type()=="Column")
        clearColumn( myNeighborhood);
    else if(myNeighborhood.get_type()=="Diagonal")
        clearDiagonal(myNeighborhood);
    else
        clearBox(myNeighborhood);


}
void GameManager::clearColumn( Neighborhood& myNeighborhood){
    for(int i= 1; i<=gameBoard->get_Board().size(); i++ ){
        gameBoard->set_Tile(((10*i) + myNeighborhood.get_index()), 0, 0);

    }

}
void GameManager::clearRow(Neighborhood& myNeighborhood){
    for(int i= 1; i<=gameBoard->get_Board().size(); i++ ){
        gameBoard->set_Tile((10*myNeighborhood.get_index())+i, 0, 0);

    }

}

void GameManager::clearBox(Neighborhood& myNeighborhood){
    int i = myNeighborhood.get_index()/10;
    int j = myNeighborhood.get_index()%10;

    gameBoard->set_Tile(((i*10)+j), 0, 0);

    gameBoard->set_Tile(((i*10)+(j+1)), 0, 0);

    gameBoard->set_Tile(((i+1)*10+j), 0, 0);

    gameBoard->set_Tile((((i+1)*10)+(j+1)), 0, 0);
}
void GameManager::clearDiagonal(Neighborhood& myNeighborhood){
    if(myNeighborhood.get_index()==1){
        for(int i=1; i<=gameBoard->get_Board().size(); i++){
        for(int j=1; j <= gameBoard->get_Board().size(); j++){
         if(i==j){
            gameBoard->set_Tile((i*10+j), 0, 0);

         }}}
    }
    if(myNeighborhood.get_index()==2){
        for(int i=1; i<=gameBoard->get_Board().size(); i++){
        for(int j=1; j <= gameBoard->get_Board().size(); j++){
         if(i+j+1==gameBoard->get_Board().size()){
            gameBoard->set_Tile((i*10+j), 0, 0);

         }
        }
        }
    }
}

vector<Tile> GameManager::generateTileHand(){
    vector<Tile> randomTiles;


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
    
     for(int i=1; i < gameBoard->get_Board().size()+1; i++){
        for(int j=1; j < gameBoard->get_Board().size()+1; j++){
       if ( (gameBoard->get_Tile(i*10+ j).get_color() == 0) &&
             (gameBoard->get_Tile(i*10+ j).get_number() == 0))
           return true;
        }
     }
    return false;
}

void GameManager::activate(){
    active = true;
}

void GameManager::deactivate(){
    active = false;
}


int GameManager::score_neighborhood(const Neighborhood& myHood) {

    //***ORDER MATTERS FOR THESE IF STATEMENTS

    if (hasZeros(myHood)) {
      
        return false;
    }
    else if (hasSameColor(myHood) && hasSameNumber(myHood)){ //clears neighborhood
       
        return 400;
    }
    else if (hasSameColor(myHood) && hasEveryNumber(myHood)){ //clears neighborhood
     
        return 200;
    }
    else if (hasEveryColor(myHood) && hasSameNumber(myHood)) { //clears neighborhood
       
        return 200;
    }
    else if (hasEveryColor(myHood) && hasEveryNumber(myHood)) { //clears neighborhood
  
        return 100;
    }
    //all the rest don't clear
    else if (hasTwoPair(myHood)) {
  
        return 60;
    }
    else if (hasSameColor(myHood)) {

        return 40;
    }
    else if (hasSameNumber(myHood)) {

        return 40;
    }
    else if (hasPairColorNumber(myHood)) {

        return 20;
    }
    else if (hasEveryColor(myHood)) {

        return 10;
    }
    else if (hasPairColor(myHood)) {

        return 5;
    }
    else if (hasPairNumber(myHood)) {

        return 5;
    }

    return 0;
}

bool GameManager::hasZeros(const Neighborhood& myHood) {
    vector<Tile> tempTiles = myHood.get_Neighborhood_Tiles();

    for (int i = 0; i < 4; i++) {
        if (tempTiles[i].get_color() == 0)
            return true;
        if (tempTiles[i].get_number() == 0)
            return true;
    }

    return false;
}

//returns true if all tiles are the same number
bool GameManager::hasSameNumber(const Neighborhood& myHood){
    vector<Tile> tempTiles = myHood.get_Neighborhood_Tiles();


    for (int i = 0; i < 3; i++) {
        if (tempTiles[i].get_number() == 0)
            return false;
        if (tempTiles[i].get_number() != tempTiles[i+1].get_number())
            return false;
    }
    return true;

    /*
     if (tempTiles[0].get_number() == tempTiles[1].get_number() == tempTiles[2].get_number() == tempTiles[3].get_number() && tempTiles[0].get_number() != 0)
     return true;
     else
     return false;
     */

}

//returns true if all tiles are the same color
bool GameManager::hasSameColor(const Neighborhood& myHood){
    vector<Tile> tempTiles;
    tempTiles.resize(4);
    tempTiles = myHood.get_Neighborhood_Tiles();


    for (int i = 0; i < 3; i++) {
        if (tempTiles[i].get_color() == 0)
            return false;
        if (tempTiles[i].get_color() != tempTiles[i+1].get_color())
            return false;
    }
    return true;

    /*
    if (tempTiles[0].get_color() == tempTiles[1].get_color() ==
        tempTiles[2].get_color() == tempTiles[3].get_color() && tempTiles[0].get_color() != 0)
>>>>>>> KhayyamBranch
        return true;
    else
        return false;
     */
}

//returns true if every tile has a different color
bool GameManager::hasEveryColor(const Neighborhood& myHood){

    vector<Tile> tempTiles;
    tempTiles.resize(4);
    tempTiles = myHood.get_Neighborhood_Tiles();

    bool hasRed = false;
    bool hasYellow = false;
    bool hasGreen = false;
    bool hasBlue = false;

    if (tempTiles[0].get_color() != 0 && tempTiles[1].get_color() != 0 &&
        tempTiles[2].get_color() != 0  &&  tempTiles[3].get_color() != 0) {
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
    }

    //if we made it out of both for loops alive, then we hit exactly every color once
    if (hasRed && hasYellow && hasGreen && hasBlue)
        return true;
    else
        return false;
}

//returns true if every tile has a different number
bool GameManager::hasEveryNumber(const Neighborhood& myHood){
    vector<Tile> tempTiles;
    tempTiles.resize(4);
    tempTiles = myHood.get_Neighborhood_Tiles();

    bool has1 = false;
    bool has2 = false;
    bool has3 = false;
    bool has4 = false;


    if (tempTiles[0].get_number() != 0 && tempTiles[1].get_number() != 00 &&
        tempTiles[2].get_number() != 0  &&  tempTiles[3].get_number() != 0) {

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
    }

    //if we made it out of both for loops alive, then we hit exactly every number once
    if (has1 && has2 && has3 && has4)
        return true;
    else
        return false;


}

//returns true if there are two pairs, having the same numbers and colors
bool GameManager::hasTwoPair(const Neighborhood& myHood){
    vector<int> hashTiles;
    //hash tiles holds tile count for the hood
    //index of tile G3 = [ (color - 1) * 4 ] + number - 1
    hashTiles.resize(16, 0);

    vector<Tile> tempTiles;
    tempTiles.resize(4);
    tempTiles = myHood.get_Neighborhood_Tiles();

    if (tempTiles[0].get_color() != 0 && tempTiles[1].get_color() != 00 &&
        tempTiles[2].get_color() != 0  &&  tempTiles[3].get_color() != 0) {

        //counts how many of each tile are in the neighborhood
        for (int i = 0; i < tempTiles.size(); i++) {

            int tempColor = tempTiles[i].get_color();
            int tempNumber = tempTiles[i].get_number();

            //index of tile G3 = [ (color - 1) * 4 ] + number - 1
            int index = (tempColor - 1) * 4 + tempNumber - 1;
            hashTiles[index] += 1;

        }

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
bool GameManager::hasPairColorNumber(const Neighborhood& myHood){
    if (hasPairColor(myHood) && hasPairNumber(myHood)){
        return true;
    }
    else {
        return false;
    }
}

//returns true if there exists a pair of colors
bool GameManager::hasPairColor(const Neighborhood& myHood){
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
    //now if any tiles color does not = that tile

    if (tempTiles[0].get_color() != 0 && tempTiles[1].get_color() != 00 &&
        tempTiles[2].get_color() != 0  &&  tempTiles[3].get_color() != 0) {

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

    }


    return (hasPair1 && hasPair2);
}

//returns true if there exists a pair of numbers
bool GameManager::hasPairNumber(const Neighborhood& myHood){

    bool hasPair1 = false;
    bool hasPair2 = false;
    //numOfTiles1/2 is a variable to indicate how many of the tiles
    //have color1 and color2
    int numOfTiles1 = 0;
    int numOfTiles2 = 0;
    int num1 = -1;
    int num2 = -1;
    vector<Tile> tempTiles = myHood.get_Neighborhood_Tiles();

    if (tempTiles[0].get_color() != 0 && tempTiles[1].get_color() != 00 &&
        tempTiles[2].get_color() != 0  &&  tempTiles[3].get_color() != 0) {


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
    }
    return (hasPair1 && hasPair2);

    return false;
}


//returns the score of the neighborhood myTiles
int GameManager::score_neighborhood_with_joker(const Neighborhood& myHood) {
    
    //    //***ORDER MATTERS FOR THESE IF STATEMENTS
    //    if (hasZeros(myHood)) {
    //        cout << "Had Zeros." << endl;
    //        return false;
    //    }
    //    else
    if (hasSameColorWithJoker(myHood) && hasSameNumberWithJoker(myHood)){ //clears neighborhood
        cout << "Returning 400" << endl;
        return 400;
    }
    else if (hasSameColorWithJoker(myHood) && hasEveryNumberWithJoker(myHood)){ //clears neighborhood
        cout << "Returning 200, sColor e_number" << endl;
        return 200;
    }
    else if (hasEveryColorWithJoker(myHood) && hasSameNumberWithJoker(myHood)) { //clears neighborhood
        cout << "Returning 200, eColor, sNumber" << endl;
        return 200;
    }
    else if (hasEveryColorWithJoker(myHood) && hasEveryNumberWithJoker(myHood)) { //clears neighborhood
        cout << "Returning 100, eColor, eNumber" << endl;
        return 100;
    }
    //all the rest don't clear
    else if (hasTwoPairWithJoker(myHood)) {
        cout << "Returning 60, 2pair" << endl;
        return 60;
    }
    else if (hasSameColorWithJoker(myHood)) {
        cout << "Returning 40, sColor" << endl;
        return 40;
    }
    else if (hasSameNumberWithJoker(myHood)) {
        cout << "Returning 40, sNumber" << endl;
        return 40;
    }
    else if (hasPairColorNumberWithJoker(myHood)) {
        cout << "Returning 20, pColorNumber" << endl;
        return 20;
    }
    else if (hasEveryColorWithJoker(myHood)) {
        cout << "Returning 10, eColor" << endl;
        return 10;
    }
    else if (hasPairColorWithJoker(myHood)) {
        cout << "Returning 5, pColor" << endl;
        return 5;
    }
    else if (hasPairNumberWithJoker(myHood)) {
        cout << "Returning 5, pNumber" << endl;
        return 5;
    }
    
    return 0;
}


bool GameManager::hasPairColorNumberWithJoker(const Neighborhood& myHood) {
    if (hasPairColorWithJoker(myHood) && hasPairNumberWithJoker(myHood))
        return true;
    else
        return false;
}

//returns true if ever tile in myHood has the same Color
bool GameManager::hasSameColorWithJoker(const Neighborhood & myHood) {
    vector<Tile> t = myHood.get_Neighborhood_Tiles();
    //loop through all the tiles
    for (int i = 0; i < t.size() -1; i++){
        
        //loop through all the other tiles != i
        for (int j = 1; j <= t.size()-1; j++){
            
            //see if they're not equal
            if (t[i].get_color() != t[i+j].get_color() && (i+j) < t.size()){
                
                //if they aren't, check and see if it's because one of the two are jokers, J-tile = [5,5]
                if (t[i].get_color() != 5 && t[i+j].get_color() != 5) {
                    cout << "I = " << i << ", J = " << j << endl;
                    return false;
                }
            }
            
        }
    }
    
    //if we make it out of this for-loop alive, return true because everything(except the joker) is equal
    return true;
}


//returns true if ever tile in myHood has the same number
bool GameManager::hasSameNumberWithJoker(const Neighborhood & myHood) {
    vector<Tile> t = myHood.get_Neighborhood_Tiles();
    //loop through all the tiles
    for (int i = 0; i < t.size() -1; i++){
        
        //loop through all the other tiles != i
        for (int j = 1; j <= t.size()-1; j++){
            
            //see if they're not equal
            if (t[i].get_number() != t[i+j].get_number() && (i+j) < t.size()){
                
                //if they aren't, check and see if it's because one of the two are jokers, J-tile = [5,5]
                if (t[i].get_number() != 5 && t[i+j].get_number() != 5) {
                    return false;
                }
            }
            
        }
    }
    
    //if we make it out of this for-loop alive, return true because everything(except the joker) is equal
    return true;
}

//returns true if ever tile in myHood has a different color
bool GameManager::hasEveryColorWithJoker(const Neighborhood & myHood) {
    vector<Tile> t = myHood.get_Neighborhood_Tiles();
    //loop through all the tiles
    for (int i = 0; i < t.size() -1; i++){
        
        //loop through all the other tiles != i
        for (int j = 1; j <= t.size()-1; j++){
            
            //see if they're equal
            if (t[i].get_color() == t[i+j].get_color() && (i+j) < t.size()){
                
                //we don't have to worry about the joker because we know
                //there is only going to be one joker in the hood
                return false;
            }
            
        }
    }
    
    //if we make it out of this for-loop alive, return true because everything(except the joker) is different
    return true;
}

//returns true if ever tile in myHood has a different number
bool GameManager::hasEveryNumberWithJoker(const Neighborhood & myHood) {
    vector<Tile> t = myHood.get_Neighborhood_Tiles();
    //loop through all the tiles
    for (int i = 0; i < t.size() -1; i++){
        
        //loop through all the other tiles != i
        for (int j = 1; j <= t.size()-1; j++){
            
            //see if they're equal
            if (t[i].get_number() == t[i+j].get_number() && (i+j) < t.size()){
                
                //we don't have to worry about the joker because we know
                //there is only going to be one joker in the hood
                return false;
            }
            
        }
    }
    
    //if we make it out of this for-loop alive, return true because everything(except the joker) is different
    return true;
}

//returns true if their is at least one pair of number and color within the neighborhood
bool GameManager::hasTwoPairWithJoker(const Neighborhood & myHood) {
    vector<Tile> t = myHood.get_Neighborhood_Tiles();
    bool hasTwoPair = false;
    
    //loop through all the tiles
    for (int i = 0; i < t.size() -1; i++){
        
        //loop through all the other tiles != i
        for (int j = 1; j <= t.size()-1; j++){
            
            //see if their colors are equal
            if (t[i].get_color() == t[i+j].get_color() && (i+j) < t.size()){
                
                //now see if their numbers are equal
                if (t[i].get_number() == t[i+j].get_number()) {
                    
                    //if so we found at least one pair of color and number being equal. Set hasTwoPair to true;
                    //**NOTE**, hasTwoPair could be already be set to true, but this function doesn't handle logic
                    //it's not our fault if this is already true. The function says it returns true if their is at
                    //least one pair
                    hasTwoPair = true;
                }
            }
            
        }
    }
    
    //if their was a pair, 'hasTwoPair' will be true, if not it will be false
    //so just return the bool 'hasTwoPair'
    return hasTwoPair;
}

//returns true if there is are at least two tiles in the neighborhood with the same color
bool GameManager::hasPairColorWithJoker(const Neighborhood & myHood) {
    vector<Tile> t = myHood.get_Neighborhood_Tiles();
    bool hasPairColor = false;
    //loop through all the tiles
    for (int i = 0; i < t.size() -1; i++){
        
        //loop through all the other tiles != i
        for (int j = 1; j <= t.size()-1; j++){
            
            //see if they're equal
            if (t[i].get_color() == t[i+j].get_color() && (i+j) < t.size()){
                
                //if so we found at least two tiles equal colors. Set hasPairColor to true;
                //**NOTE**, hasPairColor could be already be set to true, but this function doesn't handle logic
                //it's not our fault if this is already true. The function says it returns true if their is at
                //least one pair
                hasPairColor = true;
            }
            
        }
    }
    
    //if their was a pair, 'hasPairColor' will be true, if not it will be false
    //so just return the bool 'hasPairColor'
    return hasPairColor;
}


//returns true if there is are at least two tiles in the neighborhood with the same number
bool GameManager::hasPairNumberWithJoker(const Neighborhood & myHood) {
    vector<Tile> t = myHood.get_Neighborhood_Tiles();
    bool hasPairNumber = false;
    //loop through all the tiles
    for (int i = 0; i < t.size() -1; i++){
        
        //loop through all the other tiles != i
        for (int j = 1; j <= t.size()-1; j++){
            
            //see if they're equal
            if (t[i].get_color() == t[i+j].get_color() && (i+j) < t.size()){
                
                //if so we found at least two tiles with equal numbers. Set hasPairNumber to true;
                //**NOTE**, hasPairNumber could be already be set to true, but this function doesn't handle logic
                //it's not our fault if this is already true. The function says it returns true if their is at
                //least one pair
                hasPairNumber = true;
            }
            
        }
    }
    
    //if their was a pair, 'hasPairNumber' will be true, if not it will be false
    //so just return the bool 'hasPairNumber'
    return hasPairNumber;
}


vector<Neighborhood> GameManager::get_local_Neighborhoods(const int& location){
    int rowPosition = location / 10;
    int colPosition = location % 10;
    Tile myTile;
    Neighborhood hood;
    vector<Neighborhood> hoods;
    int foo;
    if (location == 14)
        cin >> foo;
    // generate the rows
    for(int i = 0; i < 4; i++) {
        myTile= gameBoard->get_Tile(rowPosition*10+i+1);
        hood.add_Tile(myTile, i);

    }
    hoods.push_back(hood);
    
    //generate the columns
    for(int i = 0; i < 4; i++) {
        myTile= gameBoard->get_Tile((i+1)*10+colPosition);
        hood.add_Tile(myTile, i);
        
    }
    hoods.push_back(hood);
    
    // generate the boxes
//    int boxLimiti = rowPosition ;
//    int boxLimitj = colPosition ;
//    for (int i = rowPosition; i <= boxLimiti;i++){
//        if(i = 1)
//            i++;
//        if(i == 4)
//            boxLimiti--;
//            
//        for(int j = colPosition; j <= boxLimitj; j++){
//            if(j == 0)
//                j++;
//            if(boxLimitj == 3)
//                boxLimitj--;
//            
//            hood.add_Tile(gameBoard->get_Tile((i*10+j)), 1);
//            hood.add_Tile(gameBoard->get_Tile((i*10+(j+1))), 2);
//            hood.add_Tile(gameBoard->get_Tile(((i+1)*10+j)), 3);
//            hood.add_Tile(gameBoard->get_Tile(((i+1)*10+(j+1))), 4);
//        }
//        hoods.push_back(hood);
//        }
    if((rowPosition+1 <= 4) && (colPosition+1 <=4)){
        hood.add_Tile(gameBoard->get_Tile((rowPosition*10+colPosition)), 1);
        hood.add_Tile(gameBoard->get_Tile((rowPosition*10+(colPosition+1))), 2);
        hood.add_Tile(gameBoard->get_Tile(((rowPosition+1)*10+colPosition)), 3);
        hood.add_Tile(gameBoard->get_Tile(((rowPosition+1)*10+(colPosition+1))), 4);
        hoods.push_back(hood);
    }
    
    if((rowPosition-1 >= 1) && (colPosition-1 >=1)){
        hood.add_Tile(gameBoard->get_Tile((rowPosition*10+colPosition)), 1);
        hood.add_Tile(gameBoard->get_Tile((rowPosition*10+(colPosition-1))), 2);
        hood.add_Tile(gameBoard->get_Tile(((rowPosition-1)*10+colPosition)), 3);
        hood.add_Tile(gameBoard->get_Tile(((rowPosition-1)*10+(colPosition-1))), 4);
        hoods.push_back(hood);
    }
    
    if((rowPosition+1 <= 4) && (colPosition-1 >=1)){
        hood.add_Tile(gameBoard->get_Tile((rowPosition*10+colPosition)), 1);
        hood.add_Tile(gameBoard->get_Tile((rowPosition*10+(colPosition-1))), 2);
        hood.add_Tile(gameBoard->get_Tile(((rowPosition+1)*10+colPosition)), 3);
        hood.add_Tile(gameBoard->get_Tile(((rowPosition+1)*10+(colPosition-1))), 4);
        hoods.push_back(hood);
    }
    
    if((rowPosition-1 >= 1) && (colPosition+1 <=4)){
        hood.add_Tile(gameBoard->get_Tile((rowPosition*10+colPosition)), 1);
        hood.add_Tile(gameBoard->get_Tile((rowPosition*10+(colPosition+1))), 2);
        hood.add_Tile(gameBoard->get_Tile(((rowPosition-1)*10+colPosition)), 3);
        hood.add_Tile(gameBoard->get_Tile(((rowPosition-1)*10+(colPosition+1))), 4);
        hoods.push_back(hood);
    }
    
    
    
    // generate diagonals

    if(rowPosition == colPosition){
        hood.add_Tile(gameBoard->get_Tile(11), 1);
        hood.add_Tile(gameBoard->get_Tile(22), 2);
        hood.add_Tile(gameBoard->get_Tile(33), 3);
        hood.add_Tile(gameBoard->get_Tile(44), 4);
        hoods.push_back(hood);
    }
    
    if(rowPosition+colPosition==gameBoard->get_Board().size()+1){
        hood.add_Tile(gameBoard->get_Tile(14), 1);
        hood.add_Tile(gameBoard->get_Tile(23), 2);
        hood.add_Tile(gameBoard->get_Tile(32), 3);
        hood.add_Tile(gameBoard->get_Tile(41), 4);
        hoods.push_back(hood);
    }
    
    // generate corners
    if(location == 11 || location == 14 || location == 41 || location == 44){
        
        hood.add_Tile(gameBoard->get_Tile(11), 1);
        hood.add_Tile(gameBoard->get_Tile(gameBoard->get_Board().size()*10 + 1), 2);
        hood.add_Tile(gameBoard->get_Tile(10 + gameBoard->get_Board().size()), 3);
        hood.add_Tile(gameBoard->get_Tile(gameBoard->get_Board().size()*10 + 4), 4);
        
        hoods.push_back(hood);
    }
    return hoods;
    }

    


vector<WaitTile> GameManager::generate_waitList(Board* boardToBuild){
    Tile currentTile;
    WaitTile currentWaitTile;
    vector<WaitTile> newList;
    int priorityScore = 0;
    for(int i = 0; i < gameBoard->get_Board().size(); i++){
        for (int j = 0; j < gameBoard->get_Board().size(); j++){
            //for every place on the board
            //if the tile space is empty
            if(gameBoard->get_Tile((i+1)*10+j+1).get_color() == 0){
                currentTile.set_location((i+1)*10+j+1);
                // for every tile we could place
                for(int k = 1; k <= 4; k++){
                    for(int l = 1; l <= 4; l++){
                        
                        // create that tile
                        currentTile.set_color(k);
                        currentTile.set_number(l);
                        
                        
                        // add that tile temporarily to the board
                        gameBoard->add_Tile(currentTile, currentTile.get_location());
                        
                        // set a vector equal to the local neighborhoods
                        
                        vector<Neighborhood> locals = get_local_Neighborhoods(currentTile.get_location());
                        
                        priorityScore = getPriorityScore(locals);
                        
                        // if the placement generated a score, create this tile as a wait tile and push it onto the waitlist.
                        if(priorityScore > 0){
                            currentWaitTile.set_location(currentTile.get_location());
                            currentWaitTile.set_color(currentTile.get_color());
                            currentWaitTile.set_number(currentTile.get_number());
                            newList.push_back(currentWaitTile);
                        }
                  
                    }
                } // end of all tiles test
                
                // re empty the location
                Tile emptyTile;
                gameBoard->add_Tile(emptyTile, currentTile.get_location());
            
            
            } // end of the if empty space part
        } // end of for every column
    } // end of for every row.
    return newList;
}




int GameManager::getPriorityScore(const vector <Neighborhood> & town){
    int numOfClears = 0;
    int townTotalScore = 0;
    int totalScore = 0;
    //mulitiplier gives incentive to the computer to score clearing
    //configurations higher than non clearing configurations
    int multiplier = 5;
    
    //score every neighborhood
    int tempScore = 0;
    for (int i = 0; i < town.size(); i++) {
        //score neighborhood i
        tempScore = score_neighborhood(town[i]);
        
        //see if it cleared
        if (tempScore >= 100) {
            //if it does, increment numOfClears
            numOfClears += 1;
            }
        
        //Add on to current townTotalScore
        townTotalScore += tempScore;
        }
    
    //here, we simply set the totalScore = the total Town score
    //no "bonus" or anything for not clearing
    if (numOfClears == 0) {
        totalScore = townTotalScore;
        }
    else{
        //total score has a multiplierso that these scores are desired more
        //**multiplier = 5
        totalScore = townTotalScore * multiplier * numOfClears;
        }
    return 0;
}

vector<Tile> GameManager::getBestMoves(Board* myBoard, vector<WaitTile> WaitList, vector<Tile> TileHand){
    int BestScore = 0;
    vector<Tile> bestSequence;
    for(int first =0; first<TileHand.size(); first++){
        for(int second=0; second<TileHand.size(); second++){
            for(int third=0; third<TileHand.size(); third++){
                for(int fourth=0; fourth<TileHand.size(); fourth++){
                    int currentScore;
                    if(second==first)
                        ++second;
                    if(third==first)
                        ++third;
                    if(third==second)
                        ++third;
                    if(fourth==first)
                        ++fourth;
                    if(fourth==second)
                        ++fourth;
                    if(fourth==third)
                        ++fourth;
                    currentScore =0;
                    vector<Tile> newTileHand;
                    newTileHand.push_back(TileHand[first]);
                    newTileHand.push_back(TileHand[second]);
                    newTileHand.push_back(TileHand[third]);
                    newTileHand.push_back(TileHand[fourth]);
                    vector<WaitTile> newList = WaitList;
                    Board* newBoard = new Board(myBoard);
                    
                    WaitTile firstTile = getBestWaitTileInWaitList(WaitList, TileHand[first]);
                    Tile playTile = getBestTileInWaitList(newList, TileHand[first]);
                    newBoard->add_Tile(playTile, playTile.get_location());
                    currentScore= currentScore + scoreBoard(newBoard);
                    newList = generate_waitList(newBoard);
                    WaitTile secondTile = getBestWaitTileInWaitList(WaitList, TileHand[second]);
                    playTile = getBestTileInWaitList(newList, TileHand[second]);
                    newBoard->add_Tile(playTile, playTile.get_location());
                    currentScore= currentScore +scoreBoard(newBoard);
                    newList = generate_waitList(newBoard);
                    WaitTile thirdTile = getBestWaitTileInWaitList(WaitList, TileHand[third]);
                    playTile = getBestTileInWaitList(newList, TileHand[third]);
                    newBoard->add_Tile(playTile, playTile.get_location());
                    currentScore= currentScore +scoreBoard(newBoard);
                    newList= generate_waitList(newBoard);
                    WaitTile fourthTile = getBestWaitTileInWaitList(WaitList, TileHand[fourth]);
                    playTile = getBestTileInWaitList(newList, TileHand[fourth]);
                    newBoard->add_Tile(playTile, playTile.get_location());
                    currentScore= currentScore +scoreBoard(newBoard);
                    newList= generate_waitList(newBoard);
                    
                    if (currentScore > BestScore){
                        BestScore= currentScore;
                        bestSequence=newTileHand;
                    }   
                    
                }
            }}}
              return bestSequence;
 }

WaitTile GameManager::getBestWaitTileInWaitList(vector<WaitTile> wl, Tile myTile){
    WaitTile newTile;
    int color = myTile.get_color();
    int number = myTile.get_number();
    int highestScore = 0;
    
    int indexOfHighestPriorityTile = -10000;
    
    for (int i = 0; i < wl.size(); i++) {
        int tileColor = wl[i].get_color();
        int tileNumber = wl[i].get_number();
        int tileScore = wl[i].get_priorityScore();
        
        //if tile in waitList == myTile
        if (tileColor == color && tileNumber == number) {
            //see if the priorty score is higher than the current best priority score
            if (tileScore > highestScore) {
                highestScore = tileScore;
                indexOfHighestPriorityTile = i;
            }
        }
    }
    

        if(wl.size() == 0){
            for(int i = 0; i < gameBoard->get_Board().size(); i++){
                for (int j = 0; j < gameBoard->get_Board().size(); j++){
                    //for every place on the board
                    //if the tile space is empty
                    if(gameBoard->get_Tile((i+1)*10+j+1).get_color() == 0){
                        newTile.set_location((i+1)*10+j+1);
                    }
                }
            }
            return newTile;
        }
    else{
    newTile.set_color(wl[indexOfHighestPriorityTile].get_color());
    newTile.set_number(wl[indexOfHighestPriorityTile].get_number());
    newTile.set_location(wl[indexOfHighestPriorityTile].get_location());
    newTile.set_priorityScore(wl[indexOfHighestPriorityTile].get_priorityScore());
    
    
    return newTile;
    }
}

Tile GameManager::getBestTileInWaitList(vector<WaitTile> wl, Tile myTile){
    Tile newTile;
    int color = myTile.get_color();
    int number = myTile.get_number();
    int highestScore = 0;
    
    int indexOfHighestPriorityTile = -10000;
    
    for (int i = 0; i < wl.size(); i++) {
        int tileColor = wl[i].get_color();
        int tileNumber = wl[i].get_number();
        int tileScore = wl[i].get_priorityScore();
        
        //if tile in waitList == myTile
        if (tileColor == color && tileNumber == number) {
            //see if the priorty score is higher than the current best priority score
            if (tileScore > highestScore) {
                highestScore = tileScore;
                indexOfHighestPriorityTile = i;
            }
        }
    }
    
    if(wl.size() == 0){
        for(int i = 0; i < gameBoard->get_Board().size(); i++){
            for (int j = 0; j < gameBoard->get_Board().size(); j++){
                //for every place on the board
                //if the tile space is empty
                if(gameBoard->get_Tile((i+1)*10+j+1).get_color() == 0){
                    newTile.set_location((i+1)*10+j+1);
                }
            }
        }
        return newTile;
    }
        
    else{
        newTile.set_color(wl[indexOfHighestPriorityTile].get_color());
        newTile.set_number(wl[indexOfHighestPriorityTile].get_number());
        newTile.set_location(wl[indexOfHighestPriorityTile].get_location());
        
        
        return newTile;
    }
}

#endif
