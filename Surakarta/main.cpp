#include <chrono>
#include <iostream>
#include <thread>
#include <QWidget>
#include "surakarta_agent/surakarta_agent_mine.h"
#include "surakarta_agent/surakarta_agent_random.h"
#include "surakarta_common.h"
#include "surakarta_game.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget w;
    w.show();

    return a.exec();
}
