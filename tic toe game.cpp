#include <iostream>
using namespace std;

char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
char currentPlayer = 'X';

// Function to display the game board
void displayBoard() {
    cout << "  1 2 3" << endl;
    cout << " -------" << endl;
    for (int i = 0; i < 3; i++) {
        cout << i+1 << "|";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << "|";
        }
        cout << endl << " -------" << endl;
    }
}

// Function to check if the game is over (win or draw)
bool gameOver() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' '))
            return true;
    }
    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' '))
        return true;
    
    // Check for draw
    bool isDraw = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                isDraw = false;
        }
    }
    if (isDraw) {
        cout << "It's a draw!" << endl;
        return true;
    }

    return false;
}

// Function to switch players
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// Function to check if a move is valid
bool isValidMove(int row, int col) {
    return row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ';
}

// Function to update the game board with the player's move
void makeMove(int row, int col) {
    board[row][col] = currentPlayer;
}

int main() {
    cout << "Welcome to Tic-Tac-Toe!" << endl;
    cout << "Player 1: X\nPlayer 2: O" << endl;

    displayBoard();

    while (!gameOver()) {
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        if (isValidMove(row - 1, col - 1)) {
            makeMove(row - 1, col - 1);
            displayBoard();
            if (gameOver())
                cout << "Player " << currentPlayer << " wins!" << endl;
            else
                switchPlayer();
        } else {
            cout << "Invalid move! Try again." << endl;
        }
    }

    char playAgain;
    cout << "Do you want to play again? (y/n): ";
    cin >> playAgain;
    if (playAgain == 'y' || playAgain == 'Y') {
        // Reset the board and currentPlayer
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = ' ';
            }
        }
        currentPlayer = 'X';
        main(); // Restart the game
    } else {
        cout << "Thanks for playing!" << endl;
    }

    return 0;
}

