#include "mainwindow.h"
#include "./ui_mainwindow.h"

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

// Global variable
QString inputCity;

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

// MainWindow constructor
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 连接红色按钮的点击信号到颜色设置槽函数
    connect(ui->redradio, &QRadioButton::clicked, this, &MainWindow::on_set_color);
    // 连接蓝色按钮的点击信号到颜色设置槽函数
    connect(ui->blueradio, &QRadioButton::clicked, this, &MainWindow::on_set_color);
    // 连接绿色按钮的点击信号到颜色设置槽函数
    connect(ui->greenradio, &QRadioButton::clicked, this, &MainWindow::on_set_color);
}


// MainWindow destructor
MainWindow::~MainWindow()
{
    delete ui;
}

// Clear text in plainTextEdit
void MainWindow::on_clearTxt_clicked()
{
    ui->plainTextEdit->clear();
}

// Toggle bold text in plainTextEdit
void MainWindow::on_blodcheckBox_clicked(bool checked)
{
    QFont font = ui->plainTextEdit->font();
    font.setBold(checked);
    ui->plainTextEdit->setFont(font);
}

// Toggle underline in plainTextEdit
void MainWindow::on_linecheckbox_clicked(bool checked)
{
    QFont font = ui->plainTextEdit->font();
    font.setUnderline(checked);
    ui->plainTextEdit->setFont(font);
}

// Set text color based on selected radio button
void MainWindow::on_set_color()
{
    QString color;
    if (ui->redradio->isChecked()) {
        color = "red";
    } else if (ui->blueradio->isChecked()) {
        color = "blue";
    } else if (ui->greenradio->isChecked()) {
        color = "green";
    } else {
        color = "black";
    }

    // 设置文本框中输入的文本颜色
    ui->plainTextEdit->setStyleSheet("color: " + color);
}


// Handle the weather query button click
void MainWindow::on_pushButton_clicked()
{
    if (inputCity.isEmpty()) {
        ui->label->setText("请输入城市！");
        return;
    }
    ui->label->setText("请稍候...");

    // Create network manager
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

    // Load city code from JSON file
    QString path = QDir::cleanPath(QString("../../res/cityCode.json"));
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Cannot open file:" << file.errorString();
        return;
    }
    QByteArray fileData = file.readAll();
    file.close();
    QString cityCode = findCityCodeByInput(fileData, inputCity);

    if (cityCode.isEmpty()) {
        ui->label->setText("城市名错误！");
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
            ui->label->setText("数据解析错误！");
            reply->deleteLater();
            return;
        }

        QJsonObject obj = jsonDoc.object();
        QJsonObject cityInfo = obj.value("cityInfo").toObject();
        QJsonObject dataRes = obj.value("data").toObject();
        QJsonArray forecast = dataRes.value("forecast").toArray();
        QJsonObject todayFore = forecast.first().toObject();

        QString weatherInfo = QString("城市: %1\t天气: %2\t温度: %3\tPM2.5: %4")
                                  .arg(cityInfo.value("city").toString())
                                  .arg(todayFore.value("type").toString())
                                  .arg(dataRes.value("wendu").toString())
                                  .arg(dataRes.value("pm25").toInt());

        ui->label->setText(weatherInfo);
        reply->deleteLater();
    });
}

// Update inputCity when text changes in plainTextEdit
void MainWindow::on_plainTextEdit_textChanged()
{
    inputCity = ui->plainTextEdit->toPlainText();
}
