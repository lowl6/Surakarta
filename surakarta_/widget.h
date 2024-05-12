#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QPaintEvent>
#include<QPainter>
#include<QMouseEvent>
#include "surakarta/surakarta_game.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT
public:
    Widget(QWidget *parent = nullptr);
    std::shared_ptr<SurakartaGame> game;
    std::shared_ptr<SurakartaBoard> board=game->board_;
    inline QPoint center(unsigned int row,unsigned int col);//输入行列坐标 返回像素坐标
    inline QPoint center(int id);  // //输入棋子的id 返回像素坐标
    bool getRowCol(QPoint pt,int&row,int&col);
    void drawPiece(QPainter & painter, int id);
    void paintEvent(QPaintEvent *); //与显示到窗口中有关的函数
    void mouseReleaseEvent(QMouseEvent*ev);
    void toSelectPieces(int id);
    bool canSelect(int id);
    void repaintEvent(QPaintEvent *);
    ~Widget();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
