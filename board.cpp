#ifndef BOARD
#define BOARD

#include <iostream>
#include "./piece/piece.cpp"
#include "./move/move.cpp"

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

    void PerformMove(Move m) {
        board[m.getP1()->getX()][m.getP1()->getY()] = 
        board[m.getP2()->getX()][m.getP2()->getY()];
        board[m.getP2()->getX()][m.getP2()->getY()] = nullptr;
    }

    void toDefaultBoard() {
        board[0][0] = new Piece(Piece::Type::ROOK, Piece::Color::BLACK);
        board[0][1] = new Piece(Piece::Type::KNIGHT, Piece::Color::BLACK);
        board[0][2] = new Piece(Piece::Type::BISHOP, Piece::Color::BLACK);
        board[0][3] = new Piece(Piece::Type::QUEEN, Piece::Color::BLACK);
        board[0][4] = new Piece(Piece::Type::KING, Piece::Color::BLACK);
        board[0][5] = new Piece(Piece::Type::BISHOP, Piece::Color::BLACK);
        board[0][6] = new Piece(Piece::Type::KNIGHT, Piece::Color::BLACK);
        board[0][7] = new Piece(Piece::Type::ROOK, Piece::Color::BLACK);

        board[7][0] = new Piece(Piece::Type::ROOK, Piece::Color::WHITE);
        board[7][1] = new Piece(Piece::Type::KNIGHT, Piece::Color::WHITE);
        board[7][2] = new Piece(Piece::Type::BISHOP, Piece::Color::WHITE);
        board[7][3] = new Piece(Piece::Type::QUEEN, Piece::Color::WHITE);
        board[7][4] = new Piece(Piece::Type::KING, Piece::Color::WHITE);
        board[7][5] = new Piece(Piece::Type::BISHOP, Piece::Color::WHITE);
        board[7][6] = new Piece(Piece::Type::KNIGHT, Piece::Color::WHITE);
        board[7][7] = new Piece(Piece::Type::ROOK, Piece::Color::WHITE);

        for (int col = 0; col < 8; col++) {
            board[1][col] = new Piece(Piece::Type::PAWN, Piece::Color::BLACK);
            board[6][col] = new Piece(Piece::Type::PAWN, Piece::Color::WHITE);
        }

        for (int row = 2; row < 6; row++) {
            for (int col = 0; col < 8; col++) {
                board[row][col] = nullptr;
            }
        }
    }

    Piece* getPiece(int x, int y) {
        return board[x][y];
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