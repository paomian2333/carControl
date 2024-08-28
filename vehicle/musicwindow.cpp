#include "musicwindow.h"
#include "ui_musicwindow.h"
#include <QDebug>
#include <QFileDialog>
#include <QDir>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QUrl>
#include <QRandomGenerator>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>
#include <QMessageBox>
#include <QString>
#include <QLCDNumber>
#include <QBrush>


MusicWindow::MusicWindow(QMainWindow *parent)
    : QMainWindow(parent)
    , ui(new Ui::MusicWindow)
{
    ui->setupUi(this);
    //net
    manager = new QNetworkAccessManager(this);
    connect(manager,SIGNAL(finished(QNetworkReply *)),this,SLOT(databack(QNetworkReply *)));


    //play music

    audioOutput = new QAudioOutput(this);

    mediaPlayer = new QMediaPlayer(this);
    mediaPlayer->setAudioOutput(audioOutput);

    //get the total time of current song
    connect(mediaPlayer,&QMediaPlayer::durationChanged,this,[=](qint64 duration)
    {
        ui->totalLabel->setText(QString("%1:%2").arg(duration/1000/60,2,10,QChar('0')).arg(duration/1000%60,2,10,QChar('0')));
        ui->playSlider->setRange(0,duration);
    });
    //get the current time of current song
    connect(mediaPlayer,&QMediaPlayer::positionChanged,this,[=](qint64 position)
    {
        ui->curLabel->setText(QString("%1:%2").arg(position/1000/60,2,10,QChar('0')).arg(position/1000%60,2,10,QChar('0')));
        ui->playSlider->setValue(position);
    });

    //slide the slider to change the music time
    connect(ui->playSlider,&QSlider::sliderMoved,mediaPlayer,&QMediaPlayer::setPosition);

    audioOutput->setVolume(prevolume / 100.0);
    ui->volumeSlider->setRange(0,100);
    ui->volumeSlider->setValue(prevolume);
    //change volume
    connect(ui->volumeSlider,&QSlider::valueChanged,[=](int value)
    {
        audioOutput->setVolume(value/100.0);
    });

    //auto play
    connect(mediaPlayer,&QMediaPlayer::mediaStatusChanged,[=]()
    {
        if(mediaPlayer->playbackState() == QMediaPlayer::StoppedState && ui->playSlider->value() == ui->playSlider->maximum())
        {
            switch (playmode) {
            case 0:
                curplayIndex = (curplayIndex+1)% playList.size();
                ui->listWidget->setCurrentRow(curplayIndex);
                mediaPlayer->setSource(playList[curplayIndex]);
                mediaPlayer->play();
                break;
            case 1:
                curplayIndex = QRandomGenerator::global()->bounded(0,playList.size());
                ui->listWidget->setCurrentRow(curplayIndex);
                mediaPlayer->setSource(playList[curplayIndex]);
                mediaPlayer->play();
                break;

            case 2:
                curplayIndex = curplayIndex;
                ui->listWidget->setCurrentRow(curplayIndex);
                mediaPlayer->setSource(playList[curplayIndex]);
                mediaPlayer->play();
                break;
            }
        }

    });
}

MusicWindow::~MusicWindow()
{
    delete ui;
}

void MusicWindow::on_opendicButton_clicked()
{
    auto path = QFileDialog::getExistingDirectory(this,"选择音乐所在目录","/home");

    QDir dir(path);
    auto musicList = dir.entryList(QStringList()<<"*.mp3"<<"*.wav");
    //show music filename
    ui->listWidget->addItems(musicList);

    ui->listWidget->setCurrentRow(0);
    //save the path of musics
    for(auto file: musicList) playList.append(QUrl::fromLocalFile(path+"/"+file));
    qInfo()<<playList;
}

//play and pause
void MusicWindow::on_playButton_clicked()
{
    if(playList.empty()) return;
    switch(mediaPlayer->playbackState())
    {
    case QMediaPlayer::PlaybackState::StoppedState:
    {
        //NOT PLAYING
        //get choosen row
        curplayIndex = ui->listWidget->currentRow();
        //play choosen music
        mediaPlayer->setSource(playList[curplayIndex]);
        mediaPlayer->play();
        ui->playButton->setStyleSheet("border-image: url(:/sources/stop.png)");
        qInfo()<<"playing";
        break;
    }

    case QMediaPlayer::PlaybackState::PlayingState:
        //PLAYING
        //stop playing
        mediaPlayer->pause();
        ui->playButton->setStyleSheet("border-image: url(:/sources/play_fill.png)");
        qInfo()<<"paused";
        break;
    case QMediaPlayer::PlaybackState::PausedState:
        //Paused
        mediaPlayer->play();
        qInfo()<<"playing";
        ui->playButton->setStyleSheet("border-image: url(:/sources/stop.png)");
        break;
    }


}

//last song
void MusicWindow::on_lastButton_clicked()
{
    switch (playmode) {
    case 0:
        curplayIndex = (curplayIndex-1)% playList.size();
        ui->listWidget->setCurrentRow(curplayIndex);
        mediaPlayer->setSource(playList[curplayIndex]);
        mediaPlayer->play();
        break;
    case 1:
        curplayIndex = QRandomGenerator::global()->bounded(0,playList.size());
        ui->listWidget->setCurrentRow(curplayIndex);
        mediaPlayer->setSource(playList[curplayIndex]);
        mediaPlayer->play();
        break;

    case 2:
        curplayIndex = curplayIndex;
        ui->listWidget->setCurrentRow(curplayIndex);
        mediaPlayer->setSource(playList[curplayIndex]);
        mediaPlayer->play();
        break;
    }
}

//next song
void MusicWindow::on_nextButton_clicked()
{
    switch (playmode) {
    case 0:
        curplayIndex = (curplayIndex+1)% playList.size();
        ui->listWidget->setCurrentRow(curplayIndex);
        mediaPlayer->setSource(playList[curplayIndex]);
        mediaPlayer->play();
        break;
    case 1:
        curplayIndex = QRandomGenerator::global()->bounded(0,playList.size());
        ui->listWidget->setCurrentRow(curplayIndex);
        mediaPlayer->setSource(playList[curplayIndex]);
        mediaPlayer->play();
        break;

    case 2:
        curplayIndex = curplayIndex;
        ui->listWidget->setCurrentRow(curplayIndex);
        mediaPlayer->setSource(playList[curplayIndex]);
        mediaPlayer->play();
        break;
    }
}


void MusicWindow::on_listWidget_doubleClicked(const QModelIndex &index)
{
    curplayIndex = index.row();
    mediaPlayer->setSource(playList[curplayIndex]);
    mediaPlayer->play();
}


void MusicWindow::on_volumeButton_clicked()
{
    volumemode = !volumemode;
    if(volumemode == 1)
    {
        audioOutput->setMuted(0);

        ui->volumeButton->setStyleSheet("border-image: url(:/sources/notification_fill.png)");
    }
    else if(volumemode == 0)
    {
        audioOutput->setMuted(1);

        ui->volumeButton->setStyleSheet("border-image: url(:/sources/notification.png)");
    }
}


void MusicWindow::on_modeButton_clicked()
{
    playmode = (playmode+1)%3;
    switch (playmode) {
    case 0:
        ui->modeButton->setStyleSheet("border-image: url(:/sources/music_playmode_order.png)");
        break;
    case 1:
        ui->modeButton->setStyleSheet("border-image: url(:/sources/music_playmode_random.png)");
        break;
    case 2:
        ui->modeButton->setStyleSheet("border-image: url(:/sources/songtab_playmode_singlecycle.png)");
        break;

    }
}


void MusicWindow::on_searchButton_clicked()
{
    ui->Netlist->clear();
    QString str,s;
    s=ui->lineEdit->text();
    str="http://music.163.com/api/search/get/web?csrf_token=hlpretag=&hlposttag=&s={"+s+"}&type=1&offset=0&total=true&limit=1";
    QNetworkRequest request;
    request.setUrl(str);
    manager->get(request);              //请求
}

void MusicWindow::databack(QNetworkReply *reply)
{
    searchInfo=reply->readAll();
    QJsonParseError err;               //错误信息对象
    QJsonDocument json_recv = QJsonDocument::fromJson(searchInfo,&err);//将json文本转换为 json 文件对象
    if(err.error != QJsonParseError::NoError)             //判断是否符合语法
    {
        qDebug() <<"搜索歌曲Json获取格式错误"<< err.errorString();
        return;
    }
    QJsonObject totalObject = json_recv.object();
    QStringList keys = totalObject.keys();
    if(keys.contains("result"))
    {
        QJsonObject resultObject = totalObject["result"].toObject();
        QStringList resultKeys = resultObject.keys();
        if(resultKeys.contains("songs"))
        {
            QJsonArray array = resultObject["songs"].toArray();
            for(auto i : array)
            {
                QJsonObject object = i.toObject();
                QStringList artistsKeys = object.keys();

                musicId = object["id"].toInt();
                musicName = object["name"].toString();
                if(artistsKeys.contains("artists"))                //如果result中包含了 artists
                {
                    QJsonArray artistsArray = object["artists"].toArray();   //将 artist 的内容提取后保存
                    for(auto j : artistsArray)
                    {
                        QJsonObject object2 = j.toObject();
                        singerName = object2["name"].toString();         // 歌手名
                    }
                }
                ui->Netlist->addItem(musicName+"-"+singerName);

            }

        }
        url=QString("https://music.163.com/song/media/outer/url?id=%0").arg(musicId);
    }


}

void MusicWindow::on_Netlist_doubleClicked(const QModelIndex &index)
{
    playList.append(url);
    ui->listWidget->addItem(musicName+"-"+singerName);
}

