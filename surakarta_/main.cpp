// #include "surakarta/surakarta_agent/surakarta_agent_mine.h"
// #include "surakarta/surakarta_agent/surakarta_agent_random.h"
#include <QApplication>
#include <ui_widget.h>
#include "mainbegin.h"
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    mainbegin begin;
    begin.show();
    return app.exec();
}//进入widget.h文件里面，自动调用了构造函数？？
