/********************************************************************************
** Form generated from reading UI file 'map.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAP_H
#define UI_MAP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Map
{
public:
    QWidget *centralWidget;
    QPushButton *InButton;
    QPushButton *outButton;
    QComboBox *startBox;
    QLabel *label;
    QLabel *label_2;
    QComboBox *endBox;
    QLabel *label_3;
    QPushButton *shortBtn;
    QLineEdit *showDist;
    QLineEdit *edit_search;
    QWidget *mapWidget;
    QPushButton *reduceBtn;
    QPushButton *searchBtn;
    QPushButton *enlargeBtn;
    QLabel *piclabel;
    QGraphicsView *graphicsView;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *btnClose;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Map)
    {
        if (Map->objectName().isEmpty())
            Map->setObjectName("Map");
        Map->resize(1850, 950);
        centralWidget = new QWidget(Map);
        centralWidget->setObjectName("centralWidget");
        InButton = new QPushButton(centralWidget);
        InButton->setObjectName("InButton");
        InButton->setGeometry(QRect(1650, 0, 93, 41));
        InButton->setStyleSheet(QString::fromUtf8("background-color: rgb(160, 255, 143);\n"
"font: 75 10pt \"Consolas\";"));
        outButton = new QPushButton(centralWidget);
        outButton->setObjectName("outButton");
        outButton->setGeometry(QRect(1750, 0, 93, 41));
        outButton->setStyleSheet(QString::fromUtf8("background-color: rgb(160, 255, 143);\n"
"font: 75 10pt \"Consolas\";"));
        startBox = new QComboBox(centralWidget);
        startBox->setObjectName("startBox");
        startBox->setGeometry(QRect(100, 0, 141, 41));
        label = new QLabel(centralWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 0, 81, 41));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);\n"
"font: 75 10pt \"Consolas\";"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(310, 0, 81, 41));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"font: 75 10pt \"Consolas\";\n"
"color: rgb(255, 255, 255);"));
        endBox = new QComboBox(centralWidget);
        endBox->setObjectName("endBox");
        endBox->setGeometry(QRect(390, 0, 141, 41));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(930, 0, 101, 41));
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 127);\n"
"font: 75 10pt \"Consolas\";"));
        shortBtn = new QPushButton(centralWidget);
        shortBtn->setObjectName("shortBtn");
        shortBtn->setGeometry(QRect(630, 0, 151, 41));
        shortBtn->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);\n"
"font: 75 10pt \"Consolas\";"));
        showDist = new QLineEdit(centralWidget);
        showDist->setObjectName("showDist");
        showDist->setGeometry(QRect(1030, 0, 131, 41));
        showDist->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 75 10pt \"Consolas\";"));
        edit_search = new QLineEdit(centralWidget);
        edit_search->setObjectName("edit_search");
        edit_search->setGeometry(QRect(20, 70, 891, 61));
        mapWidget = new QWidget(centralWidget);
        mapWidget->setObjectName("mapWidget");
        mapWidget->setGeometry(QRect(380, 260, 831, 361));
        reduceBtn = new QPushButton(centralWidget);
        reduceBtn->setObjectName("reduceBtn");
        reduceBtn->setGeometry(QRect(1330, 70, 89, 61));
        searchBtn = new QPushButton(centralWidget);
        searchBtn->setObjectName("searchBtn");
        searchBtn->setGeometry(QRect(980, 70, 131, 61));
        enlargeBtn = new QPushButton(centralWidget);
        enlargeBtn->setObjectName("enlargeBtn");
        enlargeBtn->setGeometry(QRect(1170, 70, 89, 61));
        piclabel = new QLabel(centralWidget);
        piclabel->setObjectName("piclabel");
        piclabel->setGeometry(QRect(380, 260, 831, 361));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setEnabled(true);
        graphicsView->setGeometry(QRect(20, -150, 1471, 861));
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(30, -140, 160, 80));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        btnClose = new QPushButton(centralWidget);
        btnClose->setObjectName("btnClose");
        btnClose->setGeometry(QRect(1230, 0, 121, 41));
        Map->setCentralWidget(centralWidget);
        mapWidget->raise();
        piclabel->raise();
        InButton->raise();
        outButton->raise();
        graphicsView->raise();
        edit_search->raise();
        gridLayoutWidget->raise();
        searchBtn->raise();
        enlargeBtn->raise();
        reduceBtn->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        startBox->raise();
        showDist->raise();
        shortBtn->raise();
        endBox->raise();
        btnClose->raise();
        menuBar = new QMenuBar(Map);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1850, 27));
        Map->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Map);
        mainToolBar->setObjectName("mainToolBar");
        Map->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Map);
        statusBar->setObjectName("statusBar");
        Map->setStatusBar(statusBar);

        retranslateUi(Map);

        QMetaObject::connectSlotsByName(Map);
    } // setupUi

    void retranslateUi(QMainWindow *Map)
    {
        Map->setWindowTitle(QCoreApplication::translate("Map", "MainWindow", nullptr));
        InButton->setText(QCoreApplication::translate("Map", "\346\224\276\345\244\247 +", nullptr));
        outButton->setText(QCoreApplication::translate("Map", "\347\274\251\345\260\217 -", nullptr));
        label->setText(QCoreApplication::translate("Map", " \350\265\267\345\247\213\347\202\271\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("Map", " \347\273\210\347\202\271\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("Map", "\346\234\200\347\237\255\350\267\235\347\246\273\344\270\272\357\274\232", nullptr));
        shortBtn->setText(QCoreApplication::translate("Map", "\345\274\200\345\247\213\346\237\245\346\211\276\346\234\200\347\237\255\350\267\257\345\276\204", nullptr));
        showDist->setText(QString());
        reduceBtn->setText(QString());
        searchBtn->setText(QCoreApplication::translate("Map", "\346\220\234\347\264\242", nullptr));
        enlargeBtn->setText(QString());
        piclabel->setText(QCoreApplication::translate("Map", "l", nullptr));
        btnClose->setText(QCoreApplication::translate("Map", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Map: public Ui_Map {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAP_H
