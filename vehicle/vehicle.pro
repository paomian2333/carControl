QT       += core gui multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    clockwidget.cpp \
    main.cpp \
    mainwindow.cpp \
    musicwindow.cpp \
    timewindow.cpp \
    weatherwindow.cpp

HEADERS += \
    clockwidget.h \
    mainwindow.h \
    musicwindow.h \
    timewindow.h \
    weatherwindow.h

FORMS += \
    mainwindow.ui \
    musicwindow.ui \
    timewindow.ui \
    weatherwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
