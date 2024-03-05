#ifndef MOVECHECKER
#define MOVECHECKER

#include <iostream>
#include "./board.cpp"
#include "./move/move.cpp"
#include "./piece/piece.cpp"

using namespace std;

class MoveChecker {

public:


    static bool isValidMove(Move m) {
        Piece p = b.getPiece(m.getP1()->getX(), m.getP1()->getY());
         if (!p.checkMove(m)) {
            cout << "Invalid move according to the piece's rules." << endl;
            return false;
        }
         if (isPathClear(m)) {
            return true;
        } else {
            cout << "There is an obstacle on the path." << endl;
            return false;
        }
        //continue
    }
}

private:
    Board b;
     bool isPathClear(Move m) {
     return true;
}
#endif