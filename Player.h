#ifndef PLAYER_H
#define PLAYER_H

using namespace std;

#include "Tile.h"
#include "Board.h"
#include "Graphics.h"
#include "GameManager.h"

class Player{

   public:

   	 Player(Graphics* myDisplay, Board* myBoard );
      
     void makeMove(Board* gameBoard);
     void dealTileHand(vector<Tile> myHand);
     void roll(); 
     void checkActive(); 
   private:

   	 Board* gameBoard
   	 vector<Tile> tileHand;
   	 int score;
   	 Graphics* display;

};
Player(Graphics* myDisplay, Board* myBoard){
 gameBoard= myBoard;
 display = myDisplay;
}

void dealTileHand(vector<Tile> myHand){
  
   tileHand = myHand;
 }

void makeMove(Board* gameBoard){
   while (isActive){
   	  Tile choice = new Tile;
      choice = display->get_tile();
      int location;
      location = display->get_location();
      gameBoard->add_tile(choice, location);
      for(int i = 0; i<hand.size(); i++) {
       if(hand[i]->get_number() == choice->get_number() && hand[i]->get_color() == choice->get_color()){
       	 hand[i]->get_number(0);
       	 hand[i]->set_color(0);
         }
       }

    checkActive();

   }
 }

 void roll(){
 	isActive = false;
 }

void checkActive(){
	
	 for(int i = 0; i<hand.size(); i++){
	 	if(hand[i]->get_number() != 0 || hand[i]->get_color() != 0 )
	 	 roll();
	 }

	 }