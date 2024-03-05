#ifndef PIECE
#define PIECE 

#include <iostream>
#include <string>
#include "../Move/move.cpp"

using namespace std;

class Piece {
public:
    enum class Type {KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN };
    enum class Color {WHITE, BLACK};
  
    Piece() {}
    Piece(Type type, Color color) : type(type), color(color) {}
    
    Type getType() const{
        return type;
    }

    Color getColor() const{
        return color;
    }

    char getSymbol(const Piece& piece) {
        switch (piece.getType()) {
            case Piece::Type::KING:
                return (piece.getColor() == Piece::Color::WHITE) ? '♔' : '♚';
            case Piece::Type::QUEEN:
                return (piece.getColor() == Piece::Color::WHITE) ? '♕' : '♛';
            case Piece::Type::ROOK:
                return (piece.getColor() == Piece::Color::WHITE) ? '♖' : '♜';
            case Piece::Type::BISHOP:
                return (piece.getColor() == Piece::Color::WHITE) ? '♗' : '♝';
            case Piece::Type::KNIGHT:
                return (piece.getColor() == Piece::Color::WHITE) ? '♘' : '♞';
            case Piece::Type::PAWN:
                return (piece.getColor() == Piece::Color::WHITE) ? '♙' : '♟';
            default:
                return '?';
        }
    }

    virtual bool checkMove(Move m) const = 0;
private:
    Type type;
    Color color;
};

#endif