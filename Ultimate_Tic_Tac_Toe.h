#ifndef _ULTIMATE_TIC_TAC_TOE_H
#define _ULTIMATE_TIC_TAC_TOE_H
#include "BoardGame_Classes.h"
#include <bits/stdc++.h>

using namespace std;

// External variables for player names
extern string player_name1;
extern string player_name2;
map<int,char>mapp;
char c0, c1, c2, c3, c4, c5, c6, c7, c8;
int board_num ;
int iswin=0;
bool P1=false;
int counterr=0;

// Class for 5x5 Tic Tac Toe board
template <typename T>
class Ultimate_Tic_Tac_Toe_Board : public Board<T> {
public:
    Ultimate_Tic_Tac_Toe_Board(); // Constructor to initialize the board
    bool update_board(int x, int y, T symbol); // Update the board with a move
    void display_board(); // Display the board
    void display_large_board(int small_board_num); // Display a large board showing all small boards
    map<int, char> is_win1();
    bool is_win(); // Check if there is a winner
    bool is_draw(); // Check if the game is a draw
    bool game_is_over(); // Check if the game is over
};

// Class for a human Tic Tac Toe player
template<typename T>
class Ultimate_Tic_Tac_Toe_Player : public Player<T> {
public:
    Ultimate_Tic_Tac_Toe_Player(string name, T symbol) : Player<T>(name, symbol) {}
    void getmove(int &x, int &y){
        while(true) {
            cout << "Choose the small board (0-8):";
            cin >> board_num;
            if(board_num<0 or board_num>8){
                cout<<"Invalid please enter a number from 0 to 8\n";
                continue;
            }
            else{
                break;
            }
        }
        int offset_row = (board_num / 3) * 3;
        int offset_col = (board_num % 3) * 3;

        cout << "Enter x and y for your move separated by spaces : ";
        int local_x, local_y;
        cin >> local_x >> local_y;

        x = offset_row + local_x;
        y = offset_col + local_y;
    }
};

// Class for a random AI Tic Tac Toe player
template <typename T>
class Ultimate_Tic_Tac_Toe_Random_Player : public RandomPlayer<T> {
    int dimension; // Dimension of the large board (3x3 small boards)

public:
    Ultimate_Tic_Tac_Toe_Random_Player(T symbol, int dim = 3) : RandomPlayer<T>(symbol), dimension(dim) {
        srand(static_cast<unsigned int>(time(0))); // Seed for randomness
        this->name = "Random Computer Player with symbol ";
        this->name+=symbol;
    }
    void getmove(int &x, int &y) override {
        board_num = rand() % 9;

        int offset_row = (board_num / 3) * 3;
        int offset_col = (board_num % 3) * 3;


        int local_x = rand() % 3;
        int local_y = rand() % 3;

        x = offset_row + local_x;
        y = offset_col + local_y;

//        cout << "AI chose small board " << board_num
//             << " and move (" << local_x << ", " << local_y << ")\n";
    }
};

// Board constructor - initializes a 5x5 grid
template <typename T>
Ultimate_Tic_Tac_Toe_Board<T>::Ultimate_Tic_Tac_Toe_Board() {
    this->rows = this->columns = 9; // Set dimensions for the main board
    this->board = new T*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new T[this->columns](); // Initialize with 0 (empty)
    }
    this->n_moves = 0; // Initialize move count
}

// Update the board with a player's move
template <typename T>
bool Ultimate_Tic_Tac_Toe_Board<T>::update_board(int x, int y, T mark) {
    if(this->n_moves%2==0){
        P1= true;
    }
    else{
        P1=false;
    }
    if (x < 0 || x >= this->rows || y < 0 || y >= this->columns) {
        return false;
    }
    if (this->board[x][y] != 0) {
        return false;
    }
    this->board[x][y] = mark;
    this->n_moves++;
    mapp=is_win1();
    return true;
}

// Display the current state of the Ultimate Tic Tac Toe Board
template <typename T>
void Ultimate_Tic_Tac_Toe_Board<T>::display_board() {

    // Display the Ultimate Tic Tac Toe Board
    cout << "\nUltimate Tic Tac Toe Board:\n";
    for (int big_row = 0; big_row < 3; big_row++) {
        for (int sub_row = 0; sub_row < 3; sub_row++) {
            for (int big_col = 0; big_col < 3; big_col++) {
                for (int sub_col = 0; sub_col < 3; sub_col++) {
                    int row = big_row * 3 + sub_row;
                    int col = big_col * 3 + sub_col;

                    if (this->board[row][col] != 0) {
                        cout << " " << this->board[row][col] << " ";
                    } else {
                        cout << " - ";
                    }
                    if (sub_col < 2) cout << "|";
                }
                if (big_col < 2) cout << " | ";
            }
            cout << "\n";
        }
        if (big_row < 2) {
            cout << "------------|-------------|------------\n";
        }
    }
}

// Check for winning patterns on the board
template <typename T>
map<int,char> Ultimate_Tic_Tac_Toe_Board<T>::is_win1() {

    if (board_num == 5) {
        bool B5 = false;
        // Check rows, columns, and diagonals for a winner
        for (int i = 3; i < 6; i++) {
            if (this->board[i][6] == this->board[i][7] && this->board[i][7] == this->board[i][8] &&
                this->board[i][6] != 0) {
                B5 = true;
            }
        }
        for (int j = 6; j < 9; j++) {
            if (this->board[3][j] == this->board[4][j] && this->board[4][j] == this->board[5][j] &&
                this->board[3][j] != 0) {
                B5 = true;
            }
        }
        // Check diagonals
        if (this->board[3][6] == this->board[4][7] && this->board[4][7] == this->board[5][8] &&
            this->board[3][6] != 0) {
            B5 = true;
        }
        if (this->board[3][8] == this->board[4][7] && this->board[4][7] == this->board[5][6] &&
            this->board[3][8] != 0) {
            B5 = true;
        }
        if (B5) {
            if (P1) {
                c5 = 'X';
            } else {
                c5 = 'O';
            }
            for (int j = 3; j < 6; j++) {
                for (int k = 6; k < 9; k++) {
                    this->board[j][k] = c5;
                }

            }
            mapp[5]=c5;
            counterr++;
        } else {
            int count4=0;
            for (int j = 6; j < 9; j++) {
                for (int k = 3; k < 6; k++) {
                    if((this->board[j][k]=='X' or this->board[j][k]=='O')){
                        count4++;
                    }
                }
            }
            if(count4==9){
                counterr++;
            }
            B5 = false;
        }
        return mapp;
    }
    if (board_num == 4) {
        bool B4 = false;
        // Check rows, columns, and diagonals for a winner
        for (int i = 3; i < 6; i++) {
            if (this->board[i][3] == this->board[i][4] && this->board[i][4] == this->board[i][5] &&
                this->board[i][3] != 0) {
                B4 = true;
            }
        }
        for (int j = 3; j < 6; j++) {
            if (this->board[3][j] == this->board[4][j] && this->board[4][j] == this->board[5][j] &&
                this->board[3][j] != 0) {
                B4 = true;
            }
        }
        // Check diagonals
        if (this->board[3][3] == this->board[4][4] && this->board[4][4] == this->board[5][5] &&
            this->board[3][3] != 0) {
            B4 = true;
        }
        if (this->board[3][5] == this->board[4][4] && this->board[4][4] == this->board[5][3] &&
            this->board[3][5] != 0) {
            B4 = true;
        }
        if (B4) {
            if (P1) {
                c4 = 'X';
            } else {
                c4 = 'O';
            }
            for (int j = 3; j < 6; j++) {
                for (int k = 3; k < 6; k++) {
                    this->board[j][k] = c4;
                }

            }
            mapp[4]=c4;
            counterr++;
        } else {
            int count4=0;
            for (int j = 3; j < 6; j++) {
                for (int k = 3; k < 6; k++) {
                    if(this->board[j][k]=='X' or this->board[j][k]=='O'){
                        count4++;
                    }
                }
            }
            if(count4==9){
                counterr++;
            }
            B4 = false;
        }
        return mapp;
    }
    if (board_num == 3) {
        bool B3 = false;
        // Check rows, columns, and diagonals for a winner
        for (int i = 3; i < 6; i++) {
            if (this->board[i][0] == this->board[i][1] && this->board[i][1] == this->board[i][2] &&
                this->board[i][0] != 0) {
                B3 = true;
            }
        }
        for (int j = 0; j < 3; j++) {
            if (this->board[3][j] == this->board[4][j] && this->board[4][j] == this->board[5][j] &&
                this->board[3][j] != 0) {
                B3 = true;
            }
        }
        // Check diagonals
        if (this->board[3][0] == this->board[4][1] && this->board[4][1] == this->board[5][2] &&
            this->board[3][0] != 0) {
            B3 = true;
        }
        if (this->board[3][2] == this->board[4][1] && this->board[4][1] == this->board[5][0] &&
            this->board[3][2] != 0) {
            B3 = true;
        }
        if (B3) {
            if (P1) {
                c3 = 'X';
            } else {
                c3 = 'O';
            }
            for (int j = 3; j < 6; j++) {
                for (int k = 0; k < 3; k++) {
                    this->board[j][k] = c3;
                }

            }
            mapp[3]=c3;
            counterr++;
        } else {
            int count4=0;
            for (int j = 3; j < 6; j++) {
                for (int k = 0; k < 3; k++) {
                    if(this->board[j][k]=='X' or this->board[j][k]=='O'){
                        count4++;
                    }
                }
            }
            if(count4==9){
                counterr++;
            }
            B3 = false;
        }
        return mapp;
    }
    if (board_num == 0) {
        bool B0 = false;
        // Check rows, columns, and diagonals for a winner
        for (int i = 0; i < 3; i++) {
            if (this->board[i][0] == this->board[i][1] && this->board[i][1] == this->board[i][2] &&
                this->board[i][0] != 0) {
                B0 = true;
            }
        }
        for (int j = 0; j < 3; j++) {
            if (this->board[0][j] == this->board[1][j] && this->board[1][j] == this->board[2][j] &&
                this->board[0][j] != 0) {
                B0 = true;
            }
        }
        // Check diagonals
        if (this->board[0][0] == this->board[1][1] && this->board[1][1] == this->board[2][2] &&
            this->board[0][0] != 0) {
            B0 = true;
        }
        if (this->board[0][2] == this->board[1][1] && this->board[1][1] == this->board[2][0] &&
            this->board[0][2] != 0) {
            B0 = true;
        }
        if (B0) {
            if (P1) {
                c0 = 'X';
            } else {
                c0 = 'O';
            }
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    this->board[j][k] = c0;
                }

            }
            mapp[0]=c0;
            counterr++;
        } else {
            int count4=0;
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if(this->board[j][k]=='X' or this->board[j][k]=='O'){
                        count4++;
                    }
                }
            }
            if(count4==9){
                counterr++;
            }
            B0 = false;
        }
        return mapp;
    }
    if (board_num == 1) {
        bool B1 = false;
        // Check rows, columns, and diagonals for a winner
        for (int i = 0; i < 3; i++) {
            if (this->board[i][3] == this->board[i][4] && this->board[i][4] == this->board[i][5] &&
                this->board[i][3] != 0) {
                B1 = true;
            }
        }
        for (int j = 3; j < 6; j++) {
            if (this->board[0][j] == this->board[1][j] && this->board[1][j] == this->board[2][j] &&
                this->board[0][j] != 0) {
                B1 = true;
            }
        }
        // Check diagonals
        if (this->board[0][3] == this->board[1][4] && this->board[1][4] == this->board[2][5] &&
            this->board[0][3] != 0) {
            B1 = true;
        }
        if (this->board[0][5] == this->board[1][4] && this->board[1][4] == this->board[2][3] &&
            this->board[0][5] != 0) {
            B1 = true;
        }
        if (B1) {
            if (P1) {
                c1 = 'X';
            } else {
                c1 = 'O';
            }
            for (int j = 0; j < 3; j++) {
                for (int k = 3; k < 6; k++) {
                    this->board[j][k] = c1;
                }

            }
            mapp[1]=c1;
            counterr++;
        }
        else {
            int count4=0;
            for (int j = 0; j < 3; j++) {
                for (int k = 3; k < 6; k++) {
                    if(this->board[j][k]=='X' or this->board[j][k]=='O'){
                        count4++;
                    }
                }
            }
            if(count4==9){
                counterr++;
            }
            B1 = false;
        }
        return mapp;
    }
    if (board_num == 2) {
        bool B2 = false;
        // Check rows, columns, and diagonals for a winner
        for (int i = 0; i < 3; i++) {
            if (this->board[i][6] == this->board[i][7] && this->board[i][7] == this->board[i][8] &&
                this->board[i][6] != 0) {
                B2 = true;
            }
        }
        for (int j = 6; j < 9; j++) {
            if (this->board[0][j] == this->board[1][j] && this->board[1][j] == this->board[2][j] &&
                this->board[0][j] != 0) {
                B2 = true;
            }
        }
        // Check diagonals
        if (this->board[0][6] == this->board[1][7] && this->board[1][7] == this->board[2][8] &&
            this->board[0][6] != 0) {
            B2 = true;
        }
        if (this->board[0][8] == this->board[1][7] && this->board[1][7] == this->board[2][6] &&
            this->board[0][8] != 0) {
            B2 = true;
        }
        if (B2) {
            if (P1) {
                c2 = 'X';
            } else {
                c2 = 'O';
            }
            for (int j = 0; j < 3; j++) {
                for (int k = 6; k < 9; k++) {
                    this->board[j][k] = c2;
                }

            }
            mapp[2]=c2;
            counterr++;
        }
        else {
            int count4=0;
            for (int j = 0; j < 3; j++) {
                for (int k = 6; k < 9; k++) {
                    if(this->board[j][k]=='X' or this->board[j][k]=='O'){
                        count4++;
                    }
                }
            }
            if(count4==9){
                counterr++;
            }
            B2 = false;
        }
        return mapp;
    }
    if (board_num == 6) {
        bool B6 = false;
        // Check rows, columns, and diagonals for a winner
        for (int i = 6; i < 9; i++) {
            if (this->board[i][0] == this->board[i][1] && this->board[i][1] == this->board[i][2] &&
                this->board[i][0] != 0) {
                B6 = true;
            }
        }
        for (int j = 0; j < 3; j++) {
            if (this->board[6][j] == this->board[7][j] && this->board[7][j] == this->board[8][j] &&
                this->board[6][j] != 0) {
                B6 = true;
            }
        }
        // Check diagonals
        if (this->board[6][0] == this->board[7][1] && this->board[7][1] == this->board[8][2] &&
            this->board[6][0] != 0) {
            B6 = true;
        }
        if (this->board[6][2] == this->board[7][1] && this->board[7][1] == this->board[8][0] &&
            this->board[6][2] != 0) {
            B6 = true;
        }
        if (B6) {
            if (P1) {
                c6 = 'X';
            } else {
                c6 = 'O';
            }
            for (int j = 6; j < 9; j++) {
                for (int k = 0; k < 3; k++) {
                    this->board[j][k] = c6;
                }

            }
            mapp[6]=c6;
            counterr++;
        } else {
            int count4=0;
            for (int j = 6; j < 9; j++) {
                for (int k = 0; k < 3; k++) {
                    if(this->board[j][k]=='X' or this->board[j][k]=='O'){
                        count4++;
                    }
                }
            }
            if(count4==9){
                counterr++;
            }
            B6 = false;
        }
        return mapp;
    }
    if (board_num == 8) {
        bool B8 = false;
        // Check rows, columns, and diagonals for a winner
        for (int i = 6; i < 9; i++) {
            if (this->board[i][6] == this->board[i][7] && this->board[i][7] == this->board[i][8] &&
                this->board[i][6] != 0) {
                B8 = true;
            }
        }
        for (int j = 6; j < 9; j++) {
            if (this->board[6][j] == this->board[7][j] && this->board[7][j] == this->board[8][j] &&
                this->board[6][j] != 0) {
                B8 = true;
            }
        }
        // Check diagonals
        if (this->board[6][6] == this->board[7][7] && this->board[7][7] == this->board[8][8] &&
            this->board[6][6] != 0) {
            B8 = true;
        }
        if (this->board[6][8] == this->board[7][7] && this->board[7][7] == this->board[8][6] &&
            this->board[6][8] != 0) {
            B8 = true;
        }
        if (B8) {
            if (P1) {
                c8 = 'X';
            } else {
                c8 = 'O';
            }
            for (int j = 6; j < 9; j++) {
                for (int k = 6; k < 9; k++) {
                    this->board[j][k] = c8;
                }

            }
            mapp[8]=c8;
            counterr++;
        } else {
            int count4=0;
            for (int j = 6; j < 9; j++) {
                for (int k = 6; k < 9; k++) {
                    if(this->board[j][k]=='X' or this->board[j][k]=='O'){
                        count4++;
                    }
                }
            }
            if(count4==9){
                counterr++;
            }
            B8 = false;
        }
        return mapp;
    }
    if (board_num == 7) {
        bool B7 = false;
        // Check rows, columns, and diagonals for a winner
        for (int i = 6; i < 9; i++) {
            if (this->board[i][3] == this->board[i][4] && this->board[i][4] == this->board[i][5] &&
                this->board[i][3] != 0) {
                B7 = true;
            }
        }
        for (int j = 3; j < 6; j++) {
            if (this->board[6][j] == this->board[7][j] && this->board[7][j] == this->board[8][j] &&
                this->board[6][j] != 0) {
                B7 = true;
            }
        }
        // Check diagonals
        if (this->board[6][3] == this->board[7][4] && this->board[7][4] == this->board[8][5] &&
            this->board[6][3] != 0) {
            B7 = true;
        }
        if (this->board[6][5] == this->board[7][4] && this->board[7][4] == this->board[8][3] &&
            this->board[6][5] != 0) {
            B7 = true;
        }
        if (B7) {
            if (P1) {
                c7 = 'X';
            } else {
                c7 = 'O';
            }
            for (int j = 6; j < 9; j++) {
                for (int k = 3; k < 6; k++) {
                    this->board[j][k] = c7;
                }

            }
            mapp[7]=c7;
            counterr++;
        } else {
            int count4=0;
            for (int j = 6; j < 9; j++) {
                for (int k = 3; k < 6; k++) {
                    if(this->board[j][k]=='X' or this->board[j][k]=='O'){
                        count4++;
                    }
                }
            }
            if(count4==9){
                counterr++;
            }
            B7 = false;
        }
        return mapp;
    }
    return mapp;
}
template <typename T>
bool Ultimate_Tic_Tac_Toe_Board<T>::is_win() {
    cout<<counterr<<endl;
    if(mapp[0]==mapp[1] and mapp[1]==mapp[2] and mapp[0]!=0){
        iswin=1;
        return true;
    }
    if(mapp[0]==mapp[3] and mapp[3]==mapp[6] and mapp[0]!=0){
        iswin=1;
        return true;
    }
    1        ;if(mapp[0]==mapp[4] and mapp[4]==mapp[8] and mapp[0]!=0){
        iswin=1;
        return true;
    }
    if(mapp[3]==mapp[4] and mapp[4]==mapp[5] and mapp[3]!=0){
        iswin=1;
        return true;
    }
    if(mapp[1]==mapp[4] and mapp[4]==mapp[7] and mapp[1]!=0){
        iswin=1;
        return true;
    }
    if(mapp[6]==mapp[7] and mapp[7]==mapp[8] and mapp[6]!=0){
        iswin=1;
        return true;
    }
    if(mapp[2]==mapp[5] and mapp[5]==mapp[8] and mapp[2]!=0){
        iswin=1;
        return true;
    }
    if(mapp[2]==mapp[4] and mapp[4]==mapp[6] and mapp[2]!=0){
        iswin=1;
        return true;
    }
    return false;
}
// Check if the game has reached a draw
template <typename T>
bool Ultimate_Tic_Tac_Toe_Board<T>::is_draw() {
    return ((this->n_moves == 81 or counterr==9) and !is_win());
}

// Check if the game is over
template <typename T>
bool Ultimate_Tic_Tac_Toe_Board<T>::game_is_over() {
    if (this->n_moves >= 81) {
        if (is_draw()) {
            cout << "It's a draw!" << endl;
        }
        return true;
    }
    return false;
}



#endif //_ULTIMATE_TIC_TAC_TOE_H