#-------------------------------------------------
#
# Project created by QtCreator 2017-12-14T20:37:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PixelGates
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#QMAKE_CXXFLAGS += -std=c++17

SOURCES +=\
	src/main.cpp \
	src/mainwindow.cpp \
	src/gates/CompGate.cpp \
	src/gates/IfGate.cpp \
	src/gates/LogicGate.cpp \
	src/gates/PaletteGate.cpp \
	src/Palette.cpp \
	src/RenderArea.cpp \
	src/gates/PixelGate.cpp \
	src/gates/Gate.cpp \
	src/gates/FuncGate.cpp \
	src/gates/ConstGate.cpp \
	src/Socket.cpp \
	src/gates/RenderGate.cpp \
    src/Workspace.cpp \
    src/gates/MathGate.cpp

HEADERS  +=\
	mainwindow.h \
        include/Gate.h \
        include/IfGate.h \
        include/LogicGate.h \
        include/Palette.h \
        include/PaletteGate.h \
        include/RenderArea.h \
        include/CompGate.h \
        include/ConstGate.h \
        include/PixelGate.h \
        include/data_t.h \
        include/FuncGate.h \
        include/Socket.h \
        include/RenderGate.h \
    include/Workspace.h \
    include/MathGate.h

FORMS    += mainwindow.ui
