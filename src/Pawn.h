#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"
#include <string>

class Pawn : public Piece {
    public:
    	Pawn (string name);
        bool move (int rowIndexPlayer, int colIndexPlayer, int rowIndexDestination, int colIndexDestination, bool placeDestinatonEmpty, char placeDestinationPlayer, bool pathIsEmpty);
};
#endif


