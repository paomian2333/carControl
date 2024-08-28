QT       += core gui
QT +=multimedia
QT += xml
QT       += core gui  network
RC_ICONS = application.ico
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets



CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    chatLogin.cpp \
    clockwidget.cpp \
    imageviewer.cpp \
    main.cpp \
    mainwindow.cpp \
    map.cpp \
    musicwindow.cpp \
    timewindow.cpp \
    weatherReport.cpp \
    widget.cpp

HEADERS += \
    chatLogin.h \
    clockwidget.h \
    imageviewer.h \
    mainwindow.h \
    map.h \
    musicwindow.h \
    timewindow.h \
    weatherReport.h \
    widget.h

FORMS += \
    chatLogin.ui \
    mainwindow.ui \
    map.ui \
    musicwindow.ui \
    timewindow.ui \
    weatherReport.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc \
    res.qrc \
    res_chatroom.qrc \
    sources.qrc \
    application.qrc
DISTFILES += \
    sources/back.png \
    sources/backward_fill.png \
    sources/cat.png \
    sources/file.png \
    sources/forward_fill.png \
    sources/menu.png \
    sources/music_playmode_order.png \
    sources/music_playmode_random.png \
    sources/notification.png \
    sources/notification_fill.png \
    sources/play_fill.png \
    sources/right.png \
    sources/search.png \
    sources/songtab_playmode_singlecycle.png \
    sources/stop.png

INCLUDEPATH += C:\Users\lenovo\Desktop\ImageViewer-master\OpenCV4.1.2_contrib_MinGW64-master\OpenCV-412-Contrib-MinGW64\include

LIBS += C:\Users\lenovo\Desktop\ImageViewer-master\OpenCV4.1.2_contrib_MinGW64-master\OpenCV-412-Contrib-MinGW64\x64\mingw\bin\libopencv_core412.dll
LIBS += C:\Users\lenovo\Desktop\ImageViewer-master\OpenCV4.1.2_contrib_MinGW64-master\OpenCV-412-Contrib-MinGW64\x64\mingw\bin\libopencv_highgui412.dll
LIBS += C:\Users\lenovo\Desktop\ImageViewer-master\OpenCV4.1.2_contrib_MinGW64-master\OpenCV-412-Contrib-MinGW64\x64\mingw\bin\libopencv_imgcodecs412.dll
LIBS += C:\Users\lenovo\Desktop\ImageViewer-master\OpenCV4.1.2_contrib_MinGW64-master\OpenCV-412-Contrib-MinGW64\x64\mingw\bin\libopencv_imgproc412.dll
LIBS += C:\Users\lenovo\Desktop\ImageViewer-master\OpenCV4.1.2_contrib_MinGW64-master\OpenCV-412-Contrib-MinGW64\x64\mingw\bin\libopencv_features2d412.dll
LIBS += C:\Users\lenovo\Desktop\ImageViewer-master\OpenCV4.1.2_contrib_MinGW64-master\OpenCV-412-Contrib-MinGW64\x64\mingw\bin\libopencv_calib3d412.dll
