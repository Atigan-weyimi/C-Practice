#include <iostream>
using namespace std;

// Enum for game status
enum class GameStatus {
    IN_PROGRESS,
    X_WON,
    O_WON,
    DRAW
};

// Class for a move
class Move {
public:
    int i, j, piece;

    Move(int i, int j, int piece) : i(i), j(j), piece(piece) {}

    int getI() const { return i; }
    int getJ() const { return j; }
    int getPiece() const { return piece; }
};

// Class for the game board
class Board {
private:
    int table[3][3];

public:
    Board() {
        // Initialize the board with -1
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                table[i][j] = -1;
            }
        }
    }

    // Method to set a cell on the board
    void set(int i, int j, int piece) { table[i][j] = piece; }

    // Method to get the value of a cell on the board
    int get(int i, int j) const { return table[i][j]; }

    // Method to display the board
    void display() const {
        cout << " " << (get(0, 0) == -1 ? " " : get(0, 0) == 0 ? "X" : "O")
             << " | " << (get(0, 1) == -1 ? " " : get(0, 1) == 0 ? "X" : "O")
             << " | " << (get(0, 2) == -1 ? " " : get(0, 2) == 0 ? "X" : "O") << endl;
        cout << "---+---+---" << endl;
        cout << " " << (get(1, 0) == -1 ? " " : get(1, 0) == 0 ? "X" : "O")
             << " | " << (get(1, 1) == -1 ? " " : get(1, 1) == 0 ? "X" : "O")
             << " | " << (get(1, 2) == -1 ? " " : get(1, 2) == 0 ? "X" : "O") << endl;
        cout << "---+---+---" << endl;
        cout << " " << (get(2, 0) == -1 ? " " : get(2, 0) == 0 ? "X" : "O")
             << " | " << (get(2, 1) == -1 ? " " : get(2, 1) == 0 ? "X" : "O")
             << " | " << (get(2, 2) == -1 ? " " : get(2, 2) == 0 ? "X" : "O") << endl;
    }

    // Method to check for a winner
    GameStatus checkWinner() const {
        // Check rows
        for (int i = 0; i < 3; i++) {
            if (table[i][0] != -1 && table[i][0] == table[i][1] && table[i][1] == table[i][2]) {
                return table[i][0] == 0 ? GameStatus::X_WON : GameStatus::O_WON;
            }
        }

        // Check columns
        for (int j = 0; j < 3; j++) {
            if (table[0][j] != -1 && table[0][j] == table[1][j] && table[1][j] == table[2][j]) {
                return table[0][j] == 0 ? GameStatus::X_WON : GameStatus::O_WON;
            }
        }

        // Check diagonals
        if (table[0][0] != -1 && table[0][0] == table[1][1] && table[1][1] == table[2][2]) {
            return table[0][0] == 0 ? GameStatus::X_WON : GameStatus::O_WON;
        }
        if (table[0][2] != -1 && table[0][2] == table[1][1] && table[1][1] == table[2][0]) {
            return table[0][2] == 0 ? GameStatus::X_WON : GameStatus