#--------------------------------------------------
#
# Project created by QtCreator 2021-10-15т09:09:19
#
#--------------------------------------------------

QT    += core gui

greaterThan(QT_MAJOR_VERSION, 4) : QT += widget

TARGET = testFind
TEMPLATE = app

# They following define makes your compiler emit warnings is you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.

DEFINES += QT_DEPRECATED_WARNINGS

# You can alse make your code to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x06000 # disable all the APIs deprecated before Qt 6.0.0

SOURCES += \
	main.cpp
	countip.cpp

HEADERS += \
	countip.h

FORMS += \
	testing.ui
