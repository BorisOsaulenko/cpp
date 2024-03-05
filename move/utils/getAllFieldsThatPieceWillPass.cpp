#ifndef FIELDSONWAY
#define FIELDSONWAY

#include <iostream>
#include <string>
#include <vector>
#include "../position.cpp"
#include "../move.cpp"
#include "../../piece/piece.cpp"
#include "../../piece/rook.cpp"

using namespace std;

vector<Position *> diagonal(Move m)
{

    vector<Position *> v;

    Position *p1 = m.getP1();
    Position *p2 = m.getP2();

    bool isP2OnTheLeft = p1->getY() < p2->getY();
    bool isP2OnTheTop = p1->getX() < p2->getX();

    short xShift = isP2OnTheLeft ? 1 : -1;
    short yShift = isP2OnTheTop ? 1 : -1;

    for (int i = p1->getX() + xShift, j = p1->getY() + yShift; i != p2->getX() && j != p2->getY(); i += xShift, j += yShift)
    {
        v.push_back(new Position(i, j));
    }
    return v;
}

vector<Position *> straight(Move m)
{
    vector<Position *> v;

    Position *p1 = m.getP1();
    Position *p2 = m.getP2();

    bool vertical = p1->getX() == p2->getX();

    if (vertical)
    {
        int yShift = p1->getY() < p2->getY() ? 1 : -1;
        for (int i = p1->getY() + yShift; i != p2->getY(); i += yShift)
        {
            v.push_back(new Position(p1->getX(), i));
        }
    }
    else
    {
        int xShift = p1->getX() < p2->getX() ? 1 : -1;
        for (int i = p1->getX() + xShift; i != p2->getX(); i += xShift)
        {
            v.push_back(new Position(i, p1->getY()));
        }
    }
    return v;
}

vector<Position *> getAllFieldsThatPieceWillPass(Piece *p, Move m)
{
    // do not check knight and king here
    if (p->getType() == Type::PAWN)
        return straight(m);
    if (p->getType() == Type::BISHOP)
        return diagonal(m);

    if (p->getType() == Type::ROOK)
        return straight(m);

    if (p->getType() == Type::QUEEN)
    {
        if (m.getP1()->getX() == m.getP2()->getX() || m.getP1()->getY() == m.getP2()->getY())
        {
            return straight(m);
        }
        else
            return diagonal(m);
    }

    return vector<Position *>();

    // Handle other piece types or return a default value
}

#endif