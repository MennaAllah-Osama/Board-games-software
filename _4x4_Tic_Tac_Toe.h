#ifndef _4_X_4_TIC_TAC_TOE_H
#define _4_X_4_TIC_TAC_TOE_H
#include "BoardGame_Classes.h"
#include<bits/stdc++.h>
using namespace std;
bool player1= false;
bool player2=false;
int counter=0;
bool israndomm=false;
template <typename T>
class _4x4_Tic_Tac_Toe_Board:public Board<T> {
public:
    _4x4_Tic_Tac_Toe_Board(){
        this->rows = this->columns = 4;
        this->board = new char*[this->rows];
        for (int i = 0; i < this->rows; i++) {
            this->board[i] = new char[this->columns];
            for (int j = 0; j < this->columns; j++) {
                this->board[i][j] = 0;


            }
        }
        for(int j=0;j<this->columns;j++) {
            if (j == 0 or j == 2) {
                this->board[0][j] = 'O';
                this->board[3][j] = 'X';
            } else if (j == 1 or j == 3) {
                this->board[3][j] = 'O';
                this->board[0][j] = 'X';
            }
        }
        this->n_moves = 0;
    }
    string get_index(){
        int x,y;
        string movex,movey,move;
        if(player1 and !israndomm){
            while(true){
                cout<<"Please enter x and y  for the X you want to move separated by spaces,"
                      " Note that you should choose a cell that have X symbol only:";
                cin>>x>>y;
                if(x<0 or x>3 or y<0 or y>3 or this->board[x][y]== toupper('O') or this->board[x][y]==0){
                    continue;
                }
                else if(!( (x!=0 and this->board[x-1][y]==0) or (x!=3 and this->board[x+1][y]==0) or (y !=3 and this->board[x][y+1]==0) or
                           (y!=0 and this->board[x][y-1]==0))){
                    cout<<"Invalid,that cell can not be moved try another one\n";
                    continue;
                }
                else{
                    movex= to_string(x);
                    movey= to_string(y);
                    move=movex+movey;
                    break;
                }

            }
            return move;
        }
        else if(player2 and !israndomm){
            while(true){
                cout<<"Please enter x and y for the O you want to move separated by spaces,"
                      " Note that you should choose a cell that have O symbol only:";
                cin>>x>>y;
                if(x<0 or x>3 or y<0 or y>3 or this->board[x][y]== toupper('X') or this->board[x][y]==0){
                    continue;
                }
                else if(!( (x!=0 and this->board[x-1][y]==0) or (x!=3 and this->board[x+1][y]==0) or (y !=3 and this->board[x][y+1]==0) or
                           (y!=0 and this->board[x][y-1]==0))){
                    cout<<"Invalid,that cell can not be moved try another one\n";
                    continue;
                }
                else{
                    movex= to_string(x);
                    movey= to_string(y);
                    move=movex+movey;
                    break;
                }

            }
            return move;
        }
        else if(israndomm and player1){
            while(true){
                x = rand() % 4;
                y = rand() % 4;
                if(x<0 or x>3 or y<0 or y>3 or this->board[x][y]== toupper('O') or this->board[x][y]==0){
                    continue;
                }
                else if(!( (x!=0 and this->board[x-1][y]==0) or (x!=3 and this->board[x+1][y]==0) or (y !=3 and this->board[x][y+1]==0) or
                           (y!=0 and this->board[x][y-1]==0))){
                    continue;
                }
                else{
                    movex= to_string(x);
                    movey= to_string(y);
                    move=movex+movey;
                    break;
                }

            }
            israndomm=false;
            return move;

        }
        else if(israndomm and player2){
            while(true){
                x = rand() % 4;
                y = rand() % 4;
                if(x<0 or x>3 or y<0 or y>3 or this->board[x][y]== toupper('X') or this->board[x][y]==0){
                    continue;
                }
                else if(!( (x!=0 and this->board[x-1][y]==0) or (x!=3 and this->board[x+1][y]==0) or (y !=3 and this->board[x][y+1]==0) or
                           (y!=0 and this->board[x][y-1]==0))){
                    continue;
                }
                else{
                    movex= to_string(x);
                    movey= to_string(y);
                    move=movex+movey;
                    break;
                }


            }
            israndomm=false;
            return move;

        }
    }
    bool update_board(int x , int y , char symbol){
        if(toupper(symbol)=='X'){
            player1= true;
            player2= false;
        }
        else {
            player2 = true;
            player1 = false;
        }
        string movex, movey;
        int move_x, move_y;
        if(counter==1 and !(x < 0 or x >= this->rows or y < 0 or y >= this->columns) and (this->board[x][y] == 0 or symbol == 0)) {
            string move = get_index();
            movex.push_back(move[0]);
            movey.push_back(move[1]);
            move_x = stoi(movex);
            move_y = stoi(movey);
        }
        if (!(x < 0 or x >= this->rows or y < 0 or y >= this->columns) and (this->board[x][y] == 0 or symbol == 0)) {
            if((y!=move_y and (x!=move_x+1  or x!=move_x-1)) and (x!=move_x and (y!=move_y+1 or y!=move_y-1))){
                return false;
            }
            if((y==move_y and (x==move_x+2  or x==move_x-2)) or (x==move_x and (y==move_y+2 or y==move_y-2))){
                return false;
            }
            if((y==move_y and (x==move_x+3  or x==move_x-3)) or (x==move_x and (y==move_y+3 or y==move_y-3))){
                return false;
            }
            this->n_moves++;
            this->board[x][y] = toupper(symbol);
            this->board[move_x][move_y]=0;
            counter=0;
            return true;
        }
        counter=0;
        return false;
    }
    void display_board (){
        for (int i = 0; i < this->rows; i++) {
            cout << "\n| ";
            for (int j = 0; j < this->columns; j++) {
                cout << "(" << i << "," << j << ")";
                cout << setw(2) << this->board[i][j] << "  |";
            }
            cout << "\n------------------------------------------";
        }
        cout << endl;
    }
    bool is_win(){
        for (int i = 0; i < this->rows; i++) {
            if (this->board[i][0] != 0 && this->board[i][0] == this->board[i][1] &&
                this->board[i][1] == this->board[i][2]) {
                return true;
            }
        }

        for (int i = 0; i < this->columns; i++) {
            if (this->board[0][i] != 0 && this->board[0][i] == this->board[1][i] &&
                this->board[1][i] == this->board[2][i]) {
                return true;
            }
        }
        if (this->board[0][0] != 0 && this->board[0][0] == this->board[1][1] &&
            this->board[1][1] == this->board[2][2]) {
            return true;
        }
        if (this->board[0][3] != 0 && this->board[0][3] == this->board[1][2] &&
            this->board[1][2] == this->board[2][1]) {
            return true;
        }
        return false;
    }
    bool is_draw(){
        return false;
    }
    bool game_is_over(){
        return is_win() || is_draw();
    }
};

template <typename T>
class _4x4_Tic_Tac_Toe_Player : public Player<T> {
public:
    _4x4_Tic_Tac_Toe_Player (string name, T symbol): Player<T>(name, symbol) {}
    void getmove(int& x, int& y){
        cout << "\nPlease enter your wanted move x and y  separated by spaces: ";
        cin >> x >> y;
        counter=1;
    }

};

template <typename T>
class _4x4_Tic_Tac_Toe_Random_Player : public RandomPlayer<T>{
public:
    _4x4_Tic_Tac_Toe_Random_Player (T symbol): RandomPlayer<T>(symbol){
        this->dimension = 4;
        this->name = "Random Computer Player ";
        this->name+=symbol;
        srand(static_cast<unsigned int>(time(0)));
    }
    void getmove(int &x, int &y){
        x = rand() % this->dimension;  // Random number between 0 and 2
        y = rand() % this->dimension;
        israndomm= true;
        counter=1;
    }
};
#endif //_4_X_4_TIC_TAC_TOE_H