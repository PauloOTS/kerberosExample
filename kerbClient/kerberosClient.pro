#-------------------------------------------------
#
# Project created by QtCreator 2017-04-14T15:28:06
#
#-------------------------------------------------

QT       += core gui
QT	 += sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = kerberosClient
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


LIBS += -lcryptopp

INCLUDEPATH = include

SOURCES += src/main.cpp\
        src/kerberosclient.cpp \
    src/clientdb.cpp \
    src/login.cpp \
    src/kerbcrypto.cpp \
    src/requestticketas.cpp

HEADERS  += include/kerberosclient.h \
    include/clientdb.h \
    include/login.h \
    include/kerbcrypto.h \
    include/requestticketas.h

FORMS    += kerberosclient.ui \
    login.ui
