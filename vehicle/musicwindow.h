#ifndef MUSICWINDOW_H
#define MUSICWINDOW_H

#include <QWidget>
#include <QTextBlock>
#include <QTimer>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>
#include <QMainWindow>

class QAudioOutput;
class QMediaPlayer;

QT_BEGIN_NAMESPACE
namespace Ui {
class MusicWindow;
}
QT_END_NAMESPACE

class MusicWindow : public QMainWindow
{
    Q_OBJECT

public:
    MusicWindow(QMainWindow *parent = nullptr);
    ~MusicWindow();

private slots:
    void on_opendicButton_clicked();

    void on_playButton_clicked();

    void on_lastButton_clicked();

    void on_nextButton_clicked();


    void on_listWidget_doubleClicked(const QModelIndex &index);

    void on_volumeButton_clicked();

    void on_modeButton_clicked();

    void on_searchButton_clicked();

    void databack(QNetworkReply *reply);

    void on_Netlist_doubleClicked(const QModelIndex &index);

private:
    Ui::MusicWindow *ui;
    QList<QUrl> playList;  //play list
    QAudioOutput* audioOutput;
    QMediaPlayer* mediaPlayer;

    int curplayIndex = 0;
    int playmode = 0;
    int volumemode = 1;

    int prevolume = 50;
    QByteArray searchInfo;
    int musicId = 0;
    QString musicName,singerName;
    QNetworkAccessManager* manager;
    QString url;
};
#endif // MUSICWINDOW_H
