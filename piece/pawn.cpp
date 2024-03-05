#ifndef PAWN
#define PAWN

#include <iostream>
#include <string>
#include "../Move/move.cpp"

using namespace std;

class Pawn : public Piece {
    public:
    Pawn(Color color) : Piece(Type::PAWN, color) {}
    
    bool isValidMove(Move m) {
        if (m.getP1()->getX() == m.getP2()->getX() && m.getP1()->getY() - m.getP2()->getY() <= 2 && color == Color::WHITE) {
            return true;// two forward for white
        }
        
        if (m.getP1()->getX() == m.getP2()->getX() && m.getP1()->getY() - m.getP2()->getY() >= -2 && color == Color::BLACK) {
            return true;// two forward for black
        }

        if (m.getP1()->getX() - m.getP2()->getX() == 1 && abs(m.getP1()->getY() - m.getP2()->getY()) == 1 && color == Color::WHITE) {
            return true;// diagonal for white
        }

        if (m.getP1()->getX() - m.getP2()->getX() == -1 && abs(m.getP1()->getY() - m.getP2()->getY()) == 1 && color == Color::BLACK) {
            return true;// diagonal for black
        }

        return false;
    }
};

#endif