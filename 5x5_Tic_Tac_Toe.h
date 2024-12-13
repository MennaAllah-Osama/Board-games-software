#ifndef _5x5_Tic_Tac_Toe_H
#define _5x5_Tic_Tac_Toe_H

#include "BoardGame_Classes.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <limits>
#include "vector"

using namespace std;

// External variables for player names
extern string player_name1;
extern string player_name2;

// Global counters for tracking the number of winning patterns
int count_X = 0;
int count_O = 0;

// Class for 5x5 Tic Tac Toe board
template <typename T>
class tic_tac_toe_Board : public Board<T> {
public:
    tic_tac_toe_Board(); // Constructor to initialize the board
    bool update_board(int x, int y, T symbol); // Update the board with a move
    void display_board(); // Display the board
    bool is_win(); // Check if there is a winner
    bool is_draw(); // Check if the game is a draw
    bool game_is_over(); // Check if the game is over
};

// Class for a human Tic Tac Toe player
template<typename T>
class tic_tac_toe_Player : public Player<T> {
public:
    tic_tac_toe_Player(string name, T symbol) : Player<T>(name, symbol) {}

    // Get the player's move
    void getmove(int &x, int &y) override {
        cout << "Enter your move (row and column): ";
        cin >> x >> y;
    }
};

// Class for a random AI Tic Tac Toe player
template <typename T>
class tic_tac_toe_Random_Player : public RandomPlayer<T> {
    int dimension = 5; // Board dimension
    vector<pair<int, int>> empty_cells; // Store empty cell coordinates

public:
    tic_tac_toe_Random_Player(T symbol, int dim = 5) : RandomPlayer<T>(symbol), dimension(dim) {
        srand(static_cast<unsigned int>(time(0)));
    }

    // Generate a random move
    void getmove(int& x, int& y) override {
        x = rand() % dimension;
        y = rand() % dimension;
    }
};

// Board constructor - initializes a 5x5 grid
template <typename T>
tic_tac_toe_Board<T>::tic_tac_toe_Board() {
    this->rows = this->columns = 5; // Set dimensions
    this->board = new T*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new T[this->columns](); // Initialize with 0 (empty)
    }
    this->n_moves = 0; // Initialize move count
}

// Update the board with a player's move
template <typename T>
bool tic_tac_toe_Board<T>::update_board(int x, int y, T mark) {
    if (x < 0 || x >= this->rows || y < 0 || y >= this->columns) {
        cout << "Invalid move. Coordinates are out of bounds. Try again.\n";
        return false;
    }
    if (this->board[x][y] != 0) { // Check if cell is already occupied
        return false;
    }
    this->board[x][y] = mark;
    this->n_moves++;
    return true;
}

// Display the current state of the board
template <typename T>
void tic_tac_toe_Board<T>::display_board() {
    cout << "\n";
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->columns; j++) {
            cout << "| " << (this->board[i][j] == 0 ? ' ' : this->board[i][j]) << " ";
        }
        cout << "|\n";
    }
}

// Check for winning patterns on the board
template <typename T>
bool tic_tac_toe_Board<T>::is_win() {
    // Check rows for winning patterns
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j <= this->columns - 3; j++) {
            if (this->board[i][j] != 0 &&
                this->board[i][j] == this->board[i][j + 1] &&
                this->board[i][j + 1] == this->board[i][j + 2]) {
                if (this->board[i][j] == 'X') {
                    count_X++;
                } else if (this->board[i][j] == 'O') {
                    count_O++;
                }
            }
        }
    }

    // Check columns for winning patterns
    for (int j = 0; j < this->columns; j++) {
        for (int i = 0; i <= this->rows - 3; i++) {
            if (this->board[i][j] != 0 &&
                this->board[i][j] == this->board[i + 1][j] &&
                this->board[i + 1][j] == this->board[i + 2][j]) {
                if (this->board[i][j] == 'X') {
                    count_X++;
                } else if (this->board[i][j] == 'O') {
                    count_O++;
                }
            }
        }
    }

    // Check diagonals for winning patterns
    for (int i = 0; i <= this->rows - 3; i++) {
        for (int j = 0; j <= this->columns - 3; j++) {
            if (this->board[i][j] != 0 &&
                this->board[i][j] == this->board[i + 1][j + 1] &&
                this->board[i + 1][j + 1] == this->board[i + 2][j + 2]) {
                if (this->board[i][j] == 'X') {
                    count_X++;
                } else if (this->board[i][j] == 'O') {
                    count_O++;
                }
            }
            if (this->board[i][j + 2] != 0 &&
                this->board[i][j + 2] == this->board[i + 1][j + 1] &&
                this->board[i + 1][j + 1] == this->board[i + 2][j]) {
                if (this->board[i][j + 2] == 'X') {
                    count_X++;
                } else if (this->board[i][j + 2] == 'O') {
                    count_O++;
                }
            }
        }
    }

    // Declare winner if patterns found
    if (count_X > count_O) {
        cout << player_name1 << " Player 1 (X) wins!" << endl;
        return true;
    } else if (count_O > count_X) {
        cout << player_name2 << " Player 2 (O) wins!" << endl;
        return true;
    }
    return false;
}

// Check if the game has reached a draw
template <typename T>
bool tic_tac_toe_Board<T>::is_draw() {
    return (this->n_moves == 24 && count_X == count_O);
}

// Check if the game is over
template <typename T>
bool tic_tac_toe_Board<T>::game_is_over() {
    if (this->n_moves >= 24) {
        if (is_draw()) {
            cout << "It's a draw!" << endl;
        }
        return true;
    }
    return false;
}

#endif
