#ifndef _KNIGHT
#define _KNIGHT

#include "./piece.cpp"
#include "../move/move.cpp" 

class Knight : public Piece {
public:
    Knight(Color color) : Piece(Type::KNIGHT, color) {}

    bool isValidMove(Move m) const override
    {
        int dx = abs(m.getP1()->getX() - m.getP2()->getX());
        int dy = abs(m.getP1()->getY() - m.getP2()->getY());
        return (dx == 1 && dy == 2) || (dx == 2 && dy == 1);
    }
};

#endif