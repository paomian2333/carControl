#include "ydplayermainwidget.h"
#include "ui_ydplayermainwidget.h"
#include <QVBoxLayout>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QTimer>
#include <QDir>
#include <QTime>
#include <QFileDialog>
#include <QStandardPaths>

#define SHOW_TIMER_DURATION 3*1000

YDPlayerMainWidget::YDPlayerMainWidget(QWidget *parent) :
    QWidget(parent),
    ignoreShowTimer(false),
    ui(new Ui::YDPlayerMainWidget)
{
    ui->setupUi(this);
    //player init
    m_player = new QMediaPlayer(this, QMediaPlayer::VideoSurface);
    m_videoWidget = new QVideoWidget;
    m_player->setVideoOutput(m_videoWidget);

    setMouseTracking(true);
    QVBoxLayout *vl = new QVBoxLayout();
    vl->addWidget(m_videoWidget);
    m_videoWidget->hide();
    setLayout(vl);

    ui->frameBottom->setMouseTracking(true);
    ui->frameBottom->setStyleSheet(QLatin1String("QFrame#frameBottom\n"
                                                 "{\n"
                                                 "border:none;\n"
                                                 "background:rgba(0, 0, 0, 0.5);\n"
                                                 "}"));
    ui->frameBottom->installEventFilter(this);

    ui->frameVolume->hide();
    ui->frameVolume->installEventFilter(this);

    //播放进度条
    ui->horizontalSlider->setDisabled(true);
    ui->horizontalSlider->setTracking(true);
    ui->horizontalSlider->setMinimum(0);
    ui->horizontalSlider->installEventFilter(this);

    //play按钮
    connect(ui->pushButtonPlay, &QPushButton::clicked, this, &YDPlayerMainWidget::t_togglePlayPause);

    //扬声器
    ui->pushButtonSpeaker->setProperty("mute", false);
    connect(ui->pushButtonSpeaker, &QPushButton::clicked, [=] {
        bool isMute = ui->pushButtonSpeaker->property("mute").toBool();
        m_player->setMuted(!isMute);
        ui->pushButtonSpeaker->setProperty("mute", !isMute);
    });
    ui->pushButtonSpeaker->installEventFilter(this);

    //音量显示条
    ui->verticalSlider->setMinimum(0);
    ui->verticalSlider->setMaximum(100);
    ui->verticalSlider->setTracking(true);
    ui->verticalSlider->setValue(50); // 设置默认音量为 50
    ui->verticalSlider->installEventFilter(this);

    ui->pushButtonReplay->hide();
    connect(ui->pushButtonReplay, &QPushButton::clicked, this, &YDPlayerMainWidget::t_replay);

    connect(m_player, &QMediaPlayer::mediaStatusChanged, this, [=](QMediaPlayer::MediaStatus status) {
        if (status == QMediaPlayer::EndOfMedia) {
            ui->pushButtonReplay->show();
        }
    });

    //play event
    connect(m_player, &QMediaPlayer::mediaStatusChanged, this, &YDPlayerMainWidget::slotMediaStatusChanged);
    connect(m_player, &QMediaPlayer::stateChanged, this, &YDPlayerMainWidget::slotPlayerStatusChanged);
    connect(m_player, QOverload<QMediaPlayer::Error>::of(&QMediaPlayer::error), this, &YDPlayerMainWidget::slotPlayerError);
    connect(m_player, &QMediaPlayer::positionChanged, this, &YDPlayerMainWidget::slotPositionChange);
    connect(m_player, &QMediaPlayer::mutedChanged, this, &YDPlayerMainWidget::slotMuteChanged);
    connect(m_player, &QMediaPlayer::volumeChanged, this, &YDPlayerMainWidget::slotVolumeChanged);

    m_player->setVolume(50);

    //当前时间/总时间
    currentTime = totalTime = QString("00:00:00");
    QString showtime = currentTime + " / " + totalTime;
    ui->labelTime->setText(showtime);

    showTimer = new QTimer(this);
    showTimer->setSingleShot(true);
    showTimer->setInterval(SHOW_TIMER_DURATION);
    connect(showTimer, &QTimer::timeout, [=]{
        if (!ignoreShowTimer) {
            ui->frameBottom->hide();
        }
    });
}

YDPlayerMainWidget::~YDPlayerMainWidget()
{
    if (m_player)
        m_player->stop();
    delete m_player;
    delete ui;
}

bool YDPlayerMainWidget::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == ui->horizontalSlider && ui->horizontalSlider->isEnabled())
    {
        if (event->type() == QEvent::MouseButtonPress)
        {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
            if (mouseEvent->button() == Qt::LeftButton)
            {
                int dur = ui->horizontalSlider->maximum() - ui->horizontalSlider->minimum();
                int pos = ui->horizontalSlider->minimum() + dur * ((double)mouseEvent->x() / ui->horizontalSlider->width());
                if (pos != ui->horizontalSlider->sliderPosition())
                {
                    t_setPosition(pos);
                }
            }
        }
        else if (event->type() == QEvent::Wheel)
        {
            QWheelEvent *wheelevent = static_cast<QWheelEvent *>(event);
            int dur = ui->horizontalSlider->maximum() - ui->horizontalSlider->minimum();
            int pos = 0;
            if (wheelevent->angleDelta().y() > 0)
                pos = ui->horizontalSlider->value() + dur * 0.01;
            else
                pos = ui->horizontalSlider->value() - dur * 0.01;

            t_setPosition(pos);
        }
    }
    else if (obj == ui->verticalSlider && ui->verticalSlider->isEnabled())
    {
        if (event->type() == QEvent::MouseButtonPress)
        {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
            if (mouseEvent->button() == Qt::LeftButton)
            {
                int dur = ui->verticalSlider->maximum() - ui->verticalSlider->minimum();
                int value = ui->verticalSlider->maximum() - dur * ((double)mouseEvent->y() / ui->verticalSlider->height());
                t_setVolume(value);
            }
        }
        else if (event->type() == QEvent::Wheel)
        {
            QWheelEvent *wheelevent = static_cast<QWheelEvent *>(event);
            int dur = ui->verticalSlider->maximum() - ui->verticalSlider->minimum();
            int value = 0;
            if (wheelevent->angleDelta().y() > 0)
                value = ui->verticalSlider->value() + dur * 0.05;
            else
                value = ui->verticalSlider->value() - dur * 0.05;

            t_setVolume(value);
        }
    }
    else if (obj == ui->pushButtonSpeaker)
    {
        if (event->type() == QEvent::Enter)
        {
            QPoint pos = ui->frameBottom->mapToParent(ui->pushButtonSpeaker->pos());
            ui->frameVolume->setGeometry(pos.x() - ui->frameVolume->width() / 2 + ui->pushButtonSpeaker->width() / 2,
                                         this->height() - ui->frameVolume->height() - 37, ui->frameVolume->width(), ui->frameVolume->height());
            ui->frameVolume->show();
            ui->frameVolume->raise();
        }
        else if (event->type() == QEvent::Leave)
        {
            // do nothing
        }
        else if (event->type() == QEvent::Wheel)
        {
            QWheelEvent *wheelevent = static_cast<QWheelEvent *>(event);
            int dur = ui->verticalSlider->maximum() - ui->verticalSlider->minimum();
            int value = -1;
            if (wheelevent->angleDelta().y() > 0)
                value = ui->verticalSlider->value() + dur * 0.05;
            else
                value = ui->verticalSlider->value() - dur * 0.05;

            t_setVolume(value);
        }
    }
    else if (obj == ui->frameVolume)
    {
        if (event->type() == QEvent::Enter)
        {
            ignoreShowTimer = true;
        }
        else if (event->type() == QEvent::Leave)
        {
            ignoreShowTimer = false;
        }
        else if (event->type() == QEvent::Show)
        {
            ui->labelVolume->setText(QString::number(m_player->volume()));
        }
        else if (event->type() == QEvent::Wheel)
        {
            QWheelEvent *wheelevent = static_cast<QWheelEvent *>(event);
            int dur = ui->verticalSlider->maximum() - ui->verticalSlider->minimum();
            int value = -1;
            if (wheelevent->angleDelta().y() > 0)
                value = ui->verticalSlider->value() + dur * 0.05;
            else
                value = ui->verticalSlider->value() - dur * 0.05;

            t_setVolume(value);
        }
    }
    else if (obj == ui->frameBottom)
    {
        if (event->type() == QEvent::Enter)
        {
            ignoreShowTimer = true;
        }
        else if (event->type() == QEvent::Leave)
        {
            ignoreShowTimer = false;
        }
    }

    return QWidget::eventFilter(obj, event);
}


void YDPlayerMainWidget::resizeEvent(QResizeEvent *e)
{
    QWidget::resizeEvent(e);
    ui->frameBottom->setGeometry(0, this->height() - ui->frameBottom->height(), this->width(), ui->frameBottom->height());
    ui->pushButtonReplay->setGeometry((this->width() - ui->pushButtonReplay->width()) / 2, (this->height() - ui->pushButtonReplay->height()) / 2,
                                      ui->pushButtonReplay->width(), ui->pushButtonReplay->height());
}

void YDPlayerMainWidget::play()
{
    if (!url.isEmpty() && m_player)
    {
        m_player->setMedia(url);
        m_player->play();
    }
}

void YDPlayerMainWidget::t_togglePlayPause()
{
    if (m_player->state() == QMediaPlayer::PlayingState)
    {
        m_player->pause();
    }
    else if (m_player->state() == QMediaPlayer::StoppedState)
    {
        play();
    }
    else if (m_player->state() == QMediaPlayer::PausedState)
    {
        m_player->play();
    }
}

void YDPlayerMainWidget::stop()
{
    if (m_player)
        m_player->stop();
}

void YDPlayerMainWidget::mouseMoveEvent(QMouseEvent *e)
{
    QWidget::mouseMoveEvent(e);
    QPoint mousePos = e->globalPos();

    if (ui->frameVolume->isVisible())
    {
        QPoint pos = ui->frameVolume->mapToGlobal(QPoint(0, 0));
        QRect rect = QRect(pos, QSize(ui->frameVolume->width(), ui->frameVolume->height() + 37));
        if (!rect.contains(mousePos))
        {
            ui->frameVolume->hide();
        }
    }

    ui->frameBottom->show();
    ui->frameBottom->raise();

    if (showTimer)
    {
        if (showTimer->isActive())
        {
            showTimer->stop();
        }
        showTimer->start();
    }
}

void YDPlayerMainWidget::t_setPosition(int pos)
{
    m_player->setPosition(pos);
}

void YDPlayerMainWidget::t_setVolume(int value)
{
    m_player->setVolume(value);
}

void YDPlayerMainWidget::onExit()
{
    if (m_player)
        m_player->stop();
    hide();
}

void YDPlayerMainWidget::slotMediaStatusChanged(QMediaPlayer::MediaStatus status)
{
    qDebug() << __FUNCTION__ << status;
    if (status == QMediaPlayer::BufferedMedia)
        slotPlayerStarted();
}

void YDPlayerMainWidget::slotPlayerStatusChanged(QMediaPlayer::State status)
{
    qDebug() << __FUNCTION__ << status;
    if (status == QMediaPlayer::PlayingState)
    {
        ui->pushButtonPlay->setStyleSheet(QLatin1String("QPushButton\n"
                                                        "{\n"
                                                        " background:none;\n"
                                                        " border:none;\n"
                                                        " image: url(:/images/icon_pause.png);\n"
                                                        "}\n"
                                                        "QPushButton:hover\n"
                                                        "{\n"
                                                        " background:none;\n"
                                                        " border:none;\n"
                                                        " image: url(:/images/icon_pause_hover.png);\n"
                                                        "}"));
    }
    else if (status == QMediaPlayer::PausedState)
    {
        ui->pushButtonPlay->setStyleSheet(QLatin1String("QPushButton\n"
                                                        "{\n"
                                                        " background:none;\n"
                                                        " border:none;\n"
                                                        " image: url(:/images/icon_play.png);\n"
                                                        "}\n"
                                                        "QPushButton:hover\n"
                                                        "{\n"
                                                        " background:none;\n"
                                                        " border:none;\n"
                                                        " image: url(:/images/icon_play_hover.png);\n"
                                                        "}"));
    }
    else if (status == QMediaPlayer::StoppedState)
    {
        ui->pushButtonPlay->setStyleSheet(QLatin1String("QPushButton\n"
                                                        "{\n"
                                                        " background:none;\n"
                                                        " border:none;\n"
                                                        " image: url(:/images/icon_play.png);\n"
                                                        "}\n"
                                                        "QPushButton:hover\n"
                                                        "{\n"
                                                        " background:none;\n"
                                                        " border:none;\n"
                                                        " image: url(:/images/icon_play_hover.png);\n"
                                                        "}"));
        slotPlayerStoped();
    }
}

void YDPlayerMainWidget::slotMuteChanged(bool bMute)
{
    if (bMute)
    {
        ui->pushButtonSpeaker->setStyleSheet(QLatin1String("QPushButton\n"
                                                           "{\n"
                                                           " background:none;\n"
                                                           " border:none;\n"
                                                           " image: url(:/images/icon_speaker_mute.png);\n"
                                                           "}\n"
                                                           "QPushButton:hover\n"
                                                           "{\n"
                                                           " background:none;\n"
                                                           " border:none;\n"
                                                           " image: url(:/images/icon_speaker_mute_hover.png);\n"
                                                           "}"));
        ui->pushButtonSpeaker->setProperty("mute", true);
    }
    else
    {
        ui->pushButtonSpeaker->setStyleSheet(QLatin1String("QPushButton\n"
                                                           "{\n"
                                                           " background:none;\n"
                                                           " border:none;\n"
                                                           " image: url(:/images/icon_speaker.png);\n"
                                                           "}\n"
                                                           "QPushButton:hover\n"
                                                           "{\n"
                                                           " background:none;\n"
                                                           " border:none;\n"
                                                           " image: url(:/images/icon_speaker_hover.png);\n"
                                                           "}"));
        ui->pushButtonSpeaker->setProperty("mute", false);
    }
}

void YDPlayerMainWidget::slotVolumeChanged(int value)
{
    ui->verticalSlider->setValue(value);
    ui->labelVolume->setText(QString::number(value));
}

void YDPlayerMainWidget::slotPlayerStarted()
{
    ui->horizontalSlider->setValue(0);
    ui->horizontalSlider->setEnabled(m_player->isSeekable());
    ui->pushButtonReplay->hide();
    m_videoWidget->show();

    qint64 duration = m_player->duration();
    ui->horizontalSlider->setRange(0, duration);
    QTime totalTime(0, (duration / 60000) % 60, (duration / 1000) % 60);
    ui->labelTime->setText(currentTime + " / " + totalTime.toString("HH:mm:ss"));
}

void YDPlayerMainWidget::slotPlayerStoped()
{
    m_videoWidget->hide();
    ui->pushButtonReplay->show();
    ui->pushButtonReplay->raise();
    ui->horizontalSlider->setValue(0);
    ui->horizontalSlider->setDisabled(true);
    ui->horizontalSlider->setMinimum(0);
    ui->horizontalSlider->setMaximum(0);
    // 停止的时候重置时间到 00:00:00
    ui->labelTime->setText("00:00:00");
}

void YDPlayerMainWidget::slotPlayerError(QMediaPlayer::Error e)
{
    qDebug() << e;
}

void YDPlayerMainWidget::slotPositionChange(qint64 pos)
{
    ui->horizontalSlider->setValue(pos);
    QTime currentTime(0, (pos / 60000) % 60, (pos / 1000) % 60);
    QTime totalTime(0, (m_player->duration() / 60000) % 60, (m_player->duration() / 1000) % 60);
    ui->labelTime->setText(currentTime.toString("HH:mm:ss") + " / " + totalTime.toString("HH:mm:ss"));
}

void YDPlayerMainWidget::on_btnOpenFile_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Video File"), QStandardPaths::writableLocation(QStandardPaths::MoviesLocation), tr("Video Files (*.mp4 *.avi *.mkv)"));
    if (!fileName.isEmpty()) {
        url = QUrl::fromLocalFile(fileName);
        play();
    }
}

void YDPlayerMainWidget::t_replay()
{
    m_player->setPosition(0); // 将播放位置重置为开始
    m_player->play(); // 开始播放
    ui->pushButtonReplay->hide(); // 隐藏 replay 按钮
}
