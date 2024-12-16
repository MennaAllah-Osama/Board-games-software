#include <iostream>
#include "Four-in-a-row.h"
#include "5x5_Tic_Tac_Toe.h"
#include "Numerical_Tic_Tac_Toe.h"
#include "_4x4_Tic_Tac_Toe.h"
#include "Ultimate_Tic_Tac_Toe.h"
#include "PYRAMID_TICTACTOE.h"
#include "WORD_TIC_TAC_TOE.h"
#include "3x3_Misere_Tic_Tac_Toe.h"
string player_name1, player_name2;
string player_n1, player_n2;
void Pyramid_Tic_Tac_Toe(){
        int choice;
        Player<char> *players[2];
        Pyramid_Board<char> *board = new Pyramid_Board<char>();
        string player1_Name, player2_Name;
        while (true) {
            cout << "Welcome to Pyramid Tic-Tac-Toe Game!\n";
            cout << "Choose Player1 Type:\n";
            cout << "1. Human\n";
            cout << "2. Random Player\n";
            cout << "Your Choice:";
            cin >> choice;

            if (choice == 1) {
                cout << "Enter Player1 name:";
                cin >> player1_Name;
                players[0] = new Pyramid_Player<char>(player1_Name,'X');;

                break;
            } else if (choice == 2) {
                players[0] = new Pyramid_Random_Player<char>('O');
                break;
            } else {
                cout << "Invalid choice for Player1. please enter a valid one\n";
                continue;
            }
        }
        while (true) {
            cout << "Choose Player2 Type:\n";
            cout << "1. Human\n";
            cout << "2. Random Player\n";
            cout << "Your Choice:";
            cin >> choice;

            if (choice == 1) {
                cout << "Enter Player2 name: ";
                cin >> player2_Name;
                players[1] = new Pyramid_Player<char>(player1_Name, 'X');
                break;
            } else if (choice == 2) {
                players[1] = new Pyramid_Random_Player<char>( 'O');
                break;
            } else {
                cout << "Invalid choice for Player2.please enter a valid one\n";
                continue;
            }
        }
        GameManager<char> gameManager(board, players);
        gameManager.run();
        delete board;
        for (int i = 0; i < 2; ++i) {
            delete players[i];
        }
}
void Four_in_a_row(){
    int choice;
    Player<char> *players[2];
    Four_in_a_row_Board<char> *Game_2 = new Four_in_a_row_Board<char>();
    string player1_Name, player2_Name;
    while (true) {
        cout << "Welcome to Four_in_a_Row Game.^_^\n<--Menu-->\n";
        cout << "Choose Player 1 Type:\n";
        cout << "1. Human\n";
        cout << "2. Random Player\n";
        cout << "Your Choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter Player 1 name: ";
            cin >> player1_Name;
            players[0] = new Four_in_a_row_Player<char>(player1_Name, 'X');
            break;
        } else if (choice == 2) {
            cout << "Enter Random Player 1 Symbol: ";
            players[0] = new Four_in_a_row_Random_Player<char>('X');
            break;

        } else {
            cout << "Invalid choice for Player 1. Please enter a valid one\n";
            continue;
        }
    }

    while (true) {
        cout << "Choose Player2 Type:\n";
        cout << "1. Human\n";
        cout << "2. Random Player\n";
        cout<<"Your Choice:";
        cin >> choice;
        if (choice == 1) {
            cout << "Enter Player 2 name: ";
            cin >> player2_Name;
            cout << "Enter Player 2 Symbol: ";
            players[1] = new Four_in_a_row_Player<char>(player2_Name, 'O');
            break;
        } else if (choice == 2) {
            cout << "Enter Random Player 2 Symbol: ";
            players[1] = new Four_in_a_row_Random_Player<char>('O');
            break;
        } else {
            cout << "Invalid choice for Player 2.Please enter a valid one.\n";
            continue;
        }
    }
    GameManager<char> Four_in_a_row(Game_2, players);
    Four_in_a_row.run();
    delete Game_2;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }
}
void _5X5_Tic_Tac_Toe(){
        int choice;
        Player<char>* players[2];
        tic_Board<char>* B = new tic_Board<char>();

        cout << "Welcome to FCAI 5x5_tic_tac_toe Game. :)\n";

        // Set up player 1
        cout << "Enter Player X name: ";
        cin >> player_name1;

        // Use a while loop for Player 1 choice
        bool validChoice1 = false;
        while (!validChoice1) {
            cout << "Choose Player X type:\n";
            cout << "1. Human\n";
            cout << "2. Random Computer\n";
            cin >> choice;

            if (choice == 1) {
                players[0] = new tic_Player<char>(player_name1, 'X');
                validChoice1 = true;
            } else if (choice == 2) {
                players[0] = new tic_Random_Player<char>('X');
                validChoice1 = true;
            } else {
                cout << "Invalid choice for Player 1. Please choose again.\n";
            }
        }

        // Set up player 2
        cout << "Enter Player 2 name: ";
        cin >> player_name2;

        // Use a while loop for Player 2 choice
        bool validChoice2 = false;
        while (!validChoice2) {
            cout << "Choose Player 2 type:\n";
            cout << "1. Human\n";
            cout << "2. Random Computer\n";
            cin >> choice;

            if (choice == 1) {
                players[1] = new tic_Player<char>(player_name2, 'O');
                validChoice2 = true;
            } else if (choice == 2) {
                players[1] = new tic_Random_Player<char>('O');
                validChoice2 = true;
            } else {
                cout << "Invalid choice for Player 2. Please choose again.\n";
            }
        }

        // Create the game manager and run the game
        GameManager<char> tic_game(B, players);
        tic_game.run();

        delete B;
        for (int i = 0; i < 2; ++i) {
            delete players[i];
        }

}
void Word_Tic_Tac_Toe(){
        int choice;
        Player<char> *players[2];
        Word_Board<char> *board = new Word_Board<char>();
        string player1_Name, player2_Name;
        while (true) {
            cout << "Welcome to Word Tic-Tac-Toe Game!\n";
            cout << "Choose Player1 Type:\n";
            cout << "1. Human\n";
            cout << "2. Random Player\n";
            cout << "Your Choice:";
            cin >> choice;

            if (choice == 1) {
                cout << "Enter Player1 name:";
                cin >> player1_Name;
                players[0] = new Word_Player<char>(player1_Name,0);;
                player1_human= true;
                break;
            }
            else if (choice == 2) {
                players[0] = new Word_Random_Player<char>(0);
                player1_human= false;
                break;
            } else {
                cout << "Invalid choice for Player1. please enter a valid one\n";
                continue;
            }
        }
        while (true) {
            cout << "Choose Player2 Type:\n";
            cout << "1. Human\n";
            cout << "2. Random Player\n";
            cout << "Your Choice:";
            cin >> choice;

            if (choice == 1) {
                cout << "Enter Player2 name: ";
                cin >> player2_Name;
                players[1] = new Word_Player<char>(player1_Name,  0);
                player2_human= true;
                break;
            } else if (choice == 2) {
                players[1] = new Word_Random_Player<char>(0);
                player2_human= false;

                break;
            } else {
                cout << "Invalid choice for Player2.please enter a valid one\n";
                continue;
            }
        }
        GameManager<char> gameManager(board, players);
        gameManager.run();
        delete board;
        for (int i = 0; i < 2; ++i) {
            delete players[i];
        }
}
void Numerical_Tic_Tac_Toe(){
    int choice;
    Player<int> *players[2];
    Numerical_Tic_Tac_Toe_Board<int> *Game_5 = new Numerical_Tic_Tac_Toe_Board<int>();
    string player1_Name, player2_Name;
    while (true) {
        cout << "Welcome to Numerical_Tic_Tac_Toe Game.^_^\n<--Menu-->\n";
        cout << "Choose Player1 Type:\n";
        cout << "1. Human\n";
        cout << "2. Random Player\n";
        cout << "Your Choice:";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter Player1 name:";
            cin >> player1_Name;
            players[0] = new Numerical_Tic_Tac_Toe_Player<int>(player1_Name, 0);

            break;
        } else if (choice == 2) {
            players[0] = new Numerical_Tic_Tac_Toe_Random_Player<int>(0);
            break;
        } else {
            cout << "Invalid choice for Player1. please enter a valid one\n";
            continue;
        }
    }
    while (true) {
        cout << "Choose Player2 Type:\n";
        cout << "1. Human\n";
        cout << "2. Random Player\n";
        cout << "Your Choice:";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter Player2 name: ";
            cin >> player2_Name;
            players[1] = new Numerical_Tic_Tac_Toe_Player<int>(player2_Name, 0);
            break;
        } else if (choice == 2) {
            players[1] = new Numerical_Tic_Tac_Toe_Random_Player<int>(0);
            break;
        } else {
            cout << "Invalid choice for Player2.please enter a valid one\n";
            continue;
        }
    }
    GameManager<int> Numerical_Tic_Tac_Toe(Game_5, players);
    Numerical_Tic_Tac_Toe.run();

    delete Game_5;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }

}
void _3X3_Misere_Tic_Tac_Toe() {
    int choice;
    Player<char> *players[2];
    Misere_tic_tac_toe_Board<char> *B = new Misere_tic_tac_toe_Board<char>();

    cout << "Welcome to FCAI 3x3_Misere_Tic_Tac_Toe Game. :)\n";

    // Player X setup
    cout << "Enter Player X name: ";
    cin >> player_n1;
    while (true) {
        cout << "Choose Player X type:\n";
        cout << "1. Human\n";
        cout << "2. Random Computer\n";
        cout << "3. Smart Computer (AI)\n";
        cin >> choice;

        if (choice == 1) {
            players[0] = new Misere_tic_tac_toe_Player<char>(player_n1, 'X');
            break;
        } else if (choice == 2) {
            players[0] = new Misere_tic_tac_toe_Random_Player<char>('X');
            break;
        } else {
            cout << "Invalid choice for Player X. Please try again.\n";
        }
    }

    // Player O setup
    cout << "Enter Player O name: ";
    cin >> player_n2;
    while (true) {
        cout << "Choose Player O type:\n";
        cout << "1. Human\n";
        cout << "2. Random Computer\n";
        cout << "3. Smart Computer (AI)\n";
        cin >> choice;

        if (choice == 1) {
            players[1] = new Misere_tic_tac_toe_Player<char>(player_n2, 'O');
            break;
        } else if (choice == 2) {
            players[1] = new Misere_tic_tac_toe_Random_Player<char>('O');
            break;
        } else {
            cout << "Invalid choice for Player O. Please try again.\n";
        }
    }

    // Start the game
    GameManager<char> tic_tac_toe_game(B, players);
    tic_tac_toe_game.run();

    // Clean up
    delete B;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }

}
void _4x4_Tic_Tac_Toe(){
    int choice;
    Player<char> *players[2];
    _4x4_Tic_Tac_Toe_Board<char>*Game_7=new _4x4_Tic_Tac_Toe_Board<char>();
    string player1_Name, player2_Name;
    cout << "Welcome to 4x4 Tic-Tac-Toe Game!\n";
    while (true) {
        cout << "Choose Player 1 Type:\n";
        cout << "1. Human\n";
        cout << "2. Random Player\n";
        cout << "Your Choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter Player 1 name: ";
            cin >> player1_Name;
            players[0] = new _4x4_Tic_Tac_Toe_Player<char>(player1_Name, 'x');
            break;
        } else if (choice == 2) {
            players[0] = new _4x4_Tic_Tac_Toe_Random_Player<char>('x');
            break;

        } else {
            cout << "Invalid choice for Player 1. Please enter a valid one\n";
            continue;
        }
    }

    while (true) {
        cout << "Choose Player2 Type:\n";
        cout << "1. Human\n";
        cout << "2. Random Player\n";
        cout<<"Your Choice:";
        cin >> choice;
        if (choice == 1) {
            cout << "Enter Player 2 name: ";
            cin >> player2_Name;
            players[1] = new _4x4_Tic_Tac_Toe_Player<char>(player2_Name,'o');
            break;
        } else if (choice == 2) {
            players[1] = new _4x4_Tic_Tac_Toe_Random_Player<char>('o');
            break;
        } else {
            cout << "Invalid choice for Player 2.Please enter a valid one.\n";
            continue;
        }
    }
    GameManager<char> _4x4_Tic_Tac_Toe(Game_7, players);
    _4x4_Tic_Tac_Toe.run();
    delete Game_7;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }
}
void Ultimate_Tic_Tac_Toe(){
        int choice;
        Player<char> *players[2];
        Ultimate_Tic_Tac_Toe_Board<char> *board = new Ultimate_Tic_Tac_Toe_Board<char>();
        string player1_Name, player2_Name;
        cout << "Welcome to Ultimate Tic-Tac-Toe Game!\n";
        while (true) {
            cout << "Choose Player1 Type:\n";
            cout << "1. Human\n";
            cout << "2. Random Player\n";
            cout << "Your Choice:";
            cin >> choice;

            if (choice == 1) {
                cout << "Enter Player1 name:";
                cin >> player1_Name;
                players[0] = new Ultimate_Tic_Tac_Toe_Player<char>(player1_Name,'X');;
                break;
            }
            else if (choice == 2) {
                players[0] = new Ultimate_Tic_Tac_Toe_Random_Player<char>('X');
                break;
            } else {
                cout << "Invalid choice for Player1. please enter a valid one\n";
                continue;
            }
        }
        while (true) {
            cout << "Choose Player2 Type:\n";
            cout << "1. Human\n";
            cout << "2. Random Player\n";
            cout << "Your Choice:";
            cin >> choice;

            if (choice == 1) {
                cout << "Enter Player2 name: ";
                cin >> player2_Name;
                players[1] = new Ultimate_Tic_Tac_Toe_Player<char>(player1_Name,'O');

                break;
            }
            else if (choice == 2) {
                players[1] = new Ultimate_Tic_Tac_Toe_Random_Player<char>('O');

                break;
            } else {
                cout << "Invalid choice for Player2.please enter a valid one\n";
                continue;
            }
        }
        GameManager<char> gameManager(board, players);
        gameManager.run();
        delete board;
        for (int i = 0; i < 2; ++i) {
            delete players[i];
        }
}
int main() {
    char choice;
    while(true) {
        cout << "**************************************\n<-Welcome to our program for playing 8 Different Games->\n"
                "<-- Menu -->\n1- Pyramid_Tic_Tac_Toe\n2- Four_in_a_row \n3- 5X5_Tic_Tac_Toe\n4- Word_Tic_Tac_Toe\n"
                "5- Numerical_Tic_Tac_Toe\n6- 3X3_Misere_Tic_Tac_Toe\n7- 4x4_Tic_Tac_Toe\n8- Ultimate_Tic_Tac_Toe\n"
                "9- Exit\nYour choice:";
        cin >> choice;
        if (choice == '1') {
            Pyramid_Tic_Tac_Toe();
            continue;
        } else if (choice == '2') {
            Four_in_a_row();
            continue;
        }
        else if (choice == '3') {
            _5X5_Tic_Tac_Toe();
            continue;
        }
        else if (choice == '4') {
            Word_Tic_Tac_Toe();
            continue;
        }
        else if (choice == '5') {
            Numerical_Tic_Tac_Toe();
            continue;
        }
        else if (choice == '6') {
            _3X3_Misere_Tic_Tac_Toe();
            continue;
        }
        else if (choice == '7') {
            _4x4_Tic_Tac_Toe();
            continue;
        }
        else if (choice == '8') {
            Ultimate_Tic_Tac_Toe();
            continue;
        }
        else if (choice == '9') {
            cout<<"Thank you for using this program\n";
            break;
        }
        else{
            cout<<"Invalid,please enter a valid choice\n";
            continue;
        }
    }
    return 0;
}
