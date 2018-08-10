//
//  Board.h
//  Battleship
//

#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include "Ship.h"
#include "Point.h"
#include "PointCollection.h"


class Board
{
private:
    
    Ship *ships[4];
    PointCollection misses;
    
    Ship * generateShipWithLength ( int );
    
public:
    
    Board();
    ~Board();
    bool fireShot( int, int );
    int unsunkShipCount();
    void display();
};

#endif
