#ifndef PIECE_H
#define PIECE_H

#include <string>
using namespace std;

class Piece {	
	protected:
		string name;
	public:
		string getName ();
		virtual bool move(int rowIndexPlayer, int colIndexPlayer, int rowIndexDestination, int colIndexDestination, bool placeDestinatonEmpty, char placeDestinationPlayer, bool pathIsEmpty);
};

#endif
