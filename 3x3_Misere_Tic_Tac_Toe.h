#ifndef _3x3_Misere_Tic_Tac_Toe_O_H
#define _3x3_Misere_Tic_Tac_Toe_O_H
#include "BoardGame_Classes.h"

extern string player_name1;
extern string player_name2;
bool misere = false;        // Flag to handle a special win/loss state

using namespace std;

template <typename T>
class tic_tac_toe_Board : public Board<T> {
public:
    tic_tac_toe_Board();
    bool update_board(int x, int y, T symbol);
    void display_board();
    bool is_win();
    bool game_is_over();
    bool is_draw();
};

// Constructor: Initializes a 3x3 empty board
template <typename T>
tic_tac_toe_Board<T>::tic_tac_toe_Board() {
    this->rows = this->columns = 3;  // Set the board size to 3x3
    this->board = new T*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new T[this->columns](); // Initialize board cells to zero
    }
    this->n_moves = 0; // Initialize the move count to zero
}

// Update the board with a player's move at (x, y)
template <typename T>
bool tic_tac_toe_Board<T>::update_board(int x, int y, T mark) {
    // Check if the position is valid and not already occupied
    if (x < 0 || x >= this->rows || y < 0 || y >= this->columns ||
        (this->board[x][y] != 0 && !misere)) {
        return false; // Invalid move
    }
    if (!misere) {
        this->board[x][y] = mark; // Update the cell with the player's symbol
        this->n_moves++;          // Increment the move count
    }
    return true; // Move successful
}

// Display the current state of the board
template <typename T>
void tic_tac_toe_Board<T>::display_board() {
    cout << "\n";
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->columns; j++) {
            // Print cell contents or space if empty
            cout << "| " << (this->board[i][j] == 0 ? ' ' : this->board[i][j]) << " ";
        }
        cout << "|\n";
    }
}

// Check if a player has won
template <typename T>
bool tic_tac_toe_Board<T>::is_win() {
    if (misere) {
        return true; // Special condition where game ends
    }

    // Check rows, columns, and diagonals for a win condition
    if (this->board[0][0] != 0 && this->board[0][0] == this->board[0][1] && this->board[0][1] == this->board[0][2]) misere = true;
    if (this->board[1][0] != 0 && this->board[1][0] == this->board[1][1] && this->board[1][1] == this->board[1][2]) misere = true;
    if (this->board[2][0] != 0 && this->board[2][0] == this->board[2][1] && this->board[2][1] == this->board[2][2]) misere = true;

    if (this->board[0][0] != 0 && this->board[0][0] == this->board[1][0] && this->board[1][0] == this->board[2][0]) misere = true;
    if (this->board[0][1] != 0 && this->board[0][1] == this->board[1][1] && this->board[1][1] == this->board[2][1]) misere = true;
    if (this->board[0][2] != 0 && this->board[0][2] == this->board[1][2] && this->board[1][2] == this->board[2][2]) misere = true;

    if (this->board[0][0] != 0 && this->board[0][0] == this->board[1][1] && this->board[1][1] == this->board[2][2]) misere = true;
    if (this->board[0][2] != 0 && this->board[0][2] == this->board[1][1] && this->board[1][1] == this->board[2][0]) misere = true;

    return false; // No winner yet
}

// Check if the game is over
template <typename T>
bool tic_tac_toe_Board<T>::game_is_over() {
    if (this->n_moves >= 10) { // If the total moves exceed the maximum allowed
        if (is_draw()) {
            cout << "It's a draw!" << endl; // Display draw message
        }
        return true; // Game over
    }
    return false; // Game not over
}

// Check if the game ended in a draw
template <typename T>
bool tic_tac_toe_Board<T>::is_draw() {
    return this->n_moves == 10 && !is_win(); // No winner and board is full
}

// Class representing a human Tic-Tac-Toe player
template <typename T>
class tic_tac_toe_Player : public Player<T> {
public:
    tic_tac_toe_Player(string name, T symbol) : Player<T>(name, symbol) {}

    // Get the player's move input
    void getmove(int &x, int &y) override {
        if (!misere) { // If game is not over
            cout << "Enter your move (row and column): ";
            cin >> x >> y;
        } else {
            x = 0;
            y = 0;
        }
    }
};

// Class representing a random Tic-Tac-Toe player
template <typename T>
class tic_tac_toe_Random_Player : public RandomPlayer<T> {
    int dimension;

public:
    tic_tac_toe_Random_Player(T symbol, int dim = 3) : RandomPlayer<T>(symbol), dimension(dim) {
        srand(static_cast<unsigned int>(time(0)));
    }

    // Generate a random move on the board
    void getmove(int &x, int &y) override {
        x = rand() % dimension;
        y = rand() % dimension;
    }
};

#endif
