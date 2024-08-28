/********************************************************************************
** Form generated from reading UI file 'weatherReport.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEATHERREPORT_H
#define UI_WEATHERREPORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_weatherReport
{
public:
    QWidget *centralwidget;
    QPlainTextEdit *plainTextEdit;
    QPushButton *pushButton;
    QLabel *weatherPic;
    QLabel *weatherTypeLabel;
    QLabel *temperatureLabel;
    QLabel *pm25Label;
    QLabel *noticeLabel;
    QLabel *cityNameLabel;
    QWidget *forecaseWidget;
    QGroupBox *groupBox1_3;
    QLabel *highLabel_3;
    QLabel *foreTypeLabel_3;
    QLabel *label_3;
    QGroupBox *groupBox1_6;
    QLabel *highLabel_6;
    QLabel *foreTypeLabel_6;
    QLabel *label_6;
    QGroupBox *groupBox1_2;
    QLabel *highLabel_2;
    QLabel *foreTypeLabel_2;
    QLabel *label_2;
    QGroupBox *groupBox1;
    QLabel *highLabel;
    QLabel *foreTypeLabel;
    QLabel *label;
    QGroupBox *groupBox1_5;
    QLabel *highLabel_5;
    QLabel *foreTypeLabel_5;
    QLabel *label_5;
    QGroupBox *groupBox1_7;
    QLabel *highLabel_7;
    QLabel *foreTypeLabel_7;
    QLabel *label_7;
    QGroupBox *groupBox1_4;
    QLabel *highLabel_4;
    QLabel *foreTypeLabel_4;
    QLabel *label_4;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *weatherReport)
    {
        if (weatherReport->objectName().isEmpty())
            weatherReport->setObjectName("weatherReport");
        weatherReport->resize(923, 631);
        centralwidget = new QWidget(weatherReport);
        centralwidget->setObjectName("centralwidget");
        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setGeometry(QRect(130, 20, 501, 31));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(plainTextEdit->sizePolicy().hasHeightForWidth());
        plainTextEdit->setSizePolicy(sizePolicy);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(640, 20, 106, 25));
        weatherPic = new QLabel(centralwidget);
        weatherPic->setObjectName("weatherPic");
        weatherPic->setGeometry(QRect(180, 140, 51, 41));
        weatherTypeLabel = new QLabel(centralwidget);
        weatherTypeLabel->setObjectName("weatherTypeLabel");
        weatherTypeLabel->setGeometry(QRect(100, 130, 81, 51));
        QFont font;
        font.setPointSize(18);
        weatherTypeLabel->setFont(font);
        temperatureLabel = new QLabel(centralwidget);
        temperatureLabel->setObjectName("temperatureLabel");
        temperatureLabel->setGeometry(QRect(520, 70, 211, 111));
        QFont font1;
        font1.setPointSize(40);
        temperatureLabel->setFont(font1);
        pm25Label = new QLabel(centralwidget);
        pm25Label->setObjectName("pm25Label");
        pm25Label->setGeometry(QRect(580, 180, 91, 31));
        noticeLabel = new QLabel(centralwidget);
        noticeLabel->setObjectName("noticeLabel");
        noticeLabel->setGeometry(QRect(100, 180, 331, 41));
        cityNameLabel = new QLabel(centralwidget);
        cityNameLabel->setObjectName("cityNameLabel");
        cityNameLabel->setGeometry(QRect(100, 60, 291, 71));
        QFont font2;
        font2.setPointSize(30);
        cityNameLabel->setFont(font2);
        forecaseWidget = new QWidget(centralwidget);
        forecaseWidget->setObjectName("forecaseWidget");
        forecaseWidget->setGeometry(QRect(20, 230, 871, 371));
        groupBox1_3 = new QGroupBox(forecaseWidget);
        groupBox1_3->setObjectName("groupBox1_3");
        groupBox1_3->setGeometry(QRect(250, 10, 120, 351));
        highLabel_3 = new QLabel(groupBox1_3);
        highLabel_3->setObjectName("highLabel_3");
        highLabel_3->setGeometry(QRect(10, 30, 101, 101));
        QFont font3;
        font3.setPointSize(15);
        highLabel_3->setFont(font3);
        foreTypeLabel_3 = new QLabel(groupBox1_3);
        foreTypeLabel_3->setObjectName("foreTypeLabel_3");
        foreTypeLabel_3->setGeometry(QRect(10, 120, 101, 101));
        foreTypeLabel_3->setFont(font3);
        label_3 = new QLabel(groupBox1_3);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 260, 67, 17));
        groupBox1_6 = new QGroupBox(forecaseWidget);
        groupBox1_6->setObjectName("groupBox1_6");
        groupBox1_6->setGeometry(QRect(730, 10, 120, 351));
        highLabel_6 = new QLabel(groupBox1_6);
        highLabel_6->setObjectName("highLabel_6");
        highLabel_6->setGeometry(QRect(10, 30, 101, 101));
        highLabel_6->setFont(font3);
        foreTypeLabel_6 = new QLabel(groupBox1_6);
        foreTypeLabel_6->setObjectName("foreTypeLabel_6");
        foreTypeLabel_6->setGeometry(QRect(10, 120, 101, 101));
        foreTypeLabel_6->setFont(font3);
        label_6 = new QLabel(groupBox1_6);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(30, 260, 67, 17));
        groupBox1_2 = new QGroupBox(forecaseWidget);
        groupBox1_2->setObjectName("groupBox1_2");
        groupBox1_2->setGeometry(QRect(130, 10, 120, 351));
        highLabel_2 = new QLabel(groupBox1_2);
        highLabel_2->setObjectName("highLabel_2");
        highLabel_2->setGeometry(QRect(10, 30, 101, 101));
        highLabel_2->setFont(font3);
        foreTypeLabel_2 = new QLabel(groupBox1_2);
        foreTypeLabel_2->setObjectName("foreTypeLabel_2");
        foreTypeLabel_2->setGeometry(QRect(10, 120, 101, 101));
        foreTypeLabel_2->setFont(font3);
        label_2 = new QLabel(groupBox1_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 260, 67, 17));
        groupBox1 = new QGroupBox(forecaseWidget);
        groupBox1->setObjectName("groupBox1");
        groupBox1->setGeometry(QRect(10, 10, 120, 351));
        highLabel = new QLabel(groupBox1);
        highLabel->setObjectName("highLabel");
        highLabel->setGeometry(QRect(10, 30, 101, 101));
        highLabel->setFont(font3);
        foreTypeLabel = new QLabel(groupBox1);
        foreTypeLabel->setObjectName("foreTypeLabel");
        foreTypeLabel->setGeometry(QRect(10, 120, 101, 101));
        foreTypeLabel->setFont(font3);
        label = new QLabel(groupBox1);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 260, 67, 17));
        groupBox1_5 = new QGroupBox(forecaseWidget);
        groupBox1_5->setObjectName("groupBox1_5");
        groupBox1_5->setGeometry(QRect(490, 10, 120, 351));
        highLabel_5 = new QLabel(groupBox1_5);
        highLabel_5->setObjectName("highLabel_5");
        highLabel_5->setGeometry(QRect(10, 30, 101, 101));
        highLabel_5->setFont(font3);
        foreTypeLabel_5 = new QLabel(groupBox1_5);
        foreTypeLabel_5->setObjectName("foreTypeLabel_5");
        foreTypeLabel_5->setGeometry(QRect(10, 120, 101, 101));
        foreTypeLabel_5->setFont(font3);
        label_5 = new QLabel(groupBox1_5);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(30, 260, 67, 17));
        groupBox1_7 = new QGroupBox(forecaseWidget);
        groupBox1_7->setObjectName("groupBox1_7");
        groupBox1_7->setGeometry(QRect(610, 10, 120, 351));
        highLabel_7 = new QLabel(groupBox1_7);
        highLabel_7->setObjectName("highLabel_7");
        highLabel_7->setGeometry(QRect(10, 30, 101, 101));
        highLabel_7->setFont(font3);
        foreTypeLabel_7 = new QLabel(groupBox1_7);
        foreTypeLabel_7->setObjectName("foreTypeLabel_7");
        foreTypeLabel_7->setGeometry(QRect(10, 120, 101, 101));
        foreTypeLabel_7->setFont(font3);
        label_7 = new QLabel(groupBox1_7);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(30, 260, 67, 17));
        groupBox1_4 = new QGroupBox(forecaseWidget);
        groupBox1_4->setObjectName("groupBox1_4");
        groupBox1_4->setGeometry(QRect(370, 10, 120, 351));
        highLabel_4 = new QLabel(groupBox1_4);
        highLabel_4->setObjectName("highLabel_4");
        highLabel_4->setGeometry(QRect(10, 30, 101, 101));
        highLabel_4->setFont(font3);
        foreTypeLabel_4 = new QLabel(groupBox1_4);
        foreTypeLabel_4->setObjectName("foreTypeLabel_4");
        foreTypeLabel_4->setGeometry(QRect(10, 120, 101, 101));
        foreTypeLabel_4->setFont(font3);
        label_4 = new QLabel(groupBox1_4);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, 260, 67, 17));
        weatherReport->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(weatherReport);
        statusbar->setObjectName("statusbar");
        weatherReport->setStatusBar(statusbar);

        retranslateUi(weatherReport);

        QMetaObject::connectSlotsByName(weatherReport);
    } // setupUi

    void retranslateUi(QMainWindow *weatherReport)
    {
        weatherReport->setWindowTitle(QCoreApplication::translate("weatherReport", "weatherReport", nullptr));
        plainTextEdit->setPlainText(QString());
        pushButton->setText(QCoreApplication::translate("weatherReport", "\346\237\245\350\257\242\345\244\251\346\260\224", nullptr));
        weatherPic->setText(QString());
        weatherTypeLabel->setText(QString());
        temperatureLabel->setText(QString());
        pm25Label->setText(QString());
        noticeLabel->setText(QString());
        cityNameLabel->setText(QCoreApplication::translate("weatherReport", "\350\257\267\350\276\223\345\205\245\345\237\216\345\270\202\345\220\215\347\247\260", nullptr));
        groupBox1_3->setTitle(QCoreApplication::translate("weatherReport", "GroupBox", nullptr));
        highLabel_3->setText(QCoreApplication::translate("weatherReport", "TextLabel", nullptr));
        foreTypeLabel_3->setText(QCoreApplication::translate("weatherReport", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("weatherReport", "TextLabel", nullptr));
        groupBox1_6->setTitle(QCoreApplication::translate("weatherReport", "GroupBox", nullptr));
        highLabel_6->setText(QCoreApplication::translate("weatherReport", "TextLabel", nullptr));
        foreTypeLabel_6->setText(QCoreApplication::translate("weatherReport", "TextLabel", nullptr));
        label_6->setText(QCoreApplication::translate("weatherReport", "TextLabel", nullptr));
        groupBox1_2->setTitle(QCoreApplication::translate("weatherReport", "GroupBox", nullptr));
        highLabel_2->setText(QCoreApplication::translate("weatherReport", "TextLabel", nullptr));
        foreTypeLabel_2->setText(QCoreApplication::translate("weatherReport", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("weatherReport", "TextLabel", nullptr));
        groupBox1->setTitle(QCoreApplication::translate("weatherReport", "GroupBox", nullptr));
        highLabel->setText(QCoreApplication::translate("weatherReport", "TextLabel", nullptr));
        foreTypeLabel->setText(QCoreApplication::translate("weatherReport", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("weatherReport", "TextLabel", nullptr));
        groupBox1_5->setTitle(QCoreApplication::translate("weatherReport", "GroupBox", nullptr));
        highLabel_5->setText(QCoreApplication::translate("weatherReport", "TextLabel", nullptr));
        foreTypeLabel_5->setText(QCoreApplication::translate("weatherReport", "TextLabel", nullptr));
        label_5->setText(QCoreApplication::translate("weatherReport", "TextLabel", nullptr));
        groupBox1_7->setTitle(QCoreApplication::translate("weatherReport", "GroupBox", nullptr));
        highLabel_7->setText(QCoreApplication::translate("weatherReport", "TextLabel", nullptr));
        foreTypeLabel_7->setText(QCoreApplication::translate("weatherReport", "TextLabel", nullptr));
        label_7->setText(QCoreApplication::translate("weatherReport", "TextLabel", nullptr));
        groupBox1_4->setTitle(QCoreApplication::translate("weatherReport", "GroupBox", nullptr));
        highLabel_4->setText(QCoreApplication::translate("weatherReport", "TextLabel", nullptr));
        foreTypeLabel_4->setText(QCoreApplication::translate("weatherReport", "TextLabel", nullptr));
        label_4->setText(QCoreApplication::translate("weatherReport", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class weatherReport: public Ui_weatherReport {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEATHERREPORT_H
