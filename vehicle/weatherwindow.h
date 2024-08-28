#ifndef weatherwindow_H
#define weatherwindow_H

#include <QMainWindow>
#include <QApplication>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QVariantMap>
#include <QVariantList>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QMessageBox>
#include <QNetworkReply>
#include <QPixmap>
#include <QFile>
#include <QDebug>
#include <QPainter>

namespace Ui {
class weatherwindow;
}

class weatherwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit weatherwindow(QWidget *parent = nullptr);
    QString getCityCode(const QString& cityName, const QString& filePath);
    void drivenotice(QString weatherConditon);
    void initLable();
    void changeBackground(QString weatherCondtion);
    ~weatherwindow();

private slots:
    void getWeatherInfo();
    void on_back_clicked();    //返回按钮
    void replyFinished(QNetworkReply *);    //对返回的数据进行json解析处理
    void GPSreplyFinished(QNetworkReply *);    //对返回的数据进行json解析处理
    void on_searchbutton_clicked();         //search
    void on_searchbutton_2_clicked();
    void onEnterPress() {
        on_searchbutton_clicked();
    }


signals:
    void GPSfinished();    //GPS定位完成

protected:

private:
    QString myAK = "mrnKOfPOXofTCwJWCauSbsHRpuAruiwI";
    Ui::weatherwindow *ui;
    QNetworkAccessManager *manager;         //请求
    QNetworkAccessManager *GPSmanager;        //请求
    QLabel *dw[6];                          //日期
    QLabel *tpe1[6];                        //天气类型
    QLabel *hg[6];                          //最高温
    QLabel *lw[6];                          //最低温
    //    QString currentCity = "长春";            //当前城市
    //    QString currentCityCode = "101060101";  //当前城市代码
    QString currentCity;                    //当前城市
    QString currentCityCode;                //当前城市代码
    bool currentLocation = true;            //是否是当前位置
    QPixmap *background;                    //背景图片
    QPalette *palette;                      //背景调色板
};

#endif // weatherwindow_H
