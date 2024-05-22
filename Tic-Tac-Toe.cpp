#include<bits/stdc++.h>

using namespace std;

// Function to display the current game Grid
void displayBoard(const vector<char>& board) {

    for (int i = 0; i < 3; i++) {
        cout << " " << board[i] << " |";
    }
    cout << endl;
    cout << " ---+---+---" << endl;

    for (int i = 3; i < 6; i++) {
        cout << " " << board[i] << " |";
    }
    cout << endl;
    cout << " ---+---+---" << endl;

    for (int i = 6; i < 9; i++) {
        cout << " " << board[i] << " |";
    }
    cout << endl;
   
}
// derived from chatgpt
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Function to check if a player has won
bool checkWin(const vector<char>& board, char player) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i] == player && board[i + 3] == player && board[i + 6] == player) {
            return true;
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[i] == player && board[i + 3] == player && board[i + 6] == player) {
            return true;
        }
    }

    // Check diagonals
    if (board[0] == player && board[4] == player && board[8] == player) {
        return true;
    }
    if (board[2] == player && board[4] == player && board[6] == player) {
        return true;
    }

    return false;
}

// Function to check if the game is a draw
bool isDraw(const vector<char>& board) {
    for (char cell : board) {
        if (cell == ' ') {
            return false;
        }
    }
    return true;
}

int main() {
    vector<char> board(9, ' '); 
    cout<<" INSTRUCTIONS:"<<endl;
    cout<<" 1: Please enter the valid inputs which are positions from 1-9 "<< endl;
    cout<<" 2: Choose you strategy wisely "<< endl;

    char currentPlayer = 'X'; // Always Player X starts the game
    int moves = 0;

    while (true) {
        clearScreen(); // to clear the screen every time play input something
        displayBoard(board);

        int choice;
        cout << currentPlayer << endl << "'s TURN, enter a postion from (1-9): ";
        cin >> choice;

        // Validating  input from 1-9 position only 
        if (choice < 1 || choice > 9 || board[choice - 1] != ' ') {
            cout << "Invalid input. Please try again." << endl;
            continue;
        }

        board[choice - 1] = currentPlayer; // Place the move

        moves++;

        // Checking  for winner or draw
        if (checkWin(board, currentPlayer)) {
            clearScreen();
            displayBoard(board);
            cout <<endl << " "<<currentPlayer << " Player Won the Game" << endl;
            break;
        }

        if (isDraw(board)) {
            clearScreen();
            displayBoard(board);
            cout<< endl<< " The game is a draw." <<endl;
            break;
        }

        // Switch player turns
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
cout << " Thank you for playing . Please Visit Again\n" << endl;

    return 0;
}
