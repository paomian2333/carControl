#include "mainwindow.h"

#include <QApplication>
#include "map.h"

resolve_xml XML;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();
    // QString qss;
    // QFile qssFile(":/map/myQss.qss");
    // qssFile.open(QFile::ReadOnly);
    // if(qssFile.isOpen())
    // {
    //     qss = QLatin1String(qssFile.readAll());
    //     a.setStyleSheet(qss);
    //     qssFile.close();
    // }
    XML.imortant();
    return a.exec();
}
