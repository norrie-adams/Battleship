
#include <iostream>
using namespace std;

void drawBoard() {
    char board[10][10]; 
    
    for (int row = 0; row < 10; row++) {
        for (int col = 0; col < 10; col++) {
            board[row][col] = '-';
        }
    }

    cout << "  "; 
    for (int col = 0; col < 10; col++) {
        cout << col << " ";
    }
    cout << endl;

    for (int row = 0; row < 10; row++) {
        cout << row << " "; 

        for (int col = 0; col < 10; col++) {
            cout << board[row][col] << " ";
        }
        cout << endl; 
    }
}

int main() {
    drawBoard();
    return 0;
}