//
//  Graphics.h
//  AI Project - Lock n Roll
//
//  Created by Richard Poutier on 9/28/16.
//  Copyright © 2016 Richard Poutier. All rights reserved.
//

#ifndef Graphics_h
#define Graphics_h

#include <string>
#include "Tile.h"
#include "Board.h"

/*
 ALL CONST INT
 
 red    = 1
 yellow = 2
 green  = 3
 blue   = 4
 */

using namespace std;

class Graphics {
    
public:
    
    virtual void start_Game() = 0;
    
    virtual Tile get_tile(vector <Tile> h) = 0;
    
    virtual string get_location() = 0;
        
};


#endif /* Graphics_h */
