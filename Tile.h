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
    Tile();
    
    // randomier for the tile
    void rand_Tile();
    
    //get and set the tiles number
    int get_number() const;
    void set_number(const int& newNumber);
    
    // get and set the tiles color
    int get_color() const;
    void set_color(const int& newColor);
    
    
private:
        int number;
        int color;
};

Tile::Tile(){
    number = NULL;
    color = NULL;
}

void Tile::rand_Tile(){
    set_number(rand() % 5); // gives a random number between 1 and 4
    set_color(rand() % 5); // give a random number 1-4 to represent in order, red, yellow, green, blue
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


#endif /* DieRandomizer_h */
