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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MusicWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QLineEdit *searchline;
    QPushButton *btn_search;
    QPushButton *btnAdd;
    QPushButton *btnRemove;
    QPushButton *btnClear;
    QPushButton *btnClose;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_2;
    QListWidget *listWidget;
    QPlainTextEdit *plainTextEdit;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *labPic;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btnPlay;
    QPushButton *btnPause;
    QPushButton *btnStop;
    QPushButton *btnPrevious;
    QPushButton *btnNext;
    QSpacerItem *horizontalSpacer;
    QDoubleSpinBox *doubleSpinBox;
    QPushButton *btnLoop;
    QPushButton *btnSound;
    QSlider *sliderVolumn;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labCurMedia;
    QSlider *sliderPosition;
    QLabel *labRatio;

    void setupUi(QMainWindow *MusicWindow)
    {
        if (MusicWindow->objectName().isEmpty())
            MusicWindow->setObjectName("MusicWindow");
        MusicWindow->resize(727, 446);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/MusicWindow_picture/musicplayer.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        MusicWindow->setWindowIcon(icon);
        MusicWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MusicWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName("horizontalLayout");
        searchline = new QLineEdit(groupBox);
        searchline->setObjectName("searchline");

        horizontalLayout->addWidget(searchline);

        btn_search = new QPushButton(groupBox);
        btn_search->setObjectName("btn_search");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/MusicWindow_picture/search.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btn_search->setIcon(icon1);

        horizontalLayout->addWidget(btn_search);

        btnAdd = new QPushButton(groupBox);
        btnAdd->setObjectName("btnAdd");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/MusicWindow_picture/add.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnAdd->setIcon(icon2);

        horizontalLayout->addWidget(btnAdd);

        btnRemove = new QPushButton(groupBox);
        btnRemove->setObjectName("btnRemove");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/image/MusicWindow_picture/delete.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnRemove->setIcon(icon3);

        horizontalLayout->addWidget(btnRemove);

        btnClear = new QPushButton(groupBox);
        btnClear->setObjectName("btnClear");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/image/MusicWindow_picture/clear.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnClear->setIcon(icon4);

        horizontalLayout->addWidget(btnClear);

        btnClose = new QPushButton(groupBox);
        btnClose->setObjectName("btnClose");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/image/MusicWindow_picture/exit.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnClose->setIcon(icon5);

        horizontalLayout->addWidget(btnClose);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        horizontalLayout_2 = new QHBoxLayout(groupBox_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        listWidget = new QListWidget(groupBox_2);
        listWidget->setObjectName("listWidget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamilies({QString::fromUtf8("\346\245\267\344\275\223")});
        listWidget->setFont(font);
        listWidget->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CursorShape::PointingHandCursor)));

        horizontalLayout_2->addWidget(listWidget);

        plainTextEdit = new QPlainTextEdit(groupBox_2);
        plainTextEdit->setObjectName("plainTextEdit");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(2);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(plainTextEdit->sizePolicy().hasHeightForWidth());
        plainTextEdit->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setUnderline(true);
        plainTextEdit->setFont(font1);
        plainTextEdit->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CursorShape::ArrowCursor)));
        plainTextEdit->setAutoFillBackground(false);
        plainTextEdit->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(plainTextEdit);

        scrollArea = new QScrollArea(groupBox_2);
        scrollArea->setObjectName("scrollArea");
        sizePolicy1.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy1);
        scrollArea->setMinimumSize(QSize(300, 0));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 298, 294));
        labPic = new QLabel(scrollAreaWidgetContents);
        labPic->setObjectName("labPic");
        labPic->setGeometry(QRect(0, 0, 321, 251));
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(labPic->sizePolicy().hasHeightForWidth());
        labPic->setSizePolicy(sizePolicy2);
        labPic->setAlignment(Qt::AlignCenter);
        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout_2->addWidget(scrollArea);


        verticalLayout->addWidget(groupBox_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        btnPlay = new QPushButton(centralwidget);
        btnPlay->setObjectName("btnPlay");
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/image/MusicWindow_picture/startplay.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnPlay->setIcon(icon6);

        horizontalLayout_3->addWidget(btnPlay);

        btnPause = new QPushButton(centralwidget);
        btnPause->setObjectName("btnPause");
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/image/MusicWindow_picture/pause.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnPause->setIcon(icon7);

        horizontalLayout_3->addWidget(btnPause);

        btnStop = new QPushButton(centralwidget);
        btnStop->setObjectName("btnStop");
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/image/MusicWindow_picture/stop.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnStop->setIcon(icon8);

        horizontalLayout_3->addWidget(btnStop);

        btnPrevious = new QPushButton(centralwidget);
        btnPrevious->setObjectName("btnPrevious");
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/image/MusicWindow_picture/preview.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnPrevious->setIcon(icon9);

        horizontalLayout_3->addWidget(btnPrevious);

        btnNext = new QPushButton(centralwidget);
        btnNext->setObjectName("btnNext");
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/image/MusicWindow_picture/next.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnNext->setIcon(icon10);

        horizontalLayout_3->addWidget(btnNext);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        doubleSpinBox = new QDoubleSpinBox(centralwidget);
        doubleSpinBox->setObjectName("doubleSpinBox");
        doubleSpinBox->setMinimum(0.500000000000000);
        doubleSpinBox->setMaximum(3.000000000000000);
        doubleSpinBox->setSingleStep(0.100000000000000);
        doubleSpinBox->setValue(1.000000000000000);

        horizontalLayout_3->addWidget(doubleSpinBox);

        btnLoop = new QPushButton(centralwidget);
        btnLoop->setObjectName("btnLoop");
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/image/MusicWindow_picture/cycle.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnLoop->setIcon(icon11);
        btnLoop->setCheckable(true);
        btnLoop->setChecked(true);

        horizontalLayout_3->addWidget(btnLoop);

        btnSound = new QPushButton(centralwidget);
        btnSound->setObjectName("btnSound");
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/image/MusicWindow_picture/noSound.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnSound->setIcon(icon12);

        horizontalLayout_3->addWidget(btnSound);

        sliderVolumn = new QSlider(centralwidget);
        sliderVolumn->setObjectName("sliderVolumn");
        sliderVolumn->setMaximum(100);
        sliderVolumn->setValue(100);
        sliderVolumn->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(sliderVolumn);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        labCurMedia = new QLabel(centralwidget);
        labCurMedia->setObjectName("labCurMedia");
        labCurMedia->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout_4->addWidget(labCurMedia);

        sliderPosition = new QSlider(centralwidget);
        sliderPosition->setObjectName("sliderPosition");
        sliderPosition->setTracking(false);
        sliderPosition->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(sliderPosition);

        labRatio = new QLabel(centralwidget);
        labRatio->setObjectName("labRatio");
        labRatio->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout_4->addWidget(labRatio);


        verticalLayout->addLayout(horizontalLayout_4);

        MusicWindow->setCentralWidget(centralwidget);

        retranslateUi(MusicWindow);

        QMetaObject::connectSlotsByName(MusicWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MusicWindow)
    {
        MusicWindow->setWindowTitle(QCoreApplication::translate("MusicWindow", "MusicWindow", nullptr));
        groupBox->setTitle(QString());
        btn_search->setText(QString());
        btnAdd->setText(QCoreApplication::translate("MusicWindow", "\346\267\273\345\212\240", nullptr));
        btnRemove->setText(QCoreApplication::translate("MusicWindow", "\347\247\273\351\231\244", nullptr));
        btnClear->setText(QCoreApplication::translate("MusicWindow", "\346\270\205\347\251\272", nullptr));
        btnClose->setText(QCoreApplication::translate("MusicWindow", "\351\200\200\345\207\272", nullptr));
        groupBox_2->setTitle(QString());
        labPic->setText(QCoreApplication::translate("MusicWindow", "\345\260\232\346\234\252\346\222\255\346\224\276", nullptr));
        btnPlay->setText(QCoreApplication::translate("MusicWindow", "\346\222\255\346\224\276", nullptr));
        btnPause->setText(QCoreApplication::translate("MusicWindow", "\346\232\202\345\201\234", nullptr));
        btnStop->setText(QCoreApplication::translate("MusicWindow", "\345\201\234\346\255\242", nullptr));
        btnPrevious->setText(QCoreApplication::translate("MusicWindow", "\344\270\212\344\270\200\351\246\226", nullptr));
        btnNext->setText(QCoreApplication::translate("MusicWindow", "\344\270\213\344\270\200\351\246\226", nullptr));
        btnLoop->setText(QCoreApplication::translate("MusicWindow", "\345\276\252\347\216\257", nullptr));
        btnSound->setText(QCoreApplication::translate("MusicWindow", "\345\243\260\351\237\263", nullptr));
        labCurMedia->setText(QCoreApplication::translate("MusicWindow", "\345\260\232\346\227\240\346\233\262\347\233\256", nullptr));
        labRatio->setText(QCoreApplication::translate("MusicWindow", "00\357\274\23200/00\357\274\23200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MusicWindow: public Ui_MusicWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUSICWINDOW_H
