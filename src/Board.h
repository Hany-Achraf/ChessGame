#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <string>
#include <fstream>
#include "Place.h"
#include "Player.h"
using namespace std;

class Board {
	private:
	    Place **place = new Place*[9]; // 2D dynamic array => it is COMPOSITION
		Player *player = new Player [2]; // 1D dynamic array => it is COMPOSITION   
	public:
	    Board ();
	    ~Board ();
	    
	    Place** getPlace();
	    Player* getPlayer();
	    
		void show ();
	    void insertInFile (); // still need to modify
	    void set_players_begin ();
	    bool rookPathIsEmpty (int rowIndexPlayer, int colIndexPlayer, int rowIndexDestination, int colIndexDestination);
	    bool bishopPathIsEmpty (int rowIndexPlayer, int colIndexPlayer, int rowIndexDestination, int colIndexDestination);
	    bool queenPathIsEmpty (int rowIndexPlayer, int colIndexPlayer, int rowIndexDestination, int colIndexDestination);
};

#endif
