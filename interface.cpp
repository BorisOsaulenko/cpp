#include <iostream>
#include "./board.cpp"
#include "./move/move.cpp"
#include "./piece/piece.cpp"

using namespace std;

int main() {
    Board b = *new Board();
    b.toDefaultBoard();
    Move m = *new Move("a2 a4");
    b.PerformMove(m);
    return 0;
}