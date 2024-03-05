#include <iostream>
#include "./board.cpp"
#include "./move/move.cpp"
#include "./piece/piece.cpp"
#include "./move/moveChecker.cpp"

using namespace std;

Board b;
MoveChecker mc = *new MoveChecker(b);

void oneRound() {
    string moveWhite, moveBlack;
    cout << "White's move: ";
    cin >> moveWhite;

    Move m = *new Move(moveWhite);
    bool isCorrect = mc.isValidMove(m);

    while (!isCorrect) {
        cout << "Invalid move. Try again: ";
        cin >> moveWhite;
        m = *new Move(moveWhite);
        isCorrect = mc.isValidMove(m);
    }

    b.performMove(m);
    b.print();

    cout << "Black's move: ";
    cin >> moveBlack;
    Move m2 = *new Move(moveBlack);
    isCorrect = mc.isValidMove(m2);

    while (!isCorrect) {
        cout << "Invalid move. Try again: ";
        cin >> moveBlack;
        m2 = *new Move(moveBlack);
        isCorrect = mc.isValidMove(m2);
    }

    b.performMove(m2);
    b.print();
}

int main() {
    b.toDefaultBoard();

    // b.performMove(*new Move("e2_e4"));
    b.print();

    oneRound();
    oneRound();

    return 0;
}