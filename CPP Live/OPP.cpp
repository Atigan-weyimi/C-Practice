#include <iostream>
using namespace std;

// Function to draw the game board
void drawBoard(char board[3][3]) {
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "---+---+---" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "---+---+---" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

// Function to handle player move
void playerMove(char board[3][3], char player) {
    int row, col;
    cout << "Enter row (1-3): ";2
    cin >> row;
    cout << "Enter column (1-3): ";
    cin >> col;
    row--; col--;
    if (board[row][col] == ' ') {
        board[row][col] = player;
    } else {
        cout << "Invalid move, try again." << endl;
        playerMove(board, player);
    }
}

// Function to check for win
bool checkWin(char board[3][3], char player) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }
    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char player = 'X';
    while (true) {
        drawBoard(board);
        playerMove(board, player);
        if (checkWin(board, player)) {
            drawBoard(board);
            cout << "Player " << player << " wins!" << endl;
            break;
        }
        player = (player == 'X') ? 'O' : 'X';
    }
    return 0;
}
