#include <iostream>
#include "TicTacToe.h"

// This code draws and displays the game board
void TicTacToe::Display() const
{
    std::cout << m_board[0] << "|" << m_board[1] << "|" << m_board[2] << "\n";
    std::cout << "-----\n";
    std::cout << m_board[3] << "|" << m_board[4] << "|" << m_board[5] << "\n";
    std::cout << "-----\n";
    std::cout << m_board[6] << "|" << m_board[7] << "|" << m_board[8] << "\n";
    std::cout << "\n";
}

bool TicTacToe::IsGameOver() const
{
    //Diagonal Wins
    if (m_board[0] == m_board[4] && m_board[4] == m_board[8] && m_board[0] != ' ') {
        std::cout << "Player " << (m_currentPlayer == 1 ? 2 : 1) << " wins\n";
        return true;
    }
    if (m_board[2] == m_board[4] && m_board[4] == m_board[6] && m_board[2] != ' ') {
        std::cout << "Player " << (m_currentPlayer == 1 ? 2 : 1) << " wins\n";
        return true;
    }

    //Vertical Wins
    if (m_board[0] == m_board[3] && m_board[3] == m_board[6] && m_board[0] != ' ') {
        std::cout << "Player " << (m_currentPlayer == 1 ? 2 : 1) << " wins\n";
        return true;
    }
    if (m_board[1] == m_board[4] && m_board[4] == m_board[7] && m_board[1] != ' ') {
        std::cout << "Player " << (m_currentPlayer == 1 ? 2 : 1) << " wins\n";
        return true;
    }
    if (m_board[2] == m_board[5] && m_board[5] == m_board[8] && m_board[2] != ' ') {
        std::cout << "Player " << (m_currentPlayer == 1 ? 2 : 1) << " wins\n";
        return true;
    }

    //Horizontal Wins
    if (m_board[0] == m_board[1] && m_board[1] == m_board[2] && m_board[0] != ' ') {
        std::cout << "Player " << (m_currentPlayer == 1 ? 2 : 1) << " wins\n";
        return true;
    }
    if (m_board[3] == m_board[4] && m_board[4] == m_board[5] && m_board[3] != ' ') {
        std::cout << "Player " << (m_currentPlayer == 1 ? 2 : 1) << " wins\n";
        return true;
    }
    if (m_board[6] == m_board[7] && m_board[7] == m_board[8] && m_board[6] != ' ') {
        std::cout << "Player " << (m_currentPlayer == 1 ? 2 : 1) << " wins\n";
        return true;
    }

    // Check for a tie
    if (m_currentTurn == 9) {
        std::cout << "It's a tie!\n";
        return true;
    }

    return false;
}

void TicTacToe::TakeTurn()
{
    // Set up variables for the player's choice of spot on the board and the game letters
    int playerChoice = 0;
    char playerLetter;

    // Determine and save current player
    int currentPlayer = m_currentPlayer; 
    std::cout << "It's Player " << currentPlayer << "'s turn.\n";
    // Set up X for player 1 and O for player 2
    if (currentPlayer == 1) { playerLetter = 'X'; }
    else { playerLetter = 'O'; }
    // Re-prompt user if they don't pick a spot on the board
    while (playerChoice < 1 || playerChoice > 9)
    {
        std::cout << "Please select a spot on the board(1-9): ";
        std::cin >> playerChoice;

        if (playerChoice < 1 || playerChoice > 9) {
            std::cout << "Please select a valid spot on the board(1-9).\n";
        }
        // Re-prompt user if the spot they choose is already taken
        else if (m_board[playerChoice - 1] == 'X' || m_board[playerChoice - 1] == 'O') {
            std::cout << "Please select an empty spot on the board.\n";
            playerChoice = 0;
        }
        // Otherwise, put mark on the board
        else {
            m_board[playerChoice - 1] = playerLetter;
        }
    }

    // Switch players after the turn
    if (m_currentPlayer == 1) {
        m_currentPlayer = 2;
    }
    else {
        m_currentPlayer = 1;
    }

    // Increment turn counter
    m_currentTurn += 1;
}
