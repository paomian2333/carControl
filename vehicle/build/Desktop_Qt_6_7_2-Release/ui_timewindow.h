/********************************************************************************
** Form generated from reading UI file 'timewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMEWINDOW_H
#define UI_TIMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <clockwidget.h>

QT_BEGIN_NAMESPACE

class Ui_timewindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_pic;
    QSpacerItem *horizontalSpacer;
    QLabel *label_date;
    QLabel *label_time;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_3;
    clockwidget *widget;
    QCalendarWidget *calendarWidget;

    void setupUi(QMainWindow *timewindow)
    {
        if (timewindow->objectName().isEmpty())
            timewindow->setObjectName("timewindow");
        timewindow->resize(576, 398);
        timewindow->setMinimumSize(QSize(230, 230));
        timewindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(timewindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        label_pic = new QLabel(groupBox);
        label_pic->setObjectName("label_pic");

        horizontalLayout->addWidget(label_pic);

        horizontalSpacer = new QSpacerItem(120, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_date = new QLabel(groupBox);
        label_date->setObjectName("label_date");
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        label_date->setFont(font);

        horizontalLayout->addWidget(label_date);

        label_time = new QLabel(groupBox);
        label_time->setObjectName("label_time");
        label_time->setFont(font);

        horizontalLayout->addWidget(label_time);

        horizontalSpacer_2 = new QSpacerItem(120, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addWidget(groupBox);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");

        horizontalLayout_2->addWidget(comboBox);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        widget = new clockwidget(centralwidget);
        widget->setObjectName("widget");
        widget->setMinimumSize(QSize(230, 0));

        horizontalLayout_3->addWidget(widget);

        calendarWidget = new QCalendarWidget(centralwidget);
        calendarWidget->setObjectName("calendarWidget");

        horizontalLayout_3->addWidget(calendarWidget);


        verticalLayout->addLayout(horizontalLayout_3);

        timewindow->setCentralWidget(centralwidget);

        retranslateUi(timewindow);

        QMetaObject::connectSlotsByName(timewindow);
    } // setupUi

    void retranslateUi(QMainWindow *timewindow)
    {
        timewindow->setWindowTitle(QCoreApplication::translate("timewindow", "timewindow", nullptr));
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("timewindow", "\346\227\266\351\227\264", nullptr));
        label_pic->setText(QCoreApplication::translate("timewindow", "\345\233\276\347\211\207", nullptr));
        label_date->setText(QCoreApplication::translate("timewindow", "TextLabel", nullptr));
        label_time->setText(QCoreApplication::translate("timewindow", "TextLabel", nullptr));
        pushButton->setText(QCoreApplication::translate("timewindow", "\350\277\224\345\233\236", nullptr));
        label_2->setText(QCoreApplication::translate("timewindow", "where you are?", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("timewindow", "\344\270\255\345\233\275", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("timewindow", "\346\227\245\346\234\254", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("timewindow", "\347\276\216\345\233\275", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("timewindow", "\350\213\261\345\233\275", nullptr));

    } // retranslateUi

};

namespace Ui {
    class timewindow: public Ui_timewindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMEWINDOW_H
