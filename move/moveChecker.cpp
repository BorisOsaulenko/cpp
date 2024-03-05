#include <iostream>
#include "./board.cpp"
#include "./move/move.cpp"
#include "./piece/piece.cpp"

using namespace std;

public:
    static bool isValidMove(const Board& board, const Move& move) {

    Position* p1 = move.getP1();
    Position* p2 = move.getP2();

    Piece* piece = board.getPiece(p1->getX(), p1->getY());

    if (piece == nullptr) {
        cout <<"Invalid move. No piece at the starting position."
    }
    }