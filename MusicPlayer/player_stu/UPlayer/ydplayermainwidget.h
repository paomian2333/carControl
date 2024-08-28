#ifndef YDPLAYERMAINWIDGET_H
#define YDPLAYERMAINWIDGET_H

#include <QWidget>
#include <QFrame>
#include <QLabel>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QTimer>
#include <QUrl>
#include <QResizeEvent>
#include <QMouseEvent>
#include <QEvent>
#include <QFileDialog>
#include <QStandardPaths>
#include <QVBoxLayout>

namespace Ui {
class YDPlayerMainWidget;
}

class QMediaPlayer;
class QVideoWidget;

class YDPlayerMainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit YDPlayerMainWidget(QWidget *parent = nullptr);
    ~YDPlayerMainWidget();

private slots:
    void t_replay();
    void resizeEvent(QResizeEvent *e);
    bool eventFilter(QObject *obj, QEvent *event);

    void play();
    void stop();
protected:
    void mouseMoveEvent(QMouseEvent *);
private:
    void t_togglePlayPause();
    void t_setPosition(int);
    void t_setVolume(int);
public slots:
    void onExit();
private slots:
    void slotPlayerStarted();
    void slotPlayerStoped();
    void slotPlayerError(QMediaPlayer::Error);
    void slotMediaStatusChanged(QMediaPlayer::MediaStatus);
    void slotPlayerStatusChanged(QMediaPlayer::State);
    void slotMuteChanged(bool);
    void slotVolumeChanged(int);
    void slotPositionChange(qint64 pos);
private slots:
    void on_btnOpenFile_clicked();
private:
    QMediaPlayer* m_player;
    QVideoWidget* m_videoWidget;
    QString currentTime;
    QString totalTime;

    QTimer* showTimer;
    bool ignoreShowTimer;
    QUrl url;

    Ui::YDPlayerMainWidget *ui;
};

#endif // YDPLAYERMAINWIDGET_H
