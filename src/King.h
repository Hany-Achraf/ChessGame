#ifndef KING_H
#define KING_H

#include "Piece.h"
#include <string>

using namespace std;

class King : public Piece {
	public:
		King (string name);
		bool move (int rowIndexPlayer, int colIndexPlayer, int rowIndexDestination, int colIndexDestination, bool placeDestinationEmpty, char placeDestinationPlayer, bool pathIsEmpty);
};

#endif
