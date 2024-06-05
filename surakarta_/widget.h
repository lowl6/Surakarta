#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QPaintEvent>
#include<QPainter>
#include<QMouseEvent>
#include "surakarta/surakarta_game.h"
//单人模式界面
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
    bool getRowCol(QPoint pt,int&row,int&col);//获得点上棋子的坐标
    void drawPiece(QPainter & painter, int id);//画棋子
    void paintEvent(QPaintEvent *); //与显示到窗口中有关的函数
    virtual void mouseReleaseEvent(QMouseEvent*ev);
    void toSelectPieces(int id);//
    bool canSelect(int id);
    ~Widget();
    void Hide();
private:
    Ui::Widget *ui;

   // void hidentb();
public slots:
   virtual void on_restart_clicked();//重新开始游戏
   virtual void on_admit_defeat_clicked();//认输并重开

   private slots:
   virtual void on_AI_clicked();//手动代打
};
#endif // WIDGET_H
