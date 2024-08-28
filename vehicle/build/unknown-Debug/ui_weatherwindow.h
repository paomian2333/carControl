/********************************************************************************
** Form generated from reading UI file 'weatherwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEATHERWINDOW_H
#define UI_WEATHERWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_weatherwindow
{
public:
    QWidget *centralwidget;
    QCommandLinkButton *back;
    QLabel *dateweekday;
    QLabel *type1;
    QLabel *high;
    QLabel *low;
    QFrame *line;
    QLabel *high_2;
    QLabel *type1_2;
    QLabel *low_2;
    QLabel *dateweekday_2;
    QLabel *high_3;
    QLabel *type1_3;
    QLabel *low_3;
    QLabel *dateweekday_3;
    QLabel *high_4;
    QLabel *type1_4;
    QLabel *low_4;
    QLabel *dateweekday_4;
    QLabel *high_5;
    QLabel *type1_5;
    QLabel *low_5;
    QLabel *dateweekday_5;
    QLabel *high_6;
    QLabel *type1_6;
    QLabel *low_6;
    QLabel *dateweekday_6;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *aqi;
    QLabel *aqilevel;
    QLabel *windIcon;
    QLabel *wind;
    QLabel *humidIcon;
    QLabel *humid;
    QLabel *city;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *date_2;
    QLabel *weekday;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *centigrade;
    QLabel *icon;
    QLabel *type;
    QFrame *line_2;
    QFrame *line_3;
    QLabel *warningPanel;
    QFrame *line_4;
    QLabel *noticeIcon;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *searchbutton_2;
    QLineEdit *searchline;
    QPushButton *searchbutton;

    void setupUi(QMainWindow *weatherwindow)
    {
        if (weatherwindow->objectName().isEmpty())
            weatherwindow->setObjectName("weatherwindow");
        weatherwindow->setEnabled(true);
        weatherwindow->resize(800, 480);
        weatherwindow->setMinimumSize(QSize(800, 480));
        weatherwindow->setMaximumSize(QSize(800, 480));
        QFont font;
        font.setPointSize(9);
        font.setBold(true);
        weatherwindow->setFont(font);
        weatherwindow->setStyleSheet(QString::fromUtf8(""));
        weatherwindow->setAnimated(true);
        weatherwindow->setTabShape(QTabWidget::Rounded);
        centralwidget = new QWidget(weatherwindow);
        centralwidget->setObjectName("centralwidget");
        back = new QCommandLinkButton(centralwidget);
        back->setObjectName("back");
        back->setGeometry(QRect(20, 10, 41, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI")});
        font1.setPointSize(28);
        font1.setBold(true);
        back->setFont(font1);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/main/main.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        back->setIcon(icon1);
        back->setIconSize(QSize(50, 50));
        dateweekday = new QLabel(centralwidget);
        dateweekday->setObjectName("dateweekday");
        dateweekday->setGeometry(QRect(-10, 320, 141, 21));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        dateweekday->setFont(font2);
        dateweekday->setAlignment(Qt::AlignCenter);
        type1 = new QLabel(centralwidget);
        type1->setObjectName("type1");
        type1->setGeometry(QRect(20, 350, 51, 51));
        type1->setScaledContents(true);
        high = new QLabel(centralwidget);
        high->setObjectName("high");
        high->setGeometry(QRect(10, 390, 61, 51));
        QFont font3;
        font3.setPointSize(17);
        font3.setBold(true);
        high->setFont(font3);
        low = new QLabel(centralwidget);
        low->setObjectName("low");
        low->setGeometry(QRect(70, 400, 51, 41));
        QFont font4;
        font4.setPointSize(10);
        font4.setBold(true);
        low->setFont(font4);
        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setGeometry(QRect(0, 300, 801, 20));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        high_2 = new QLabel(centralwidget);
        high_2->setObjectName("high_2");
        high_2->setGeometry(QRect(140, 390, 61, 51));
        high_2->setFont(font3);
        type1_2 = new QLabel(centralwidget);
        type1_2->setObjectName("type1_2");
        type1_2->setGeometry(QRect(150, 350, 51, 51));
        type1_2->setScaledContents(true);
        low_2 = new QLabel(centralwidget);
        low_2->setObjectName("low_2");
        low_2->setGeometry(QRect(200, 400, 51, 41));
        low_2->setFont(font4);
        dateweekday_2 = new QLabel(centralwidget);
        dateweekday_2->setObjectName("dateweekday_2");
        dateweekday_2->setGeometry(QRect(120, 320, 141, 21));
        dateweekday_2->setFont(font2);
        dateweekday_2->setAlignment(Qt::AlignCenter);
        high_3 = new QLabel(centralwidget);
        high_3->setObjectName("high_3");
        high_3->setGeometry(QRect(270, 390, 61, 51));
        high_3->setFont(font3);
        type1_3 = new QLabel(centralwidget);
        type1_3->setObjectName("type1_3");
        type1_3->setGeometry(QRect(280, 350, 51, 51));
        type1_3->setScaledContents(true);
        low_3 = new QLabel(centralwidget);
        low_3->setObjectName("low_3");
        low_3->setGeometry(QRect(330, 400, 51, 41));
        low_3->setFont(font4);
        dateweekday_3 = new QLabel(centralwidget);
        dateweekday_3->setObjectName("dateweekday_3");
        dateweekday_3->setGeometry(QRect(250, 320, 141, 21));
        dateweekday_3->setFont(font2);
        dateweekday_3->setAlignment(Qt::AlignCenter);
        high_4 = new QLabel(centralwidget);
        high_4->setObjectName("high_4");
        high_4->setGeometry(QRect(410, 390, 61, 51));
        high_4->setFont(font3);
        type1_4 = new QLabel(centralwidget);
        type1_4->setObjectName("type1_4");
        type1_4->setGeometry(QRect(420, 350, 51, 51));
        type1_4->setScaledContents(true);
        low_4 = new QLabel(centralwidget);
        low_4->setObjectName("low_4");
        low_4->setGeometry(QRect(470, 400, 51, 41));
        low_4->setFont(font4);
        dateweekday_4 = new QLabel(centralwidget);
        dateweekday_4->setObjectName("dateweekday_4");
        dateweekday_4->setGeometry(QRect(380, 320, 141, 21));
        dateweekday_4->setFont(font2);
        dateweekday_4->setAlignment(Qt::AlignCenter);
        high_5 = new QLabel(centralwidget);
        high_5->setObjectName("high_5");
        high_5->setGeometry(QRect(540, 390, 61, 51));
        high_5->setFont(font3);
        type1_5 = new QLabel(centralwidget);
        type1_5->setObjectName("type1_5");
        type1_5->setGeometry(QRect(550, 350, 51, 51));
        type1_5->setScaledContents(true);
        low_5 = new QLabel(centralwidget);
        low_5->setObjectName("low_5");
        low_5->setGeometry(QRect(600, 400, 51, 41));
        low_5->setFont(font4);
        dateweekday_5 = new QLabel(centralwidget);
        dateweekday_5->setObjectName("dateweekday_5");
        dateweekday_5->setGeometry(QRect(510, 320, 141, 21));
        dateweekday_5->setFont(font2);
        dateweekday_5->setAlignment(Qt::AlignCenter);
        high_6 = new QLabel(centralwidget);
        high_6->setObjectName("high_6");
        high_6->setGeometry(QRect(660, 390, 61, 51));
        high_6->setFont(font3);
        type1_6 = new QLabel(centralwidget);
        type1_6->setObjectName("type1_6");
        type1_6->setGeometry(QRect(670, 350, 51, 51));
        type1_6->setScaledContents(true);
        low_6 = new QLabel(centralwidget);
        low_6->setObjectName("low_6");
        low_6->setGeometry(QRect(720, 400, 51, 41));
        low_6->setFont(font4);
        dateweekday_6 = new QLabel(centralwidget);
        dateweekday_6->setObjectName("dateweekday_6");
        dateweekday_6->setGeometry(QRect(640, 320, 141, 21));
        dateweekday_6->setFont(font2);
        dateweekday_6->setAlignment(Qt::AlignCenter);
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(110, 260, 551, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        aqi = new QLabel(horizontalLayoutWidget);
        aqi->setObjectName("aqi");
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Andale Mono")});
        font5.setPointSize(14);
        font5.setBold(false);
        aqi->setFont(font5);

        horizontalLayout->addWidget(aqi);

        aqilevel = new QLabel(horizontalLayoutWidget);
        aqilevel->setObjectName("aqilevel");
        aqilevel->setFont(font5);

        horizontalLayout->addWidget(aqilevel);

        windIcon = new QLabel(horizontalLayoutWidget);
        windIcon->setObjectName("windIcon");

        horizontalLayout->addWidget(windIcon);

        wind = new QLabel(horizontalLayoutWidget);
        wind->setObjectName("wind");
        wind->setFont(font5);

        horizontalLayout->addWidget(wind);

        humidIcon = new QLabel(horizontalLayoutWidget);
        humidIcon->setObjectName("humidIcon");

        horizontalLayout->addWidget(humidIcon);

        humid = new QLabel(horizontalLayoutWidget);
        humid->setObjectName("humid");
        humid->setFont(font5);
        humid->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(humid);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(3, 1);
        horizontalLayout->setStretch(5, 1);
        city = new QLabel(centralwidget);
        city->setObjectName("city");
        city->setGeometry(QRect(250, 40, 281, 119));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Hannotate SC")});
        font6.setPointSize(40);
        font6.setBold(false);
        city->setFont(font6);
        city->setAlignment(Qt::AlignCenter);
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(629, 0, 171, 65));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        date_2 = new QLabel(verticalLayoutWidget);
        date_2->setObjectName("date_2");
        QFont font7;
        font7.setPointSize(13);
        font7.setBold(true);
        date_2->setFont(font7);
        date_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(date_2);

        weekday = new QLabel(verticalLayoutWidget);
        weekday->setObjectName("weekday");
        weekday->setFont(font7);
        weekday->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(weekday);

        horizontalLayoutWidget_2 = new QWidget(centralwidget);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(250, 139, 291, 101));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        centigrade = new QLabel(horizontalLayoutWidget_2);
        centigrade->setObjectName("centigrade");
        QFont font8;
        font8.setFamilies({QString::fromUtf8("Hannotate SC")});
        font8.setPointSize(35);
        font8.setBold(true);
        centigrade->setFont(font8);
        centigrade->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(centigrade);

        icon = new QLabel(horizontalLayoutWidget_2);
        icon->setObjectName("icon");
        QFont font9;
        font9.setFamilies({QString::fromUtf8("Yuppy SC")});
        font9.setPointSize(36);
        font9.setBold(false);
        icon->setFont(font9);
        icon->setScaledContents(true);

        horizontalLayout_2->addWidget(icon);

        type = new QLabel(horizontalLayoutWidget_2);
        type->setObjectName("type");
        QFont font10;
        font10.setFamilies({QString::fromUtf8("Hannotate SC")});
        font10.setPointSize(27);
        font10.setBold(true);
        type->setFont(font10);
        type->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(type);

        horizontalLayout_2->setStretch(0, 1);
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(0, 440, 801, 20));
        line_2->setFrameShape(QFrame::Shape::HLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);
        line_3 = new QFrame(centralwidget);
        line_3->setObjectName("line_3");
        line_3->setGeometry(QRect(-10, 60, 801, 20));
        line_3->setFrameShape(QFrame::Shape::HLine);
        line_3->setFrameShadow(QFrame::Shadow::Sunken);
        warningPanel = new QLabel(centralwidget);
        warningPanel->setObjectName("warningPanel");
        warningPanel->setGeometry(QRect(640, 140, 151, 91));
        line_4 = new QFrame(centralwidget);
        line_4->setObjectName("line_4");
        line_4->setGeometry(QRect(0, 250, 801, 20));
        line_4->setFrameShape(QFrame::Shape::HLine);
        line_4->setFrameShadow(QFrame::Shadow::Sunken);
        noticeIcon = new QLabel(centralwidget);
        noticeIcon->setObjectName("noticeIcon");
        noticeIcon->setGeometry(QRect(690, 110, 51, 51));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(130, 10, 491, 44));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        searchbutton_2 = new QPushButton(layoutWidget);
        searchbutton_2->setObjectName("searchbutton_2");
        QFont font11;
        font11.setFamilies({QString::fromUtf8("Hannotate SC")});
        font11.setPointSize(18);
        font11.setBold(true);
        searchbutton_2->setFont(font11);
        searchbutton_2->setFlat(true);

        horizontalLayout_3->addWidget(searchbutton_2);

        searchline = new QLineEdit(layoutWidget);
        searchline->setObjectName("searchline");

        horizontalLayout_3->addWidget(searchline);

        searchbutton = new QPushButton(layoutWidget);
        searchbutton->setObjectName("searchbutton");
        searchbutton->setFont(font11);
        searchbutton->setFlat(true);

        horizontalLayout_3->addWidget(searchbutton);

        horizontalLayout_3->setStretch(1, 10);
        weatherwindow->setCentralWidget(centralwidget);

        retranslateUi(weatherwindow);

        QMetaObject::connectSlotsByName(weatherwindow);
    } // setupUi

    void retranslateUi(QMainWindow *weatherwindow)
    {
        weatherwindow->setWindowTitle(QCoreApplication::translate("weatherwindow", "MainWindow", nullptr));
        back->setText(QString());
        dateweekday->setText(QCoreApplication::translate("weatherwindow", "date/week", nullptr));
        type1->setText(QCoreApplication::translate("weatherwindow", "type1", nullptr));
        high->setText(QCoreApplication::translate("weatherwindow", "high", nullptr));
        low->setText(QCoreApplication::translate("weatherwindow", "low", nullptr));
        high_2->setText(QCoreApplication::translate("weatherwindow", "high", nullptr));
        type1_2->setText(QCoreApplication::translate("weatherwindow", "type1", nullptr));
        low_2->setText(QCoreApplication::translate("weatherwindow", "low", nullptr));
        dateweekday_2->setText(QCoreApplication::translate("weatherwindow", "date/week", nullptr));
        high_3->setText(QCoreApplication::translate("weatherwindow", "high", nullptr));
        type1_3->setText(QCoreApplication::translate("weatherwindow", "type1", nullptr));
        low_3->setText(QCoreApplication::translate("weatherwindow", "low", nullptr));
        dateweekday_3->setText(QCoreApplication::translate("weatherwindow", "date/week", nullptr));
        high_4->setText(QCoreApplication::translate("weatherwindow", "high", nullptr));
        type1_4->setText(QCoreApplication::translate("weatherwindow", "type1", nullptr));
        low_4->setText(QCoreApplication::translate("weatherwindow", "low", nullptr));
        dateweekday_4->setText(QCoreApplication::translate("weatherwindow", "date/week", nullptr));
        high_5->setText(QCoreApplication::translate("weatherwindow", "high", nullptr));
        type1_5->setText(QCoreApplication::translate("weatherwindow", "type1", nullptr));
        low_5->setText(QCoreApplication::translate("weatherwindow", "low", nullptr));
        dateweekday_5->setText(QCoreApplication::translate("weatherwindow", "date/week", nullptr));
        high_6->setText(QCoreApplication::translate("weatherwindow", "high", nullptr));
        type1_6->setText(QCoreApplication::translate("weatherwindow", "type1", nullptr));
        low_6->setText(QCoreApplication::translate("weatherwindow", "low", nullptr));
        dateweekday_6->setText(QCoreApplication::translate("weatherwindow", "date/week", nullptr));
        aqi->setText(QCoreApplication::translate("weatherwindow", "aqi", nullptr));
        aqilevel->setText(QCoreApplication::translate("weatherwindow", "aqilevel", nullptr));
        windIcon->setText(QCoreApplication::translate("weatherwindow", "IICON", nullptr));
        wind->setText(QCoreApplication::translate("weatherwindow", "wind", nullptr));
        humidIcon->setText(QString());
        humid->setText(QCoreApplication::translate("weatherwindow", "humid", nullptr));
        city->setText(QCoreApplication::translate("weatherwindow", "\351\225\277\346\230\245\345\270\202", nullptr));
        date_2->setText(QCoreApplication::translate("weatherwindow", "date", nullptr));
        weekday->setText(QCoreApplication::translate("weatherwindow", "weekday", nullptr));
        centigrade->setText(QCoreApplication::translate("weatherwindow", "T", nullptr));
        icon->setText(QCoreApplication::translate("weatherwindow", "icon", nullptr));
        type->setText(QCoreApplication::translate("weatherwindow", "type", nullptr));
        warningPanel->setText(QCoreApplication::translate("weatherwindow", "warning", nullptr));
        noticeIcon->setText(QCoreApplication::translate("weatherwindow", "TextLabel", nullptr));
        searchbutton_2->setText(QString());
        searchbutton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class weatherwindow: public Ui_weatherwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEATHERWINDOW_H
