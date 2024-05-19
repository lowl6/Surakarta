#include "surakarta_game.h"
#include <QMessageBox>
#include <QTimer>

void SurakartaGame::UpdateGameInfo(SurakartaIllegalMoveReason move_reason, SurakartaEndReason end_reason, SurakartaPlayer winner) {


    if (move_reason == SurakartaIllegalMoveReason::LEGAL_CAPTURE_MOVE) {
        game_info_->last_captured_round_ = game_info_->num_round_;
    }
    if (!IsEndReason(end_reason) && !(checktimeout)) {
        game_info_->current_player_ = ReverseColor(game_info_->current_player_);
        game_info_->num_round_++;

        if (game_info_->current_player_ == SurakartaPlayer::BLACK) {
            if (!blackTimerId->isActive()) // 如果黑方计时器未激活，则启动它
                blackTimerId->start();
            if (whiteTimerId->isActive()) // 如果白方计时器激活，则停止它
                whiteTimerId->stop();
        } else {
            if (!whiteTimerId->isActive()) // 如果白方计时器未激活，则启动它
                whiteTimerId->start();
            if (blackTimerId->isActive()) // 如果黑方计时器激活，则停止它
                blackTimerId->stop();
        }


    } else {

        game_info_->end_reason_ = end_reason;
        game_info_->winner_ = winner;

        QMessageBox msgBox;
        msgBox.setWindowTitle("Game Over");
        if(game_info_->winner_== SurakartaPlayer::BLACK){
            msgBox.setText("The game is over!  winner : BLACK");
        }else{
            msgBox.setText("The game is over!  winner : WHITE");
        }
        checktimeout=false;

        msgBox.addButton(QMessageBox::Ok);

        // 设置消息框的图标
        msgBox.setIcon(QMessageBox::Information);

        // 显示消息框
        msgBox.exec();


    }
}

SurakartaMoveResponse SurakartaGame::Move(const SurakartaMove& move) {
    // std::cout<<"begin move"<<std::endl;
    SurakartaIllegalMoveReason move_reason = rule_manager_->JudgeMove(move);
    SurakartaPosition p_1(-1,-1);
    // std::cout<<move_reason<<std::endl;
    int move_toID=(*board_).getPiecesID(move.to.x,move.to.y);
    int  move_fromID=(*board_).getPiecesID(move.from.x,move.from.y);
    auto [end_reason, winner] = rule_manager_->JudgeEnd(move_reason);
    if(end_reason==SurakartaEndReason::ILLIGAL_MOVE||move_fromID==-1)
    {
        SurakartaMoveResponse r(move_reason, end_reason, winner);
        return r;
    }
    UpdateGameInfo(move_reason, end_reason, winner); 

    // std::cout<<"move_fromID: "<<move_fromID<<std::endl;
    //    std::cout<<move_reason<<std::endl;
    if (move_reason == SurakartaIllegalMoveReason::LEGAL_NON_CAPTURE_MOVE) {
        board_->piece[move_fromID].SetPosition(move.to);
        board_->isBlackTurn = !board_->isBlackTurn;
    } else if (move_reason == SurakartaIllegalMoveReason::LEGAL_CAPTURE_MOVE&&move_toID!=-1) {
        (*board_).piece[move_toID].SetColor(PieceColor::NONE);
        (*board_).piece[move_toID].SetPosition(p_1);
        (*board_).piece[move_fromID].SetPosition(move.to);
         board_->isBlackTurn = !board_->isBlackTurn;
    }

    // std::cout<<"???move.from: "<< board_->piece[move_fromID].position_<<std::endl;
    SurakartaMoveResponse response(move_reason, end_reason, winner);
    return response;
}
