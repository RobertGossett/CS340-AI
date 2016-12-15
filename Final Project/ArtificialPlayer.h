//
//  ArtificialPlayer.h
//  Final Project
//
//  Created by Robert Gossett on 12/10/16.
//  Copyright © 2016 Robert Gossett. All rights reserved.
//

#ifndef ArtificialPlayer_h
#define ArtificialPlayer_h

#include "Player.h"

using namespace std;

class ArtificialPlayer : public Player {

public:
    // constructor we still need to fill out. going to require sets and gets
    ArtificialPlayer();
    
    // parameterized constructor
    ArtificialPlayer(Graphics* myDisplay, Board* myBoard,  GameManager* gameM ); // complete
    
    //different than the Human players make move function. This will find the best move based off of our algorithm and execute that
    void makeMove(Board* gameBoard); // complete
    
    // deals the tile hand for the ArtificialPlayer
    void dealTileHand(vector<Tile> myHand);
    
    // roll will be used to end the ArtificialPlayers turn once we build out the scoring and play options
    void roll();
    
    // checks if the ArtificialPlayer is active
    void checkActive();
    
    // returns true if the ArtificialPlayer is active
    bool is_Active() const;
    
    // gets and sets for the board
    // set board
    void set_board(Board* newBoard);
    
    //gets and sets for display
    // set display
    void set_display(Graphics* newDisplay);
    
    // gets and sets for score
    // sets the score to a new value
    void set_score(int const& newScore);
    
    // gets the value of the ArtificialPlayers score
    int get_score() const;
    
    // increments the score by a certain number
    void increment_score(int const& addend);


    bool has_joker();

    void set_joker();

    bool level_Up();
private:
    
    Board* gameBoard;
    vector<Tile> tileHand;
    int score;
    Graphics* display;
    bool isActive;
    bool hasJoker;
    int jokerBar;
    GameManager* game;

    
};

ArtificialPlayer::ArtificialPlayer(){
    gameBoard = NULL;
    display = NULL;
    score = 0;
    isActive = false;
    jokerBar = 1;
    hasJoker=false;
    
}

ArtificialPlayer::ArtificialPlayer(Graphics* myDisplay, Board* myBoard, GameManager* myGame){
    gameBoard = myBoard;
    display = myDisplay;
    score = 0;
    isActive = false;
    jokerBar = 1;
    hasJoker=false;
    game= myGame;
}

bool ArtificialPlayer::level_Up(){
    if(jokerBar<=6){
        if(score >= (250*jokerBar)){
            ++jokerBar;     
            return true;    
        }
        else
            return false;
      }
      else{
        if(score>=1500*(jokerBar-5)){
            ++jokerBar;
            return true;
        }
        else
            return false;

      }
}      
   
void ArtificialPlayer::dealTileHand(vector<Tile> myHand){
    
    for(int i = 0; i < 4; i++){ // check because internally, first element kept getting set to zero. idk why
        while(myHand[i].get_number() == 0)
            myHand[i].randomize();
        
    }
    
    tileHand = myHand;
    isActive = true;
    
}


// make this function follow our alg
void ArtificialPlayer::makeMove(Board* gameBoard){
    isActive = true;
  
        Tile choice;
        display->print_Board(gameBoard->get_Board());
        display->print_score(score);
        display->print_Hand(tileHand);
        display->print_joker(hasJoker);
        vector<Tile> moveSequence = tileHand;
        getBestMoves(gameBoard,waitList, tileHand,moveSequence);
        for(int i=0; i<moveSequence.size()i++){
        choice = moveSequence[0];
        location = moveSequence[0].get_location();
        gameBoard->add_Tile(choice, location);
        }
        
        
}

void getBestMoves(Board* myBoard, vector<waitTile> WaitList, vector<tile> TileHand,vector<tile>& bestSequence){
    int BestScore = 0;
    for(int (first =0; first<TileHand.size(); first++){
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
                  int currentScore =0;
                  vector<tile> newTileHand;
                  newTileHand.push_back(TileHand[first]);
                  newTileHand.push_back(TileHand[second]);
                  newTileHand.push_back(TileHand[third]);
                  newTileHand.push_back(TileHand[fourth]);
                  vector<waitTile> newList = waitList;
                  Board* newBoard = new Board(myBoard);

                  waitTile firstTile = getBestWaitTileInWaitList(waitList, TileHand[first]);
                  Tile playTile = getBestTileInWaitList(newList, TileHand[first]);
                  newBoard.add_Tile(playTile, playTile.get_location());
                  currentScore= currentScore +game->scoreBoard(newBoard);
                  newList=generateWaitList(newBoard);
                  waitTile secondTile = getBestWaitTileInWaitList(waitList, TileHand[second]);
                  playTile = getBestTileInWaitList(newList, TileHand[second]);
                  newBoard.add_Tile(playTile, playTile.get_location());
                  currentScore= currentScore +game->scoreBoard(newBoard);
                  newList=generateWaitList(newBoard);
                  waitTile thirdTile = getBestWaitTileInWaitList(waitList, TileHand[third]);
                  playTile = getBestTileInWaitList(newList, TileHand[third]);
                  newBoard.add_Tile(playTile, playTile.get_location());
                  currentScore= currentScore +game->scoreBoard(newBoard);
                  newList=generateWaitList(newBoard);
                  waitTile fourthTile = getBestWaitTileInWaitList(waitList, TileHand[fourth]);
                  playTile = getBestTileInWaitList(newList, TileHand[fourth]);
                  newBoard.add_Tile(playTile, playTile.get_location());
                  currentScore= currentScore +game->scoreBoard(newBoard);
                  newList=generateWaitList(newBoard);

                  if (currentScore > highestScore){
                     highestScore= currentScore;
                     bestSequence=newTileHand;
                  }   
                                    
 }
 }}}}
void ArtificialPlayer::roll(){
    isActive = false;
}

void ArtificialPlayer::checkActive(){
    bool continueGame = false;
    for(int i = 0; i<tileHand.size(); i++){
        if(tileHand[i].get_number() != 0 || tileHand[i].get_color() != 0 )
            continueGame = true;
    }
    
    if(!continueGame)
        roll();
    
}
bool ArtificialPlayer::is_Active() const{
    return isActive;
}


void ArtificialPlayer::set_board(Board* newBoard){
    gameBoard = newBoard;
}

void ArtificialPlayer::set_display(Graphics* newDisplay){
    display = newDisplay;
}

void ArtificialPlayer::set_score(const int& newScore){
    score = newScore;
}

int ArtificialPlayer::get_score() const{
    return score;
}

void ArtificialPlayer::increment_score(const int& addend){
    score += addend;
}
bool ArtificialPlayer::has_joker(){
    return hasJoker;
}
void ArtificialPlayer::set_joker(){
     hasJoker= true;
}    
#endif 
