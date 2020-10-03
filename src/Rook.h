#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"
#include <string>

using namespace std;

class Rook : public Piece {
	public:
		Rook (string name);
		bool move (int rowIndexPlayer, int colIndexPlayer, int rowIndexDestination, int colIndexDestination, bool placeDestinatonEmpty, char placeDestinationPlayer, bool pathIsEmpty);
};
#endif
