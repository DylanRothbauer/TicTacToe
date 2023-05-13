#include <iostream>
using namespace std;

// Function to display the board
void displayBoard(char board[3][3]) {
    cout << "-------------" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << endl;
        cout << "-------------" << endl;
    }
}

// Function to check for win condition
bool checkWin(char board[3][3], char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }
    return false;
}

int main() {
    char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    bool player1Turn = true;
    int turns = 0;
    while (turns < 9) {
        displayBoard(board);
        char playerChar = player1Turn ? 'X' : 'O';
        int row, col;
        cout << "Player " << (player1Turn ? "1" : "2") << " (" << playerChar << "): ";
        cin >> row >> col;
        if (row < 1 || row > 3 || col < 1 || col > 3) {
            cout << "Invalid row or column!" << endl;
            continue;
        }
        if (board[row - 1][col - 1] != ' ') {
            cout << "That cell is already taken!" << endl;
            continue;
        }
        board[row - 1][col - 1] = playerChar;
        if (checkWin(board, playerChar)) {
            cout << "Player " << (player1Turn ? "1" : "2") << " wins!" << endl;
            displayBoard(board);
            break;
        }
        player1Turn = !player1Turn;
        turns++;
    }
    if (turns == 9) {
        cout << "It's a tie!" << endl;
    }
    return 0;
}
