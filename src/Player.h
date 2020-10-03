#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include "Piece.h"

#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Pawn.h"

using namespace std;

class Player {
	private:
	    King* king;
        Queen* queen;
        Rook* rook[2];
        Bishop* bishop[2];
        Knight* knight[2];
        Pawn* pawn[8];
     
    // == == (Getters)
    public:
		King* getKing();
        Queen* getQueen();
        
        Rook** getRook();
        Knight** getKnight();
		Bishop** getBishop();
        Pawn** getPawn(); 
    
        void setPlayer (string king, string queen, string rook, string knight, string bishop, string pawn);
        void removeKing();
};
#endif
