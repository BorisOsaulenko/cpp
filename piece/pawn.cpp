#ifndef _PAWN
#define _PAWN

#include <iostream>
#include <string>
#include "../move/move.cpp"

using namespace std;

class Pawn : public Piece {
    public:
    Pawn(Color color) : Piece(Type::PAWN, color) {}

    bool isValidMove(Move m) const override
    {
        cout << *m.getP1() << " " << *m.getP2() << endl;
        if (m.getP1()->getY() == m.getP2()->getY() &&
            m.getP1()->getX() - m.getP2()->getX() <= 2 &&
            m.getP1()->getX() - m.getP2()->getX() > 0 &&
            color == Color::WHITE)
        {
            return true;// two forward for white
        }

        if (m.getP1()->getY() == m.getP2()->getY() &&
            m.getP1()->getX() - m.getP2()->getX() >= -2 &&
            m.getP1()->getX() - m.getP2()->getX() < 0 &&
            color == Color::BLACK)
        {
            return true;// two forward for black
        }

        if (m.getP1()->getX() - m.getP2()->getX() == 1 &&
            abs(m.getP1()->getY() - m.getP2()->getY()) == 1 &&
            color == Color::WHITE)
        {
            return true;// diagonal for white
        }

        if (m.getP1()->getX() - m.getP2()->getX() == -1 &&
            abs(m.getP1()->getY() - m.getP2()->getY()) == 1 &&
            color == Color::BLACK)
        {
            return true;// diagonal for black
        }

        return false;
    }
};

#endif