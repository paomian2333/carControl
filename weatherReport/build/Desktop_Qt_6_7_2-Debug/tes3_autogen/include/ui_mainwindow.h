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
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *pushButton;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *blodcheckBox;
    QCheckBox *linecheckbox;
    QPlainTextEdit *plainTextEdit;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *blueradio;
    QRadioButton *greenradio;
    QRadioButton *redradio;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *clearTxt;
    QSpacerItem *horizontalSpacer;
    QPushButton *closeWindow;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(130, 394, 501, 121));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(500, 330, 106, 25));
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(100, 10, 141, 91));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        blodcheckBox = new QCheckBox(widget);
        blodcheckBox->setObjectName("blodcheckBox");

        horizontalLayout_2->addWidget(blodcheckBox);

        linecheckbox = new QCheckBox(widget);
        linecheckbox->setObjectName("linecheckbox");

        horizontalLayout_2->addWidget(linecheckbox);

        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setGeometry(QRect(100, 100, 371, 111));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(plainTextEdit->sizePolicy().hasHeightForWidth());
        plainTextEdit->setSizePolicy(sizePolicy);
        widget1 = new QWidget(centralwidget);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(240, 10, 231, 91));
        horizontalLayout_3 = new QHBoxLayout(widget1);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        blueradio = new QRadioButton(widget1);
        blueradio->setObjectName("blueradio");

        horizontalLayout_3->addWidget(blueradio);

        greenradio = new QRadioButton(widget1);
        greenradio->setObjectName("greenradio");

        horizontalLayout_3->addWidget(greenradio);

        redradio = new QRadioButton(widget1);
        redradio->setObjectName("redradio");

        horizontalLayout_3->addWidget(redradio);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(100, 210, 371, 161));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName("horizontalLayout");
        clearTxt = new QPushButton(groupBox);
        clearTxt->setObjectName("clearTxt");

        horizontalLayout->addWidget(clearTxt);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        closeWindow = new QPushButton(groupBox);
        closeWindow->setObjectName("closeWindow");

        horizontalLayout->addWidget(closeWindow);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 27));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "weather", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "queryWeather", nullptr));
        blodcheckBox->setText(QCoreApplication::translate("MainWindow", "blod", nullptr));
        linecheckbox->setText(QCoreApplication::translate("MainWindow", "line", nullptr));
        blueradio->setText(QCoreApplication::translate("MainWindow", "blue", nullptr));
        greenradio->setText(QCoreApplication::translate("MainWindow", "green", nullptr));
        redradio->setText(QCoreApplication::translate("MainWindow", "red", nullptr));
        clearTxt->setText(QCoreApplication::translate("MainWindow", "clearText", nullptr));
        closeWindow->setText(QCoreApplication::translate("MainWindow", "closeWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
