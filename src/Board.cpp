#include "Board.h"
#include <iostream>
#include <fstream>


Place** Board::getPlace() { return this->place; }
Player* Board::getPlayer() { return this->player; }
	    
Board::Board () {
	for (int i = 0 ; i < 9; i++)
        this->place[i] = new Place [9];
	    
    this->player [0].setPlayer(" bK " , " bQ " , " bR "  , " bN " , " bB " , " bP ");
    this->player [1].setPlayer(" wK " , " wQ " , " wR "  , " wN " , " wB " , " wP ");
    
    this->place [0] [0].setName("   ");
    
    this->place [0] [1].setName("  A ");
    this->place [0] [2].setName("  B ");
    this->place [0] [3].setName("  C ");
    this->place [0] [4].setName("  D ");
    this->place [0] [5].setName("  E ");
    this->place [0] [6].setName("  F ");
    this->place [0] [7].setName("  G ");
    this->place [0] [8].setName("  H ");
    
    this->place [1] [0].setName(" 8 ");
    this->place [2] [0].setName(" 7 ");
    this->place [3] [0].setName(" 6 ");
    this->place [4] [0].setName(" 5 ");
    this->place [5] [0].setName(" 4 ");
    this->place [6] [0].setName(" 3 ");
    this->place [7] [0].setName(" 2 ");
    this->place [8] [0].setName(" 1 ");
}

Board::~Board () {
    for (int count = 0; count < 9; ++count)
        delete[] place[count];
    delete[] place;
}

void Board::show () {
	int x = 1 ;
    int y = 2 ;
    for (int i = 1; i < 9; i++) {
        for (; x < 9; x += 2) {
            if (this->place[i][x].getPiece() == NULL) 
                this->place[i][x].setName(" . .");
            else if (this->place[i][x].getPiece() != NULL)
                this->place[i][x].setName(this->place[i][x].getPiece()->getName());
        }
    
        for (; y < 9; y += 2) {
            if (this->place[i][y].getPiece() == NULL)
                this->place[i][y].setName(" * *");
            else if (this->place[i][y].getPiece() != NULL)
                this->place[i][y].setName(this->place[i][y].getPiece()->getName());
        }
            
		// Swaping formats of rows in the board	
        if ( x == 9 ) {
            x = 2 ;
            y = 1 ;
        } else if ( x == (9 + 1) ) {
            x = 1 ;
            y = 2 ;
        }
    }
        
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++)
            cout << this->place[i][j].getName() << " ";
        cout << "\n\n";
    }
}

void Board::insertInFile () {
	int x = 1 ;
    int y = 2 ;
    for (int i = 1; i < 9; i++) {
        for (; x < 9; x += 2) {
            if (this->place[i][x].getPiece() == NULL) 
                this->place[i][x].setName(" . .");
            else if (this->place[i][x].getPiece() != NULL)
                this->place[i][x].setName(this->place[i][x].getPiece()->getName());
        }
    
        for (; y < 9; y += 2) {
            if (this->place[i][y].getPiece() == NULL)
                this->place[i][y].setName(" * *");
            else if (this->place[i][y].getPiece() != NULL)
                this->place[i][y].setName(this->place[i][y].getPiece()->getName());
        }
        
        // Swaping formats of rows in the board			
        if ( x == 9 ) {
            x = 2 ;
            y = 1 ;
        } else if ( x == (9 + 1) ) {
            x = 1 ;
            y = 2 ;
        }
    }  
    
    fstream outFile("Game_details.txt", ios::out | ios::app);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++)
            outFile << this->place[i][j].getName() << " ";
        outFile << "\n\n";
    }
    outFile << "=============================================\n\n";
    outFile.close();
}

void Board::set_players_begin () {
	// === === === >> (The Black Player)!
    this->place [1] [1].setPiece(this->player[0].getRook()[0]);
    this->place [1] [8].setPiece(this->player[0].getRook()[1]);
    
    this->place [1] [2].setPiece(this->player[0].getKnight()[0]);
    this->place [1] [7].setPiece(this->player[0].getKnight()[1]);
    
    this->place [1] [3].setPiece(this->player[0].getBishop()[0]);
    this->place [1] [6].setPiece(this->player[0].getBishop()[1]);
     
    this->place [1] [4].setPiece(this->player[0].getQueen());
    this->place [1] [5].setPiece(this->player[0].getKing());
    
    for (int i = 0; i < 8 ; i++)
        this->place [2] [i + 1].setPiece(this->player[0].getPawn()[i]) ;
        
    // === === === >> (The White Player)!
    this->place [8] [1].setPiece(this->player[1].getRook()[0]);
    this->place [8] [8].setPiece(this->player[1].getRook()[1]);
    
    this->place [8] [2].setPiece(this->player[1].getKnight()[0]);
    this->place [8] [7].setPiece(this->player[1].getKnight()[1]);
    
    this->place [8] [3].setPiece(this->player[1].getBishop()[0]);
    this->place [8] [6].setPiece(this->player[1].getBishop()[1]);
    
    this->place [8] [4].setPiece(this->player[1].getQueen());
    this->place [8] [5].setPiece(this->player[1].getKing());
    
    for (int i = 0 ; i < 8 ; i++)
            this->place [7] [i + 1].setPiece(this->player [1].getPawn()[i]);
}

bool Board::rookPathIsEmpty (int rowIndexPlayer, int colIndexPlayer, int rowIndexDestination, int colIndexDestination) {
	bool result = true;
	
    if ( (rowIndexDestination == rowIndexPlayer) && (colIndexDestination != colIndexPlayer) ) {
        if (colIndexDestination - colIndexPlayer > 0)
            for (int i = colIndexPlayer + 1 ; i < colIndexDestination ; i++)
                if (this->place [rowIndexDestination] [i].getPiece() != NULL) {
                    result = false;
                    break;
                }
        else if (colIndexDestination - colIndexPlayer < 0)
            for (int i = colIndexDestination + 1 ; i < colIndexPlayer ; i++)
                if (this->place [rowIndexDestination] [i].getPiece() != NULL) {
                    result = false;
                    break;
                }
    } else if ( (colIndexDestination == colIndexPlayer) && (rowIndexDestination != rowIndexPlayer) ) {
		if (rowIndexDestination - rowIndexPlayer > 0) {
			for (int i = rowIndexPlayer + 1; i < rowIndexDestination; i++)
				if (this->place[i][colIndexDestination].getPiece() != NULL) {
                    result = false;
                    break;
                }
        } else if (rowIndexDestination - rowIndexPlayer < 0) {
			for (int i = rowIndexDestination + 1; i < rowIndexPlayer; i++)
				if (this->place[i][colIndexDestination].getPiece() != NULL) {
                    result = false;
                    break;
                }
        }
	}
        
    return result;
}

bool Board::bishopPathIsEmpty (int rowIndexPlayer, int colIndexPlayer, int rowIndexDestination, int colIndexDestination) {
	bool result = true;
	
    if ( (rowIndexDestination - rowIndexPlayer) == (colIndexPlayer - colIndexDestination) && (rowIndexDestination - rowIndexPlayer) > 0 ) {
        int j = colIndexPlayer - 1; 
        for (int i = rowIndexPlayer + 1 ; i < rowIndexDestination ; i++) {
            if (this->place [i] [j].getPiece() != NULL) {
                result = false;
                break;
            }
            j--;
        }
    } else if ( (rowIndexDestination - rowIndexPlayer) == (colIndexDestination - colIndexPlayer) && (rowIndexDestination - rowIndexPlayer) > 0 ) {
        int j = colIndexPlayer + 1;
        for (int i = rowIndexPlayer + 1 ; i < rowIndexDestination ; i++) {
            if (this->place [i] [j].getPiece() != NULL) {
                result = false;
                break;
            }
            j++;
        }
    } else if ( (rowIndexPlayer - rowIndexDestination) == (colIndexPlayer - colIndexDestination) && (rowIndexPlayer - rowIndexDestination) > 0 ) {
        int j = colIndexPlayer - 1 ;
        for (int i = rowIndexPlayer - 1 ; i > rowIndexDestination && j > colIndexDestination ; i--) {
            if (this->place [i] [j].getPiece() != NULL) {
                result = false;
                break;
            }
            j--;
        }
    } else if ( (rowIndexPlayer - rowIndexDestination) == (colIndexDestination - colIndexPlayer) && (rowIndexPlayer - rowIndexDestination) > 0 ) {
        int j = colIndexPlayer + 1 ;
        for (int i = rowIndexPlayer - 1 ; i > rowIndexDestination && j < colIndexDestination ; i--) {
            if (this->place [i] [j].getPiece() != NULL) {
                result = false;
                break;
            }
            j++;
        }
    }
    
	return result;
}

bool Board::queenPathIsEmpty (int rowIndexPlayer, int colIndexPlayer, int rowIndexDestination, int colIndexDestination) {
	bool choose = true;
	if ( (rowIndexDestination == rowIndexPlayer) || (colIndexDestination == colIndexPlayer) )
        choose = rookPathIsEmpty (rowIndexPlayer , colIndexPlayer , rowIndexDestination , colIndexDestination);
    else if ( ( rowIndexDestination - rowIndexPlayer == colIndexDestination - colIndexPlayer ) || ( rowIndexDestination - rowIndexPlayer == colIndexPlayer - colIndexDestination ) )
        choose = bishopPathIsEmpty (rowIndexPlayer, colIndexPlayer, rowIndexDestination, colIndexDestination);
    
    return choose;
}
