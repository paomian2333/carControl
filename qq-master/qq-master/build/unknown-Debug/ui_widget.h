/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *widget_2;
    QWidget *widget;
    QTextBrowser *msgBrowser;
    QFrame *frame_2;
    QGridLayout *gridLayout;
    QToolButton *underlineTbtn;
    QComboBox *sizeCbx;
    QFontComboBox *fontCbx;
    QToolButton *clearTbtn;
    QToolButton *boldBtn;
    QToolButton *colorTbtn;
    QToolButton *saveTbtn;
    QToolButton *italicTbtn;
    QWidget *widget_3;
    QGridLayout *gridLayout_2;
    QTextEdit *msgTxtEdit;
    QWidget *widget_4;
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *sendBtn;
    QLabel *userNumLbl;
    QPushButton *exitBtn;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QWidget *widget_5;
    QGridLayout *gridLayout_4;
    QTableWidget *tableWidget;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(891, 538);
        widget_2 = new QWidget(Widget);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(0, 0, 601, 331));
        widget = new QWidget(widget_2);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(11, 11, 591, 276));
        msgBrowser = new QTextBrowser(widget);
        msgBrowser->setObjectName("msgBrowser");
        msgBrowser->setGeometry(QRect(0, -9, 581, 281));
        frame_2 = new QFrame(widget_2);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(11, 294, 581, 23));
        frame_2->setFrameShape(QFrame::Box);
        gridLayout = new QGridLayout(frame_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        underlineTbtn = new QToolButton(frame_2);
        underlineTbtn->setObjectName("underlineTbtn");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/under.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        underlineTbtn->setIcon(icon);
        underlineTbtn->setCheckable(true);

        gridLayout->addWidget(underlineTbtn, 0, 4, 1, 1);

        sizeCbx = new QComboBox(frame_2);
        sizeCbx->addItem(QString());
        sizeCbx->addItem(QString());
        sizeCbx->addItem(QString());
        sizeCbx->addItem(QString());
        sizeCbx->addItem(QString());
        sizeCbx->addItem(QString());
        sizeCbx->addItem(QString());
        sizeCbx->addItem(QString());
        sizeCbx->setObjectName("sizeCbx");

        gridLayout->addWidget(sizeCbx, 0, 1, 1, 1);

        fontCbx = new QFontComboBox(frame_2);
        fontCbx->setObjectName("fontCbx");

        gridLayout->addWidget(fontCbx, 0, 0, 1, 1);

        clearTbtn = new QToolButton(frame_2);
        clearTbtn->setObjectName("clearTbtn");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/clear.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        clearTbtn->setIcon(icon1);

        gridLayout->addWidget(clearTbtn, 0, 7, 1, 1);

        boldBtn = new QToolButton(frame_2);
        boldBtn->setObjectName("boldBtn");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/bold.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        boldBtn->setIcon(icon2);
        boldBtn->setCheckable(true);

        gridLayout->addWidget(boldBtn, 0, 2, 1, 1);

        colorTbtn = new QToolButton(frame_2);
        colorTbtn->setObjectName("colorTbtn");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/color.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        colorTbtn->setIcon(icon3);

        gridLayout->addWidget(colorTbtn, 0, 5, 1, 1);

        saveTbtn = new QToolButton(frame_2);
        saveTbtn->setObjectName("saveTbtn");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/save.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        saveTbtn->setIcon(icon4);

        gridLayout->addWidget(saveTbtn, 0, 6, 1, 1);

        italicTbtn = new QToolButton(frame_2);
        italicTbtn->setObjectName("italicTbtn");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/italic.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        italicTbtn->setIcon(icon5);
        italicTbtn->setCheckable(true);

        gridLayout->addWidget(italicTbtn, 0, 3, 1, 1);

        widget->raise();
        frame_2->raise();
        widget->raise();
        frame_2->raise();
        widget_3 = new QWidget(Widget);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(10, 330, 581, 141));
        gridLayout_2 = new QGridLayout(widget_3);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        msgTxtEdit = new QTextEdit(widget_3);
        msgTxtEdit->setObjectName("msgTxtEdit");

        gridLayout_2->addWidget(msgTxtEdit, 0, 0, 1, 1);

        widget_4 = new QWidget(Widget);
        widget_4->setObjectName("widget_4");
        widget_4->setGeometry(QRect(10, 480, 581, 50));
        gridLayout_3 = new QGridLayout(widget_4);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 0, 0, 1, 1);

        sendBtn = new QPushButton(widget_4);
        sendBtn->setObjectName("sendBtn");

        gridLayout_3->addWidget(sendBtn, 0, 1, 1, 1);

        userNumLbl = new QLabel(widget_4);
        userNumLbl->setObjectName("userNumLbl");

        gridLayout_3->addWidget(userNumLbl, 0, 3, 1, 1);

        exitBtn = new QPushButton(widget_4);
        exitBtn->setObjectName("exitBtn");

        gridLayout_3->addWidget(exitBtn, 0, 5, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 0, 4, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_4, 0, 6, 1, 1);

        widget_5 = new QWidget(Widget);
        widget_5->setObjectName("widget_5");
        widget_5->setGeometry(QRect(600, 10, 278, 521));
        gridLayout_4 = new QGridLayout(widget_5);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName("gridLayout_4");
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        tableWidget = new QTableWidget(widget_5);
        if (tableWidget->columnCount() < 1)
            tableWidget->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        tableWidget->setObjectName("tableWidget");

        gridLayout_4->addWidget(tableWidget, 0, 0, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
#if QT_CONFIG(tooltip)
        underlineTbtn->setToolTip(QCoreApplication::translate("Widget", "\344\270\213\345\210\222\347\272\277", nullptr));
#endif // QT_CONFIG(tooltip)
        underlineTbtn->setText(QCoreApplication::translate("Widget", "...", nullptr));
        sizeCbx->setItemText(0, QCoreApplication::translate("Widget", "5", nullptr));
        sizeCbx->setItemText(1, QCoreApplication::translate("Widget", "6", nullptr));
        sizeCbx->setItemText(2, QCoreApplication::translate("Widget", "7", nullptr));
        sizeCbx->setItemText(3, QCoreApplication::translate("Widget", "8", nullptr));
        sizeCbx->setItemText(4, QCoreApplication::translate("Widget", "9", nullptr));
        sizeCbx->setItemText(5, QCoreApplication::translate("Widget", "10", nullptr));
        sizeCbx->setItemText(6, QCoreApplication::translate("Widget", "11", nullptr));
        sizeCbx->setItemText(7, QCoreApplication::translate("Widget", "12", nullptr));

#if QT_CONFIG(tooltip)
        clearTbtn->setToolTip(QCoreApplication::translate("Widget", "\346\270\205\347\251\272", nullptr));
#endif // QT_CONFIG(tooltip)
        clearTbtn->setText(QCoreApplication::translate("Widget", "...", nullptr));
#if QT_CONFIG(tooltip)
        boldBtn->setToolTip(QCoreApplication::translate("Widget", "\345\212\240\347\262\227", nullptr));
#endif // QT_CONFIG(tooltip)
        boldBtn->setText(QCoreApplication::translate("Widget", "...", nullptr));
#if QT_CONFIG(tooltip)
        colorTbtn->setToolTip(QCoreApplication::translate("Widget", "\351\242\234\350\211\262", nullptr));
#endif // QT_CONFIG(tooltip)
        colorTbtn->setText(QCoreApplication::translate("Widget", "...", nullptr));
#if QT_CONFIG(tooltip)
        saveTbtn->setToolTip(QCoreApplication::translate("Widget", "\344\277\235\345\255\230", nullptr));
#endif // QT_CONFIG(tooltip)
        saveTbtn->setText(QCoreApplication::translate("Widget", "...", nullptr));
#if QT_CONFIG(tooltip)
        italicTbtn->setToolTip(QCoreApplication::translate("Widget", "\345\200\276\346\226\234", nullptr));
#endif // QT_CONFIG(tooltip)
        italicTbtn->setText(QCoreApplication::translate("Widget", "...", nullptr));
        sendBtn->setText(QCoreApplication::translate("Widget", "\345\217\221\351\200\201", nullptr));
        userNumLbl->setText(QCoreApplication::translate("Widget", "\345\234\250\347\272\277\344\272\272\346\225\260:0\344\272\272", nullptr));
        exitBtn->setText(QCoreApplication::translate("Widget", "\351\200\200\345\207\272", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Widget", "\347\224\250\346\210\267\345\220\215:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
