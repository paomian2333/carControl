#ifndef MAP_H
#define MAP_H

#include <QMainWindow>
#include <QPainter>
#include <QXmlStreamReader>
#include <QFile>
#include <unordered_map>
#include <QDebug>
#include <cmath>
#include <vector>
#include <QString>
#include <set>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>
#include <QNetworkAccessManager>
#include <QTimer>
#include <QCloseEvent>

const int INF = 10000000;
int ressssssssss(int x);

namespace Ui {
class Map;  // 将 MainWindow 替换为 Map
}

class Map : public QMainWindow  // 将 MainWindow 替换为 Map
{
    Q_OBJECT

public:
    explicit Map(QWidget *parent = 0);
    ~Map();

    void showComBox();
    void zoomInOut();
    void floyd(int n);
    void initDist();
    void getPath(int start, int end);
    void initMap();
    void click();

signals:
    void mapClose();

private slots:
    void on_btnClose_clicked();
    void onReduceBtnClicked();
    void onEnlargeBtnClicked();
    void onSearchBtnClicked();
    void InButton_clicked();
    void OutButton_clicked();
    void showShortPath();
    void shortBtnclicked();
    void onGetIp(QNetworkReply*);
    void onGetCurrentLoc(QNetworkReply*);
    void onSendMapRequest();
    void on_searchBtn_clicked();
    void onSearchLoc(QNetworkReply*);
    void on_enlargeBtn_clicked();
    void on_reduceBtn_clicked();

protected:
    void paintEvent(QPaintEvent *event) override;
    void closeEvent(QCloseEvent *event);    // 重写关闭窗口函数

private:
    Ui::Map *ui;  // 将 MainWindow 替换为 Map
    QNetworkAccessManager *m_ipManager;
    QNetworkAccessManager *m_locManager;
    QNetworkAccessManager *m_searchManager;
    QNetworkAccessManager *m_mapManager;
    QNetworkReply *m_mapReply = NULL;

    void init();
    QString ak = "yYSnHDIgAbSRlyktehYXmvlzA0s3eEhX";
    QString currentIp;
    double m_lng;
    double m_lat;
    int m_zoom = 12;
    QString m_city;
    QString m_mapFileName = "map.png";
    QTimer m_timer;
    QFile mapFile;

    bool isPress = false;
    bool isRelease = false;
    QPoint startPoint;
    QPoint endPoint;
    double mx;
    double my;

    void getIp();
    void getCurrentLoc();
    void sendMapRequest();
    bool eventFilter(QObject *watched, QEvent *event);
    QPixmap backgroundPixmap;
};

struct coordinates
{
    int id;
    double lon;
    double lat;
};

struct coordinatesStr
{
    QString id;
    QString lon;
    QString lat;
};

struct coordinatesInt
{
    QString id;
    int x;
    int y;
};

class resolve_xml
{
public:
    double degreesToRadians(double degrees);
    double radiansToDegrees(double radians);
    double calculateDistance(coordinates node1, coordinates node2);
    void saveNode(int id, coordinates node);
    void strChangeDouble(coordinatesStr node);
    void findCommonNode();
    void changeCoor(QString strId);
    int imortant();
    std::map<QString, coordinatesInt> doubleCoorMap;
    std::vector<coordinatesInt> doubleCoor;
    std::vector<coordinatesInt> doubleWay;
    double minLat;
    double maxLat;
    double minLon;
    double maxLon;
};

class Graph
{
public:
    int vertices = 54;
    std::vector<int> result;
    std::vector<std::vector<int>> distance;
    std::vector<std::vector<int>> next;

    void addEdge(int source, int destination, int weight)
    {
        distance[source][destination] = weight;
        next[source][destination] = destination;
    }

    void floydWarshall()
    {
        next.assign(54, std::vector<int>(54, -1));
        for (int k = 0; k < vertices; ++k)
        {
            for (int i = 0; i < vertices; ++i)
            {
                for (int j = 0; j < vertices; ++j)
                {
                    if (distance[i][k] != INF && distance[k][j] != INF && distance[i][k] + distance[k][j] < distance[i][j])
                    {
                        distance[i][j] = distance[i][k] + distance[k][j];
                        next[i][j] = next[i][k];
                    }
                }
            }
        }
    }

    void printShortestPath(int start, int end)
    {
        if (distance[start][end] == INF)
        {
            return;
        }

        result.push_back(start);

        while (start != end)
        {
            start = next[start][end];
            result.push_back(start);
        }
    }
};

#endif // MAP_H
