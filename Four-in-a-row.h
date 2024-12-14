#ifndef FOUR_IN_A_ROW_H
#define _FOUR_IN_A_ROW_H
#include<bits/stdc++.h>
using namespace std;
#include "BoardGame_Classes.h"
template <typename T>
class Four_in_a_row_Board:public Board<T>{
public:
    Four_in_a_row_Board(){
        this->rows=6;
        this->columns=7;
        this->board = new char *[this->rows];
        for (int i = 0; i < this->rows; i++) {
            this->board[i] = new char[this->columns];
            for (int j = 0; j < this->columns; j++) {
                this->board[i][j] = 0;
            }
        }
        this->n_moves = 0;
    }
    bool update_board(int x , int y , char symbol){
        if (!( (y-1) < 0 || (y-1) >= this->columns)){
            if(symbol==0){
                this->n_moves--;
                this->board[x][y-1]=0;
            }
            else{
                for(int i=5;i>=0;i--){
                    if(this->board[i][y-1]==0){
                    this->n_moves++;
                    this->board[i][y-1] = toupper(symbol);
                        return true;
                    }
                }
            }
        }
        return false;
    }
    void display_board (){
        cout<<endl;
        string num="1234567";
        string border = "---------------------------------------";
        for(char ch:num) {
            cout <<" "<< setw(4)<<left << ch<<" ";
        }
        cout<<endl;
        cout << border << endl;

        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 7; j++) {
                if(this->board[i][j]==0) {
                    cout<<setw(2)<<right<<'-'<< " ";

                }
                else{
                    cout << setw(2)<<right<< this->board[i][j]<<" ";
                }
                if (j < 6) cout<< " | ";
            }
            cout << endl;
            if (i < 5) cout << border << endl;
        }

        cout << border << endl;
//        cout<<endl;
    }
    bool is_win() {
        // Check rows
        for (int i = 0; i < this->rows; i++) {
            if((this->board[i][0] == this->board[i][1] and this->board[i][1] == this->board[i][2] and
            this->board[i][2] == this->board[i][3] and this->board[i][0] != 0) or

            (this->board[i][1] == this->board[i][2] and this->board[i][2] == this->board[i][3] and
            this->board[i][3]== this->board[i][4] and this->board[i][1]!=0) or

            (this->board[i][2] == this->board[i][3] and this->board[i][3]== this->board[i][4]
            and this->board[i][4]==this->board[i][5] and this->board[i][2]!=0) or

            (this->board[i][3]== this->board[i][4] and this->board[i][4]==this->board[i][5] and
            this->board[i][5]==this->board[i][6] and this->board[i][3]!=0)){
                return true;
            }
        }
        // Check columns
        for (int i = 0; i < this->columns; i++) {
            if((this->board[0][i] == this->board[1][i] and this->board[1][i] == this->board[2][i] and
                this->board[2][i] == this->board[3][i] and this->board[0][i] != 0) or

               (this->board[1][i] == this->board[2][i] and this->board[2][i] == this->board[3][i] and
                this->board[3][i]== this->board[4][i] and this->board[1][i]!=0) or

               (this->board[2][i] == this->board[3][i] and this->board[3][i]== this->board[4][i]
                and this->board[4][i]==this->board[5][i] and this->board[2][i]!=0)){
                return true;
            }
        }
        //check the right diagonal
        for(int i=0;i<6;i++){
            for(int j=0;j<7;j++) {
                    if ( i+3<6 and j+3<7 and this->board[i][j] == this->board[i + 1][j + 1] and
                        this->board[i + 1][j + 1] == this->board[i + 2][j + 2] and
                        this->board[i + 2][j + 2] == this->board[i + 3][j + 3] and this->board[i][j] != 0) {
                        return true;
                    }

            }
        }
        // check the left diagonal
        for(int i=0;i<6;i++){
            for(int j=0;j<7;j++) {
                    if ( i+3<6 and j-3>=0 and this->board[i][j] == this->board[i + 1][j - 1] and
                        this->board[i + 1][j - 1] == this->board[i + 2][j - 2] and
                        this->board[i + 2][j - 2] == this->board[i + 3][j - 3] and this->board[i][j] != 0) {
                        return true;
                    }

            }
        }
        return false;

    }
    bool is_draw(){
        return (this->n_moves == 42 and !is_win());
    }
    bool game_is_over(){
        return is_win() or is_draw();
    }
};
template <typename T>
class Four_in_a_row_Player : public Player<T> {
public:
    Four_in_a_row_Player(string name, char symbol): Player<T>(name, symbol) {}
    void getmove(int& x, int& y){
        x=5;
        cout << "\nPlease Enter the column number you want(1,7) as shown in the upper of the board: ";
        cin >> y;
    }

};
template <typename T>
class Four_in_a_row_Random_Player : public RandomPlayer<T>{
public:
    Four_in_a_row_Random_Player(T symbol) : RandomPlayer<T>(symbol) {
        this->dimension=7;
        this->name = "Random Computer Player with symbol ";
        this->name+=symbol;
//        srand(static_cast<unsigned int>(time(0))); // Seed the random number generator
    }

    void getmove(int& x, int& y){
        x = rand() % this->dimension-1;  // Random number between 0 and 2
        y = rand() % this->dimension;
    }
};


#endif
