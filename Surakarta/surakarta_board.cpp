#include "surakarta_board.h"
#include "ui_surakarta_board.h"
#include<QPaintEvent>
#include<QPainter>
// #include<QMouseEvent>
// #include<QVector>
SurakartaBoard::SurakartaBoard(QWidget *parent)
    : QWidget(parent)/*, ui(new Ui::SurakartaBoard)*/
{
    // ui->setupUi(this);
    _selectid=-1;
    isBlackTurn=true;
    QPainter painter(this);
    int i=0;
    for (unsigned int y = 0; y < BOARD_SIZE; y++) {
        for (unsigned int x = 0; x < BOARD_SIZE; x++) {
            if (y < 2) {
                SurakartaPosition position(x,y);
                piece[i++].Set(position, PieceColor::BLACK);
            } else if (y >= BOARD_SIZE - 2) {
                SurakartaPosition position(x,y);
                piece[i++].Set(position, PieceColor::WHITE);
            }
        }
    }
}
// SurakartaBoard::~SurakartaBoard（）
// {
//     // delete ui;
// }
inline QPoint SurakartaBoard::center(unsigned int x,unsigned int y)
{
    QPoint ret;
    ret.rx()=2*cell_width+x*cell_width;
    ret.ry()=2*cell_width+y*cell_width;
    return ret;
}
inline QPoint SurakartaBoard::center(int id)
{
    return center( piece[id].position_.x,piece[id].position_.y);
}
void SurakartaBoard::drawPiece(QPainter & painter, int id)
{
    if(piece[id].color_==PieceColor::NONE)
        return;
    if(id==_selectid){
        painter.setBrush(Qt::cyan);
        painter.drawEllipse(center(id),piece_radius,piece_radius);
    }
    else{
        if(piece[id].color_==PieceColor::WHITE){
            painter.setBrush(Qt::white);
            painter.drawEllipse(center(id),piece_radius,piece_radius);
        }
        else if(piece[id].color_==PieceColor::BLACK){
            painter.setBrush(Qt::black);
            painter.drawEllipse(center(id),piece_radius,piece_radius);
        }
    }

}
void SurakartaBoard::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPen pen;
    pen.setWidth(3);
    painter.setPen(pen);

    //画竖线
    for(int i=50;i<=300;i+=50){
        painter.drawLine(QPoint(i+50,100),QPoint(i+50,350));
    }
    //画横线
    for(int i=50;i<=300;i+=50){
        painter.drawLine(QPoint(100,i+50),QPoint(350,i+50));
    }
    //画外旋线
    painter.drawArc(50,50,100,100,0,270*16);
    painter.drawArc(0,0,200,200,0,270*16);
    painter.drawArc(300,50,100,100,270*16,270*16);
    painter.drawArc(250,0,200,200,270*16,270*16);
    painter.drawArc(50,300,100,100,90*16,270*16);
    painter.drawArc(0,250,200,200,90*16,270*16);
    painter.drawArc(300,300,100,100,180*16,270*16);
    painter.drawArc(250,250,200,200,180*16,270*16);
    //画棋子
    for(int i=0;i<24;i++){
        drawPiece(painter,i);
    }
}


