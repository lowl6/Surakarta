#pragma once
// #include <memory>
// #include <vector>
#include <QPainter>
#include "surakarta_piece.h"
#include <QWidget>
// #include "ui_widget.h"
#define BOARD_SIZE 6

QT_BEGIN_NAMESPACE

// namespace Ui {
// class SurakartaBoard;
// }
// QT_END_NAMESPACE

class SurakartaBoard:public QWidget
{
    Q_OBJECT
public:
    SurakartaBoard(QWidget *parent = nullptr);
    ~SurakartaBoard();
    int cell_width=50;             //格子宽度
    int  piece_radius=cell_width*3/7;// r棋子的半径
    int selectId;              // 被选中的棋子
    bool isBlackTurn;              // 是否轮到黑方走
    SurakartaPiece piece[24];

    void initBoard();
    inline QPoint center(unsigned int row,unsigned int col);//输入行列坐标 返回像素坐标
    inline QPoint center(int id);  // //输入棋子的id 返回像素坐标
    void drawPiece(QPainter & painter, int id);
    void paintEvent(QPaintEvent *); //与显示到窗口中有关的函数
    bool getRowCol(QPoint pt,int&row,int&col);
    void mouseReleaseEvent(QMouseEvent*ev);
    int getPiecesID(unsigned int row,unsigned int col);
    void toSelectPieces(int id);
    bool canSelect(int id);
    bool IsInside(const SurakartaPosition& position) const {
        return position.x < BOARD_SIZE && position.y < BOARD_SIZE;
    }


private:
         // Ui::SurakartaBoard *ui;
};

