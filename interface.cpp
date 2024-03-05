#include <iostream>
#include "./board.cpp"
#include "./move/move.cpp"
#include "./piece/piece.cpp"

using namespace std;

Board b;

void printBoard() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << b.getPiece(i, j)->getSymbol() << " ";
        }
        cout << endl;
    }
}

int main() {
    b.toDefaultBoard();
    printBoard();
    Move m = *new Move("a2 a4");
    b.PerformMove(m);
    return 0;
}