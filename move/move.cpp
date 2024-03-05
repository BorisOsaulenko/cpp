#ifndef MOVE
#define MOVE

#include <iostream>
#include <string>
#include "./position.cpp"

using namespace std;

class Move {
    private:
        Position *p1;
        Position *p2;
    public:
        Move(int x1, int y1, int x2, int y2)  {
            if (x1 < 0 || x1 > 7 || y1 < 0 || y1 > 7 || x2 < 0 || x2 > 7 || y2 < 0 || y2 > 7) {
                throw invalid_argument("Invalid move");
            }
            if (x1 == x2 && y1 == y2) {
                throw invalid_argument("Invalid move");
            }

        p1 = new Position(x1, y1);
        p2 = new Position(x2, y2);
        }
        Move (Move &m): p1(m.p1), p2(m.p2) {};
        Move(Position *p1, Position *p2) : p1(p1), p2(p2){};
        Move (string s) {
            p1 = new Position(s.substr(0, 2));
            p2 = new Position(s.substr(3, 5));
        }

        Position* getP1() {
            return p1;
        }
        Position* getP2() {
            return p2;
        }
};

#endif