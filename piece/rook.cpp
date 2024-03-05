#ifndef _ROOK
#define _ROOK

#include <iostream>
#include <string>
#include "../move/move.cpp"

using namespace std;

class Rook : public Piece {
    public:
        Rook(Color color) : Piece(Type::ROOK, color) {}

        bool isValidMove(Move m) const override
        {
            if (m.getP1()->getX() == m.getP2()->getX())
            {
                return true;
            }

            if (m.getP1()->getY() == m.getP2()->getY())
            {
                return true;
            }

            return false;
        }
};

#endif