#include "King.h"
#include <iostream>

King::King (string name) { this->name = name; }

bool King::move (int rowIndexPlayer, int colIndexPlayer, int rowIndexDestination, int colIndexDestination, bool placeDestinationEmpty, char placeDestinationPlayer, bool pathIsEmpty) {
	bool result = false;
	
    if (placeDestinationEmpty || (!placeDestinationEmpty && this->name.at(1) != placeDestinationPlayer) ) {
        if (rowIndexDestination == rowIndexPlayer) {
            if (colIndexDestination == colIndexPlayer + 1)
                result = true;
            else if (colIndexDestination == colIndexPlayer - 1)
			    result = true;
        }
        
        else if (rowIndexDestination == rowIndexPlayer + 1) {
            if (colIndexDestination == colIndexPlayer)
                result = true;
            else if (colIndexDestination == colIndexPlayer + 1)
                result = true;
            else if (colIndexDestination == colIndexPlayer - 1)
			    result = true; 
        }
            
		else if (rowIndexDestination == rowIndexPlayer - 1) {
            if (colIndexDestination == colIndexPlayer)
                result = true;
            else if (colIndexDestination == colIndexPlayer + 1) 
                result = true;
            else if ( colIndexDestination == colIndexPlayer - 1)
			    result = true;
        }
	    
		return result;
	}
}

