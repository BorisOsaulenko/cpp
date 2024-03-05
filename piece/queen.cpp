#ifndef _QUEEN_H
#define _QUEEN_H

#include "./piece.cpp"
#include "../move/move.cpp" 
class Queen : public Piece {
public:
    Queen(Color color) : Piece(Type::QUEEN, color) {}
    bool isValidMove(Move m) const override
    {
        return (m.getP1()->getX() == m.getP2()->getX() ||
                m.getP1()->getY() == m.getP2()->getY() ||
                abs(m.getP1()->getX() - m.getP2()->getX()) == abs(m.getP1()->getY() - m.getP2()->getY()));
    }
};

#endif