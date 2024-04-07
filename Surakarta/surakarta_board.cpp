#include "surakarta_board.h"
#include<QPaintEvent>
#include<QPainter>
#include<QMouseEvent>
// #include<QVector>
SurakartaBoard::SurakartaBoard(QWidget *parent)
    : QWidget(parent) /*, ui(new Ui::SurakartaBoard)*/
{
    selectId=-1;
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
SurakartaBoard:: ~SurakartaBoard(){

}
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
    if(id==selectId){
        painter.setBrush(Qt::gray);
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
//与显示到窗口中有关的函数
bool SurakartaBoard::getRowCol(QPoint pt,int&row,int&col)
{
    for(row=0;row<BOARD_SIZE;row++){
        for(col=0;col<BOARD_SIZE;col++){
            QPoint c=center(row,col);
            int dx=c.rx()-pt.rx();
            int dy=c.ry()-pt.ry();
            int d=dx*dx+dy*dy;
            if(d<piece_radius*piece_radius){
                return true;
            }
        }
    }
    return false;
}
/*选择棋子*/
void SurakartaBoard::toSelectPieces(int id)
{
    /*判断棋子是否存在*/
    if(id == -1) {
        return;
    }
    /*判断棋子是否能够被选中*/
    if(!canSelect(id)) {
        return;
    }
    selectId = id;
    update();
}
bool SurakartaBoard::canSelect(int id)
{
    if(piece[id].color_==PieceColor::NONE)
        return false;
    return isBlackTurn == (piece[id].color_==PieceColor::BLACK);
}

void SurakartaBoard::mouseReleaseEvent(QMouseEvent*ev)
{
    /*判断是否为鼠标左键*/
    if(ev->button() != Qt::LeftButton) {
        return;
    }
    /*判断点击的位置是否合法（是否在棋盘坐标的棋子范围内），同时计算出对应的棋盘行列坐标*/
    int row, col;
    if(!getRowCol(ev->pos(), row, col)) {
        return;
    }
    /*获取当前坐标上的棋子*/
    int id = getPiecesID(row, col);
    if(selectId == -1) {
        /*选择棋子*/
        toSelectPieces(id);
    } else {
        /*移动棋子*/
        //toMovePieces(id, row, col);
    }

}

int SurakartaBoard::getPiecesID(unsigned int row, unsigned int col)
{
    for(int i=0; i<24; i++) {
        if(piece[i].color_!=PieceColor::NONE && piece[i].position_.x==row && piece[i].position_.y==col) {
            return i;
        }
    }
    return -1;
}

void SurakartaBoard::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPen pen;
    pen.setWidth(3);
    painter.setPen(pen);

    //画竖线
    for(int i=cell_width;i<=6*cell_width;i+=cell_width){
        painter.drawLine(QPoint(i+cell_width,cell_width*2),QPoint(i+cell_width,cell_width*7));
    }
    //画横线
    for(int i=cell_width;i<=cell_width*6;i+=cell_width){
        painter.drawLine(QPoint(cell_width*2,i+cell_width),QPoint(7*cell_width,i+cell_width));
    }
    //画外旋线
    painter.drawArc(cell_width,cell_width,2*cell_width,2*cell_width,0,cell_width*27/5*16);
    painter.drawArc(0,0,4*cell_width,4*cell_width,0,cell_width*27/5*16);
    painter.drawArc(6*cell_width,cell_width,2*cell_width,2*cell_width,cell_width*27/5*16,cell_width*27/5*16);
    painter.drawArc(cell_width*5,0,4*cell_width,4*cell_width,cell_width*27/5*16,cell_width*27/5*16);
    painter.drawArc(cell_width,6*cell_width,2*cell_width,2*cell_width,90*16,cell_width*27/5*16);
    painter.drawArc(0,5*cell_width,4*cell_width,4*cell_width,cell_width*9/5*16,cell_width*27/5*16);
    painter.drawArc(6*cell_width,6*cell_width,2*cell_width,2*cell_width,cell_width*18/5*16,cell_width*27/5*16);
    painter.drawArc(5*cell_width,5*cell_width,4*cell_width,4*cell_width,cell_width*18/5*16,cell_width*27/5*16);
    //画棋子
    for(int i=0;i<24;i++){
        drawPiece(painter,i);
    }
}


