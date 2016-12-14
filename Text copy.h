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



class Text : public Graphics {
    
public:
    
    Text();
    
    void start_Game();
    
    Tile get_tile(vector <Tile> h);
    
    int get_location();
    
    //displays the hand of available tiles to the screen
    //tiles are passed in through tile vector h
    void print_Hand(vector <Tile> h);
    
    void print_Single_Tile(Tile t);
    
    void print_Board(vector <vector <Tile> > board);
    
private:
    
    //helper functions
    
    //takes a 1 in as an input and returns "R" for red
    //takes a 2 in as an input and returns "Y" for yellow and so on
    string get_String_Value_Of_Color(int val);
    
};


#endif /* Text_h */


Text::Text(){
    
    
}

void Text::start_Game(){
    cout << "Hello welcome to the Tile Game (Name Pending)!" << endl;
    cout << endl;
    cout << "The goal is to score as many points as possible." << endl;
    cout << "To score points, you must place your tiles to form unique combinations that will yield points. " << endl;
    
    
}

    //displays the hand of available tiles to the screen
    //tiles are passed in through tile vector h
void Text::print_Hand(vector <Tile> h){
    for (int i = 0; i < h.size(); i ++){
        //prints ->   '1': R3
        cout << "'" << i+1 << "': " << get_String_Value_Of_Color(h[i].get_color()) << h[i].get_number() << endl;
    }
}

string Text::get_String_Value_Of_Color(int val) {
    switch (val) {
        case RED_COLOR:
            return "R";
            break;
        case YELLOW_COLOR:
            return "Y";
            break;
        case GREEN_COLOR:
            return "G";
            break;
        case BLUE_COLOR:
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
    int input;
    cout << "Please select where to place your tile on the board" << endl;
    cin >> input;
    
    return input;
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
            cout << get_String_Value_Of_Color(board[i][j].get_color()) << board[i][j].get_number() << " | ";
            
        };
        
        cout << endl;
        cout << "---------------------" << endl;
    };
    
}

