#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Ship {
private:
    int size;
    int hits;
    string name;

public:
    Ship(string n, int s) : name(n), size(s), hits(0) {}

    bool isSunk() {
        return hits >= size;
    }
    
    void takeHit() { hits++; }
    int getSize() { return size; }
};

// GLOBAL BOARDS
shared_ptr<Ship> shipBoard[10][10]; // Pointers for actual ships
char guessBoard[10][10];            // Chars for your hits/misses

void initializeBoards() {
    for (int r = 0; r < 10; r++) {
        for (int c = 0; c < 10; c++) {
            shipBoard[r][c] = nullptr;
            guessBoard[r][c] = '-';
        }
    }
}

// DRAW FUNCTION
void drawBoard() {
    cout << "\n       MY SHIPS                       MY GUESSES" << endl;
    cout << "  0 1 2 3 4 5 6 7 8 9            0 1 2 3 4 5 6 7 8 9" << endl;

    for (int r = 0; r < 10; r++) {
        // LEFT BOARD
        cout << r << " ";
        for (int c = 0; c < 10; c++) {
            if (shipBoard[r][c] == nullptr) cout << "- ";
            else cout << "S ";
        }

        cout << "         "; // Spacer

        // RIGHT BOARD
        cout << r << " ";
        for (int c = 0; c < 10; c++) {
            cout << guessBoard[r][c] << " ";
        }
        cout << endl;
    }
}

// LOGIC FOR ATTACKING
void updateBoard(int r, int c) {
    if (r >= 0 && r < 10 && c >= 0 && c < 10) {
        if (shipBoard[r][c] != nullptr) {
            cout << "HIT!" << endl;
            guessBoard[r][c] = 'X';
            shipBoard[r][c]->takeHit();
        } else {
            cout << "MISS!" << endl;
            guessBoard[r][c] = 'M';
        }
    } else {
        cout << "Out of bounds!" << endl;
    }
}

int main() {
    initializeBoards();

    // Let's manually place a Destroyer for testing
    auto destroyer = make_shared<Ship>("Destroyer", 3);
    for(int i = 0; i < 3; i++) {
        shipBoard[2][2 + i] = destroyer; // Places at 2,2 2,3 2,4
    }

    drawBoard();

    int rowInput, colInput;
    cout << "\nEnter target (Row Col): ";
    cin >> rowInput >> colInput;

    updateBoard(rowInput, colInput);
    drawBoard();

    return 0;
}