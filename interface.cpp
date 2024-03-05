#include <iostream>
#include "./board.cpp"
#include "./move/move.cpp"
#include "./piece/piece.cpp"
#include "./move/moveChecker.cpp"

using namespace std;

Board b;

void printBoard() {
    cout << endl;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << b.getPiece(i, j)->getSymbol() << " ";
        }
        cout << endl;
    }

    cout << endl;
}

void oneRound() {
    string moveWhite, moveBlack;
    cout << "White's move: ";
    cin >> moveWhite;
    Move m = *new Move(moveWhite);
    bool isCorrect = MoveChecker::isValidMove(b, m);

    while (!isCorrect) {
        cout << "Invalid move. Try again: ";
        cin >> moveWhite;
        m = *new Move(moveWhite);
        isCorrect = MoveChecker::isValidMove(b, m);
    }
    
    b.PerformMove(m);
    printBoard();

    cout << "Black's move: ";
    cin >> moveBlack;
    Move m2 = *new Move(moveBlack);
    isCorrect = MoveChecker::isValidMove(b, m2);

    while (!isCorrect) {
        cout << "Invalid move. Try again: ";
        cin >> moveBlack;
        m2 = *new Move(moveBlack);
        isCorrect = MoveChecker::isValidMove(b, m2);
    }
    
    b.PerformMove(m2);
    printBoard();

}

int main() {
    b.toDefaultBoard();
    printBoard();
    Move m = *new Move("a2 a4");
    b.PerformMove(m);
    return 0;
}