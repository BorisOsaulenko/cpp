#ifndef FIELDSONWAY
#define FIELDSONWAY

#include <iostream>
#include <string>
#include <vector>
#include "../position.cpp"
#include "../move.cpp"
#include "../../piece/piece.cpp"

using namespace std;

vector<Position> getAllFieldsThatPieceWillPass(Piece* p, Move* m) {
    vector<Position> v;
    switch (p->getType()) {
        case Piece::Type::PAWN {
            (*m)
        }
    }
}

#endif