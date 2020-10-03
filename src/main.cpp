#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

#include "Board.h"
#include "Place.h"
#include "Piece.h"
#include "Player.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Pawn.h"
using namespace std;

#define FILENAME "Game_details.txt"

int main () {
	// Program data section 
    Board board;
    Piece* pieceToMove;
    int rowIndexPlayer = 0;
	int colIndexPlayer = 0;
	int rowIndexDestinaion = 0;
	int colIndexDestinaion = 0;
	Place* pickPlace;
	Place* destinationPlace;
	Player* blackPlayer;
	Player* whitePlayer;
	string movement;
	char currentPlayer;
	string errorMessage;
	int movesCounter = 0;
	fstream outFile (FILENAME, ios::out | ios::app);
	// Initial settings
    board.set_players_begin();
    blackPlayer = &board.getPlayer()[0];
	whitePlayer = &board.getPlayer()[1];
	cout << "=======================================================================" << endl
	     << "\tWelcome to chess game!\n" << endl
	     << "i) White player can move pieces starting with 'w' only." << endl
	     << "ii) Black player can move pieces starting with 'b' only." << endl
	     << "iii) You can separat between picking location and destination location" << endl 
		 << "using any character, symbol, or just space." << endl
		 << "iv) The system will accept the legal movements only :)" << endl
		 << "v) Example for accepted movement => 'D2-D3'" << endl
	     << "=======================================================================\n" << endl;
	
	board.show();
     // === === === === >> Move using Characters And Numbers !!
    currentPlayer = 'w';
    while (blackPlayer->getKing() != NULL && whitePlayer->getKing() != NULL) {
        getMoveFromUser:
	    if (currentPlayer == 'b')
            cout << "===================" << "\n" << "Black Player : " << "\n" << "===================" << endl;
        else if (currentPlayer == 'w')
            cout << "===================" << "\n" << "White Player : " << "\n" << "===================" << endl;
			
	    try {
		    getline(cin, movement);
		    int x1, x2, x3, x4;
		    errorMessage = "ERROR: Invalid input!";
		    if (movement.length() >= 5) {
		    	for (x1 = 65; x1 <= 72; x1++)
			            if ((int)movement.at(0) == x1)
					    break;
			    for (x2 = 49; x2 <= 56; x2++)
				    if ((int)movement.at(1) == x2)
				        break;
			    for (x3 = 65; x3 <= 72; x3++)
				    if ((int)movement.at(3) == x3)
		     	        break;
			    for (x4 = 49; x4 <= 56; x4++)
				    if ((int)movement.at(4) == x4)
					    break;
			}
				
			if (x1 > 72 || x2 > 56 || x3 > 72 || x4 > 56 || movement.length() < 5)
				throw errorMessage;
		} catch (string msg) {
			system("CLS");
			cerr << "==========================\n" << movement << endl
			     << "=====================" << "\n" << msg << endl
			     << "=====================" << endl;
			board.show();
			goto getMoveFromUser;
		}		
        cout << "===================" << endl;
        
		for (int i = 0; i < 9; i++)
            if (movement.at(0) == board.getPlace()[0][i].getName().at(2)) {
				colIndexPlayer = i;
                break;
			}			
        for (int i = 1; i < 9; i++)
            if (movement.at(1) == board.getPlace()[i][0].getName().at(1)) {
                rowIndexPlayer = i;
                break;
            }
		    
		try {
		    pickPlace = &board.getPlace()[rowIndexPlayer][colIndexPlayer];
			if (!(currentPlayer == pickPlace->getName().at(1))) {
				if (pickPlace->getName().at(1) == '.' || pickPlace->getName().at(1) == '*')
				    errorMessage = "ERROR: No piece to move!";
				else
				    errorMessage = "ERROR: Piece is not yours!";    
				throw errorMessage;
			}
		} catch (string msg) {
			system("CLS");
			cerr << "==========================\n" << movement << endl
			     << "==========================" << "\n" << msg << endl
			     << "==========================" << endl;
			board.show();
			goto getMoveFromUser;
		}
				
        for (int i = 1; i < 9; i++)
            if (movement.at(3) == board.getPlace()[0][i].getName().at(2)) { 
                colIndexDestinaion = i;
                break;
            }
        for (int i = 1; i < 9; i++)
            if (movement.at(4) == board.getPlace()[i][0].getName().at(1)) { 
                rowIndexDestinaion = i;
                break;
            }
			
        try {
        	pieceToMove = board.getPlace()[rowIndexPlayer][colIndexPlayer].getPiece();
			destinationPlace = &board.getPlace()[rowIndexDestinaion][colIndexDestinaion];
		    errorMessage = "Invalid Movement .. Cannot move to this destination!";
			bool pieceAbleToMove = false;
			
			switch (pieceToMove->getName().at(2)) {
                case 'R':
                    if (pieceToMove->move(rowIndexPlayer, colIndexPlayer, rowIndexDestinaion, colIndexDestinaion, destinationPlace->placeDestinationEmpty(), destinationPlace->getName().at(1), board.rookPathIsEmpty(rowIndexPlayer, colIndexPlayer, rowIndexDestinaion, colIndexDestinaion)) )
						pieceAbleToMove = true;
                    break;
                case 'B':
                    if (pieceToMove->move(rowIndexPlayer, colIndexPlayer, rowIndexDestinaion, colIndexDestinaion, destinationPlace->placeDestinationEmpty(), destinationPlace->getName().at(1), board.bishopPathIsEmpty(rowIndexPlayer, colIndexPlayer, rowIndexDestinaion, colIndexDestinaion)) )
					    pieceAbleToMove = true;
                    break;
                case 'Q':
                    if (pieceToMove->move(rowIndexPlayer, colIndexPlayer, rowIndexDestinaion, colIndexDestinaion, destinationPlace->placeDestinationEmpty(), destinationPlace->getName().at(1), board.queenPathIsEmpty(rowIndexPlayer, colIndexPlayer, rowIndexDestinaion, colIndexDestinaion)) )
						pieceAbleToMove = true;
                    break;
                default:
                    if (pieceToMove->move(rowIndexPlayer, colIndexPlayer, rowIndexDestinaion, colIndexDestinaion, destinationPlace->placeDestinationEmpty(), destinationPlace->getName().at(1), true) )
						pieceAbleToMove = true;
                    break;	
		    }			
			if (!pieceAbleToMove)
					throw errorMessage;
        } catch (string msg) {
			system("CLS");
			cerr << "==========================\n" << movement << endl
			     << "====================================================" << "\n" << msg << endl
			     << "====================================================" << endl;
			board.show();
			goto getMoveFromUser;
		}			
			
        if (destinationPlace->getPiece() != NULL)
            if (destinationPlace->getName().at(2) == 'K')
                if (currentPlayer == 'b')
                    blackPlayer->removeKing();    
                else if (currentPlayer == 'w')
                    whitePlayer->removeKing();

        destinationPlace->setPiece(pieceToMove);
        pickPlace->removePiece();
        board.insertInFile();
        movesCounter++;
        system("CLS");
        cout << "==========================\n" << movement << endl
             << "==========================\n";
        board.show();
               
        if (currentPlayer == 'b') // swaping turns between the players
            currentPlayer = 'w';
        else if (currentPlayer == 'w')
            currentPlayer = 'b';
    } // End of The Loop
    // Printing The Winner !!
    cout << "=============================================" << endl;
    if (currentPlayer == 'b') { // *** Warning--because "SWAPING" inside the loop !! ***
        cout << "White Player is the winner !!" << endl
		     << "=============================================\n";
        outFile << "White Player is the winner !!" << endl
		        << "=============================================\n";
	} else if (currentPlayer == 'w') {
        cout << "Black Player is the Winner !!" << endl
		     << "=============================================\n";
        outFile << "Black Player is the winner !!" << endl
		        << "=============================================\n";
    }
    outFile << "Both players made " << movesCounter << " movements." << endl
	        << "=============================================\n\n";
	outFile.close();        
    cout << "Check game details file generated!" << endl;
     // == End of The Program
	return 0;
}
