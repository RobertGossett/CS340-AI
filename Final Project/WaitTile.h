//
//  WaitTile.h
//  Final Project
//
//  Created by Robert Gossett on 12/10/16.
//  Copyright © 2016 Robert Gossett. All rights reserved.
//

#ifndef WaitTile_h_INCLUDED_
#define WaitTile_h_INCLUDED_

using namespace std;

// tile inheriting from the tile class with the addition of a priority score to use when storing in a wait list

class WaitTile : public Tile {

public:
    WaitTile(); // constructor
    WaitTile(int col, int num); // parameterized constructor
    WaitTile(const WaitTile& tile);

    int get_priorityScore() const;
    void set_priorityScore(const int& priorityValue);

    
private:
    int number; // number on the face of the tile
    int color; // integer representation of the colors of the tile
    bool locked; // bool telling us if the tile is locked on the board
    int priority; // priority score of the tile. Indicating the usefulness of a peace on the board

    int location;

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

    location = 0;
}

WaitTile::WaitTile(const WaitTile& tile){
    priority = tile.get_priorityScore();
    number = tile.get_number();
    color = tile.get_color();
    locked = tile.isLocked();
    
    location = tile.get_location();
}

int WaitTile::get_priorityScore() const{
    return priority;
}

void WaitTile::set_priorityScore(const int& priorityValue){
    priority = priorityValue;
}


#endif /* WaitTile_h */
