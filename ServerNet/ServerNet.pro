QT       += core gui
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    NetworkLibrary/networkdata.cpp \
    NetworkLibrary/networkserver.cpp \
    main.cpp \
    mainwindow.cpp \
    surakarta/surakarta_board.cpp \
    surakarta/surakarta_reason.cpp \
    surakarta/surakarta_rule_manager.cpp

HEADERS += \
    NetworkLibrary/networkdata.h \
    NetworkLibrary/networkserver.h \
    ServerNet/mainwindow.h \
    ServerNet/ui_mainwindow.h \
    mainwindow.h \
    surakarta/surakarta_board.h \
    surakarta/surakarta_common.h \
    surakarta/surakarta_piece.h \
    surakarta/surakarta_reason.h \
    surakarta/surakarta_rule_manager.h \
    ui_mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
