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




