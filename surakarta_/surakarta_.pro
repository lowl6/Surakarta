QT       += core gui
QT       +=network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ClientNet/client.cpp \
    NetworkLibrary/networkdata.cpp \
    NetworkLibrary/networksocket.cpp \
    main.cpp \
    mainbegin.cpp \
    netwindow.cpp \
    surakarta/surakarta_board.cpp \
    surakarta/surakarta_game.cpp \
    surakarta/surakarta_reason.cpp \
    surakarta/surakarta_rule_manager.cpp \
    widget.cpp

HEADERS += \
    ClientNet/client.h \
    ClientNet/ui_client.h \
    NetworkLibrary/networkdata.h \
    NetworkLibrary/networksocket.h \
    mainbegin.h \
    netwindow.h \
    surakarta/global_random_generator.h \
    surakarta/surakarta_board.h \
    surakarta/surakarta_common.h \
    surakarta/surakarta_game.h \
    surakarta/surakarta_piece.h \
    surakarta/surakarta_reason.h \
    surakarta/surakarta_rule_manager.h \
    widget.h\

FORMS += \
    ClientNet/client.ui \
    mainbegin.ui \
    netwindow.ui \
    surakarta/surakarta_board.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    imagines.qrc
