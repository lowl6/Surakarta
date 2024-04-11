#pragma once
// #include <memory>
// #include <vector>
// #include <QPainter>
#include "surakarta_piece.h"
// #include "surakarta_common.h"
// #include "surakarta_game.h"
#include <QWidget>
#define BOARD_SIZE 6

QT_BEGIN_NAMESPACE

// namespace Ui {
// class SurakartaBoard;
// }
// QT_END_NAMESPACE

class SurakartaBoard
{
public:
    SurakartaBoard(unsigned int );
    ~SurakartaBoard();
    int cell_width=50;             //格子宽度
    int  piece_radius=cell_width*3/7;// r棋子的半径
    int selectId;              // 被选中的棋子
    bool isBlackTurn;              // 是否轮到黑方走
    SurakartaPiece piece[24];
    int getPiecesID(unsigned int row,unsigned int col) const;
    PieceColor xy2PositionColor(unsigned int x,unsigned int y) const;
    bool IsInside(const SurakartaPosition& position) const {
        return position.x < BOARD_SIZE && position.y < BOARD_SIZE;
    }
    unsigned int boardSize;

private:
         // Ui::SurakartaBoard *ui;
};

