#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class timewindow;
class weatherReport;
class MusicWindow;
class videowindow;
class mapwindow;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void do_show_time();

    void on_pushButton_clicked();

    void on_pushButton_music_clicked();

    void on_pushButton_time_clicked();

    void on_pushButton_weather_clicked();

private:
    QMovie *backgroundMovie;
    QTimer *timer;
    Ui::MainWindow *ui;
    timewindow *time;
    MusicWindow *music;
    weatherReport *weather;

    // QWidget interface
protected:
    virtual void paintEvent(QPaintEvent *event) override;
};


#endif // MAINWINDOW_H
