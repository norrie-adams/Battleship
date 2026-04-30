#include <iostream>
using namespace std;

char board[10][10]; 

void initializeBoard() {
    for (int row = 0; row < 10; row++) {
        for (int col = 0; col < 10; col++) {
            board[row][col] = '-';
        }
    }
}

void drawBoard() {
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

void updateBoard(int r, int c) {
    if (r >= 0 && r < 10 && c >= 0 && c < 10) {
        board[r][c] = 'X'; 
    } else {
        cout << "Out of bounds!" << endl;
    }
}

int main() {
    initializeBoard(); 
    drawBoard();

    int rowInput;
    int colInput;

    cout << "Enter a coordinate pair (Row and Col separated by space. Ex: 4 5): " << endl;
    cin >> rowInput >> colInput;

    updateBoard(rowInput, colInput);
    drawBoard(); 

    return 0;
}