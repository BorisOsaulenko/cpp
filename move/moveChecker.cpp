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
    Board *b;

public:
    MoveChecker(Board &b) : b(&b) {}
    bool isValidMove(Move m, Color c)
    {
        Position *p1 = m.getP1();
        Position *p2 = m.getP2();
        Piece *p = (*b).getPiece(*p1);

        if (p == nullptr)
        {
            cout << "No piece at " << *p1 << endl;
            return false;
        }

        if (p->getColor() != c)
        {
            cout << "It's not your piece." << endl;
            return false;
        }
        if (!p->isValidMove(m))
        {
            cout << "Invalid move according to the piece's rules." << endl;
            return false;
        }
        if (isPathClear(*b, m))
        {
            return true;
        }
        else
        {
            cout << "There is an obstacle on the path." << endl;
            return false;
        }
        // continue
        return true;
    }
};

#endif