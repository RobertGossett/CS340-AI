//
//  Tile.h
//  Final Project
//
//  Created by Robert Gossett on 9/28/16.
//  Copyright © 2016 Robert Gossett. All rights reserved.
//

#ifndef TILE_H_INCLUDED_
#define TILE_H_INCLUDED_
//#include "Game.h"
#include <cstdlib>
//#include "HumanPlayer.h"
//#include<cmath>

class Tile {
public:

    // Tile constructor
    Tile(); // complete

    // parameterize constructor
    Tile(int col, int num); //complete

    // randomizer for the tile
    void randomize(); // complete

    //get and set the tiles number
    int get_number() const; // complete
    void set_number(const int& newNumber); // complete

    // get and set the tiles color
    int get_color() const; // complete
    void set_color(const int& newColor); // complete

    // returns true if the tile is locked
    bool isLocked() const; // complete

    // lock and unlock for the tile
    void lock(); // complete
    void unlock(); // complete
    
    int get_location() const;
    void set_location(const int& loc);

    // equals operator for tiles
    Tile & operator=(const Tile& other);

private:
    int number; // number on the face of the tile
    int color; // integer representation of the colors of the tile
    bool locked; // bool telling us if the tile is locked on the board
    int location; // holds the tiles location on the board
};

Tile::Tile(){
    number = 0;
    color = 0;
    locked = false;
    location = 0;
}

Tile::Tile(int col, int num){
    number = num;
    color = col;
    locked = false;
}

void Tile::randomize(){
    set_number((rand() % 4) + 1); // gives a random number between 1 and 4
    set_color((rand() % 4) + 1); // give a random number 1-4 to represent in order, red, yellow, green, blue

}

int Tile::get_number() const{
    return number;
}

void Tile::set_number(const int& num){
    number = num;
}

int Tile::get_color() const{
    return color;
}

void Tile::set_color(const int& newColor){
    color = newColor;
}

bool Tile::isLocked() const{
    return locked;
}

void Tile::lock(){
    locked = true;
}

void Tile::unlock(){
    locked = false;
}

int Tile::get_location() const{
    return location;
}

void Tile::set_location(const int& loc){
    location = loc;
}

Tile& Tile::operator=(const Tile& other){
    number = other.get_number();
    color = other.get_color();
    locked = other.isLocked();
    return *this;
}
#endif /* TILE_h */
