#pragma once
#include "Game.h"
#include <iostream>
#include <conio.h>

class TicTacToe : public Game {
private:
	// Set up game board, as well as variables for the player and game turns

	char m_board[9] = { ' ', ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' };
	int m_currentPlayer = 1;
	int m_currentTurn = 0;

public:


	virtual bool IsGameOver() const;

	virtual void TakeTurn();

	virtual void Display() const;


};
