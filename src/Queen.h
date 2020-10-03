#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"
#include <string>

using namespace std;

class Queen : public Piece {
	public:
		Queen (string name);
		bool move(int rowIndexPlayer, int colIndexPlayer, int rowIndexDestination, int colIndexDestination, bool placeDestinationEmpty, char placeDestinationPlayer, bool pathIsEmpty);
};

#endif

