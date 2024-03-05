#ifndef ROOK
#define ROOK

#include <iostream>
#include <string>
#include "../Move/move.cpp"

using namespace std;

class Rook : public Piece {
    public:
    Rook(Color color) : Piece(Type::ROOK, color) {}
    
    bool isValidMove(Move m) {
        if (m.getP1()->getX() == m.getP2()->getX()) {
            return true;
        } 

        if (m.getP1()->getY() == m.getP2()->getY()) {
            return true;
        }

        return false;
    }
};

#endif