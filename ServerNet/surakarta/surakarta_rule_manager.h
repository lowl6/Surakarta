#pragma once

// #include <iostream>


#include <memory>
#include <vector>
#include "surakarta_common.h"
//#include "surakarta_game.h"



#include <QTimer>
#include <QObject>

class SurakartaRuleManager : public QObject {
    Q_OBJECT // 必须添加这个宏来启用 Qt 的元对象系统

public:
    //SurakartaRuleManager(QObject *parent = nullptr) : QObject(parent) {}

    SurakartaRuleManager(std::shared_ptr<SurakartaBoard> board,
                         std::shared_ptr<SurakartaGameInfo> game_info)
        :
        board_(std::const_pointer_cast<const SurakartaBoard>(board)),
        game_info_(std::const_pointer_cast<const SurakartaGameInfo>(game_info)) {
        board_size_ = BOARD_SIZE;

    }


    virtual void OnUpdateBoard();

    /**
     * @brief Judge whether a move is legal.
     * @param move The move to be judged.
     */
    virtual SurakartaIllegalMoveReason JudgeMove(const SurakartaMove& move);

    /**
     * @brief Judge whether the game is end.
     * @param reason SurakartaIllegalMoveReason of the last move.
     */
    virtual std::pair<SurakartaEndReason, SurakartaPlayer> JudgeEnd(const SurakartaIllegalMoveReason reason);

    /**
     * @brief Get all legal target positions of a piece.
     * @param postion The position of the piece.
     */
    virtual std::unique_ptr<std::vector<SurakartaPosition>> GetAllLegalTarget(const SurakartaPosition postion);

    //    protected:
    //SurakartaGame game_;
    unsigned int board_size_;
    std::shared_ptr<const SurakartaBoard> board_;
    std::shared_ptr<const SurakartaGameInfo> game_info_;
    //std::shared_ptr<const SurakartaGame> game_;




   public:

    // TODO:
    //  define your own functions/variables here
    // void HelloWorld();

    // void InlineHelloWorld() {
    //     std::cout << "Hello World!" << std::endl;
    // }
    // int bye_world_ = 0;
};
