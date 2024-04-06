// #include <chrono>
// #include <iostream>
// #include <thread>
// #include "surakarta_agent/surakarta_agent_mine.h"
// #include "surakarta_agent/surakarta_agent_random.h"
#include "surakarta_board.h"
#include "widget.h"
// #include "surakarta_common.h"
// #include "surakarta_game.h"
#include <QApplication>
#include <QHBoxLayout>
// #define ANSI_CLEAR_SCREEN "\033[2J"
// #define ANSI_MOVE_TO_START "\033[H"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 创建主窗口
    // Widget mainWindow;

    // 创建居中的水平布局管理器
    // QHBoxLayout *layout = new QHBoxLayout(&mainWindow);
    // layout->setAlignment(Qt::AlignCenter); // 设置布局居中对齐

    // // 创建棋盘部件
    SurakartaBoard chessBoard;

    // // 将棋盘部件添加到布局管理器
    // layout->addWidget(chessBoard);

    // // 设置主窗口布局
    // mainWindow.setLayout(layout);

    // 显示主窗口
    chessBoard.show();

    return a.exec();
}
