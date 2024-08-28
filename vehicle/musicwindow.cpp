#include "musicwindow.h"
#include "ui_musicwindow.h"
#include<QFile>
#include<QMessageBox>
#include<QElapsedTimer>
#include<QScrollBar>
#include <QPainter>
#include <QPlainTextEdit>
#include <QMovie>
bool MusicWindow::eventFilter(QObject *watched, QEvent *event)
{
    if(event->type()!=QEvent::KeyPress)
        return QWidget::eventFilter(watched,event);
    QKeyEvent*keyEvent=static_cast<QKeyEvent*>(event);
    if(keyEvent->key()!=Qt::Key_Delete)
        return QWidget::eventFilter(watched,event);
    if(watched==ui->listWidget)
    {
        delete ui->listWidget->takeItem(ui->listWidget->currentRow());
    }
    return true;
}

void MusicWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,pmovie->currentPixmap());
    QMainWindow::paintEvent(event);
}
MusicWindow::MusicWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MusicWindow)
{
    ui->setupUi(this);
    manager = new QNetworkAccessManager(this);//歌曲请求
    musicmanager=new QNetworkAccessManager(this);//歌曲字节流
    //ui->listWidget->setCurrentItem(QString(reply->readAll()));

    connect(ui->searchline, SIGNAL(returnPressed), this, SLOT(onEnterPress()));
    connect(manager, SIGNAL(finished(QNetworkReply *)), this, SLOT(replyFinished(QNetworkReply *)));
    connect(musicmanager, SIGNAL(finished(QNetworkReply *)), this, SLOT(replymusicFinished(QNetworkReply *)));

    this->setFixedSize(870,388);
    ui->scrollArea->setStyleSheet("background-color: transparent;");
    pmovie2=new QMovie(":/image/MusicWindow_picture/174128.gif",QByteArray(),this);
    pmovie2->start();
    pmovie=new QMovie(":/image/MusicWindow_picture/870388.gif",QByteArray(),this);
    pmovie->start();
    ui->scrollArea->setStyleSheet("background-color: transparent;");
    ui->plainTextEdit->setStyleSheet("background-color: transparent;");
    ui->plainTextEdit->setEnabled(false);
    ui->labPic->setScaledContents(true);
   // ui->labPic->setPixmap(QPixmap(":/image/MusicWindow_picture/default.jpg"));


     timer = new QTimer(this);
    timer->start();
   connect(timer,&QTimer::timeout,this,&MusicWindow::onTimeout);


    player=new QMediaPlayer(this);
    QAudioOutput*audioOutput=new QAudioOutput(this);
    player->setAudioOutput(audioOutput);

 connect(player,&QMediaPlayer::positionChanged,this,&MusicWindow::do_positionChanged);//位置
 connect(player,&QMediaPlayer::durationChanged,this,&MusicWindow::do_durationChanged);//持续时间

 connect(player,&QMediaPlayer::sourceChanged,this,&MusicWindow::do_sourceChanged);//播放源
 connect(player,&QMediaPlayer::playbackStateChanged,this,&MusicWindow::do_playbackStateChanged);//播放状态
 connect(player,&QMediaPlayer::metaDataChanged,this,&MusicWindow::do_metaDataChanged);//用于图片

}

MusicWindow::~MusicWindow()
{    QDir dir(QDir::currentPath()); // 获取当前目录
    QFileInfoList fileList = dir.entryInfoList(QStringList() << "*.mp3", QDir::Files); // 过滤出所有.mp3文件
    foreach (const QFileInfo &fileInfo, fileList) {
        QFile file(fileInfo.fileName());
        if (file.remove()) {
            qDebug() << fileInfo.fileName() << "has been deleted.";
        } else {
            qDebug() << "Failed to delete" << fileInfo.fileName();
        }
    }
    delete ui;
}
void MusicWindow::replyFinished(QNetworkReply *arg)//初步请求，获取js里歌曲的基本信息
{QString js = arg->readAll();                                       // 取出返回的数据
    QJsonParseError error;                                             // 定义json解析错误
    QJsonDocument json = QJsonDocument::fromJson(js.toUtf8(), &error); // 解析json
    if (error.error != QJsonParseError::NoError)
    {
        qDebug() << error.errorString();
    }
    else
        qDebug() << "init json succeed!";
    // 取对象
    QJsonObject obj = json.object(); // 取出json对象
    //按网易云url内js结构获取歌名，歌手，id信息
    QJsonValue valueresult = obj.take("result");
    QJsonObject obj1 = valueresult.toObject();

    QJsonValue valuesong = obj1.take("songs");
    QJsonArray obj2 = valuesong.toArray();
    QVariantList list=obj2.toVariantList();
    auto map=list[0].toMap();
    QString songid=map["id"].toString();
    QString songname=map["name"].toString();
    auto artists=map["artists"].toList();
    auto artistsmap=artists[0].toMap();
    QString singername=artistsmap["name"].toString();
    downloadSong=songname+"-"+singername;
    //下面是防止文件中存在可列表中没有，此时直接结束函数
    if(QFile::exists(songname+"-"+singername+".mp3")){

        for(int i=0;i<ui->listWidget->count();i++){
            if(ui->listWidget->item(i)->text()==downloadSong){
                return;
            }
        }
        QListWidgetItem *aItem=new QListWidgetItem(downloadSong);
        //将歌曲名+歌手 的信息放入最左侧listwidget的行中
        ui->listWidget->addItem(aItem);
        ui->listWidget->setCurrentRow(ui->listWidget->count()-1);//搜索放入只有一首，此时指向第0个
        //下面生成  歌曲名-歌手.MP3的字符串，通过QUrl::fromLocalFile将这个文件名转换成一个本地文件的URL，也就是让当前的row指向一个歌曲名-歌手.MP3文件
        ui->listWidget->currentItem()->setData(Qt::UserRole,QUrl::fromLocalFile(QString("%1.mp3").arg(downloadSong)));
        //下面将列表，歌词都清空（搜索文件目前不能解析lrc，会影响显示效果
        ui->plainTextEdit->clear();
        lrclist.clear();
        lrctext.clear();
        //播放指向的个歌曲名-歌手.MP3文件，本地文件中
        player->setSource(QUrl::fromLocalFile(QString("%1.mp3").arg(downloadSong)));
        return;
    }
    ui->listWidget->clear();//若文件中不存在同名MP3，需要继续二次请求构造MP3文件，先清屏保证效果

    QListWidgetItem *aItem=new QListWidgetItem(downloadSong);
    ui->listWidget->addItem(aItem);
    ui->listWidget->setCurrentRow(ui->listWidget->count()-1);
    musicmanager->get(QNetworkRequest(QUrl(QString("http://music.163.com/song/media/outer/url?id=%1.mp3").arg(songid))));
//二次请求获取音乐文件字节流
}

void MusicWindow::replymusicFinished(QNetworkReply *arg)//二次请求获取音乐文件字节流
{
    if (arg->error() == QNetworkReply::NoError) {
        // 读取响应中的所有数据
        QByteArray responseData = arg->readAll();

        // 创建一个文件对象，准备写入数据
        QFile file(QString("%1.mp3").arg(downloadSong));
        // 检查文件是否存在，如果存在则删除
        if (file.exists() && !file.remove()) {//旧版的文件处理，用来防止文件重名
            qDebug() << "Error: Unable to delete existing file.";
            return; // 如果无法删除文件，则返回或进行错误处理
        }
        if (file.open(QIODevice::WriteOnly)) {//技术点：音乐文件字节流写入文件
            // 将字节流写入文件
            file.write(responseData);
            file.close(); // 关闭文件，完成写入

            // 可以在这里添加代码，比如播放音乐文件
        }
    } else {
        // 处理错误情况，比如打印错误信息
        qDebug() << "Network error:" << arg->errorString();
    }
    ui->listWidget->currentItem()->setData(Qt::UserRole,QUrl::fromLocalFile(QString("%1.mp3").arg(downloadSong)));
    ui->plainTextEdit->clear();
    lrclist.clear();
    lrctext.clear();
    player->setSource(QUrl::fromLocalFile(QString("%1.mp3").arg(downloadSong)));
}

void MusicWindow::onTimeout()
{
    this->repaint();
}

void MusicWindow::do_positionChanged(qint64 position)
{
    if(ui->sliderPosition->isSliderDown())//滑动条正在被拖动，不理会
        return;
    ui->sliderPosition->setSliderPosition(position);
    int secs=position/1000;//秒数
    int mins=secs/60;
    secs%=60;
    positionTime =QString::asprintf("%02d:%02d",mins,secs);
    show_lrc(QTime(0,mins,secs));

    ui->labRatio->setText(positionTime+"/"+durationTime);//进度文本框 fenzi/fenmu
}

void MusicWindow::do_durationChanged(qint64 duration)//总时长发生了改变
{ui->sliderPosition->setMaximum(duration);
    int secs=duration/1000;//秒数
    int mins=secs/60;
    secs%=60;
    durationTime =QString::asprintf("%02d:%02d",mins,secs);

    ui->labRatio->setText(positionTime+"/"+durationTime);

}

void MusicWindow::do_sourceChanged(const QUrl &media)//左下角的曲目更改
{ui->labCurMedia->setText(media.fileName());//按文件名称改了
    read_lrc(media.path());
}

void MusicWindow::do_playbackStateChanged(QMediaPlayer::PlaybackState newState)
{//设置播放相关按钮的状态
    ui->btnPlay->setEnabled(newState!=QMediaPlayer::PlayingState);//现在如果已经在播放则无效
    ui->btnPause->setEnabled(newState==QMediaPlayer::PlayingState);
    ui->btnStop->setEnabled(newState==QMediaPlayer::PlayingState);
    if((newState==QMediaPlayer::StoppedState)&&loopPay)//停滞状态但默认开循环
    {//循环：1.自动下一首2.从最后一首跳到第一
        int countsong=ui->listWidget->count();//歌数量
        int curRow=ui->listWidget->currentRow();//当前所在行
        ++curRow;
       curRow= curRow>=countsong?0:curRow;//当前行数如果大于count就归零
        ui->listWidget->setCurrentRow(curRow);//下一行
       player->setSource(ui->listWidget->currentItem()->data(Qt::UserRole).value<QUrl>());//将data保存的当前播放音乐的文件地址转化成Qurl
        player->play();
        //如果不是循环，播放完一首就暂停
    }

}


void MusicWindow::do_metaDataChanged()
{//元数据发生变化,修改显示图片
    QMediaMetaData metaData=player->metaData();
    QVariant metaImg=metaData.value(QMediaMetaData::ThumbnailImage);//获取,指定其中图片(缩略）
    if(metaImg.isValid())//有效
    {QImage img=metaImg.value<QImage>();
        QPixmap musicPixmp=QPixmap::fromImage(img);
        if(ui->scrollArea->width()<musicPixmp.width())
            ui->labPic->setPixmap(musicPixmp.scaledToWidth(ui->scrollArea->width()-30));
        else ui->labPic->setPixmap(musicPixmp);
        //右边区域大小与图片大小作比较,谁小取谁，留出30的框
        ui->plainTextEdit->clear();


    }    else//无效

    {    ui->labPic->setMovie(pmovie2);
}


}
#include <QFileDialog>
void MusicWindow::on_btnAdd_clicked()
{   QString curPath=QDir::homePath();
    QString dlgTiltle="选择音频=v=";
    QString filter="你选择的音频是(*.mp3 *.wav *.wma);;所有文件(*.*)" ;//过滤器
    QStringList fileList= QFileDialog::getOpenFileNames(this,dlgTiltle,curPath,filter);
    if(fileList.isEmpty())
    {
        return;
    }
    foreach (const auto&item, fileList) {
        QFileInfo fileInfo(item);
        QListWidgetItem *aItem=new QListWidgetItem(fileInfo.fileName());
        aItem->setIcon(QIcon(":/images/images/musicFile.png"));
        aItem->setData(Qt::UserRole,QUrl::fromLocalFile(item));
        ui->listWidget->addItem(aItem);
        QString lrcpath=fileInfo.absoluteFilePath().chopped(3)+"lrc";
        if(!QFile::exists(lrcpath)){
            QMessageBox::warning(this,"警告",fileInfo.fileName()+"没有歌词",QMessageBox::Yes|QMessageBox::Cancel,QMessageBox::Yes);
        }
        lrclist<<lrcpath;
    }

    //如果没有正在播放，就从第一开始播放
    if(player->playbackState()!=QMediaPlayer::PlayingState)
    {
        ui->listWidget->setCurrentRow(0);
        QUrl source=ui->listWidget->currentItem()->data(Qt::UserRole).value<QUrl>();
        player->setSource(source);
        player->play();
    }






}


void MusicWindow::on_btnRemove_clicked()
{//只是从widget移除
    int index=ui->listWidget->currentRow();
    if(index<0)return;
    delete ui->listWidget->takeItem(index);
    loopPay=false;
    ui->btnLoop->setChecked(false);
    player->stop();
    ui->labPic->setPixmap(QPixmap(":/image/MusicWindow_picture/default.jpg"));
    ui->plainTextEdit->clear();
    p0=QString::asprintf("%02d:%02d",0,0);
    d0=QString::asprintf("%02d:%02d",0,0);
    ui->labRatio->setText(p0+"/"+d0);
    ui->labCurMedia->clear();
    ui->listWidget->clearSelection();
    // if(ui->listWidget->count()<=0)
//移除当前播放曲目后，会停止播放状态，退出循环模式（参考QQ音乐）
}


void MusicWindow::on_btnClear_clicked()
{loopPay=false;
    ui->btnLoop->setChecked(false);
    ui->listWidget->clear();
    player->stop();
    ui->labPic->setMovie(pmovie2);
    ui->plainTextEdit->clear();
    ui->labCurMedia->clear();
    p0=QString::asprintf("%02d:%02d",0,0);
    d0=QString::asprintf("%02d:%02d",0,0);
    ui->labRatio->setText(p0+"/"+d0);
    ui->listWidget->clearSelection();
    ui->listWidget->clearSelection();

}


void MusicWindow::on_btnClose_clicked()
{
    player->pause();
    QMainWindow *parent=static_cast<QMainWindow *>(this->parent());
    this->hide();
    parent->show();
}


void MusicWindow::on_btnPlay_clicked()
{
    if(player->playbackState()==QMediaPlayer::PausedState)
    {
        player->play();
        return;
    }


    if(ui->listWidget->count()<=0)
    {
        return;
        if(ui->listWidget->currentRow()<0)
           ui->listWidget->setCurrentRow(0);

    }
    player->setSource(ui->listWidget->currentItem()->data(Qt::UserRole).value<QUrl>());

    player->play();
}


void MusicWindow::on_btnPause_clicked()
{player->pause();


}


void MusicWindow::on_btnStop_clicked()
{   loopPay=false;
    ui->btnLoop->setChecked(false);
    player->stop();
}


void MusicWindow::on_btnPrevious_clicked()
{    int curRow=ui->listWidget->currentRow();
    --curRow;
   curRow= curRow<0?0:curRow;
    ui->listWidget->setCurrentRow(curRow);
   loopPay=false;
    ui->btnLoop->setChecked(false);
   player->setSource(ui->listWidget->currentItem()->data(Qt::UserRole).value<QUrl>());
    player->play();
   loopPay=ui->btnLoop->isChecked();
}


void MusicWindow::on_btnNext_clicked()
{    int count=ui->listWidget->count();
    int curRow=ui->listWidget->currentRow();
    ++curRow;
    curRow= curRow>=count?count-1:curRow;
    ui->listWidget->setCurrentRow(curRow);
    loopPay=false;
    ui->btnLoop->setChecked(false);
    player->setSource(ui->listWidget->currentItem()->data(Qt::UserRole).value<QUrl>());
    player->play();
    loopPay=ui->btnLoop->isChecked();
}


void MusicWindow::on_doubleSpinBox_valueChanged(double arg1)
{
    player->setPlaybackRate(arg1);
}


void MusicWindow::on_btnLoop_clicked(bool checked)
{  loopPay=checked;

}


void MusicWindow::on_btnSound_clicked()
{
    bool mute=player->audioOutput()->isMuted();//用于检查某个音频输出或视频播放组件是否已经被静音
    player->audioOutput()->setMuted(!mute);
    if(mute)
        ui->btnSound->setIcon(QIcon(":/image/MusicWindow_picture/noSound.png"));
    else
        ui->btnSound->setIcon(QIcon(":/image/MusicWindow_picture/Sound.png"));
}


void MusicWindow::on_sliderVolumn_valueChanged(int value)
{

     player->audioOutput()->setVolume(value/100.0);
}


void MusicWindow::on_sliderPosition_valueChanged(int value)
{

    player->setPosition(value);
}


void MusicWindow::on_listWidget_doubleClicked(const QModelIndex &index)
{   Q_UNUSED(index);//宏，用于显式地标记一个参数或变量为未使用，从而避免编译器因为变量未使用而发出的警告
    loopPay=false;
   // ui->btnLoop->setChecked(false);
    player->setSource(ui->listWidget->currentItem()->data(Qt::UserRole).value<QUrl>());
    player->play();
    //loopPay=true;
    loopPay= ui->btnLoop->isChecked();
}

void MusicWindow::read_lrc(QString mp3name)
{
    mp3name.chop(3);
    QString lrcname = mp3name + "lrc";          //歌词文件名
    lrcname=lrcname.mid(1);
    qDebug() << "lrc:" << lrcname;
    QStringList::const_iterator it;
    lrctext.clear();
    it = std::find(lrclist.cbegin(),lrclist.cend(),lrcname);
    if(it == lrclist.cend())     //没有找到对应歌曲的歌词
    {
        //清空列表
        ui->plainTextEdit->clear();
        ui->plainTextEdit->setStyleSheet("background-color: transparent;");
        return ;
    }
    QFile lrc(lrcname);
    lrc.open( QIODevice::ReadOnly/*|QIODevice::Truncate*/);                 //打开歌词文件
    QTextStream textStream(&lrc);
    textStream.setEncoding(QStringConverter::Encoding::System);

    while(!textStream.atEnd()){
        QString line=textStream.readLine();
        lrctext<<line;
    }

}

void MusicWindow::show_lrc(QTime time)
{
    bool flag=false;
    for(int i=5;i<lrctext.size();i++){
        QString locatedtime=lrctext.at(i).mid(1,5);
        auto lt=QTime::fromString(locatedtime,"mm:ss");
        if(lt==time) {
            flag=true;
            ui->plainTextEdit->clear();
        }
        if(!flag&&lt>time) break;
        if(flag){
        ui->plainTextEdit->appendPlainText(lrctext.at(i).mid(10));
                  ui->plainTextEdit->setStyleSheet("background-color: #ffffff;");
        }

    }
    ui->plainTextEdit->verticalScrollBar()->setValue(0);

}


void MusicWindow::on_searchline_returnPressed()
{ if(ui->searchline->text().isEmpty())
    {
        QMessageBox::warning(this,"警告","搜索栏怎么敢为空的啊？你让我搜什么= =",QMessageBox::Yes|QMessageBox::Cancel,QMessageBox::Yes);
        return;
    }
    manager->get(QNetworkRequest(QUrl("http://music.163.com/api/search/get/web?csrf_token=hlpretag=&hlposttag=&s="+ui->searchline->text()+"&type=1&offset=0&total=true&limit=2")));


}


void MusicWindow::on_btn_search_clicked()
{
  on_searchline_returnPressed();
}

