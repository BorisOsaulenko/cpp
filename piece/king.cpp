#ifndef KING
#define KING

#include "./piece.cpp"
#include "../move/move.cpp"

class King : public Piece {
public:
    King(Color color) : Piece(Type::KING, color) {}

    bool isValidMove(const Move& move) const override {
        return (abs(move.getP1()->getX() - move.getP2()->getX()) <= 1 && abs(move.getP1()->getY() - move.getP2()->getY()) <= 1);
    }
};

#endif
