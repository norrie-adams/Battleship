#include <iostream>
using namespace std;

class Board {
private:
    char grid[10][10];

public:
    // FIX 1: Added a Constructor to initialize the grid with '-'
    Board() {
        for(int r = 0; r < 10; r++) {
            for(int c = 0; c < 10; c++) {
                grid[r][c] = '-';
            }
        }
    }

    void display() {
        cout << "  "; 
        for (int col = 0; col < 10; col++) {
            cout << col << " ";
        }
        cout << endl;

        for (int row = 0; row < 10; row++) {
            char rowLabel = 'A' + row; 
            cout << rowLabel << " "; 

            for (int column = 0; column < 10; column++) {
                cout << grid[row][column] << " ";
            }
            cout << endl;
        }
    } // FIX 2: Added missing closing brace for display()

    void updateBoard (char row, int column) {
        grid[row-'A'][column] = 'X';
    }
}; // FIX 2: Added missing closing brace/semicolon for the class

struct Coordinate {
    int x;
    int y;

    bool operator==(const Coordinate& other) const {
        return (x == other.x && y == other.y);
    }
};

class Ship {
private:
    int health;
    int length;

public:
    Ship(int len) : length(len), health(len) {}

    void takeDamage() {
        if (health > 0) health--;
    }
    
    bool isSunk() const {
        return health <= 0;
    }

    void attackShip(char row, int column) {
        cout << row - 'A' << endl;
        cout << column << endl;
    }
};

int main() {
    Board gameBoard;
    gameBoard.display();

    char row;
    int column;

    cout << "Enter a coordinate pair (i.e. A5)" << endl;
    cin >> row >> column;  
    
    gameBoard.updateBoard(row, column);
    gameBoard.display();

    

    //Ship destroyer(3);

    //destroyer.attackShip(letter, number);
    

    return 0;
}