//
//  DieRandomizer.h
//  Final Project
//
//  Created by Robert Gossett on 9/28/16.
//  Copyright © 2016 Robert Gossett. All rights reserved.
//

#ifndef Tile_h
#define Tile_h

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
    
    
private:
    int number;
    int color;
    bool locked;
};

Tile::Tile(){
    number = 0;
    color = 0;
    locked = false;
}

Tile::Tile(int col, int num){
    number = num;
    color = col;
    locked = false;
}

void Tile::randomize(){
    Tile randomTile;
    set_number(rand() % 5); // gives a random number between 1 and 4
    set_color(rand() % 5); // give a random number 1-4 to represent in order, red, yellow, green, blue
    randomTile.set_number(rand() % 5); // gives a random number between 1 and 4
    randomTile.set_color(rand() % 5); // give a random number 1-4 to represent in order, red, yellow,
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

#endif /* DieRandomizer_h */
