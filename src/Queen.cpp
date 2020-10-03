#include "Queen.h"

Queen::Queen (string name) { this->name = name; }
bool Queen::move (int rowIndexPlayer, int colIndexPlayer, int rowIndexDestination, int colIndexDestination, bool placeDestinationEmpty, char placeDestinationPlayer, bool pathIsEmpty) {
	bool result = false;
	
	// == Rook Movement##
    if (pathIsEmpty && (placeDestinationEmpty || (!placeDestinationEmpty && this->name.at(1) != placeDestinationPlayer)) ) {
        if ( (rowIndexDestination - rowIndexPlayer != 0) && (colIndexDestination == colIndexPlayer) )
            result = true;
        else if ( (rowIndexDestination == rowIndexPlayer) && (colIndexDestination - colIndexPlayer != 0) )
            result = true;
    }
    // == Bishop Movement##
	if (pathIsEmpty && (placeDestinationEmpty || (!placeDestinationEmpty && this->name.at(1) != placeDestinationPlayer)) ) {
        if ( (rowIndexDestination - rowIndexPlayer) == (colIndexPlayer - colIndexDestination) )
            result = true;
        else if ( (rowIndexPlayer - rowIndexDestination) == (colIndexDestination - colIndexPlayer) )
            result = true;
        else if ( (rowIndexPlayer - rowIndexDestination) == (colIndexPlayer - colIndexDestination) )
            result = true;
        else if ( (rowIndexDestination - rowIndexPlayer) == (colIndexDestination - colIndexPlayer) )
            result = true;
    }
	    
	return result;
}
