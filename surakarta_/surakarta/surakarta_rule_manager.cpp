#include "surakarta_rule_manager.h"
//#include "surakarta_game.h"
// #include <iostream>


void SurakartaRuleManager::OnUpdateBoard() {
    // TODO:
    // Every time the board and game_info is updated to the next round version, this function will be called.
    // You don't need to implement this function if you don't need it.
    // A more delicate way is to use Qt's signal and slot mechanism, but that's the advanced part.
}
SurakartaIllegalMoveReason SurakartaRuleManager::JudgeMove(const SurakartaMove& move) {

    if(move.from.x<0||move.from.x>=board_size_||move.from.y<0||move.from.y>=board_size_||move.to.x<0||move.to.x>=board_size_||move.to.x<0||move.to.x>=board_size_)
        return SurakartaIllegalMoveReason::OUT_OF_BOARD;
    PieceColor move_toColor = board_->xy2PositionColor(move.to.x,move.to.y);
    PieceColor move_fromColor = board_->xy2PositionColor(move.from.x,move.from.y);
    if(move_fromColor==PieceColor::NONE)
        return SurakartaIllegalMoveReason::NOT_PIECE;
    if (move_fromColor != game_info_->current_player_)
        return SurakartaIllegalMoveReason::NOT_PLAYER_PIECE;
    if(move.player!=game_info_->current_player_)
        return SurakartaIllegalMoveReason::NOT_PLAYER_TURN;




    bool flag = false;
    if (move_toColor != PieceColor::NONE) {
        if (move_toColor == game_info_->current_player_)
            return SurakartaIllegalMoveReason::ILLIGAL_NON_CAPTURE_MOVE;
        if ((move.from.x == 0 && move.from.y == 0) || (move.from.x == 0 && move.from.y == board_size_ - 1) || (move.from.x == board_size_ - 1 && move.from.y == 0) || (move.from.x == board_size_ - 1 && move.from.y == board_size_ - 1))
            return SurakartaIllegalMoveReason::ILLIGAL_CAPTURE_MOVE;

        // LEGAL_CAPTURE_MOVE:
        std::vector<SurakartaPosition> interface, outface, interface_to;
        // 寻找interface
        if (!(move.from.y == 0 || move.from.y == BOARD_SIZE - 1)) {
            unsigned int i = move.from.x;
            while (1) {
                if (i == BOARD_SIZE - 1) {
                    SurakartaPosition newPosition(i, move.from.y);
                    interface.push_back(newPosition);
                    break;
                }
                int piece_id=(*board_).getPiecesID(++i,move.from.y);
                if (i < BOARD_SIZE - 1) {
                    if (piece_id ==-1)
                        continue;
                    else
                        break;
                } else if (i == BOARD_SIZE - 1&&piece_id ==-1) {
                    SurakartaPosition newPosition(i, move.from.y);
                    interface.push_back(newPosition);
                    break;}
                else
                    break;
            }
            i = move.from.x;
            while (1) {
                if (i == 0) {
                    SurakartaPosition newPosition(i, move.from.y);
                    interface.push_back(newPosition);
                    break;
                }
                int piece_id=(*board_).getPiecesID(--i,move.from.y);
                if (i > 0 && i < BOARD_SIZE) {
                    if (piece_id ==-1)
                        continue;
                    else
                        break;
                } else if (i == 0 &&piece_id ==-1) {
                    SurakartaPosition newPosition(i, move.from.y);
                    interface.push_back(newPosition);
                    break;
                }
                else
                    break;
            }
        }
        if (!(move.from.x == 0 || move.from.x == BOARD_SIZE - 1)) {
            unsigned int i = move.from.y;
            while (1) {
                if (i == BOARD_SIZE - 1) {
                    SurakartaPosition newPosition(move.from.x, i);
                    interface.push_back(newPosition);
                    break;
                }
                int piece_id=(*board_).getPiecesID(move.from.x,++i);
                if (i < BOARD_SIZE - 1) {
                    if (piece_id ==-1)
                        continue;
                    else
                        break;
                }
                else if (i == BOARD_SIZE - 1&&piece_id ==-1) {
                    SurakartaPosition newPosition(move.from.x, i);
                    interface.push_back(newPosition);
                    break;
                }
                else break;
            }
            i = move.from.y;
            while (1) {
                if (i == 0) {
                    SurakartaPosition newPosition(move.from.x, i);
                    interface.push_back(newPosition);
                    break;
                }
                int piece_id=(*board_).getPiecesID(move.from.x,--i);
                if (i > 0 && i < BOARD_SIZE) {
                    if (piece_id ==-1)
                        continue;
                    else
                        break;
                } else if (i == 0&&piece_id ==-1) {
                    SurakartaPosition newPosition(move.from.x, i);
                    interface.push_back(newPosition);
                    break;
                }
                else break;
            }
        }
        // 寻找通路：Accessible_xRoad, Accessible_yRoad;
        std::vector<unsigned int> Accessible_xRoad, Accessible_yRoad;
        for (unsigned i = 1; i <= 4; i++) {
            int cnt = 0;
            int f1 = 0;
            int f2 = 0;
            for (unsigned j = 0; j < BOARD_SIZE; j++) {
                if (i == move.from.x && j == move.from.y) {
                    f1 = 1;
                    continue;
                }
                if (i == move.to.x && j == move.to.y) {
                    f2 = 1;
                    continue;
                }
                if ((*board_).getPiecesID(i,j) ==-1)
                    cnt++;
            }
            if (f1)
                cnt = cnt + f1 + f2;
            if (cnt == BOARD_SIZE) {
                Accessible_xRoad.push_back(i);
            }
        }
        for (unsigned i = 1; i <= 4; i++) {
            int cnt = 0;
            int f1 = 0;
            int f2 = 0;
            for (unsigned j = 0; j < BOARD_SIZE; j++) {
                if (i == move.from.y && j == move.from.x) {
                    f1 = 1;
                    continue;
                }
                if (j == move.to.x && i == move.to.y) {
                    f2 = 1;
                    continue;
                }
                if ((*board_).getPiecesID(j,i) ==-1)
                    cnt++;
            }
            if (f1)
                cnt = f1 + f2 + cnt;
            if (cnt == BOARD_SIZE) {
                Accessible_yRoad.push_back(i);
            }
        }
        // 寻找outface
        for (auto i : interface) {
            if ((i.x == 0 || i.y == 0) && i.x < 3 && i.y < 3) {
                SurakartaPosition newPosition(i.y, i.x);
                outface.push_back(newPosition);
            } else if (i.x >= 3 && i.y >= 3) {
                SurakartaPosition newPosition(i.y, i.x);
                outface.push_back(newPosition);
            } else {
                SurakartaPosition newPosition(5 - i.y, 5 - i.x);
                outface.push_back(newPosition);
            }
        }

        ///// loop_num==2
        if (Accessible_xRoad.size() > 0 || Accessible_yRoad.size() > 0) {
            bool flag = 0;
            for (auto i : outface) {
                for (auto j : Accessible_xRoad)
                    if (i.x == j) {
                        flag = 1;
                        if (i.y == 0) {
                            SurakartaPosition newPosition(j, BOARD_SIZE - 1);
                            interface.push_back(newPosition);
                        } else {
                            SurakartaPosition newPosition(j, 0);
                            interface.push_back(newPosition);
                        }
                    }
            }
            for (auto i : outface) {
                for (auto j : Accessible_yRoad)
                    if (i.y == j) {
                        flag = 1;
                        if (i.x == 0) {
                            SurakartaPosition newPosition(BOARD_SIZE - 1, j);
                            interface.push_back(newPosition);
                        } else {
                            SurakartaPosition newPosition(0, j);
                            interface.push_back(newPosition);
                        }
                    }
            }
            if (flag) {
                flag = 0;
                for (auto i : interface) {
                    if ((i.x == 0 || i.y == 0) && i.x < 3 && i.y < 3) {
                        SurakartaPosition newPosition(i.y, i.x);
                        outface.push_back(newPosition);
                    } else if (i.x >= 3 && i.y >= 3) {
                        SurakartaPosition newPosition(i.y, i.x);
                        outface.push_back(newPosition);
                    } else {
                        SurakartaPosition newPosition(5 - i.y, 5 - i.x);
                        outface.push_back(newPosition);
                    }
                }
                for (auto i : outface) {
                    for (auto j : Accessible_xRoad)
                        if (i.x == j) {
                            flag = 1;
                            if (i.y == 0) {
                                SurakartaPosition newPosition(j, BOARD_SIZE - 1);
                                interface.push_back(newPosition);
                            } else {
                                SurakartaPosition newPosition(j, 0);
                                interface.push_back(newPosition);
                            }
                        }
                }
                for (auto i : outface) {
                    for (auto j : Accessible_yRoad)
                        if (i.y == j) {
                            flag = 1;
                            if (i.x == 0) {
                                SurakartaPosition newPosition(BOARD_SIZE - 1, j);
                                interface.push_back(newPosition);
                            } else {
                                SurakartaPosition newPosition(0, j);
                                interface.push_back(newPosition);
                            }
                        }
                }
                if (flag) {
                    for (auto i : interface) {
                        if ((i.x == 0 || i.y == 0) && i.x < 3 && i.y < 3) {
                            SurakartaPosition newPosition(i.y, i.x);
                            outface.push_back(newPosition);
                        } else if (i.x >= 3 && i.y >= 3) {
                            SurakartaPosition newPosition(i.y, i.x);
                            outface.push_back(newPosition);
                        } else {
                            SurakartaPosition newPosition(5 - i.y, 5 - i.x);
                            outface.push_back(newPosition);
                        }
                    }

                    ///// loop_num==4
                    flag = 0;
                    for (auto i : outface) {
                        for (auto j : Accessible_xRoad)
                            if (i.x == j) {
                                flag = 1;
                                if (i.y == 0) {
                                    SurakartaPosition newPosition(j, BOARD_SIZE - 1);
                                    interface.push_back(newPosition);
                                } else {
                                    SurakartaPosition newPosition(j, 0);
                                    interface.push_back(newPosition);
                                }
                            }
                    }
                    for (auto i : outface) {
                        for (auto j : Accessible_yRoad)
                            if (i.y == j) {
                                flag = 1;
                                if (i.x == 0) {
                                    SurakartaPosition newPosition(BOARD_SIZE - 1, j);
                                    interface.push_back(newPosition);
                                } else {
                                    SurakartaPosition newPosition(0, j);
                                    interface.push_back(newPosition);
                                }
                            }
                    }
                    if (flag) {
                        for (auto i : interface) {
                            if ((i.x == 0 || i.y == 0) && i.x < 3 && i.y < 3) {
                                SurakartaPosition newPosition(i.y, i.x);
                                outface.push_back(newPosition);
                            } else if (i.x >= 3 && i.y >= 3) {
                                SurakartaPosition newPosition(i.y, i.x);
                                outface.push_back(newPosition);
                            } else {
                                SurakartaPosition newPosition(5 - i.y, 5 - i.x);
                                outface.push_back(newPosition);
                            }
                        }
                    }
                }
            }
        }

        // 对to寻找interface
        if (!(move.to.y == 0 || move.to.y == BOARD_SIZE - 1)) {
            unsigned int i = move.to.x;
            while (1) {
                if (i == BOARD_SIZE - 1) {
                    SurakartaPosition newPosition(i, move.to.y);
                    interface_to.push_back(newPosition);
                    break;
                }
                int piece_id=(*board_).getPiecesID(++i,move.to.y);
                if (i < BOARD_SIZE - 1) {
                    if (piece_id ==-1|| (move.from.x == i && move.from.y == move.to.y))
                        continue;
                    else
                        break;
                } else if (i == BOARD_SIZE - 1&&(piece_id ==-1||(move.from.x == i && move.from.y == move.to.y))) {
                    SurakartaPosition newPosition(i, move.to.y);
                    interface_to.push_back(newPosition);
                    break;
                } else
                    break;
            }
            i = move.to.x;
            while (1) {
                if (i == 0) {
                    SurakartaPosition newPosition(i, move.to.y);
                    interface_to.push_back(newPosition);
                    break;
                }
                int piece_id=(*board_).getPiecesID(--i,move.to.y);
                if (i > 0 && i < BOARD_SIZE) {
                    if (piece_id ==-1 || (move.from.x == i && move.from.y == move.to.y))
                        continue;
                    else
                        break;
                } else if (i == 0  && (piece_id ==-1|| (move.from.x == i && move.from.y == move.to.y))) {
                    SurakartaPosition newPosition(i, move.to.y);
                    interface_to.push_back(newPosition);
                    break;
                } else
                    break;
            }
        }
        if (!(move.to.x == 0 || move.to.x == BOARD_SIZE - 1)) {
            unsigned int i = move.to.y;
            while (1) {
                if (i == BOARD_SIZE - 1) {
                    SurakartaPosition newPosition(move.to.x, i);
                    interface_to.push_back(newPosition);
                    break;
                }
                int piece_id=(*board_).getPiecesID(move.to.x,++i);
                if (i < BOARD_SIZE - 1) {
                    if (piece_id ==-1|| (move.from.x == move.to.x && move.from.y == i))
                        continue;
                    else
                        break;
                }
                else if (i == BOARD_SIZE - 1&& (piece_id ==-1|| (move.from.x == move.to.x && move.from.y == i))) {
                    SurakartaPosition newPosition(move.to.x, i);
                    interface_to.push_back(newPosition);
                    break;
                }else
                    break;
            }
            i = move.to.y;
            while (1) {
                if (i == 0) {
                    SurakartaPosition newPosition(move.to.x, i);
                    interface_to.push_back(newPosition);
                    break;
                }
                int piece_id=(*board_).getPiecesID(move.to.x,--i);
                if (i > 0 && i < BOARD_SIZE) {
                    if (piece_id ==-1|| (move.from.x == move.to.x && move.from.y == i))
                        continue;
                    else
                        break;
                } else if (i == 0&&(piece_id ==-1 || (move.from.x == move.to.x && move.from.y == i))){
                    SurakartaPosition newPosition(move.to.x, i);
                    interface_to.push_back(newPosition);
                    break;
                }
                else
                    break;
            }
        }
        //////// check
        for (auto i : outface) {
            for (auto j : interface_to) {
                if (i == j) {
                    return SurakartaIllegalMoveReason::LEGAL_CAPTURE_MOVE;
                }
            }
        }

        return SurakartaIllegalMoveReason::ILLIGAL_CAPTURE_MOVE;
    }
    // LEGAL_NON_CAPTURE_MOVE
    flag = 0;
    SurakartaPosition newPosition;
    for (int j = 1; j >= -1; j--) {
        for (int t = 1; t >= -1; t--) {
            if (j == 0 && t == 0)
                continue;
            newPosition = move.from;
            newPosition.x += j;
            newPosition.y += t;
            if (newPosition == move.to) {
                flag = 1;
                break;
            }
            if (flag)
                break;
        }
    }
    if (flag)
        return SurakartaIllegalMoveReason::LEGAL_NON_CAPTURE_MOVE;
    else
        return SurakartaIllegalMoveReason::ILLIGAL_NON_CAPTURE_MOVE;

    return SurakartaIllegalMoveReason::LEGAL;
}

std::pair<SurakartaEndReason, SurakartaPlayer> SurakartaRuleManager::JudgeEnd(const SurakartaIllegalMoveReason reason) {

    if(reason == SurakartaIllegalMoveReason::NO_MOVE){
        if(game_info_->current_player_== SurakartaPlayer::BLACK){
            return std::make_pair(SurakartaEndReason::TIMEOUT, SurakartaPlayer::WHITE);
        }else{
            return std::make_pair(SurakartaEndReason::TIMEOUT, SurakartaPlayer::BLACK);
        }

    }


    // TODO: Implement this function.
    // Note that at this point, the board and game_info have not been updated yet.

    // return std::make_pair(SurakartaEndReason::NONE, SurakartaPlayer::NONE);
    int sum_black = 0;
    int sum_white = 0;
    // if(game_info_->num_round_==12) return std::make_pair(SurakartaEndReason::STALEMATE, SurakartaPlayer::NONE);
    // if(game_info_->num_round_==99) return std::make_pair(SurakartaEndReason::NONE, SurakartaPlayer::NONE);

    for (unsigned int i = 0; i < board_size_; i++) {
        for (unsigned int j = 0; j < board_size_; j++) {
            int pieceID=(*board_).getPiecesID(i,j);
            if(pieceID==-1)
                continue;
            else  {
                PieceColor color = (*board_).piece[pieceID].color_;
                if (color == PieceColor::BLACK) {
                    sum_black++;
                } else if (color == PieceColor::WHITE) {
                    sum_white++;
                }
            }
        }
    }  // get the num of both color sides

    if (sum_black == 1 && sum_white > 0 && game_info_->current_player_ == SurakartaPlayer::WHITE && reason == SurakartaIllegalMoveReason::LEGAL_CAPTURE_MOVE) {
        return std::make_pair(SurakartaEndReason::CHECKMATE, SurakartaPlayer::WHITE);
    } else if (sum_white == 1 && sum_black > 0 && game_info_->current_player_ == SurakartaPlayer::BLACK && reason == SurakartaIllegalMoveReason::LEGAL_CAPTURE_MOVE) {
        return std::make_pair(SurakartaEndReason::CHECKMATE, SurakartaPlayer::BLACK);
    }
    switch (reason) {
    case SurakartaIllegalMoveReason::ILLIGAL_CAPTURE_MOVE:
    case SurakartaIllegalMoveReason::ILLIGAL_NON_CAPTURE_MOVE:
    case SurakartaIllegalMoveReason::NOT_PIECE:
    case SurakartaIllegalMoveReason::NOT_PLAYER_PIECE:
    case SurakartaIllegalMoveReason::NOT_PLAYER_TURN:
    case SurakartaIllegalMoveReason::OUT_OF_BOARD:
        if (game_info_->current_player_ == SurakartaPlayer::BLACK) {
            return std::make_pair(SurakartaEndReason::ILLIGAL_MOVE, SurakartaPlayer::WHITE);
        } else {
            return std::make_pair(SurakartaEndReason::ILLIGAL_MOVE, SurakartaPlayer::BLACK);
        }
    default:
        if ((game_info_->num_round_ - game_info_->last_captured_round_) >= game_info_->max_no_capture_round_ && reason == SurakartaIllegalMoveReason::LEGAL_NON_CAPTURE_MOVE) {
            if (sum_black > sum_white) {
                return std::make_pair(SurakartaEndReason::STALEMATE, SurakartaPlayer::BLACK);
            } else if (sum_black < sum_white) {
                return std::make_pair(SurakartaEndReason::STALEMATE, SurakartaPlayer::WHITE);
            } else {
                return std::make_pair(SurakartaEndReason::STALEMATE, SurakartaPlayer::NONE);
            }
        }
    }

    return std::make_pair(SurakartaEndReason::NONE, SurakartaPlayer::NONE);
}

std::vector<SurakartaPosition> SurakartaRuleManager::GetAllLegalTarget(const SurakartaPosition postion) {

    SurakartaMove possible_steps_tmp;
    std::vector<SurakartaPosition> AllLegalTarget, current_player_, last_player_;
    possible_steps_tmp.player=game_info_->current_player_;
    //获取所棋子的位置
    for (unsigned int i = 0; i < board_size_; i++) {
        for (unsigned int j = 0; j < board_size_; j++) {
            SurakartaPosition position = {i, j};
            int pieceID=(*board_).getPiecesID(i,j);
            if(pieceID<24&&pieceID>=0)
            {
                PieceColor color = (*board_).piece[pieceID].color_;
                if (color == game_info_->current_player_) {
                    current_player_.push_back(position);
                } else if ( color!= PieceColor::NONE) {
                    last_player_.push_back(position);
                }
            }
        }
    }
    possible_steps_tmp.from = postion;
    for (auto j:last_player_) {
        possible_steps_tmp.to = j;
        if (JudgeMove(possible_steps_tmp) == SurakartaIllegalMoveReason::LEGAL_CAPTURE_MOVE) {
            AllLegalTarget.push_back(possible_steps_tmp.to);
        }
    }

    for (int j = 1; j >= -1; j--) {
        for (int t = 1; t >= -1; t--) {
            if (j == 0 && t == 0)
                continue;
            possible_steps_tmp.to = postion;
            possible_steps_tmp.to.x += j;
            possible_steps_tmp.to.y += t;
            if( possible_steps_tmp.to.x>=BOARD_SIZE|| possible_steps_tmp.to.y>=BOARD_SIZE|| possible_steps_tmp.to.x<0|| possible_steps_tmp.to.y<0)
                continue;
            if ((JudgeMove(possible_steps_tmp)) == SurakartaIllegalMoveReason::LEGAL_NON_CAPTURE_MOVE) {
                AllLegalTarget.push_back(possible_steps_tmp.to);
            }
        }
    }
    return AllLegalTarget;
}
