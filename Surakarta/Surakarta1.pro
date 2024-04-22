QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    surakarta_board.cpp \
    widget.cpp \
    surakarta_game.cpp \
    surakarta_reason.cpp \
    surakarta_rule_manager.cpp\
    surakarta_agent/surakarta_agent_mine.cpp\

HEADERS += \
    surakarta_board.h \
    surakarta_piece.h \
    ui_widget.h \
    widget.h \
    global_random_generator.h \
    surakarta_common.h \
    surakarta_reason.h \
    surakarta_rule_manager.h \
    surakarta_game.h\
    surakarta_agent/surakarta_agent_base.h\
    surakarta_agent/surakarta_agent_mine.h\

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
     widget.ui

MOC += surakarta_rule_manager.h
MOC += surakarta_game.h
