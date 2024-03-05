#ifndef _KING
#define _KING

#include "./piece.cpp"
#include "../move/move.cpp"

class King : public Piece {
public:
    King(Color color) : Piece(Type::KING, color) {}

    bool isValidMove(Move m) const override
    {
        return (abs(m.getP1()->getX() - m.getP2()->getX()) <= 1 && abs(m.getP1()->getY() - m.getP2()->getY()) <= 1);
    }
};

#endif
