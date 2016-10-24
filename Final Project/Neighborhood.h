//
//  Neighborhood.h
//  Final Project
//
//  Created by Robert Gossett on 10/23/16.
//  Copyright © 2016 Robert Gossett. All rights reserved.
//

#ifndef NEIGHBORHOOD_h
#define NEIGHBORHOOD_h


using namespace std;

#include <vector>
#include <string>
#include "Tile.h"
#include <iostream>
#include "Game.h"

class Neighborhood{
public:
    
    // constructor for the board
    Neighborhood(); // complete
    
    // get and set for the neighborhood vector of tiles
    vector<Tile> get_Neighborhood_Tiles() const; // complete
    void set_Neighborhood_Tiles(const vector<Tile>& newNeighborhood); // complete
    
    // is locked returns a bool with the neighborhoods lock status
    bool isLocked() const; // complete
    
    // locks and unlucks the neighborhood. full neighborhoods become locked to deal with double counting.
    void lock(); // complete
    void unlock(); // complete
    
    // get and set for the type of the neighborhood
    string get_type() const; // complete
    void set_type(const string& newType); // complete
    
    // add, push, and remove tiles from the neighborhood.
    bool add_Tile(const Tile& tile, const int& tileLocation); // complete
    bool remove_Tile(const int& tileLocation); // complete
    
    
private:
    
    vector<Tile> neighborhood; // the gameBoard
    Tile baseTile; // the tile used for tile work within the board class
    string type;
    bool locked;
    
    
};

Neighborhood::Neighborhood() {
    neighborhood.resize(4);
    locked = false;
}

vector<Tile> Neighborhood::get_Neighborhood_Tiles() const {
    return neighborhood;
}

void Neighborhood::set_Neighborhood_Tiles(const vector<Tile>& newNeighborhood) {
    neighborhood = newNeighborhood;
}

bool Neighborhood::isLocked() const {
    return locked;
}

void Neighborhood::lock() {
    locked = true;
}

void Neighborhood::unlock() {
    locked = false;
}

string Neighborhood::get_type() const {
    return type;
}

void  Neighborhood::set_type(const string& newType) {
    type = newType;
}

bool Neighborhood::add_Tile(const Tile& tile, const int& tileLocation){
    if(!neighborhood[tileLocation].isLocked()){
    neighborhood[tileLocation].set_color(tile.get_color());
    neighborhood[tileLocation].set_number(tile.get_number());
        return true;
    }
    else return false;
}

bool Neighborhood::remove_Tile(const int& tileLocation) {
    if(!neighborhood[tileLocation].isLocked()){
        neighborhood[tileLocation].set_color(0);
        neighborhood[tileLocation].set_number(0);
        return true;
    }
    else return false;
}


#endif /* Neighborhood_h */
