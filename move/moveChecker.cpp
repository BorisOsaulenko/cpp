#ifndef MOVECHECKER
#define MOVECHECKER

#include <iostream>
#include "../board.cpp"
#include "./move.cpp"
#include "../piece/piece.cpp"
#include "./isPathClear.cpp"

using namespace std;

class MoveChecker {
private:
    Board b;

public:
    MoveChecker(Board &b) : b(b) {}
    bool isValidMove(Move m)
    {
        // Piece *p = b.getPiece(m.getP1()->getX(), m.getP1()->getY());
        // if (!p->isValidMove(m))
        // {
        //     cout << "Invalid move according to the piece's rules." << endl;
        //     return false;
        // }
        // if (isPathClear(b, m))
        // {
        //     return true;
        // }
        // else
        // {
        //     cout << "There is an obstacle on the path." << endl;
        //     return false;
        // }
        // continue
        return true;
    }
};

#endif