//
//  Ship.cpp
//  Battleship
//

#include "Ship.h"

//***************************************************************************
// Constructor
//***************************************************************************

Ship::Ship ( point originPoint, direction orientationDirection, int lengthValue ) {
    
    this->origin = originPoint;
    this->orientation = orientationDirection;
    this->length = lengthValue;
    
    for ( int i = 0; i < lengthValue; i++ ) {
        
        point p;
        
        if( orientationDirection == HORIZONTAL ) {
            
            p.setX ( originPoint.getX() + i );
            p.setY ( originPoint.getY ( ) );
        }
        else {
            
            p.setX ( originPoint.getX ( ) );
            p.setY ( originPoint.getY ( ) + i );
        }
        
        points << p;
    }
}

// Copy constructor
Ship::Ship ( const Ship& s )  {
    
    *this = s;
}
// Contains point
bool Ship::containsPoint(const point& p) const {
    
    return points.contains(p);
}


//***************************************************************************
// Collides with
//***************************************************************************

bool Ship::collidesWith(const Ship& s) const {
    
    for (int i = 0; i < s.points.getSize(); i++) {
        
        if(points.contains(s.points[i])) {
         
            return true;
        }
    }
    
	return false;
}


//***************************************************************************
// Shot fired at point
//***************************************************************************

void Ship::shotFiredAtPoint(const point& p) {
    
    if(points.contains(p)) {
        
        hits << p;
    }
}


//***************************************************************************
// Is hit at point
//***************************************************************************

bool Ship::isHitAtPoint(const point& p) {
    
    return hits.contains(p);
}


//***************************************************************************
// Hit count
//***************************************************************************

int Ship::hitCount() const {
    
    return hits.getSize();
}


//***************************************************************************
// Operator =
//***************************************************************************

const Ship& Ship::operator=(const Ship& s) {
    
    this->length = s.length;
    this->orientation = s.orientation;
    this->origin = s.origin;
    this->points = s.points;
    this->hits = s.hits;
    
	return *this;
}


//***************************************************************************
// Is sunk
//***************************************************************************

bool Ship::isSunk() {
    
    return points.getSize() == hits.getSize();
}
