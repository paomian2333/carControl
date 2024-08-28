/********************************************************************************
** Form generated from reading UI file 'ydplayermainwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_YDPLAYERMAINWIDGET_H
#define UI_YDPLAYERMAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_YDPlayerMainWidget
{
public:
    QFrame *frameBottom;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QSlider *horizontalSlider;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonPlay;
    QSpacerItem *horizontalSpacer_2;
    QLabel *labelTime;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButtonSpeaker;
    QSpacerItem *horizontalSpacer_6;
    QFrame *frameVolume;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelVolume;
    QSlider *verticalSlider;
    QPushButton *pushButtonReplay;
    QPushButton *btnOpenFile;

    void setupUi(QWidget *YDPlayerMainWidget)
    {
        if (YDPlayerMainWidget->objectName().isEmpty())
            YDPlayerMainWidget->setObjectName("YDPlayerMainWidget");
        YDPlayerMainWidget->resize(1084, 610);
        YDPlayerMainWidget->setMinimumSize(QSize(1084, 610));
        YDPlayerMainWidget->setStyleSheet(QString::fromUtf8("QWidget#YDPlayerMainWidget\n"
"{\n"
"background:#45484E;\n"
"}"));
        frameBottom = new QFrame(YDPlayerMainWidget);
        frameBottom->setObjectName("frameBottom");
        frameBottom->setGeometry(QRect(210, 520, 477, 48));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frameBottom->sizePolicy().hasHeightForWidth());
        frameBottom->setSizePolicy(sizePolicy);
        frameBottom->setMinimumSize(QSize(0, 48));
        frameBottom->setMaximumSize(QSize(16777215, 48));
        frameBottom->setFrameShape(QFrame::StyledPanel);
        frameBottom->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frameBottom);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, -1, 0, -1);
        horizontalSpacer_3 = new QSpacerItem(30, 5, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        horizontalSlider = new QSlider(frameBottom);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setMinimumSize(QSize(0, 8));
        horizontalSlider->setMaximumSize(QSize(16777215, 8));
        horizontalSlider->setFocusPolicy(Qt::NoFocus);
        horizontalSlider->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"border:none;\n"
"background:none;\n"
"height: 4px;\n"
"border-radius:2px;\n"
"padding-left:-1px;\n"
"padding-right:-1px;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"background:rgba(246, 76, 40, 1);\n"
"border:none;\n"
"height: 4px;\n"
"border-radius: 2px;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal {\n"
"background:rgba(153, 153, 153, 0.6);\n"
"border:none;\n"
"height:4px;\n"
"border-radius: 2px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal \n"
"{\n"
"    background:rgba(255, 255, 255, 1);\n"
"    width:6px;\n"
"	height:6px;\n"
"	margin-top:-1px;\n"
"	margin-bottom:-1px;\n"
"    border-radius:3px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:hover \n"
"{\n"
"    background:rgba(255, 255, 255, 1);\n"
"    width:8px;\n"
"	height:8px;\n"
"    border-radius:4px;\n"
"	margin-top:-1px;\n"
"	margin-bottom:-1px;\n"
"}\n"
"\n"
"\n"
"\n"
"QSlider::groove:horizontal:hover {\n"
"border:none;\n"
"background:none;\n"
"height: 6px;\n"
"border-radius:3px;\n"
"padding-left:-1px;\n"
"padding-rig"
                        "ht:-1px;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal:hover {\n"
"background:rgba(246, 76, 40, 1);\n"
"border:none;\n"
"height: 6px;\n"
"border-radius: 3px;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal:hover {\n"
"background:rgba(153, 153, 153, 0.6);\n"
"border:none;\n"
"height:6px;\n"
"border-radius: 3px;\n"
"}"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(horizontalSlider);

        horizontalSpacer_4 = new QSpacerItem(30, 5, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(-1, -1, 0, -1);
        horizontalSpacer = new QSpacerItem(30, 5, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButtonPlay = new QPushButton(frameBottom);
        pushButtonPlay->setObjectName("pushButtonPlay");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButtonPlay->sizePolicy().hasHeightForWidth());
        pushButtonPlay->setSizePolicy(sizePolicy1);
        pushButtonPlay->setMinimumSize(QSize(28, 32));
        pushButtonPlay->setMaximumSize(QSize(28, 32));
        pushButtonPlay->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButtonPlay->setFocusPolicy(Qt::NoFocus);
        pushButtonPlay->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background:none;\n"
"	border:none;\n"
"	image: url(:/images/icon_play.png);\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	background:none;\n"
"	border:none;\n"
"	image: url(:/images/icon_play_hover.png);\n"
"}"));

        horizontalLayout->addWidget(pushButtonPlay);

        horizontalSpacer_2 = new QSpacerItem(70, 5, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        labelTime = new QLabel(frameBottom);
        labelTime->setObjectName("labelTime");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(labelTime->sizePolicy().hasHeightForWidth());
        labelTime->setSizePolicy(sizePolicy2);
        labelTime->setMinimumSize(QSize(88, 0));
        labelTime->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"color:rgba(255, 255, 255, 1);\n"
"font-family:\"Microsoft YaHei\";\n"
"font-size:14px;\n"
"border:none;\n"
"background:none;\n"
"}"));

        horizontalLayout->addWidget(labelTime);

        horizontalSpacer_5 = new QSpacerItem(40, 5, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        pushButtonSpeaker = new QPushButton(frameBottom);
        pushButtonSpeaker->setObjectName("pushButtonSpeaker");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pushButtonSpeaker->sizePolicy().hasHeightForWidth());
        pushButtonSpeaker->setSizePolicy(sizePolicy3);
        pushButtonSpeaker->setMinimumSize(QSize(24, 0));
        pushButtonSpeaker->setMaximumSize(QSize(24, 100));
        pushButtonSpeaker->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButtonSpeaker->setFocusPolicy(Qt::NoFocus);
        pushButtonSpeaker->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background:none;\n"
"	border:none;\n"
"	image: url(:/images/icon_speaker.png);\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	background:none;\n"
"	border:none;\n"
"	image: url(:/images/icon_speaker_hover.png);\n"
"}"));

        horizontalLayout->addWidget(pushButtonSpeaker);

        horizontalSpacer_6 = new QSpacerItem(175, 5, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout);

        frameVolume = new QFrame(YDPlayerMainWidget);
        frameVolume->setObjectName("frameVolume");
        frameVolume->setGeometry(QRect(170, 190, 36, 140));
        sizePolicy1.setHeightForWidth(frameVolume->sizePolicy().hasHeightForWidth());
        frameVolume->setSizePolicy(sizePolicy1);
        frameVolume->setMinimumSize(QSize(36, 140));
        frameVolume->setMaximumSize(QSize(36, 140));
        frameVolume->setStyleSheet(QString::fromUtf8("QFrame#frameVolume\n"
"{\n"
"	background:rgba(51, 51, 51, 0.9);\n"
"}"));
        frameVolume->setFrameShape(QFrame::StyledPanel);
        frameVolume->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frameVolume);
        verticalLayout_2->setSpacing(4);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 4, 0, 15);
        labelVolume = new QLabel(frameVolume);
        labelVolume->setObjectName("labelVolume");
        labelVolume->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"color:rgba(255, 255, 255, 1);\n"
"font-family:\"Microsoft YaHei\";\n"
"font-size:12px;\n"
"border:none;\n"
"background:none;\n"
"}"));
        labelVolume->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(labelVolume);

        verticalSlider = new QSlider(frameVolume);
        verticalSlider->setObjectName("verticalSlider");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(verticalSlider->sizePolicy().hasHeightForWidth());
        verticalSlider->setSizePolicy(sizePolicy4);
        verticalSlider->setMinimumSize(QSize(0, 100));
        verticalSlider->setMaximumSize(QSize(16777215, 100));
        verticalSlider->setFocusPolicy(Qt::NoFocus);
        verticalSlider->setStyleSheet(QString::fromUtf8("QSlider::groove:vertical {\n"
"border:none;\n"
"background:none;\n"
"width: 4px;\n"
"border-radius: 2px;\n"
"padding-left:-1px;\n"
"padding-right:-1px;\n"
"padding-top:0px;\n"
"padding-bottom:0px;\n"
"}\n"
"\n"
"QSlider::sub-page:vertical {\n"
"background:rgba(34, 34, 34, 1);\n"
"border:none;\n"
"border-radius: 2px;\n"
"width:4px;\n"
"}\n"
"\n"
"QSlider::add-page:vertical {\n"
"background:rgba(15, 134, 255, 1);\n"
"border:none;\n"
"border-radius: 2px;\n"
"width:4px;\n"
"}\n"
"\n"
"QSlider::handle:vertical \n"
"{\n"
"	background:white;\n"
"	width:16px;\n"
"    height: 16px;\n"
"    margin-left: -6px;\n"
"    margin-right: -6px;\n"
"    border-radius: 8px;\n"
"}"));
        verticalSlider->setOrientation(Qt::Vertical);

        verticalLayout_2->addWidget(verticalSlider);

        pushButtonReplay = new QPushButton(YDPlayerMainWidget);
        pushButtonReplay->setObjectName("pushButtonReplay");
        pushButtonReplay->setGeometry(QRect(480, 270, 51, 52));
        pushButtonReplay->setMinimumSize(QSize(51, 52));
        pushButtonReplay->setMaximumSize(QSize(51, 52));
        pushButtonReplay->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButtonReplay->setFocusPolicy(Qt::NoFocus);
        pushButtonReplay->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background:none;\n"
"	border:none;\n"
"	image: url(:/images/icon_replay.png);\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	background:none;\n"
"	border:none;\n"
"	image: url(:/images/icon_replay_hover.png);\n"
"}"));
        btnOpenFile = new QPushButton(YDPlayerMainWidget);
        btnOpenFile->setObjectName("btnOpenFile");
        btnOpenFile->setGeometry(QRect(20, 20, 93, 28));
        btnOpenFile->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"color:#666666;\n"
"background:#FFFFFF;\n"
"font-family:\"Microsoft YaHei\";\n"
"font-size: 14px;\n"
"border:1px solid #AAAAAA;\n"
"border-radius: 14px;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"color:#FFFFFF;\n"
"background:#0F88FF;\n"
"font-family:\"Microsoft YaHei\";\n"
"font-size: 14px;\n"
"border-radius: 14px;\n"
"}"));
        btnOpenFile->setFlat(true);

        retranslateUi(YDPlayerMainWidget);

        QMetaObject::connectSlotsByName(YDPlayerMainWidget);
    } // setupUi

    void retranslateUi(QWidget *YDPlayerMainWidget)
    {
        YDPlayerMainWidget->setWindowTitle(QCoreApplication::translate("YDPlayerMainWidget", "C++Player", nullptr));
        pushButtonPlay->setText(QString());
        labelTime->setText(QString());
        pushButtonSpeaker->setText(QString());
        labelVolume->setText(QCoreApplication::translate("YDPlayerMainWidget", "TextLabel", nullptr));
        pushButtonReplay->setText(QString());
        btnOpenFile->setText(QCoreApplication::translate("YDPlayerMainWidget", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class YDPlayerMainWidget: public Ui_YDPlayerMainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_YDPLAYERMAINWIDGET_H
