#include "mainwindow.h"
#include "ui_mainwindow.h"

// Include necessary network modules
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

// URL and JSON parsing modules
#include <QUrl>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QFile>
#include <QDir>

//绘图
#include <QPalette>
#include <QPixmap>
#include <QBrush>

// Global variable
QString inputCity = "北京";

// Function to find city code by input
QString findCityCodeByInput(const QByteArray &jsonContent, const QString &userInput) {
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonContent);
    QJsonObject jsonObj = jsonDoc.object();
    QJsonArray jsonArray = jsonObj.value("城市代码").toArray();

    for (const QJsonValue &cityGroup : jsonArray) {
        QJsonObject cityObj = cityGroup.toObject();
        QJsonArray citiesArray = cityObj.value("市").toArray();
        for (const QJsonValue &cityData : citiesArray) {
            QJsonObject city = cityData.toObject();
            if (city.value("市名").toString() == userInput) {
                return city.value("编码").toString();
            }
        }
    }
    return QString(); // Return an empty string if the city code is not found
}

// Get weather information
void MainWindow::getWeather(){
    // Create network manager
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

    // Load city code from JSON file
    QString path = QDir::cleanPath(QString("../../res/cityCode.json"));
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Cannot open file:" << file.errorString();
        file.close();
        return;
    }
    QByteArray fileData = file.readAll();
    file.close();
    QString cityCode = findCityCodeByInput(fileData, inputCity);

    if (cityCode.isEmpty()) {
        ui->cityNameLabel->setText("城市名错误！");
        return;
    }

    // Set up and send the network request
    QNetworkRequest request(QUrl("http://t.weather.itboy.net/api/weather/city/" + cityCode));
    QNetworkReply *reply = manager->get(request);

    // Handle the network reply
    connect(reply, &QNetworkReply::readyRead, [=]() {
        QByteArray data = reply->readAll();
        QJsonParseError jsonError;
        QJsonDocument jsonDoc = QJsonDocument::fromJson(data, &jsonError);

        if (jsonError.error != QJsonParseError::NoError) {
            qWarning() << "JSON parsing error:" << jsonError.errorString();
            ui->cityNameLabel->setText("数据解析错误！");
            reply->deleteLater();
            return;
        }

        QJsonObject obj = jsonDoc.object();
        QJsonObject cityInfo = obj.value("cityInfo").toObject();
        QJsonObject dataRes = obj.value("data").toObject();
        QJsonArray forecast = dataRes.value("forecast").toArray();
        QJsonObject todayFore = forecast.first().toObject();
        QString weatherType = todayFore.value("type").toString();

        QString weatherInfo = QString("城市: %1\n今日天气: %2\n温度: %3\nPM2.5: %4\n%5")
                                  .arg(cityInfo.value("city").toString())
                                  .arg(todayFore.value("type").toString())
                                  .arg(dataRes.value("wendu").toString())
                                  .arg(dataRes.value("pm25").toInt())
                                  .arg(todayFore.value("notice").toString());

        ui->cityNameLabel->setText(cityInfo.value("city").toString());
        ui->weatherTypeLabel->setText(todayFore.value("type").toString());
        ui->temperatureLabel->setText(QString("%1℃").arg(dataRes.value("wendu").toString()));
        ui->pm25Label->setText(QString("PM2.5：%1").arg(dataRes.value("pm25").toInt()));
        ui->noticeLabel->setText(todayFore.value("notice").toString());

        //根据天气显示图标
        QString picFileName;
        QStringList stringList;
        stringList << "晴" << "小雨" << "中雨" << "大雨" << "多云" << "阴";
        switch(stringList.indexOf(weatherType)){
        case 0:
            picFileName = "100.svg";
            break;
        case 1:
            picFileName = "305.svg";
            break;
        case 2:
            picFileName = "306.svg";
            break;
        case 3:
            picFileName = "307.svg";
            break;
        case 4:
            picFileName = "103.svg";
            break;
        case 5:
            picFileName = "104.svg";
            break;
        }

        QString picPath = QDir::cleanPath(QString("../../res/icons/%1").arg(picFileName));
        qDebug() << picPath;
        QPixmap weatherPixmap(picPath);
        // QPixmap pixmapScaled = weatherPixmap.scaled(60, 60, Qt::KeepAspectRatio);

        ui->weatherPic->setPixmap(weatherPixmap);
        ui->weatherPic->setScaledContents(true);

        QString daysInfo;
        QList groupBoxList = ui->forecaseWidget->findChildren<QGroupBox *>();
        for(int i = 0; i < 7; i ++){
            QJsonObject dayObj = forecast[i].toObject();
            QString ymd = dayObj.value("ymd").toString();
            QString high = dayObj.value("high").toString();
            QString low = dayObj.value("low").toString();
            QString type = dayObj.value("type").toString();
            groupBoxList[i]->setTitle(ymd);
            QList labelList = groupBoxList[i]->findChildren<QLabel *>();
            labelList[0]->setText(high);
            labelList[1]->setText(low);
            labelList[2]->setText(type);
        }

        reply->deleteLater();
    });
}

// MainWindow constructor
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    getWeather();
}


// MainWindow destructor
MainWindow::~MainWindow()
{
    delete ui;
}

// Handle the weather query button click
void MainWindow::on_pushButton_clicked()
{
    if (inputCity.isEmpty()) {
        ui->cityNameLabel->setText("请输入城市！");
        return;
    }
    ui->cityNameLabel->setText("请稍候...");
    getWeather();
}

// Update inputCity when text changes in plainTextEdit
void MainWindow::on_plainTextEdit_textChanged()
{
    inputCity = ui->plainTextEdit->toPlainText();
}
