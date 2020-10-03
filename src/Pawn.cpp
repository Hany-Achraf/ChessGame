#include "Pawn.h"

Pawn::Pawn (string name) { this->name = name; }
bool Pawn::move (int rowIndexPlayer, int colIndexPlayer, int rowIndexDestination, int colIndexDestination, bool placeDestinationEmpty, char placeDestinationPlayer, bool pathIsEmpty) {
	
	if (rowIndexPlayer != 8  && rowIndexPlayer != 1) {
        switch (this->name.at(1)) {
            case 'b':
            {
                if (rowIndexDestination == 8)
                    this->name.replace(2, 3, "Q");
                    
                if (rowIndexDestination == rowIndexPlayer + 1 && placeDestinationEmpty)
                    return colIndexDestination == colIndexPlayer;
                else if (rowIndexDestination == rowIndexPlayer + 1 && (!placeDestinationEmpty && placeDestinationPlayer != 'b') )
                    return (colIndexDestination == colIndexPlayer - 1 || colIndexDestination == colIndexPlayer + 1);
                else
                    return false ;
                break;    
            } 
            case 'w':
            {
                if (rowIndexDestination == 1) 
                    this->name.replace (2, 3, "Q");
                
                if (rowIndexDestination == rowIndexPlayer - 1 && placeDestinationEmpty)
                        return colIndexDestination == colIndexPlayer;
                else if (rowIndexDestination == rowIndexPlayer - 1 && (!placeDestinationEmpty && placeDestinationPlayer != 'w') )
                    return (colIndexDestination == colIndexPlayer - 1 || colIndexDestination == colIndexPlayer + 1);
                else
				    return false;    
                break;
            }
            default:
                return false ;
        }
    } else if ( (rowIndexDestination == rowIndexPlayer) || (colIndexDestination == colIndexPlayer) ) { // Rook Movement
            if (pathIsEmpty && (placeDestinationEmpty || (!placeDestinationEmpty && this->name.at(1) != placeDestinationPlayer)) ) { // ********* pathIsEmpty !!
                if ( (rowIndexDestination - rowIndexPlayer != 0) && (colIndexDestination == colIndexPlayer) )
                   return true;
                else if ( (rowIndexDestination == rowIndexPlayer) && (colIndexDestination - colIndexPlayer != 0) )
                   return true;
                else {
                   return false;
                }
            } else {
                return false;
            }
    } else if ( ( rowIndexDestination - rowIndexPlayer == colIndexDestination - colIndexPlayer ) || ( rowIndexDestination - rowIndexPlayer == colIndexPlayer - colIndexDestination ) ) { // == Bishop Movement !!
        bool result = false;
            
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
    } else // == Failed to Movet !!
            return false;
}

