//
//  Text.h
//  AI Project - Lock n Roll
//
//  Created by Richard Poutier on 9/28/16.
//  Copyright © 2016 Richard Poutier. All rights reserved.
//

#ifndef Text_h
#define Text_h

#include <iostream>
#include "Graphics.h"
#include "Tile.h"
#include "Board.h"
#include "Game.h"




class Text : public Graphics {
    
public:
    
    Text();
    
    // starts the game
    void start_Game();
    
    // returns a tile created by the user
    Tile get_tile(vector <Tile> h);
    
    // returns an int representing the move location given by the user
    int get_location();
    
    //displays the hand of available tiles to the screen
    //tiles are passed in through tile vector h
    void print_Hand(vector <Tile> h);
    
    // prints the players current score
    void print_score(const int& score);
    
    // prints the board
    void print_Board(vector <vector <Tile> > board);
    
private:
    
    // prints a single tile
    void print_Single_Tile(Tile t);
//    int RED_COLOR;
//    int YELLOW_COLOR;
//    int GREEN_COLOR;
//    int BLUE_COLOR;
    
    //helper functions
    
    //takes a 1 in as an input and returns "R" for red
    //takes a 2 in as an input and returns "Y" for yellow and so on
    string get_String_Value_Of_Color(int val);
    
};


#endif /* Text_h */


Text::Text(){
//    RED_COLOR = 1;
//    YELLOW_COLOR = 2;
//    GREEN_COLOR = 3;
//    BLUE_COLOR = 4;
    
}

void Text::start_Game(){
    cout << "Hello welcome to the Tile Game (Name Pending)!" << endl;
    cout << endl;
    cout << "The goal of this game is to score as many points as possible." << endl;
    cout << "To score points, you must place your tiles on the board to form unique combinations that will yield points. " << endl;
    cout << endl;
    
    cout << "Below is a sample board displaying how the game will recognize locations on the board. Each location on the board has a coordinate value. This value is of the format (row, columnn). So as shown below, a coordinate (1,4) corrisponds to row 1, column 4, or \"the top right position on the board\"." << endl;
    
    cout << endl << "Board:" << endl;
    cout << "  ---------------------" << endl;
    for(int i = 1; i <= 4; i++){
        
        cout << "| ";
        for(int j = 1; j <= 4; j++){
            cout << i << "," <<  j << " | ";
        }
        cout << endl;
    }
    cout << "  ---------------------" << endl;
    cout << endl;
    
    
    //sample hand to send print_Hand for the tutorial
    vector <Tile> sampleHand;
    Board tileBoard;
    Tile foo(1, 2);
    sampleHand.push_back(foo);
    Tile faa(2, 3);
    sampleHand.push_back(faa);
    Tile moo(3, 2);
    sampleHand.push_back(moo);
    Tile daa(4, 1);
    sampleHand.push_back(daa);
    
    print_Hand(sampleHand);
    
    cout << endl << "Above, you will see your 'Hand'. These are your available tiles to place on the board. They are randomly generated after all four tiles have been played. Observe that all Tiles follow the format 'Letter-Number', the letter corrisponds to a color. R = Red, Y = Yellow, G = Green and B = Blue. The number is the value of the tile. " << endl;
    cout << endl;
    cout << "During the game, you will be asked to select a tile from the hand. In order to do this, simply enter the number value adjacent to the Tile. For example, you should see that on the first row of your 'Hand', it says,\" '1': R2 \". Entering a '1' will tell the game that this is the tile you would like to play. After you select your tile, you will be asked to enter in the location to play your tile. This follows the format given above where rows and columns range from 1-4. " << endl;
    
    
    
}

//displays the hand of available tiles to the screen
//tiles are passed in through tile vector h
void Text::print_Hand(vector <Tile> h){
    cout << "Hand:" << endl;
    for (int i = 0; i < h.size(); i ++){
        //prints ->   '1': R3
        cout << "'" << i+1 << "': " << get_String_Value_Of_Color(h[i].get_color()) << h[i].get_number() << endl;
    }
}

string Text::get_String_Value_Of_Color(int val) {
    switch (val) {
        case 0:
            return " ";
            break;
        case 1:
            return "R";
            break;
        case 2:
            return "Y";
            break;
        case 3:
            return "G";
            break;
        case 4:
            return "B";
            break;
        default:
            break;
    }
    return "NA";
}


//tiles in hand are passes in through h
//returns the tile that the user selected to be added to the board
Tile Text::get_tile(vector <Tile> h) {
    Tile temp(5, 5); //used in input error from user
    
    int input;
    cout << "Please select which tile you would like to add to the board: " << endl;
    cin >> input;
    
    //currently is set up so it will accept any int
    //end result will only allow user to select options presented in
    //print_hand(vector <Tile> h)
    switch (input) {
        case 1:
            return h[0];
            break;
        case 2:
            return h[1];
            break;
        case 3:
            return h[2];
            break;
        case 4:
            return h[3];
        default:
            cout << "ERROR AT GETTING TILE IN TEXT.H" << endl;
            return temp;
            break;
    }
}

int Text::get_location() {
    int row, column, input;
    cout << "Please enter the row you wish the place your tile:" << endl;
    cin >> row;
    cout << "Please enter the column on row " << row << " you want to place your tile: " << endl;
    cin >> column;
    
    input = (row * 10) + column;
    
    return input;
}

void Text::print_score(const int& score){
    cout << "Score: " << score << endl;
}


void Text::print_Single_Tile(Tile t){
    
    cout << "Tile: " << get_String_Value_Of_Color(t.get_color()) << t.get_number() << endl;
}



// prints the current board
void Text::print_Board(vector <vector <Tile> > board){
    cout << "---------------------" << endl;
    for(int i = 0; i < 4; i++){
        cout << "| ";
        for(int j = 0; j < 4; j++){
            if(board[i][j].get_number() !=0)
            cout << get_String_Value_Of_Color(board[i][j].get_color()) << board[i][j].get_number() << " | ";
            else
                cout << get_String_Value_Of_Color(board[i][j].get_color()) << " " << " | ";
            
        };
        
        cout << endl;
        cout << "---------------------" << endl;
    };
    
}
