#ifndef QUEEN_H
#define QUEEN_H

#include "./piece.cpp"
#include "../move/move.cpp" 
class Queen : public Piece {
public:
    Queen(Color color) : Piece(Type::QUEEN, color) {}
    bool isValidMove(const Move& move) const override {
        return (move.getP1()->getX() == move.getP2()->getX()  move.getP1()->getY() == move.getP2()->getY() 
                abs(move.getP1()->getX() - move.getP2()->getX()) == abs(move.getP1()->getY() - move.getP2()->getY()));
    }
};

#endif