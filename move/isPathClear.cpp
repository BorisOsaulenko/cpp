#ifndef IsPathClear
#define IsPathClear

#include <iostream>
#include <string>
#include <vector>
#include "../board.cpp"
#include "./utils/getAllFieldsThatPieceWillPass.cpp"
#include "../piece/piece.cpp"
#include "./move.cpp"
#include "./position.cpp"

using namespace std;

bool isPathClear(Board b, Move m)
{ // only checked moves here
    Piece *p = b.getPiece(*m.getP1());

    Position *p1 = m.getP1();
    Position *p2 = m.getP2();

    if (p->getType() == Type::KNIGHT || p->getType() == Type::KING)
        return true;

    for (Position *pos : getAllFieldsThatPieceWillPass(p, m))
    {
        if (b.getPiece(*pos) != nullptr)
            return false;
    }
    return true;
}

// int main()
// {
//     Board b;
//     b.toDefaultBoard();
//     return 0;
// }

#endif