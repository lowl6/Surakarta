#include "surakarta_board.h"
// #include<QVector>
SurakartaBoard::SurakartaBoard(unsigned int boardsize)
    :boardSize(boardsize)
{
    selectId=-1;
    isBlackTurn=true;
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
SurakartaPosition SurakartaBoard::Qsting2pos(QString s) {
    SurakartaPosition p;
    if (s.length() != 2) {
        // 输入字符串长度不合法，返回默认值
        p.x = -1;
        p.y = -1;
        return p;
    }

    QChar letter = s.at(0).toUpper();
    QChar number = s.at(1);

    if (letter < 'A' || letter > 'F' || number < '1' || number > '6') {
        // 输入字符串不合法，返回默认值
        p.x = -1;
        p.y = -1;
        return p;
    }

    p.x = letter.toLatin1() - 'A' + 1;
    p.y = number.toLatin1() - '0';
    return p;
}
QString SurakartaBoard::pos2Qsting(SurakartaPosition p)
{
    // 将 x 转换为大写字母
    QString letter = QChar('A' + p.x - 1);

    // 将 y 转换为数字
    QString number = QString::number(p.y);

    // 将字母和数字组合成 QString 返回
    return letter + number;
}
void SurakartaBoard:: reset()
{
    selectId=-1;
    isBlackTurn=true;
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
    //SurakartaGame::checktimeout
}
SurakartaBoard:: ~SurakartaBoard(){
}
int SurakartaBoard::getPiecesID(unsigned int row, unsigned int col) const
{
    for(int i=0; i<24; i++) {
        if(piece[i].color_!=PieceColor::NONE &&piece[i].position_.x==row &&piece[i].position_.y==col) {
            return i;
        }
    }
    return -1;
}

PieceColor SurakartaBoard::xy2PositionColor(unsigned int x, unsigned int y) const
{
    for(auto i:piece)
    {
        if(i.position_.x==x&&i.position_.y==y)
            return i.color_;

    }
    return PieceColor::NONE;
}




