// #include "surakarta_agent_mine.h"
// #include <algorithm>
// #include <cstdlib>
// #include <random>
// #include <vector>
// #include "../surakarta_common.h"
// #include "../global_random_generator.h"
// #define possible_move_Restriction 20
// struct Score_steps {
//     SurakartaMove move;
//     int score;  // 等级：1， 2， 3，4
// };
// std::vector<SurakartaPosition> current_player_, last_player_, empty_space, threatened_empty_space, threatened_my_space, threatened_your_space;

// std::vector<SurakartaPosition> Find_threatened_positions(std::vector<SurakartaPosition> Predator, std::vector<SurakartaPosition> Hunting_range, std::shared_ptr<SurakartaRuleManager> my_rule_manager_) {
//     SurakartaMove possible_captures;
//     std::vector<SurakartaPosition> threatened_positions;
//     for (unsigned int i = 0; i < Predator.size(); i++) {
//         possible_captures.from = Predator[i];
//         for (unsigned int j = 0; j < Hunting_range.size(); j++) {
//             possible_captures.to = Hunting_range[j];
//             if (my_rule_manager_->JudgeMove(possible_captures) == SurakartaIllegalMoveReason::LEGAL_CAPTURE_MOVE) {
//                 threatened_positions.push_back(Hunting_range[j]);
//             }
//         }
//     }
//     return threatened_positions;
// }
// bool compareScore(const Score_steps& a, const Score_steps& b) {
//     return a.score > b.score;  // 按照 score 从大到小排序
// }

// int Calculate_step_score(SurakartaMove move) {
//     int score = 0;
//     // 逃离危险
//     for (SurakartaPosition step : threatened_empty_space) {
//         if (move.to == step) {
//             score -= 3;
//             break;
//         }
//     }
//     for (SurakartaPosition step : threatened_my_space) {
//         if (move.from == step) {
//             score += 2;
//             break;
//         }
//     }

//     return score;
// }

// SurakartaMove SurakartaAgentMine::CalculateMove() {
//     // 获取位置:
//     for (unsigned int i = 0; i < board_size_; i++) {
//         for (unsigned int j = 0; j < board_size_; j++) {
//             SurakartaPosition position = {i, j};
//             if ((*board_)[i][j]->GetColor() == game_info_->current_player_) {
//                 current_player_.push_back(position);
//             } else if ((*board_)[i][j]->GetColor() == PieceColor::NONE) {
//                 empty_space.push_back(position);
//             } else
//                 last_player_.push_back(position);
//         }
//     }
//     SurakartaMove possible_captures;
//     for (unsigned int i = 0; i < current_player_.size(); i++) {
//         possible_captures.from = current_player_[i];
//         for (unsigned int j = 0; j < last_player_.size(); j++) {
//             possible_captures.to = last_player_[j];
//             if (rule_manager_->JudgeMove(possible_captures) == SurakartaIllegalMoveReason::LEGAL_CAPTURE_MOVE) {
//                 return possible_captures;
//             }
//         }
//     }

//     threatened_empty_space = Find_threatened_positions(last_player_, empty_space, rule_manager_);
//     threatened_my_space = Find_threatened_positions(last_player_, current_player_, rule_manager_);

//     std::vector<Score_steps> possible_steps_save;

//     SurakartaMove steps_Final_choice;
//     unsigned int possible_move_cnt = 0;
//     Score_steps possible_steps_tmp;
//     int flag = 0;

//     std::shuffle(current_player_.begin(), current_player_.end(), GlobalRandomGenerator::getInstance());
//     // 穷举八种位移
//     for (unsigned int i = 0; i < current_player_.size(); i++) {
//         possible_steps_tmp.move.from = current_player_[i];
//         for (int j = 1; j >= -1; j--) {
//             for (int t = 1; t >= -1; t--) {
//                 if (j == 0 && t == 0)
//                     continue;

//                 possible_steps_tmp.move.to = current_player_[i];
//                 possible_steps_tmp.move.to.x += j;
//                 possible_steps_tmp.move.to.y += t;

//                 if (IsLegalMoveReason(rule_manager_->JudgeMove(possible_steps_tmp.move))) {
//                     possible_move_cnt++;
//                     // 防止超时
//                     // 下面开始判分
//                     possible_steps_tmp.score = Calculate_step_score(possible_steps_tmp.move);
//                     possible_steps_save.push_back(possible_steps_tmp);
//                     if (possible_move_cnt >= possible_move_Restriction) {
//                         flag = 1;
//                         break;
//                     }
//                 }
//             }
//             if (flag)
//                 break;
//         }
//         if (flag)
//             break;
//     }

//     std::sort(possible_steps_save.begin(), possible_steps_save.end(), compareScore);
//     return possible_steps_save[0].move;
//     // TODO: Implement your own ai here.
// }
