#ifndef POSITION
#define POSITION

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Position {
    private:
        int x;
        int y;
    public:
        Position(int x, int y) {
            if (x < 0 || x > 7 || y < 0 || y > 7) {
                throw "Invalid position";
            }
            this->x = x;
            this->y = y;
        }
        
        Position (Position &p) {
            this->x = p.x;
            this->y = p.y;
        }

        Position (string s) {
            int y = s[0] - 'a';
            int x = 8 - (s[1] - '0');
            if (x < 0 || x > 7 || y < 0 || y > 7) {
                throw "Invalid position";
            }
            this->x = x;
            this->y = y;
        }

        int getX() {
            return x;
        }

        int getY() {
            return y;
        }

        friend ostream &operator<<(ostream &os, const Position &p)
        {
            char file = 'a' + p.x;
            char rank = '1' + p.y;
            os << file << rank;
            // os << "(" << p.x << ", " << p.y << ")";
            return os;
        }
};

#endif