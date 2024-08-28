/********************************************************************************
** Form generated from reading UI file 'chatLogin.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATLOGIN_H
#define UI_CHATLOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chatLogin
{
public:
    QWidget *centralwidget;
    QToolBox *toolBox;
    QWidget *page;
    QVBoxLayout *vlayout;
    QPushButton *pushButton;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *chatLogin)
    {
        if (chatLogin->objectName().isEmpty())
            chatLogin->setObjectName("chatLogin");
        chatLogin->resize(228, 607);
        centralwidget = new QWidget(chatLogin);
        centralwidget->setObjectName("centralwidget");
        toolBox = new QToolBox(centralwidget);
        toolBox->setObjectName("toolBox");
        toolBox->setGeometry(QRect(0, 0, 221, 531));
        page = new QWidget();
        page->setObjectName("page");
        page->setGeometry(QRect(0, 0, 221, 495));
        vlayout = new QVBoxLayout(page);
        vlayout->setObjectName("vlayout");
        vlayout->setContentsMargins(-1, -1, 4, -1);
        toolBox->addItem(page, QString::fromUtf8("\347\276\244\346\210\220\345\221\230"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(120, 540, 89, 25));
        chatLogin->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(chatLogin);
        statusbar->setObjectName("statusbar");
        chatLogin->setStatusBar(statusbar);
        toolBar = new QToolBar(chatLogin);
        toolBar->setObjectName("toolBar");
        chatLogin->addToolBar(Qt::ToolBarArea::BottomToolBarArea, toolBar);

        retranslateUi(chatLogin);

        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(chatLogin);
    } // setupUi

    void retranslateUi(QMainWindow *chatLogin)
    {
        chatLogin->setWindowTitle(QCoreApplication::translate("chatLogin", "MainWindow", nullptr));
        toolBox->setItemText(toolBox->indexOf(page), QCoreApplication::translate("chatLogin", "\347\276\244\346\210\220\345\221\230", nullptr));
        pushButton->setText(QCoreApplication::translate("chatLogin", "\351\200\200\345\207\272", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("chatLogin", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class chatLogin: public Ui_chatLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATLOGIN_H
