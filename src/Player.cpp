#include "Player.h"
#include <iostream>
King* Player::getKing() { return this->king; }

Queen* Player::getQueen() { return this->queen; }

Rook** Player::getRook() { return this->rook; }   
Knight** Player::getKnight() { return this->knight; }   
Bishop** Player::getBishop() { return this->bishop; }
Pawn** Player::getPawn() { return this->pawn; }
     
void Player::removeKing()  { this->king = NULL; }   
void Player::setPlayer (string kingName, string queenName, string rookName, string knightName, string bishopName, string pawnName)  {
    this->king = new King(kingName);
    this->queen = new Queen(queenName);
    
	for (int i = 0 ; i < 2 ; i++)
        this->rook[i] = new Rook(rookName);
        
    for (int i = 0 ; i < 2 ; i++)
        this->knight[i] = new Knight(knightName);

    for (int i = 0 ; i < 2 ; i++)
        this->bishop[i] = new Bishop(bishopName);
        
    for (int i = 0 ; i < 8 ; i++)
        this->pawn[i] = new Pawn(pawnName);
}


