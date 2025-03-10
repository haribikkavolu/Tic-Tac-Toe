#include <iostream>
using namespace std;

// Function to display the Tic-Tac-Toe board
void displayBoard(char board[3][3]) 
{
    cout << "-------------\n";
    for (int i = 0; i < 3; ++i) 
    {
        cout << "| ";
        for (int j = 0; j < 3; ++j) 
        {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}

// Function to verify a winning condition
bool isWinner(char board[3][3], char currentPlayer) 
{
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; ++i) 
    {
        if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) || 
            (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) 
        {
            return true;
        }
    }
    if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) || 
        (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) 
    {
        return true;
    }
    return false;
}

int main() 
{
    // Initialize the board and players
    char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    char currentPlayer = 'X';
    int row, col;
    int moves = 0;

    cout << "Welcome to Tic-Tac-Toe Game!\n";

    // Game loop
    while (moves < 9) 
    {
        displayBoard(board);

        // Prompt the user for input until a valid move is made
        bool validMove = false;
        while (!validMove) 
        {
            cout << "Player " << currentPlayer << ", enter your move (row and column: 0-2): ";
            cin >> row >> col;

            if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') 
            {
                board[row][col] = currentPlayer;
                validMove = true;
            } 
            else 
            {
                cout << "Invalid move. Please try again.\n";
            }
        }

        // Check for a win
        if (isWinner(board, currentPlayer)) 
        {
            displayBoard(board);
            cout << "Congratulations! Player " << currentPlayer << " wins!\n";
            return 0; // End the game after a win
        }

        // Switch players
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        ++moves;
    }

    // If the game is a draw
    displayBoard(board);
    cout << "It's a draw!\n";

    return 0;
}
