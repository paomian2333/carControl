#include "map.h"
#include <QApplication>

resolve_xml XML;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Map w;
    QString qss;
    QFile qssFile(":qss/myQss.qss");
    qssFile.open(QFile::ReadOnly);
    if(qssFile.isOpen())
    {
        qss = QLatin1String(qssFile.readAll());
        a.setStyleSheet(qss);
        qssFile.close();
    }
    XML.imortant();
    w.showComBox();
    w.zoomInOut();
    w.show();
    return a.exec();
}
