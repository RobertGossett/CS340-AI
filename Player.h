#ifndef PLAYER_H
#define PLAYER_H

using namespace std;

#include "Tile.h"
#include "Board.h"
#include "Graphics.h"
#include "GameManager.h"

class Player{

   public:

   	 Player(Graphics* myDisplay, Board* myDisplay );
      
     void makeMove(Board* gameBoard);
     void dealTileHand(vector<Tile> myHand);
     void roll(); 
     void checkActive() 
   private:

   	 Board* gameBoard
   	 vector<Tile> tileHand;
   	 int score;
   	 Graphics* display;

};

void dealTileHand(vector<Tile> myHand){
  
   tileHand = myHand;
 }

void makeMove(Board* gameBoard){
   while (isActive){
   	  Tile choice = new Tile;
      choice = display->GetTile();
      int location;
      location = display->get_location();
      gameBoard->add_Tile(choice, location);
      for(int i = 0; i<hand.size(); i++) {
       if(hand[i]->getNumber() == choice->get_Number() && hand[i]->get_Color() == choice->get_Color()){
       	 hand[i]->setNumber(0);
       	 hand[i]->setColor(0);
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
	 	if(hand[i]->get_Number() != 0 || hand[i]->get_Color() != 0 )
	 	 roll();
	 }

	 }