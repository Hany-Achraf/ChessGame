#ifndef PLACE_H
#define PLACE_H

#include <string>
#include "Piece.h"
using namespace std;

class Place {
	private: 
	    string name;
	    Piece *piece = NULL;
	public:
        string getName();
	    void setName(string name);
        Piece* getPiece();
	    void setPiece(Piece* p);
        void removePiece();
        bool placeDestinationEmpty();
};

#endif
