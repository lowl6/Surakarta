// #include "surakarta/surakarta_agent/surakarta_agent_mine.h"
// #include "surakarta/surakarta_agent/surakarta_agent_random.h"
#include "widget.h"
#include <QApplication>
#include <ui_widget.h>
// #define ANSI_CLEAR_SCREEN "\033[2J"
// #define ANSI_MOVE_TO_START "\033[H"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget chessboard;
    chessboard.show();
    return a.exec();
}//进入widget.h文件里面，自动调用了构造函数
