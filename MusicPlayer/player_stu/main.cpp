#include "UPlayer/ydplayermainwidget.h"
#include <QApplication>
#include <QtGui/QScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    YDPlayerMainWidget player;

    const QRect availableGeometry = QApplication::desktop()->availableGeometry(&player);
    player.resize(availableGeometry.width() / 6, availableGeometry.height() / 4);
    player.show();
    return a.exec();
}
