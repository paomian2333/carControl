/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_time;
    QPushButton *pushButton_weather;
    QHBoxLayout *horizontalLayout;
    QLCDNumber *lcdNumber_hour;
    QLCDNumber *lcdNumber_minute;
    QLCDNumber *lcdNumber_secnd;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_music;
    QPushButton *pushButton_video;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_3;
    QPushButton *pushButton_map;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(592, 446);
        QFont font;
        font.setFamilies({QString::fromUtf8("\344\273\277\345\256\213")});
        font.setPointSize(30);
        MainWindow->setFont(font);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_5 = new QVBoxLayout(centralwidget);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalSpacer = new QSpacerItem(20, 48, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        label = new QLabel(centralwidget);
        label->setObjectName("label");
        QPalette palette;
        QBrush brush(QColor(255, 0, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QBrush brush1(QColor(255, 0, 255, 128));
        brush1.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush1);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush1);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush1);
#endif
        label->setPalette(palette);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Microsoft YaHei UI")});
        font1.setPointSize(30);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(255, 0, 255);"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label);

        verticalSpacer_2 = new QSpacerItem(20, 28, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);


        verticalLayout_5->addLayout(verticalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer = new QSpacerItem(58, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        pushButton_time = new QPushButton(centralwidget);
        pushButton_time->setObjectName("pushButton_time");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\344\273\277\345\256\213")});
        font2.setPointSize(10);
        pushButton_time->setFont(font2);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/mainwindow_image/tine.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_time->setIcon(icon);

        verticalLayout->addWidget(pushButton_time);

        pushButton_weather = new QPushButton(centralwidget);
        pushButton_weather->setObjectName("pushButton_weather");
        pushButton_weather->setFont(font2);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icon/mainwindow_image/weather.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_weather->setIcon(icon1);

        verticalLayout->addWidget(pushButton_weather);


        horizontalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        lcdNumber_hour = new QLCDNumber(centralwidget);
        lcdNumber_hour->setObjectName("lcdNumber_hour");
        QPalette palette1;
        QBrush brush2(QColor(255, 0, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        lcdNumber_hour->setPalette(palette1);
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Microsoft YaHei UI")});
        font3.setPointSize(20);
        lcdNumber_hour->setFont(font3);

        horizontalLayout->addWidget(lcdNumber_hour);

        lcdNumber_minute = new QLCDNumber(centralwidget);
        lcdNumber_minute->setObjectName("lcdNumber_minute");
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        lcdNumber_minute->setPalette(palette2);
        lcdNumber_minute->setFont(font3);

        horizontalLayout->addWidget(lcdNumber_minute);

        lcdNumber_secnd = new QLCDNumber(centralwidget);
        lcdNumber_secnd->setObjectName("lcdNumber_secnd");
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        lcdNumber_secnd->setPalette(palette3);
        lcdNumber_secnd->setFont(font3);
        lcdNumber_secnd->setFrameShape(QFrame::Box);
        lcdNumber_secnd->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(lcdNumber_secnd);


        horizontalLayout_2->addLayout(horizontalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        pushButton_music = new QPushButton(centralwidget);
        pushButton_music->setObjectName("pushButton_music");
        pushButton_music->setFont(font2);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icon/mainwindow_image/music.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_music->setIcon(icon2);

        verticalLayout_2->addWidget(pushButton_music);

        pushButton_video = new QPushButton(centralwidget);
        pushButton_video->setObjectName("pushButton_video");
        pushButton_video->setFont(font2);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icon/mainwindow_image/video.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_video->setIcon(icon3);

        verticalLayout_2->addWidget(pushButton_video);


        horizontalLayout_2->addLayout(verticalLayout_2);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        horizontalSpacer_2 = new QSpacerItem(58, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_5->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalSpacer_3 = new QSpacerItem(158, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalSpacer_3 = new QSpacerItem(20, 68, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        pushButton_map = new QPushButton(centralwidget);
        pushButton_map->setObjectName("pushButton_map");
        pushButton_map->setFont(font2);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icon/mainwindow_image/map.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_map->setIcon(icon4);

        verticalLayout_3->addWidget(pushButton_map);

        verticalSpacer_4 = new QSpacerItem(20, 68, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_4);


        horizontalLayout_4->addLayout(verticalLayout_3);

        horizontalSpacer_4 = new QSpacerItem(178, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        horizontalLayout_4->setStretch(0, 2);
        horizontalLayout_4->setStretch(1, 5);
        horizontalLayout_4->setStretch(2, 2);

        verticalLayout_5->addLayout(horizontalLayout_4);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\350\275\246\350\275\275\347\263\273\347\273\237", nullptr));
        pushButton_time->setText(QCoreApplication::translate("MainWindow", "\346\227\266\351\227\264\346\230\276\347\244\272", nullptr));
        pushButton_weather->setText(QCoreApplication::translate("MainWindow", "\345\244\251\346\260\224\347\263\273\347\273\237", nullptr));
        pushButton_music->setText(QCoreApplication::translate("MainWindow", "\351\237\263\344\271\220\346\222\255\346\224\276", nullptr));
        pushButton_video->setText(QCoreApplication::translate("MainWindow", "\350\247\206\351\242\221\346\222\255\346\224\276", nullptr));
        pushButton_map->setText(QCoreApplication::translate("MainWindow", "\350\275\246\350\275\275\345\257\274\350\210\252", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
