QT       += core gui
QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addform.cpp \
    bookFile.cpp \
    countmodelform.cpp \
    delform.cpp \
    findform.cpp \
    graphicform.cpp \
    listform.cpp \
    main.cpp \
    mainwindow.cpp \
    srokform.cpp

HEADERS += \
    addform.h \
    bookFile.h \
    countmodelform.h \
    delform.h \
    findform.h \
    graphicform.h \
    listform.h \
    mainwindow.h \
    srokform.h

FORMS += \
    addform.ui \
    countmodelform.ui \
    delform.ui \
    findform.ui \
    graphicform.ui \
    listform.ui \
    mainwindow.ui \
    srokform.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
