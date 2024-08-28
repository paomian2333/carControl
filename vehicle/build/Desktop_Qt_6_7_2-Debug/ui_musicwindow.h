/********************************************************************************
** Form generated from reading UI file 'musicwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MUSICWINDOW_H
#define UI_MUSICWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MusicWindow
{
public:
    QWidget *centralwidget;
    QSlider *playSlider;
    QLineEdit *lineEdit;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *curLabel;
    QSpacerItem *horizontalSpacer_5;
    QLabel *totalLabel;
    QPushButton *searchButton;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *opendicButton;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *modeButton;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *lastButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *playButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *nextButton;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *volumeButton;
    QListWidget *Netlist;
    QPushButton *menuButton;
    QSlider *volumeSlider;
    QListWidget *listWidget;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MusicWindow)
    {
        if (MusicWindow->objectName().isEmpty())
            MusicWindow->setObjectName("MusicWindow");
        MusicWindow->resize(800, 600);
        centralwidget = new QWidget(MusicWindow);
        centralwidget->setObjectName("centralwidget");
        playSlider = new QSlider(centralwidget);
        playSlider->setObjectName("playSlider");
        playSlider->setGeometry(QRect(1, 472, 771, 18));
        playSlider->setOrientation(Qt::Orientation::Horizontal);
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(160, 260, 181, 28));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(1, 442, 801, 23));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        curLabel = new QLabel(layoutWidget);
        curLabel->setObjectName("curLabel");

        horizontalLayout_2->addWidget(curLabel);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        totalLabel = new QLabel(layoutWidget);
        totalLabel->setObjectName("totalLabel");

        horizontalLayout_2->addWidget(totalLabel);

        searchButton = new QPushButton(centralwidget);
        searchButton->setObjectName("searchButton");
        searchButton->setGeometry(QRect(360, 260, 41, 31));
        searchButton->setStyleSheet(QString::fromUtf8("border-image:url(:/sources/search.png);"));
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 490, 781, 82));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        opendicButton = new QPushButton(widget);
        opendicButton->setObjectName("opendicButton");
        opendicButton->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(opendicButton->sizePolicy().hasHeightForWidth());
        opendicButton->setSizePolicy(sizePolicy);
        opendicButton->setMinimumSize(QSize(50, 50));
        opendicButton->setMaximumSize(QSize(50, 50));
        opendicButton->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        opendicButton->setAcceptDrops(false);
        opendicButton->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        opendicButton->setAutoFillBackground(false);
        opendicButton->setStyleSheet(QString::fromUtf8("border-image: url(:/sources/file.png);\n"
""));
        opendicButton->setCheckable(false);

        horizontalLayout->addWidget(opendicButton);

        horizontalSpacer_6 = new QSpacerItem(20, 20, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        modeButton = new QPushButton(widget);
        modeButton->setObjectName("modeButton");
        sizePolicy.setHeightForWidth(modeButton->sizePolicy().hasHeightForWidth());
        modeButton->setSizePolicy(sizePolicy);
        modeButton->setMinimumSize(QSize(60, 0));
        modeButton->setMaximumSize(QSize(60, 60));
        modeButton->setStyleSheet(QString::fromUtf8("border-image:url(:/sources/music_playmode_order.png)"));

        horizontalLayout->addWidget(modeButton);

        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        lastButton = new QPushButton(widget);
        lastButton->setObjectName("lastButton");
        sizePolicy.setHeightForWidth(lastButton->sizePolicy().hasHeightForWidth());
        lastButton->setSizePolicy(sizePolicy);
        lastButton->setMinimumSize(QSize(60, 60));
        lastButton->setMaximumSize(QSize(60, 60));
        lastButton->setStyleSheet(QString::fromUtf8("border-image:url(:/sources/backward_fill.png)"));

        horizontalLayout->addWidget(lastButton);

        horizontalSpacer = new QSpacerItem(48, 20, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        playButton = new QPushButton(widget);
        playButton->setObjectName("playButton");
        playButton->setEnabled(true);
        sizePolicy.setHeightForWidth(playButton->sizePolicy().hasHeightForWidth());
        playButton->setSizePolicy(sizePolicy);
        playButton->setMinimumSize(QSize(60, 60));
        playButton->setMaximumSize(QSize(60, 60));
        playButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-image: url(:/sources/play_fill.png);\n"
"\n"
"}\n"
""));
        playButton->setCheckable(true);

        horizontalLayout->addWidget(playButton);

        horizontalSpacer_2 = new QSpacerItem(50, 20, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        nextButton = new QPushButton(widget);
        nextButton->setObjectName("nextButton");
        sizePolicy.setHeightForWidth(nextButton->sizePolicy().hasHeightForWidth());
        nextButton->setSizePolicy(sizePolicy);
        nextButton->setMinimumSize(QSize(0, 60));
        nextButton->setMaximumSize(QSize(60, 60));
        nextButton->setStyleSheet(QString::fromUtf8("border-image:url(:/sources/forward_fill.png)"));

        horizontalLayout->addWidget(nextButton);

        horizontalSpacer_3 = new QSpacerItem(80, 20, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        volumeButton = new QPushButton(widget);
        volumeButton->setObjectName("volumeButton");
        sizePolicy.setHeightForWidth(volumeButton->sizePolicy().hasHeightForWidth());
        volumeButton->setSizePolicy(sizePolicy);
        volumeButton->setMaximumSize(QSize(60, 60));
        volumeButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"\n"
"border-image:url(:/sources/notification_fill.png)\n"
"}\n"
""));
        volumeButton->setCheckable(true);
        volumeButton->setChecked(false);
        volumeButton->setAutoExclusive(true);

        horizontalLayout->addWidget(volumeButton);

        Netlist = new QListWidget(centralwidget);
        Netlist->setObjectName("Netlist");
        Netlist->setGeometry(QRect(150, 321, 256, 81));
        menuButton = new QPushButton(centralwidget);
        menuButton->setObjectName("menuButton");
        menuButton->setGeometry(QRect(0, 0, 51, 41));
        menuButton->setStyleSheet(QString::fromUtf8("border-image:url(:/sources/menu.png)"));
        volumeSlider = new QSlider(centralwidget);
        volumeSlider->setObjectName("volumeSlider");
        volumeSlider->setGeometry(QRect(811, 472, 18, 84));
        volumeSlider->setOrientation(Qt::Orientation::Vertical);
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(440, 50, 351, 361));
        MusicWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MusicWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 27));
        MusicWindow->setMenuBar(menubar);

        retranslateUi(MusicWindow);

        QMetaObject::connectSlotsByName(MusicWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MusicWindow)
    {
        MusicWindow->setWindowTitle(QCoreApplication::translate("MusicWindow", "MainWindow", nullptr));
        curLabel->setText(QCoreApplication::translate("MusicWindow", "00:00", nullptr));
        totalLabel->setText(QCoreApplication::translate("MusicWindow", "00:00", nullptr));
        searchButton->setText(QString());
        opendicButton->setText(QString());
        modeButton->setText(QString());
        lastButton->setText(QString());
        playButton->setText(QString());
        nextButton->setText(QString());
        volumeButton->setText(QString());
        menuButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MusicWindow: public Ui_MusicWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUSICWINDOW_H
