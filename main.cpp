#include <iostream>
#include <vector>
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
    string getName() { return name; }
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

    vector<shared_ptr<Ship>> myFleet;

    myFleet.push_back(make_shared<Ship>("Carrier", 5));
    myFleet.push_back(make_shared<Ship>("Battleship", 4));
    myFleet.push_back(make_shared<Ship>("Cruiser", 3));
    myFleet.push_back(make_shared<Ship>("Submarine", 3));
    myFleet.push_back(make_shared<Ship>("Destroyer", 2));

    for (auto& ship : myFleet) {
    bool placed = false;
    while (!placed) {
        drawBoard();
        int r, c;
        char orient;
        cout << "\nPlacing " << ship->getName() << " (Size " << ship->getSize() << ")" << endl;
        cout << "Enter Row and Col: ";
        cin >> r >> c;
        cout << "Horizontal or Vertical? (h/v): ";
        cin >> orient;

        bool horizontal = (orient == 'h');
        int s = ship->getSize();

        bool fits = true;
        if (horizontal) {
            if (r < 0 || r >= 10 || c < 0 || (c + s) > 10) fits = false;
        } else {
            if (r < 0 || (r + s) > 10 || c < 0 || c >= 10) fits = false;
        }

        if (!fits) {
            cout << "ERROR: Ship goes off the board. Try again." << endl;
        } else {
            for (int i = 0; i < s; i++) {
                if (horizontal) shipBoard[r][c + i] = ship;
                else shipBoard[r + i][c] = ship;
            }
            placed = true; // Exit the while loop
        }
    }
}

    int rowInput, colInput;
    cout << "\nEnter target (Row Col): ";
    cin >> rowInput >> colInput;

    updateBoard(rowInput, colInput);
    drawBoard();

    return 0;
}