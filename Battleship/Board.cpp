//
//  Board.cpp
//  Battleship
//

#include "Board.h"


Board::Board ( ) {
    
    for (int i = 0; i < 4; i++) {
        
        ships[i] = generateShipWithLength(i + 2);
    }
}


Board::~Board ( ) {
    
    for ( int i = 0; i < 4; i++ ) {
        
        delete ships[i];
    }
}


Ship * Board::generateShipWithLength ( int length ) {
    
    bool collide = false;
    point origin;
    direction orientation;
    int xCor;
    int yCor;
    
    while ( true ) {
        
        collide = false;
        orientation = rand() % 2 ? HORIZONTAL : VERTICAL;
        xCor = rand() % 9 + 1;
        yCor = rand() % 9 + 1;
        
        if(orientation == HORIZONTAL){
            
            if(9 - xCor < length)
                continue;
        }
        else {
            
            if(9 - yCor < length)
                continue;
        }
        
        origin.setX(xCor);
        origin.setY(yCor);
        
        Ship *pShip = new Ship(origin, orientation, length);
        
        for (int i = 2; i < length; i++) {
            
            if (pShip->collidesWith(*ships[i - 2])) {
                
                delete pShip;
                collide = true;
                break;
            }
        }
        
        if(collide)
            continue;
        
//        std::cout << "Ship " << length << std::endl;
//        if(orientation == HORIZONTAL)
//            std::cout << "HORIZONTAL\n";
//        else std::cout <<"VERTICAL\n";
//        std::cout << "X=" << xCor << " Y=" << yCor << std::endl;
        
        return pShip;
    }
}


bool Board::fireShot ( int x, int y ) {
    
    bool hitted = false;
    point p;
    p.setX(x);
    p.setY(y);
    
    for (int i = 0; i < 4; i++) {
        
        ships[i]->shotFiredAtPoint(p);
        
        if(ships[i]->isHitAtPoint(p)) {
            
            hitted = true;
        }
        
        if(ships[i]->isSunk() && !ships[i]->hitted) {
            
            std::cout << "You sank a ship with length " << i + 2 << "!\n";
            ships[i]->hitted = true;
        }
    }
    
    if(!hitted)
        misses.add(p);
    
    return hitted;
}


int Board::unsunkShipCount ( ) {
    
    int unsunkShips = 0;
    
    for (int i = 0; i < 4; i++) {
        
        if(!ships[i]->isSunk()){
            
            unsunkShips++;
        }
    }
    
    return unsunkShips;
}


void Board::display ( ) {
    
    point p;
    bool hitted = false;
    int k;
    
    for (int i = 0; i < 4; i++) {
        
        if(ships[i]->isSunk()) {
            
        }
    }
    for (int i = 9; i >= 0; i--) {
        
        std::cout << i << " ";
        
        for(int j = 0; j < 10; j++){
            
            p.setX(j);
            p.setY(i);
            
            for (k = 0; k < 4; k++) {
                
                if(ships[k]->isHitAtPoint(p)){
                    
                    std::cout << "X ";
                    hitted = true;
                }
            }
            
            if(!hitted) {
                
                if (misses.contains(p)){
                    
                    std::cout << ". ";
                }
                else {
                    
                    std::cout << "~ ";
                }
            }
            
            hitted = false;
        }
        
        std::cout << std::endl;
    }
    
    std::cout << "  ";
    
    for (int i = 0; i < 10; i++) {
        
        std::cout << i << " ";
    }
    
    std::cout << std::endl;
}


