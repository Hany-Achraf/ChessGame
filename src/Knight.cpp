#include "Knight.h"

Knight::Knight (string name) { this->name = name; }
bool Knight::move(int rowIndexPlayer, int colIndexPlayer, int rowIndexDestination, int colIndexDestination, bool placeDestinationEmpty, char placeDestinationPlayer, bool pathIsEmpty) {
    bool result = false;
    
	if (placeDestinationEmpty || (!placeDestinationEmpty && this->name.at(1) != placeDestinationPlayer) ) {
        if ( (rowIndexDestination == rowIndexPlayer + 1) && ((colIndexDestination == colIndexPlayer + 2) || (colIndexDestination == colIndexPlayer - 2)) )
			result = true;
        else if ( (rowIndexDestination == rowIndexPlayer - 1) && ((colIndexDestination == colIndexPlayer + 2) || (colIndexDestination == colIndexPlayer - 2)) )
			result = true;
        else if ( (rowIndexDestination == rowIndexPlayer + 2) && ((colIndexDestination == colIndexPlayer + 1) || (colIndexDestination == colIndexPlayer - 1)) )
			result = true;
        else if ( (rowIndexDestination == rowIndexPlayer - 2) && ((colIndexDestination == colIndexPlayer + 1) || (colIndexDestination == colIndexPlayer - 1)) )
			result = true;
    }
    
    return result;
}
