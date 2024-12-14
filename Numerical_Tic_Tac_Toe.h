#ifndef _NUMERICAL_TIC_TAC_TOE_H
#define _NUMERICAL_TIC_TAC_TOE_H

#include "BoardGame_Classes.h"
#include<bits/stdc++.h>
using namespace std;
int count1=0;
int israndom=0,ishuman=0;
template <typename T>
class  Numerical_Tic_Tac_Toe_Board:public Board<T> {
public:
    vector<int>Numbers={1,2,3,4,5,6,7,8,9};
    void print_numbers(){
        cout<<"The Numbers available are:";
        cout<<" {";
        for(int i=0;i<Numbers.size();i++){
            if(i!=Numbers.size()-1) {
                cout << Numbers[i] << ",";
            }
            else{
                cout<<Numbers[i];
            }
        }
        cout<<"}\n";
    }
    Numerical_Tic_Tac_Toe_Board(){
        this->rows = this->columns = 3;
        this->board = new int*[this->rows];
        for (int i = 0; i < this->rows; i++) {
            this->board[i] = new int[this->columns];
            for (int j = 0; j < this->columns; j++) {
                this->board[i][j] = 0;
            }
        }
        this->n_moves = 0;
    }
    int getnum() {
        int s;
        if (ishuman) {
            if (this->n_moves % 2 == 0) {
                while (true) {
                    cout << "Please input an odd number from 1 to 9:";
                    cin >> s;
                    if (s % 2 == 0 or s > 9) {
                        continue;
                    } else {
                        break;
                    }
                }
            } else {
                while (true) {
                    cout << "Please input an even number from 1 to 9:";
                    cin >> s;
                    if (s % 2 == 1 or s > 9) {
                        continue;
                    } else {
                        break;
                    }
                }
            }
            ishuman=0;
            Numbers.erase(remove(Numbers.begin(), Numbers.end(), s), Numbers.end());
            return s;
        }
        if(israndom) {
            vector<int> valid_Numbers;
            for (int num : Numbers) {
                if (this->n_moves % 2 == 1 && num % 2 == 0) {
                    valid_Numbers.push_back(num);
                } else if (this->n_moves % 2 == 0 && num % 2 != 0) {
                    valid_Numbers.push_back(num);
                }
            }

            if (!valid_Numbers.empty()) {
                int randomIndex = rand() % valid_Numbers.size();
                s = valid_Numbers[randomIndex];
            } else {
                cout << " No valid numbers available" << endl;
            }
            israndom=0;
            Numbers.erase(remove(Numbers.begin(), Numbers.end(), s), Numbers.end());
            return s;
        }



    }
    bool update_board (int x , int y , int symbol=0){
        if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && (this->board[x][y] == 0)) {
            symbol = getnum();
                this->n_moves++;
                this->board[x][y] = symbol;
                return true;

        }
        return false;
    }
    void display_board (){
        for (int i = 0; i < this->rows; i++) {
            cout << "\n|";
            for (int j = 0; j < this->columns; j++) {
                if (this->board[i][j]==0) {
                    cout <<" "<<i<<","<<j<<" |";
                } else {
                    cout << setw(3) << this->board[i][j] << "  |";
                }
            }
            cout << "\n-------------------";
        }
        cout << endl;
        print_numbers();
    }
    bool is_win(){
        for (int i = 0; i < this->rows; i++) {
            if ((this->board[i][0] + this->board[i][1] + this->board[i][2] == 15 and this->board[i][0]!=0 and
                this->board[i][1]!=0 and this->board[i][2]!=0) or
                (this->board[0][i] + this->board[1][i] + this->board[2][i] == 15 and this->board[0][i]!=0 and
                this->board[1][i]!=0 and this->board[2][i]!=0)) {
                return true;
            }
        }

        if ((this->board[0][0] + this->board[1][1] + this->board[2][2] == 15 and this->board[0][0]!=0 and
            this->board[1][1]!=0 and this->board[2][2]!=0) or
            (this->board[0][2] + this->board[1][1] + this->board[2][0] == 15 and this->board[0][2]!=0 and
            this->board[1][1]!=0 and this->board[2][0]!=0)) {
            return true;
        }

        return false;
    }
    bool is_draw(){
        return (this->n_moves == 9 && !is_win());
    }
    bool game_is_over() {
        return is_win() || is_draw();
    }

};

template <typename T>
class Numerical_Tic_Tac_Toe_Player: public Player<T> {
public:
    Numerical_Tic_Tac_Toe_Player(string name, int symbol): Player<T>(name, symbol) {


    }
    void getmove(int& x, int& y){
        ishuman=1;
        cout << "\nPlease enter your move x and y (0 to 2) separated by spaces in an empty cell: ";
        cin >> x >> y;
    }

};

template <typename T>
class Numerical_Tic_Tac_Toe_Random_Player : public RandomPlayer<T>{
public:
    Numerical_Tic_Tac_Toe_Random_Player(T symbol): RandomPlayer<T>(symbol) {
        count1++;
        this->name = "Random Computer Player with ";
        if(count1==1){
            this->name+="odd Numbers moves";
        }
        else{
            this->name+="even Numbers moves";
        }

        srand(static_cast<unsigned int>(time(0)));
    }
    void getmove(int &x, int &y){
        israndom=1;
        x = rand() % 3;
        y = rand()% 3;
    }
};

#endif


