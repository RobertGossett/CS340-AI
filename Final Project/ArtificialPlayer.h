//
//  ArtificialPlayer.h
//  Final Project
//
//  Created by Robert Gossett on 12/10/16.
//  Copyright © 2016 Robert Gossett. All rights reserved.
//

#ifndef ArtificialPlayer_h_INCLUDED_
#define ArtificialPlayer_h_INCLUDED_


#include "Player.h"
#include "Game.h"
#include "GameManager.h"
#include "WaitTile.h"




using namespace std;

class GameManager;

class ArtificialPlayer : public Player {

public:
    // constructor we still need to fill out. going to require sets and gets
    ArtificialPlayer();
    
    // parameterized constructor

    ArtificialPlayer(Graphics* myDisplay, Board* myBoard); // complete
    
    void set_GM(GameManager* gm);
    //different than the Human players make move function. This will find the best move based off of our algorithm and execute that
    void makeMove(Board* gameBoard, vector<Tile> aISequence); // complete
    
    
    
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
    
    void getBestMoves(Board* myBoard, vector<WaitTile> WaitList, vector<Tile> TileHand, vector<Tile>& bestSequence);


    bool has_joker();

    void set_joker();

    bool level_Up();
    
    Tile getBestTileInWaitList(vector<WaitTile> wl, Tile myTile);
    
    WaitTile getBestWaitTileInWaitList(vector<WaitTile> wl, Tile myTile);
    
    
    
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

ArtificialPlayer::ArtificialPlayer(Graphics* myDisplay, Board* myBoard){

    gameBoard = myBoard;
    display = myDisplay;
    score = 0;
    isActive = false;

    jokerBar = 1;
    hasJoker=false;
 
  
}

void ArtificialPlayer::set_GM(GameManager* gm){
    game = gm;
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
void ArtificialPlayer::makeMove(Board* gameBoard, vector<Tile> aISequence){
    isActive = true;
// <<<<<<< HEAD
//    if (isActive){
//        Tile choice;
//        display->print_Board(gameBoard->get_Board()); // maybe we don't include this
//        display->print_score(score);
//        display->print_Hand(tileHand);
//        //brain find move
//        choice = display->get_tile(tileHand, true); /// AI will choose the tile to play get_move
//        while(choice.get_color() == 0)
//            choice = display->get_tile(tileHand, false);
//        int location;
//        location = display->get_location(true); // AI will choose the location of the tile
//        while(gameBoard->get_Tile(location).get_color() != 0)
//            location = display->get_location(false);
//        choice.set_location(location);
//        gameBoard->add_Tile(choice, location); // AI will add the tile to the board
//        bool foundTile = false;
//        for(int i = 0; (i<tileHand.size()) && !foundTile; i++) { // clears the tile just used in the tile hand
//            if(tileHand[i].get_number() == choice.get_number() && tileHand[i].get_color() == choice.get_color()){
//                tileHand[i].set_number(0);
//                tileHand[i].set_color(0);
//                foundTile = true;
//            }
//        }
//        
//        
//        checkActive();
//        
//    }
//    
//
//    
//}

//
//=======
   
        Tile choice;
        display->print_Board(gameBoard->get_Board());
        display->print_score(score);
        display->print_Hand(tileHand);
        display->print_joker(hasJoker);
        vector<Tile> moveSequence = aISequence;
        //getBestMoves(gameBoard, waitList, tileHand, aISequence);
    for(int i=0; i<moveSequence.size(); i++){
        choice = moveSequence[0];
        int location = moveSequence[0].get_location();
        gameBoard->add_Tile(choice, location);
        }
        
        
}

//void ArtificialPlayer::getBestMoves(Board* myBoard, vector<WaitTile> WaitList, vector<Tile> TileHand, vector<Tile>& bestSequence){
//    int BestScore = 0;
//    for(int first =0; first<TileHand.size(); first++){
//        for(int second=0; second<TileHand.size(); second++){
//             for(int third=0; third<TileHand.size(); third++){
//                for(int fourth=0; fourth<TileHand.size(); fourth++){
//                   int currentScore;
//                   if(second==first)
//                      ++second;
//                   if(third==first)
//                      ++third;
//                   if(third==second)
//                      ++third;
//                   if(fourth==first)
//                      ++fourth;
//                   if(fourth==second)
//                      ++fourth;
//                   if(fourth==third)
//                      ++fourth;
//                  currentScore =0;
//                  vector<Tile> newTileHand;
//                  newTileHand.push_back(TileHand[first]);
//                  newTileHand.push_back(TileHand[second]);
//                  newTileHand.push_back(TileHand[third]);
//                  newTileHand.push_back(TileHand[fourth]);
//                  vector<WaitTile> newList = WaitList;
//                  Board* newBoard = new Board(myBoard);
//
//                  WaitTile firstTile = getBestWaitTileInWaitList(WaitList, TileHand[first]);
//                  Tile playTile = getBestTileInWaitList(newList, TileHand[first]);
//                  newBoard->add_Tile(playTile, playTile.get_location());
//                  currentScore= currentScore + game->scoreBoard(newBoard);
//                  newList = game->generate_waitList(newBoard);
//                  WaitTile secondTile = getBestWaitTileInWaitList(WaitList, TileHand[second]);
//                  playTile = getBestTileInWaitList(newList, TileHand[second]);
//                  newBoard->add_Tile(playTile, playTile.get_location());
//                  currentScore= currentScore +game->scoreBoard(newBoard);
//                  newList = game->generate_waitList(newBoard);
//                  WaitTile thirdTile = getBestWaitTileInWaitList(WaitList, TileHand[third]);
//                  playTile = getBestTileInWaitList(newList, TileHand[third]);
//                  newBoard->add_Tile(playTile, playTile.get_location());
//                  currentScore= currentScore +game->scoreBoard(newBoard);
//                  newList= game->generate_waitList(newBoard);
//                  WaitTile fourthTile = getBestWaitTileInWaitList(WaitList, TileHand[fourth]);
//                  playTile = getBestTileInWaitList(newList, TileHand[fourth]);
//                  newBoard->add_Tile(playTile, playTile.get_location());
//                  currentScore= currentScore +game->scoreBoard(newBoard);
//                  newList= game->generate_waitList(newBoard);
//
//                  if (currentScore > BestScore){
//                     BestScore= currentScore;
//                     bestSequence=newTileHand;
//                  }   
//                                    
// }
// }}}}

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

//returns the tile in wl that matches myTile and has highest priority
WaitTile ArtificialPlayer::getBestWaitTileInWaitList(vector<WaitTile> wl, Tile myTile){
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
    
    return wl[indexOfHighestPriorityTile];
    }

Tile ArtificialPlayer::getBestTileInWaitList(vector<WaitTile> wl, Tile myTile){
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
    
    newTile.set_color(wl[indexOfHighestPriorityTile].get_color());
    newTile.set_number(wl[indexOfHighestPriorityTile].get_number());
    
    return newTile;
    }

#endif 
