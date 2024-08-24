#include <iostream>
#include <conio.h>

using namespace std;

const int SIZE = 3;
char board[SIZE][SIZE] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };

void printBoard() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << board[i][j];
            if (j < SIZE - 1) cout << " | ";
        }
        cout << endl;
        if (i < SIZE - 1) cout << "---------" << endl;
    }
}

bool checkWin(char player) {
    for (int i = 0; i < SIZE; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) || 
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) || 
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}
bool isBoardFull() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int row, col;
    char currentPlayer = 'X';
    cout << "Tic-Tac-Toe Game!" << endl;
    while (true) {
        printBoard();
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;
        if (row < 1 || row > SIZE || col < 1 || col > SIZE || board[row-1][col-1] != ' ') {
            cout << "Invalid move. Try again." << endl;
            continue;
        }
        board[row-1][col-1] = currentPlayer;
        if (checkWin(currentPlayer)) {
            printBoard();
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }
        if (isBoardFull()) {
            printBoard();
            cout << "It's a draw!" << endl;
            break;
        }
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
    
    return 0;
}
