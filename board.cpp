#ifndef BOARD
#define BOARD

#include <iostream>
#include "./piece/piece.cpp"
#include "./move/move.cpp"
#include "./piece/rook.cpp"
#include "./piece/knight.cpp"
#include "./piece/bishop.cpp"
#include "./piece/queen.cpp"
#include "./piece/king.cpp"
#include "./piece/pawn.cpp"

using namespace std;

class Board
{
private: 
    Piece* board [8][8];
public:
    Board(): board{} {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                board[i][j] = nullptr;
            }
        }
    }
    Board(Board &b): board{} {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                board[i][j] = b.board[i][j];
            }
        }
    }

    Board(Piece* b[8][8]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = b[i][j];
        }
    }
}

void performMove(Move m)
{
    board[m.getP2()->getX()][m.getP2()->getY()] =
        board[m.getP1()->getX()][m.getP1()->getY()];
    board[m.getP1()->getX()][m.getP1()->getY()] = nullptr;
}

    void toDefaultBoard() {
        board[0][0] = new Rook(Color::BLACK);
        board[0][1] = new Knight(Color::BLACK);
        board[0][2] = new Bishop(Color::BLACK);
        board[0][3] = new Queen(Color::BLACK);
        board[0][4] = new King(Color::BLACK);
        board[0][5] = new Bishop(Color::BLACK);
        board[0][6] = new Knight(Color::BLACK);
        board[0][7] = new Rook(Color::BLACK);

        board[7][0] = new Rook(Color::WHITE);
        board[7][1] = new Knight(Color::WHITE);
        board[7][2] = new Bishop(Color::WHITE);
        board[7][3] = new Queen(Color::WHITE);
        board[7][4] = new King(Color::WHITE);
        board[7][5] = new Bishop(Color::WHITE);
        board[7][6] = new Knight(Color::WHITE);
        board[7][7] = new Rook(Color::WHITE);

        for (int col = 0; col < 8; col++) {
            board[1][col] = new Pawn(Color::BLACK);
            board[6][col] = new Pawn(Color::WHITE);
        }

        for (int row = 2; row < 6; row++) {
            for (int col = 0; col < 8; col++) {
                board[row][col] = nullptr;
            }
        }
    }

    Piece *getPiece(int x, int y)
    {
        return board[x][y];
    }

    Piece *getPiece(Position p)
    {
        return board[p.getX()][p.getY()];
    }

    void print()
    {
        cout << "    -------------------------------\n";
        for (int i = 0; i < 8; i++)
        {
            cout << 8 - i << " ";
            for (int j = 0; j < 8; j++)
            {
                if (getPiece(i, j) == nullptr)
                {
                    cout << " |  ";
                    continue;
                }
                cout << " | " << *getPiece(i, j);
            }

            cout << " |\n    -------------------------------\n";
        }

        cout << "     a   b   c   d   e   f   g   h\n";
    }

    ~Board() {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                board[i][j] = nullptr;
            }
        }
    };
};


#endif