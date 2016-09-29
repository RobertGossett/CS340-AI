//
//  main.cpp
//  Final Project
//
//  Created by Robert Gossett on 9/28/16.
//  Copyright © 2016 Robert Gossett. All rights reserved.
//

#include <iostream>
#include "Board.h"

using namespace std;

int main() {
    Board tileBoard;
    Tile foo(1, 2);
    
    tileBoard.printBoard();
    tileBoard.add_Tile(foo, 11); // foo to spot 11
    tileBoard.add_Tile(foo, 22);
    if(!tileBoard.add_Tile(foo, 32))
        cout << "shit!"<< endl;
    
    tileBoard.printBoard();
    
    tileBoard.move_Tile(11, 23); // spot 11 to 22
    
    tileBoard.printBoard();
    
    cout << tileBoard.isFull();
    
    tileBoard.lock_Tiles();
    
    vector<vector<Tile> > test = tileBoard.get_Board();
    
    
    int color = test[1][1].get_color();
    int number = test[1][1].get_number();
    bool lock = test[1][1].isLocked();
    
    cout << endl <<" color: " << color <<  " number: " << number << "lockStatus: " << lock << endl;
    
    
   
    return 0;
}
