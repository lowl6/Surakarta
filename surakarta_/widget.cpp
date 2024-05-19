#include "widget.h"
#include "ui_widget.h"
#include "surakarta/surakarta_common.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent),
    game(std::make_shared<SurakartaGame>(BOARD_SIZE, 40)), ui(new Ui::Widget)
{
    ui->setupUi(this);
    //按钮样式：
    ui->restart->setStyleSheet ("border:0.5px groove gray;border-radius:10px;padding:2px 4px;"     "color:rgb(0,0,0)");
    ui->admit_defeat->setStyleSheet ("border:0.5px groove gray;border-radius:10px;padding:2px 4px;"   "color:rgb(0,0,0)");
    ui->AI->setStyleSheet ("border:0.5px groove gray;border-radius:10px;padding:2px 4px;"   "color:rgb(0,0,0)");
    QPainter painter(this);

}
Widget::~Widget()
{
    delete ui;
}
// void Widget::hidentb()
// {
//     ui->restart->setVisible(false);
// }
inline QPoint Widget::center(unsigned int x, unsigned int y)
{
    QPoint ret;
    ret.rx() = 2 * board->cell_width + x * board->cell_width;
    ret.ry() = 2 * board->cell_width + y * board->cell_width;
    return ret;
}
inline QPoint Widget::center(int id)
{
    return center(board->piece[id].position_.x, board->piece[id].position_.y);
}

bool Widget::getRowCol(QPoint pt, int &row, int &col)
{
    for (row = 0; row < BOARD_SIZE; row++)
    {
        for (col = 0; col < BOARD_SIZE; col++)
        {
            QPoint c = center(row, col);
            int dx = c.rx() - pt.rx();
            int dy = c.ry() - pt.ry();
            int d = dx * dx + dy * dy;
            if (d < board->piece_radius * board->piece_radius)
            {
                return true;
            }
        }
    }
    return false;
}
/*选择棋子*/
void Widget::toSelectPieces(int id)
{
    /*判断棋子是否存在*/
    if (id == -1)
    {
        return;
    }
    /*判断棋子是否能够被选中*/
    if (!canSelect(id))
    {
        return;
    }
    if (board->piece[id].color_ == (board->isBlackTurn ? PieceColor::BLACK : PieceColor::WHITE))
    {
        board->selectId = id;
    }
    else
    {
        board->selectId = id;
    }

    update();
}
bool Widget::canSelect(int id)
{
    if(id<0||id>=24)
        return false;
    if (board->piece[id].color_ == PieceColor::NONE)
        return false;
    if(board->isBlackTurn)
    {
        if(board->piece[id].color_ == PieceColor::BLACK)
            return true;
    }
    else if(board->piece[id].color_==PieceColor::WHITE)
        return true;
    return false;

}

void Widget::mouseReleaseEvent(QMouseEvent *ev)
{
    /*判断是否为鼠标左键*/
    if (ev->button() != Qt::LeftButton)
    {
        return;
    }
    /*判断点击的位置是否合法（是否在棋盘坐标的棋子范围内），同时计算出对应的棋盘行列坐标*/
    int row, col;
    if (!getRowCol(ev->pos(), row, col))
    {
        return;
    }
    /*获取当前坐标上的棋子*/
    int id = board->getPiecesID(row, col);
    if (board->selectId == -1)
    {
        /*选择棋子修改selectId*/
        toSelectPieces(id);
    }
    else
    {
        if (board->piece[id].color_ == board->piece[board->selectId].color_)
        {
            toSelectPieces(id);
        }
        else
        {
            SurakartaPosition from(board->piece[board->selectId].position_.x, board->piece[board->selectId].position_.y);
            SurakartaPosition to(row, col);
            SurakartaMove move(from, to, game->game_info_->current_player_);
            SurakartaMoveResponse response= game->Move(move);
            if(!response.IsLegal())
            {
                return;
            }
            board->selectId = -1;
            update();
        }
    }
}
// 与显示到窗口中有关的函数
void Widget::drawPiece(QPainter &painter, int id)
{

    if (board->piece[id].color_ == PieceColor::NONE)
        return;
    if (id == board->selectId)
    {
        painter.setBrush(Qt::gray);
        painter.drawEllipse(QPointF(center(id)), board->piece_radius, board->piece_radius);
    }
    else
    {
        if (board->piece[id].color_ == PieceColor::WHITE)
        {
            painter.setBrush(Qt::white);
            painter.drawEllipse(QPointF(center(id)), board->piece_radius, board->piece_radius);
        }
        else if (board->piece[id].color_ == PieceColor::BLACK)
        {
            painter.setBrush(Qt::black);
            painter.drawEllipse(QPointF(center(id)), board->piece_radius, board->piece_radius);
        }
    }

}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPen pen;

    Q_UNUSED(event);
    painter.setOpacity(0.8);  //0.7
    painter.drawPixmap(rect(),QPixmap(":/Resources/20240514193115.jpg"), QRect());

    pen.setWidth(3);
    painter.setPen(pen);
     painter.setOpacity(1);
    // 画竖线
    for (int i = board->cell_width; i <= 6 * board->cell_width; i += board->cell_width)
    {
        painter.drawLine(QPoint(i + board->cell_width, board->cell_width * 2), QPoint(i + board->cell_width, board->cell_width * 7));
    }
    // 画横线
    for (int i = board->cell_width; i <= board->cell_width * 6; i += board->cell_width)
    {
        painter.drawLine(QPoint(board->cell_width * 2, i + board->cell_width), QPoint(7 * board->cell_width, i + board->cell_width));
    }
    // 画外旋线
    painter.drawArc(board->cell_width, board->cell_width, 2 * board->cell_width, 2 * board->cell_width, 0, board->cell_width * 27 / 5 * 16);
    painter.drawArc(0, 0, 4 * board->cell_width, 4 * board->cell_width, 0, board->cell_width * 27 / 5 * 16);
    painter.drawArc(6 * board->cell_width, board->cell_width, 2 * board->cell_width, 2 * board->cell_width, board->cell_width * 27 / 5 * 16, board->cell_width * 27 / 5 * 16);
    painter.drawArc(board->cell_width * 5, 0, 4 * board->cell_width, 4 * board->cell_width, board->cell_width * 27 / 5 * 16, board->cell_width * 27 / 5 * 16);
    painter.drawArc(board->cell_width, 6 * board->cell_width, 2 * board->cell_width, 2 * board->cell_width, 90 * 16, board->cell_width * 27 / 5 * 16);
    painter.drawArc(0, 5 * board->cell_width, 4 * board->cell_width, 4 * board->cell_width, board->cell_width * 9 / 5 * 16, board->cell_width * 27 / 5 * 16);
    painter.drawArc(6 * board->cell_width, 6 * board->cell_width, 2 * board->cell_width, 2 * board->cell_width, board->cell_width * 18 / 5 * 16, board->cell_width * 27 / 5 * 16);
    painter.drawArc(5 * board->cell_width, 5 * board->cell_width, 4 * board->cell_width, 4 * board->cell_width, board->cell_width * 18 / 5 * 16, board->cell_width * 27 / 5 * 16);
    // 画棋子
    for (int i = 0; i < 24; i++)
    {
        drawPiece(painter, i);
    }
    if(ui->showAllgoalbtn->isChecked()&& board->selectId!=-1)
    {
        QPainter painter(this);

        std::vector<SurakartaPosition> AllLegalTarget=game->rule_manager_->GetAllLegalTarget(board->piece[board->selectId].position_);
        painter.setOpacity(0.2);
        painter.setBrush(Qt::cyan);
        double r= board->piece_radius;
        for(auto i:AllLegalTarget)
        {
            painter.drawEllipse(QPointF(center(i.x, i.y)), r,r);
        }
    }

}
// void Widget::repaintEvent(QPaintEvent *)
// {
//     QPainter painter(this);
//     QPen pen;
//     pen.setWidth(3);
//     painter.setPen(pen);

//     // 画竖线
//     for (int i = board->cell_width; i <= 6 * board->cell_width; i += board->cell_width)
//     {
//         painter.drawLine(QPoint(i + board->cell_width, board->cell_width * 2), QPoint(i + board->cell_width, board->cell_width * 7));
//     }
//     // 画横线
//     for (int i = board->cell_width; i <= board->cell_width * 6; i += board->cell_width)
//     {
//         painter.drawLine(QPoint(board->cell_width * 2, i + board->cell_width), QPoint(7 * board->cell_width, i + board->cell_width));
//     }
//     // 画外旋线
//     painter.drawArc(board->cell_width, board->cell_width, 2 * board->cell_width, 2 * board->cell_width, 0, board->cell_width * 27 / 5 * 16);
//     painter.drawArc(0, 0, 4 * board->cell_width, 4 * board->cell_width, 0, board->cell_width * 27 / 5 * 16);
//     painter.drawArc(6 * board->cell_width, board->cell_width, 2 * board->cell_width, 2 * board->cell_width, board->cell_width * 27 / 5 * 16, board->cell_width * 27 / 5 * 16);
//     painter.drawArc(board->cell_width * 5, 0, 4 * board->cell_width, 4 * board->cell_width, board->cell_width * 27 / 5 * 16, board->cell_width * 27 / 5 * 16);
//     painter.drawArc(board->cell_width, 6 * board->cell_width, 2 * board->cell_width, 2 * board->cell_width, 90 * 16, board->cell_width * 27 / 5 * 16);
//     painter.drawArc(0, 5 * board->cell_width, 4 * board->cell_width, 4 * board->cell_width, board->cell_width * 9 / 5 * 16, board->cell_width * 27 / 5 * 16);
//     painter.drawArc(6 * board->cell_width, 6 * board->cell_width, 2 * board->cell_width, 2 * board->cell_width, board->cell_width * 18 / 5 * 16, board->cell_width * 27 / 5 * 16);
//     painter.drawArc(5 * board->cell_width, 5 * board->cell_width, 4 * board->cell_width, 4 * board->cell_width, board->cell_width * 18 / 5 * 16, board->cell_width * 27 / 5 * 16);
//     // 画棋子
// }


void Widget::on_restart_clicked()
{
    this->hide();

    // 删除当前 Widget 对象
    delete this;

    // 创建一个新的 Widget 对象
    Widget *newWidget = new Widget();

    // 显示新创建的 Widget
    newWidget->show();
}


void Widget::on_admit_defeat_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("GAME OVER");
    msgBox.setText("您认输了，再接再厉!(ง •̀_•́)ง");
    msgBox.addButton(QMessageBox::Ok);
    msgBox.setIcon(QMessageBox::Information);
    msgBox.exec();
    on_restart_clicked();
}
//将联机窗口不需要的按钮隐藏
void Widget::Hide()
{
    ui->restart->hide();
}

void Widget::on_AI_clicked()
{
    SurakartaMove move=game->myAI->CalculateMove();
    game->Move(move);
    board->selectId = -1;
    update();
}

