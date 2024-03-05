#ifndef PIECE
#define PIECE 

#include <iostream>
#include <string>

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

private:
    Type type;
    Color color;
};

#endif