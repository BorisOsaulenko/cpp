#ifndef _BISHOP
#define _BISHOP

#include <iostream>
#include <string>
#include "../move/move.cpp"

using namespace std;

class Bishop : public Piece {
    public:
    Bishop(Color color) : Piece(Type::BISHOP, color) {}

    bool isValidMove(Move m) const override
    {
        if (abs(m.getP1()->getX() - m.getP2()->getX()) == abs(m.getP1()->getY() - m.getP2()->getY())) {
            return true;
        }

        return false;
    }
};

#endif