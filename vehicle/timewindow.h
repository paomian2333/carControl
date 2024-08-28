#ifndef TIMEWINDOW_H
#define TIMEWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class timewindow; }
QT_END_NAMESPACE

class timewindow : public QMainWindow
{
    Q_OBJECT

public:
    timewindow(QWidget *parent = nullptr);
    ~timewindow();
private slots:
    void do_show_time();
    void on_pushButton_clicked();

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::timewindow *ui;
    QTimer *timer;
    QString local;
    QMap<int,QString> zone={{0,"Asia/Shanghai"},{1,"Asia/Tokyo"},{2,"America/Los_Angeles"},{3,"Europe/London"}};
};
#endif // TIMEWINDOW_H
