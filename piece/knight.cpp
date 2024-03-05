#ifndef KNIGHT
#define KNIGHT

#include "./piece.cpp"
#include "../move/move.cpp" 

class Knight : public Piece {
public:
    Knight(Color color) : Piece(Type::KNIGHT, color) {}

    bool isValidMove(const Move& move) const override {
        int dx = abs(move.getP1()->getX() - move.getP2()->getX());
        int dy = abs(move.getP1()->getY() - move.getP2()->getY());
        return (dx == 1 && dy == 2) || (dx == 2 && dy == 1);
    }
};
