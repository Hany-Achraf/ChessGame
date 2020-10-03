#include "Rook.h"

Rook::Rook (string name) { this->name = name; }
bool Rook::move(int rowIndexPlayer, int colIndexPlayer, int rowIndexDestination, int colIndexDestination, bool placeDestinationEmpty, char placeDestinationPlayer, bool pathIsEmpty){
	bool result = false;
	
    if (pathIsEmpty && (placeDestinationEmpty || (!placeDestinationEmpty && this->name.at(1) != placeDestinationPlayer)) ) {
        if ( (rowIndexDestination - rowIndexPlayer != 0) && (colIndexDestination == colIndexPlayer) )
            result = true;
        else if ( (rowIndexDestination == rowIndexPlayer) && (colIndexDestination - colIndexPlayer != 0) )
            result = true;
    }
        
	return result;
}
