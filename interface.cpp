#include <iostream>
#include "./board.cpp"
#include "./move/move.cpp"
#include "./piece/piece.cpp"
#include "./move/moveChecker.cpp"
#include "./piece/bishop.cpp"
#include "./winLost.cpp"

using namespace std;

Board b;
Color currColor = Color::WHITE;
MoveChecker mc = *new MoveChecker(b);

string colorToString(Color c)
{
    if (c == Color::WHITE)
    {
        return "White";
    }
    else
    {
        return "Black";
    }
}

void nextMove()
{
    string move;
    cout << colorToString(currColor) << "'s move: ";
    cin >> move;

    Move m = *new Move(move);
    bool isCorrect = mc.isValidMove(m, currColor);

    while (!isCorrect) {
        cout << "Invalid move. Try again: ";
        cin >> move;
        m = *new Move(move);
        isCorrect = mc.isValidMove(m, currColor);
    }

    b.performMove(m);
    b.print();

    if (currColor == Color::WHITE)
    {
        currColor = Color::BLACK;
    }
    else
    {
        currColor = Color::WHITE;
    }
}

int main() {
    b.toDefaultBoard();
    b.print();
    int state = winLost(b, currColor);

    do
    {
        nextMove();
        state = winLost(b, currColor);
    } while (state == 0);

    return 0;
}