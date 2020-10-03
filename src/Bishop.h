#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"
#include <string>

using namespace std;

class Bishop : public Piece {
	public:
		Bishop (string name);
		bool move(int rowIndexPlayer, int colIndexPlayer, int rowIndexDestination, int colIndexDestination, bool placeDestinationEmpty, char placeDestinationPlayer, bool pathIsEmpty);
};

#endif

