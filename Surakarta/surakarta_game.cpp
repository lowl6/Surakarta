#include "surakarta_game.h"


// #include <fstream>

// void SurakartaGame::StartGame(std::string file_name) {
//     // if (file_name.empty()) {
//     //     for (unsigned int y = 0; y < board_size_; y++) {
//     //         for (unsigned int x = 0; x < board_size_; x++) {
//     //             if (y < 2) {
//     //                 (*board_)[x][y] = std::make_shared<SurakartaPiece>(x, y, PieceColor::BLACK);
//     //             } else if (y >= board_size_ - 2) {
//     //                 (*board_)[x][y] = std::make_shared<SurakartaPiece>(x, y, PieceColor::WHITE);
//     //             } else {
//     //                 (*board_)[x][y] = std::make_shared<SurakartaPiece>(x, y, PieceColor::NONE);
//     //             }
//     //         }
//     //     }
//     //     game_info_->Reset();
//     // } else {
//     //     std::ifstream fin(file_name);
//     //     fin >> (*board_);
//     //     fin >> (*game_info_);
//     //     fin.close();
//     // }
//     rule_manager_->OnUpdateBoard();
// }

// void SurakartaGame::SaveGame(std::string file_name) const {
//     std::ofstream fout(file_name);
//     fout << (*board_);
//     fout << (*game_info_);
//     fout.close();
// }

void SurakartaGame::UpdateGameInfo(SurakartaIllegalMoveReason move_reason, SurakartaEndReason end_reason, SurakartaPlayer winner) {
    if (move_reason == SurakartaIllegalMoveReason::LEGAL_CAPTURE_MOVE) {
        game_info_->last_captured_round_ = game_info_->num_round_;
    }
    if (!IsEndReason(end_reason)) {
        game_info_->current_player_ = ReverseColor(game_info_->current_player_);
        game_info_->num_round_++;
    } else {
        game_info_->end_reason_ = end_reason;
        game_info_->winner_ = winner;
    }
}

SurakartaMoveResponse SurakartaGame::Move(const SurakartaMove& move) {
    // std::cout<<"begin move"<<std::endl;
    SurakartaIllegalMoveReason move_reason = rule_manager_->JudgeMove(move);
    // std::cout<<move_reason<<std::endl;
    auto [end_reason, winner] = rule_manager_->JudgeEnd(move_reason);
    UpdateGameInfo(move_reason, end_reason, winner); 
    int move_toID=(*board_).getPiecesID(move.to.x,move.to.y);
    int  move_fromID=(*board_).getPiecesID(move.from.x,move.from.y);
    // std::cout<<"move_fromID: "<<move_fromID<<std::endl;
    //    std::cout<<move_reason<<std::endl;
    if (move_reason == SurakartaIllegalMoveReason::LEGAL_NON_CAPTURE_MOVE) {
         // std::cout<<"move_fromID: "<<move_fromID<<std::endl;
         // std::cout<<"move.to: "<<move.to<<std::endl;
        board_->piece[move_fromID].SetPosition(move.to);
        // std::cout<<  board_->piece[move_fromID].position_;
          board_->isBlackTurn = !board_->isBlackTurn;
        rule_manager_->OnUpdateBoard();
    } else if (move_reason == SurakartaIllegalMoveReason::LEGAL_CAPTURE_MOVE) {
        (*board_).piece[move_toID].SetColor(PieceColor::NONE);
        (*board_).piece[move_fromID].SetPosition(move.to);
         board_->isBlackTurn = !board_->isBlackTurn;
        rule_manager_->OnUpdateBoard();
    }
     // std::cout<<"???move.from: "<< board_->piece[move_fromID].position_<<std::endl;
    SurakartaMoveResponse response(move_reason, end_reason, winner);
    return response;
}
