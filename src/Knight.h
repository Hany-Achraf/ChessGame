#ifndef KNIGHT_H
#define KNIGHT_H

#include <string>
#include "Piece.h"

using namespace std;

class Knight : public Piece {
	public:
		Knight (string name);
        bool move (int rowIndexPlayer, int colIndexPlayer, int rowIndexDestination, int colIndexDestination, bool placeDestinationEmpty, char placeDestinationPlayer, bool pathIsEmpty);
};

#endif
