#ifndef HumanPlayer_H_INCLUDED_
#define HumanPlayer_H_INCLUDED_

using namespace std;

#include "Tile.h"
#include "Board.h"
#include "Graphics.h"
//#include "GameManager.h"
#include "Game.h"

class HumanPlayer : public Player{

public:

    // constructor we still need to fill out. going to require sets and gets
    HumanPlayer();

    // parameterized constructor

    HumanPlayer(Graphics* myDisplay, Board* myBoard); // complete


    // prints the prompt, gets the move choice, and makes the move on the board
    // based off of that given input.
    void makeMove(Board* gameBoard, vector<Tile> aISequence); // complete

    // deals the tile hand for the HumanPlayer
    void dealTileHand(vector<Tile> myHand);

    // roll will be used to end the HumanPlayers turn once we build out the scoring and play options
    void roll();

    // checks if the HumanPlayer is active
    void checkActive();
    
    // returns true if the HumanPlayer is active
    bool is_Active() const;

    // gets and sets for the board
    // set board
    void set_board(Board* newBoard);

    void set_GM(GameManager* game);
    //gets and sets for display
    // set display
    void set_display(Graphics* newDisplay);

    // gets and sets for score
    // sets the score to a new value
    void set_score(int const& newScore);

    // gets the value of the HumanPlayers score
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

HumanPlayer::HumanPlayer(){
    gameBoard = NULL;
    display = NULL;
    score = 0;
    isActive = false;

    jokerBar = 1;
    hasJoker=false;

}

void HumanPlayer::set_GM(GameManager* gm){
    game = gm;
}

bool HumanPlayer::level_Up(){
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
   
HumanPlayer::HumanPlayer(Graphics* myDisplay, Board* myBoard){

    gameBoard = myBoard;
    display = myDisplay;
    score = 0;
    isActive = false;

    jokerBar = 1;
    hasJoker=false;
  


}

void HumanPlayer::dealTileHand(vector<Tile> myHand){

    for(int i = 0; i < 4; i++){ // check because internally, first element kept getting set to zero. idk why
        while(myHand[i].get_number() == 0)
            myHand[i].randomize();

    }

    tileHand = myHand;
    isActive = true;

}

//void HumanPlayer::makeMove(Board* gameBoard){
//    isActive = true;
//    while (isActive){
//        Tile choice;
//        display->print_Board(gameBoard->get_Board());
//        display->print_score(score);
//        display->print_Hand(tileHand);
//        choice = display->get_tile(tileHand, true);
//        while(choice.get_color() == 0)
//            choice = display->get_tile(tileHand, false);
//        int location;
//        location = display->get_location(true);
//        while(gameBoard->get_Tile(location).get_color() != 0)
//        location = display->get_location(false);
//        gameBoard->add_Tile(choice, location);
//        bool foundTile = false;
//        for(int i = 0; (i<tileHand.size()) && !foundTile; i++) {
//            if(tileHand[i].get_number() == choice.get_number() && tileHand[i].get_color() == choice.get_color()){
//                tileHand[i].set_number(0);
//                tileHand[i].set_color(0);
//                foundTile= true;
//            }
//        }
//        
//
//        checkActive();
//
//    }
//}

void HumanPlayer::makeMove(Board* gameBoard, vector<Tile> aISequence){
    isActive = true;
    if (isActive){
        Tile choice;
        display->print_Board(gameBoard->get_Board());
        display->print_score(score);
        display->print_Hand(tileHand);

        display->print_joker(hasJoker);
        choice = display->get_tile(tileHand, true);
        while(choice.get_color() == 0)
            choice = display->get_tile(tileHand, false);
        if(choice.get_color()==5)
            hasJoker=false;

        int location;
        location = display->get_location(true);
        while(gameBoard->get_Tile(location).get_color() != 0)
            location = display->get_location(false);

        choice.set_location(location);

        gameBoard->add_Tile(choice, location);
        bool foundTile = false;
        for(int i = 0; (i<tileHand.size()) && !foundTile; i++) {
            if(tileHand[i].get_number() == choice.get_number() && tileHand[i].get_color() == choice.get_color()){
                tileHand[i].set_number(0);
                tileHand[i].set_color(0);
                foundTile= true;
            }
        }
        
        
        checkActive();
        
    }
}


void HumanPlayer::roll(){
    isActive = false;
}

void HumanPlayer::checkActive(){
    bool continueGame = false;
    for(int i = 0; i<tileHand.size(); i++){
        if(tileHand[i].get_number() != 0 || tileHand[i].get_color() != 0 )
            continueGame = true;
    }

    if(!continueGame)
       roll();

}
bool HumanPlayer::is_Active() const{
    return isActive;
}


void HumanPlayer::set_board(Board* newBoard){
    gameBoard = newBoard;
}

void HumanPlayer::set_display(Graphics* newDisplay){
    display = newDisplay;
}

void HumanPlayer::set_score(const int& newScore){
    score = newScore;
}

int HumanPlayer::get_score() const{
    return score;
}

void HumanPlayer::increment_score(const int& addend){
    score += addend;
}

bool HumanPlayer::has_joker(){
    return hasJoker;
}
void HumanPlayer::set_joker(){
     hasJoker= true;
}

#endif
