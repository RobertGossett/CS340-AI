//
//  WaitTile.h
//  Final Project
//
//  Created by Robert Gossett on 12/10/16.
//  Copyright © 2016 Robert Gossett. All rights reserved.
//

#ifndef WaitTile_h
#define WaitTile_h

using namespace std;

// tile inheriting from the tile class with the addition of a priority score to use when storing in a wait list

class WaitTile : public Tile {

public:
    WaitTile(); // constructor
    WaitTile(int col, int num); // parameterized constructor
    
private:
    int number; // number on the face of the tile
    int color; // integer representation of the colors of the tile
    bool locked; // bool telling us if the tile is locked on the board
    int priority; // priority score of the tile. Indicating the usefulness of a peace on the board
    
};

WaitTile::WaitTile(){
    priority = 0;
    number = 0;
    color = 0;
    locked = false;
}

WaitTile::WaitTile(int col, int num){
    priority = 0;
    number = num;
    color = col;
    locked = false;
}
#endif /* WaitTile_h */
