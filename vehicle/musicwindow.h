#ifndef MUSICWINDOW_H
#define MUSICWINDOW_H
#include <QTimer>
#include <QMainWindow>
#include<QtMultimedia>
#include <QProcess>
#include <QListWidgetItem>
#include <QListWidget>
#include <QListView>
#include <QNetworkAccessManager>
QT_BEGIN_NAMESPACE
namespace Ui {
class MusicWindow;
}
QT_END_NAMESPACE

class MusicWindow : public QMainWindow
{
    Q_OBJECT
   public:
   void lrc_show(QString mp3name);
private:
    QMediaPlayer*player;
    bool loopPay=true;//判断是否循环,默认开
    QString positionTime;
    QString durationTime;
    QString p0;
    QString d0;

    QNetworkAccessManager *manager;         //请求歌曲信息
    QNetworkAccessManager *musicmanager;   //请求歌曲文件，转化成MP3
    QTimer *timer;              //定时器
public:
    MusicWindow(QWidget *parent = nullptr);
    ~MusicWindow();

private slots:
    void replyFinished(QNetworkReply *);    //对返回的数据进行json解析处理
    void replymusicFinished(QNetworkReply *); //对返回的数据进行json解析处理
    void onTimeout();   //定时器
    void do_positionChanged(qint64 position);
     void do_durationChanged(qint64 duration);
     void do_sourceChanged(const QUrl &media);
 void do_playbackStateChanged(QMediaPlayer::PlaybackState newState);
       void do_metaDataChanged();
 void on_btnAdd_clicked();

       void on_btnRemove_clicked();

 void on_btnClear_clicked();

       void on_btnClose_clicked();

 void on_btnPlay_clicked();

       void on_btnPause_clicked();

 void on_btnStop_clicked();

       void on_btnPrevious_clicked();

 void on_btnNext_clicked();

       void on_doubleSpinBox_valueChanged(double arg1);

 void on_btnLoop_clicked(bool checked);

       void on_btnSound_clicked();

 void on_sliderVolumn_valueChanged(int value);

       void on_sliderPosition_valueChanged(int value);

 void on_listWidget_doubleClicked(const QModelIndex &index);

 void on_searchline_returnPressed();

 void on_btn_search_clicked();

 private:
    QMovie *pmovie;
    QMovie *pmovie2;
    Ui::MusicWindow *ui;
    QStringList lrclist;
    QStringList lrctext;
    QString downloadSong;
       // QObject interface
    void read_lrc(QString mp3name);
    void show_lrc(QTime time);
   public:
    virtual bool eventFilter(QObject *watched, QEvent *event);

       // QWidget interface
   protected:
       void paintEvent(QPaintEvent *event);
};
#endif // MUSICWINDOW_H
