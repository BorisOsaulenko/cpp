#ifndef _PIECE
#define _PIECE

#include <iostream>
#include <string>
#include "../move/move.cpp"

using namespace std;
enum Type
{
    KING,
    QUEEN,
    ROOK,
    BISHOP,
    KNIGHT,
    PAWN
};
enum Color
{
    WHITE,
    BLACK
};

class Piece {
protected:
    Type type;
    Color color;

public:
    Piece() {}
    Piece(Type type, Color color) : type(type), color(color) {}
    
    Type getType() const{
        return type;
    }

    Color getColor() const{
        return color;
    }

    string getSymbol()
    {
        switch (type)
        {
        case Type::KING:
            return (getColor() == Color::WHITE) ? "♔" : "♚";
        case Type::QUEEN:
            return (getColor() == Color::WHITE) ? "♕" : "♛";
        case Type::ROOK:
            return (getColor() == Color::WHITE) ? "♖" : "♜";
        case Type::BISHOP:
            return (getColor() == Color::WHITE) ? "♗" : "♝";
        case Type::KNIGHT:
            return (getColor() == Color::WHITE) ? "\u2658" : "♞";
        case Type::PAWN:
            return (getColor() == Color::WHITE) ? "♙" : "♟";
        default:
            return " ";
        }
    }

    virtual bool isValidMove(Move m) const = 0;

    friend ostream &operator<<(ostream &os, Piece &piece)
    {
        os << piece.getSymbol();
        return os;
    }
};

#endif