#include "Place.h"

string Place::getName() { return this->name; }
void Place::setName(string name) { this->name = name;  }
Piece* Place::getPiece() { return this->piece; }
void Place::setPiece(Piece *p) { this->piece = p; }
void Place::removePiece () { this->piece = NULL; }
    
bool Place::placeDestinationEmpty () {
    if (piece != NULL)
        return false;
    else 
        return true;
}
