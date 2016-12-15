//
//  Brain.h
//  Final Project
//
//  Created by Robert Gossett on 12/14/16.
//  Copyright © 2016 Robert Gossett. All rights reserved.
//

#ifndef Brain_h
#define Brain_h

#include "Tile.h"
#include "WaitTile.h"
#include "Board.h"
#include "Player.h"
#include "ArtificialPlayer.h"
#include "Neighborhood.h"
//#include "GameManager.h"
#include "Game.h"

using namespace std;

class Brain {
    public:
    
    int score_Neighborhood_with_joker(const Neighborhood& myHood) const;
    
    void set_Neighborhoods(const vector<Neighborhood>& hoods);
    
    WaitTile get_WaitTile(const Neighborhood& myHood)
    
    void find_move(); // this will find the
    
    
    
    
    
private:

    Player* AI;
    Board* gameBoard;
    Neighborhood* neighborhood;
    vector<Neighborhoods> neighborhoods;
    vector<WaitTile> waiting_list;
    
    
    
};

#endif /* Brain_h */
