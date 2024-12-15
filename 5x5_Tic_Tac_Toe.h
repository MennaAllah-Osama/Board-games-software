#ifndef _5x5X_O_H
#define _5x5X_O_H

#include "BoardGame_Classes.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <limits>
#include "vector"

using namespace std;

extern string player_name1;
extern string player_name2;
int count_X = 0;
int count_O = 0;

// Board Class for 5x5 Tic Tac Toe
template <typename T>
class tic_tac_toe_Board : public Board<T> {
public:
    tic_tac_toe_Board();
    bool update_board(int x, int y, T symbol);
    void display_board();
    bool is_win();  // Function for checking if there is a winner
    bool is_draw();
    bool game_is_over();
};

template<typename T>
class tic_tac_toe_Player : public Player<T> {
public:
    tic_tac_toe_Player(string name, T symbol) : Player<T>(name, symbol) {}

    void getmove(int &x, int &y) override {
        cout << "Enter your move (row and column): ";
        cin >> x >> y;
    }
};
template <typename T>
class tic_tac_toe_Random_Player : public RandomPlayer<T> {
    int dimension = 5;  // Dimension of the board
    vector<pair<int, int>> empty_cells;  // Vector to store empty cell coordinates

public:
    tic_tac_toe_Random_Player(T symbol, int dim = 5) : RandomPlayer<T>(symbol), dimension(dim) {
        srand(static_cast<unsigned int>(time(0)));
    }

    void getmove(int& x, int& y) override {
        x = rand() % dimension;
        y = rand() % dimension;

    }
};
template <typename T>
tic_tac_toe_Board<T>::tic_tac_toe_Board() {
    this->rows = this->columns = 5;  // 5x5 grid
    this->board = new T*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new T[this->columns]();  // Initialize with 0 (empty)
    }
    this->n_moves = 0;
}
template <typename T>
bool tic_tac_toe_Board<T>::update_board(int x, int y, T mark) {
    if (x < 0 || x >= this->rows || y < 0 || y >= this->columns) {
        cout << "Invalid move. Coordinates are out of bounds. Try again.\n";
        return false;
    }
    if (this->board[x][y] != 0) {
        return false;
    }
    this->board[x][y] = mark;
    this->n_moves++;

    return true;
}
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
template <typename T>
bool tic_tac_toe_Board<T>::is_win() {
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
    if (this->n_moves % 2 == 0 && count_X > count_O && this->n_moves >= 24) {
        // Ensure player 1 (X) actually has the winning pattern
        for (int i = 0; i < this->rows; i++) {
            for (int j = 0; j < this->columns; j++) {
                if (this->board[i][j] == 'X') {
                    cout << player_name1 << " Player 1 (X) wins!" << endl;
                    return false;
                }
            }
        }
    } else if (this->n_moves % 2 != 0 && count_O > count_X && this->n_moves >= 24) {
        // Ensure player 2 (O) actually has the winning pattern
        for (int i = 0; i < this->rows; i++) {
            for (int j = 0; j < this->columns; j++) {
                if (this->board[i][j] == 'O') {
                    cout << player_name2 << " Player 2 (O) wins!" << endl;
                    return true;
                }
            }
        }
    }
    return false;
}
template <typename T>
bool tic_tac_toe_Board<T>::game_is_over() {
    if (this->n_moves >= 24) {
        if (count_X== count_O) {
            cout << "It's a draw!" << endl;
        }
        return true;
    }
    return false;
}
template <typename T>
bool tic_tac_toe_Board<T>::is_draw() {
    if (this->n_moves == 24 && count_O ==  count_X){
        return true;
    }
    return false;
}


#endif
