#include "map.h"
#include "ui_map.h"
#include <map>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>
#include <QMouseEvent>
#include <QHostInfo>
#include <QDebug>
#include <QNetworkInterface>
#include <QNetworkRequest>
#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QTimer>

// resolve_xml XML;
extern resolve_xml XML;
const int MAXN = 10000000;

Graph grap;
int n = 54;
//std::vector<std::vector<int>> prev(n, std::vector<int>(n, -1));
std::map<QString,coordinatesStr>mp;
std::map<QString,coordinates>doubleMap;
std::vector<QString>commonNode;
std::map<QString,QString>mapVillage;
std::map<QString,std::vector<QString>>mapWay;
std::map<QString,int>villageToInt;
std::map<int,QString>villageToString;
std::vector<QString>nodeVillage;

//ui->graphicsView->setScene(scene);

int dist[54][54];  // 保存点与点之间的距离
int prev[100][100];  // 保存路径上的前一个点
std::vector<int> path;  // 存储最短路径上的点
int Matrix[54][54] = {0};
resolve_xml Xml;

double resolve_xml::degreesToRadians(double degrees) {
    return degrees * M_PI / 180;
}
double resolve_xml::radiansToDegrees(double radians) {
    return radians * 180 / M_PI;
}
double resolve_xml::calculateDistance(coordinates node1, coordinates node2) { //经纬度坐标
    double dLat = degreesToRadians(node2.lat - node1.lat);   //Haversine公式
    double dLon = degreesToRadians(node2.lon - node1.lon);
    double a = std::sin(dLat / 2) * std::sin(dLat / 2) +
               std::cos(degreesToRadians(node1.lat)) * std::cos(degreesToRadians(node2.lat)) *
               std::sin(dLon / 2) * std::sin(dLon / 2);
    double c = 2 * std::atan2(std::sqrt(a), std::sqrt(1 - a));
    double distance = 6378137 * c;
    return distance;
}

void resolve_xml::strChangeDouble(coordinatesStr node)
{
    coordinates coor;
    coor.id = node.id.toInt();
    coor.lat = node.lat.toDouble();
    coor.lon = node.lon.toDouble();
    doubleMap[node.id] = coor;
}

void resolve_xml::findCommonNode() //查找公共交点
{
    QFile file(":/mapres/map/map (3)(1).osm");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
            qDebug() << "无法打开XML文件.";
            //exit(0);
    }
    QXmlStreamReader xml(&file);

    std::set<QString> wayNodes;

    int wayCount = 0;
    bool flag = false;

    while (!xml.atEnd() && !xml.hasError()) {
        QXmlStreamReader::TokenType token = xml.readNext();
        if (token == QXmlStreamReader::StartElement) {
            if (xml.name() == QLatin1String("way")) {
                flag = true;
            }
            else if (xml.name() == QLatin1String("nd") && flag == true) {
                QString ndRef = xml.attributes().value("ref").toString();
                if (wayNodes.find(ndRef) != wayNodes.end()) {
                    commonNode.push_back(ndRef);
                }
                else {
                    wayNodes.insert(ndRef);
                }
            }
            else if(xml.name() == QLatin1String("relation")){
                flag = false;
            }
            else if(xml.name() == QLatin1String("member")){
                flag = false;
            }
        }
    }
    file.close();
}

void resolve_xml::changeCoor(QString strId)
{
    coordinates coo = doubleMap[strId];
    coordinatesInt cooint ;
    int width = (maxLon - minLon) * 10000;
    int length = (maxLat - minLat) * 10000;
    int x = (maxLat - coo.lat ) * 10000 ;
    int y = (coo.lon - minLon) * 10000 ;
    cooint.id = strId;
    cooint.x = y;
    cooint.y = x;
    Xml.doubleCoor.push_back(cooint);
    Xml.doubleCoorMap[strId] = cooint;
}


int resolve_xml::  imortant()
{

    std::vector<QString>strNode;
    std::vector<QString>strWay;
    coordinatesStr coorStr;   //QString类型经纬度的结构体
    QString wayId;      //way的Id
    QString tagKey;
    QString tagValue;
    QString nodeId;     //node的ID
    QString nodeLon;    //node的经度
    QString nodeLat;    //node的纬度
    QFile fileName(":/mapres/map/map (3)(1).osm");
    if (!fileName.open(QIODevice::ReadOnly | QIODevice::Text))
    {
            qDebug() << "无法打开XML文件.";
            return 1;
    }
    QXmlStreamReader xml(&fileName);
        while (!xml.atEnd() && !xml.hasError()) {
            QXmlStreamReader::TokenType token = xml.readNext();

            if (token == QXmlStreamReader::StartElement) {
                if(xml.name() == QLatin1String("node")){
                    nodeId = xml.attributes().value("id").toString();
                    nodeLon = xml.attributes().value("lon").toString();
                    nodeLat = xml.attributes().value("lat").toString();
                    coorStr.id = nodeId;
                    coorStr.lat = nodeLat;
                    coorStr.lon = nodeLon;
                    mp[nodeId] = coorStr;
                    strNode.push_back(nodeId);
                }
                else if (xml.name() == QLatin1String("way")) {
                    // 提取way元素的id属性值
                    strWay.clear();
                    wayId = xml.attributes().value("id").toString();
                    //qDebug() << "Way ID:" << wayId;
                } else if (xml.name() == QLatin1String("nd")) {
                    // 提取nd元素的ref属性值
                    QString ndRef = xml.attributes().value("ref").toString();
                    strWay.push_back(ndRef);
                    mapWay[wayId] = strWay;
                    //qDebug() << "ND Ref:" << ndRef;
                } else if (xml.name() == QLatin1String("tag")) {
                    // 提取tag元素的k和v属性值
                    QString str1 = tagKey;
                    QString str2 = tagValue;
                    tagKey = xml.attributes().value("k").toString();
                    tagValue = xml.attributes().value("v").toString();
                    if(tagValue == "stop_position")
                    {
                        nodeVillage.push_back(str2);
                        mapVillage[str2] = nodeId;
                    }
                    //qDebug() << "Tag Key:" << tagKey << ", Value:" << tagValue;
                }
                else if(xml.name() == QLatin1String("bounds"))
                {
                    //提取数据中的最大最小经纬度
                    Xml.minLat = xml.attributes().value("minlat").toString().toDouble();
                    Xml.minLon = xml.attributes().value("minlon").toString().toDouble();
                    Xml.maxLat = xml.attributes().value("maxlat").toString().toDouble();
                    Xml.maxLon = xml.attributes().value("maxlon").toString().toDouble();
                }
            }
        }
       if (xml.hasError())
       {
           qDebug() << "XML解析错误: " << xml.errorString();
           return 1;
       }
      for(auto it = mp.begin();it != mp.end();it++) //将QString的经纬度转化成double类型的经纬度
      {
          QString Id = it->first;
          coordinatesStr jw = it->second;
          Xml.strChangeDouble(jw);
          Xml.changeCoor(Id);
          //qDebug()<<Id;
          //qDebug()<<jw.lat<<" "<<jw.lon;
      }
      for(auto it = mapWay.begin();it != mapWay.end();it++)
      {
          std::vector<QString> Strway = it->second;
          for(int i = 0;i < Strway.size();i++)
          {
                QString Qstr = Strway[i];
                double x = doubleMap[Qstr].lat;
                double y = doubleMap[Qstr].lon;
                minLat = std::min(minLat,x);
                minLon = std::min(minLon,y);
                maxLat = std::max(maxLat,x);
                maxLon = std::max(maxLon,y);
          }
      }
     // qDebug()<<"xxxx"<<minLat<<minLon<<maxLat<<maxLon; //输出最大最小经纬度
      for(auto it = mapWay.begin();it != mapWay.end();it++) //保存所有way的点
      {
          QString way = it->first;
          std::vector<QString> Strway = it->second;
          for(int i = 0;i < Strway.size();i++)
          {
                QString Qstr = Strway[i];
                //Xml.changeCoor(Qstr);
          }
      }
      for(auto it = mapWay.begin();it != mapWay.end();it++) //根据经纬度计算点与点之间距离，连接成路
      {
          QString way = it->first;
          //qDebug()<<way;
          std::vector<QString> Strway = it->second;
          //qDebug()<<"way nodeNumber:"<<Strway.size();
          int distanceWay = 0;
          for(int i = 1;i < Strway.size();i++)
          {
                QString Qstr1 = Strway[i-1];
                QString Qstr2 = Strway[i];
                coordinates node1 = doubleMap[Qstr1];
                coordinates node2 = doubleMap[Qstr2];
                distanceWay += (int)Xml.calculateDistance(node1,node2);
          }
          //qDebug()<<"way distance:"<<distanceWay;
      }
      for(auto it = mapVillage.begin();it != mapVillage.end();it++)
      {
          //qDebug()<<"village: "<<it->fiMusicWindowrst<<"village nodeId: "<<it->second;
      }
      for(int i = 0;i < nodeVillage.size();i++)
      {
          QString sst = nodeVillage[i];
          villageToInt[sst] = i;
          villageToString[i] = sst;
          //qDebug()<<sst<<i;
      }
      Xml.findCommonNode();
      for(int i = 0;i < commonNode.size();i++)
      {
          //qDebug()<<"commonNode"<<commonNode[i];
      }
      //qDebug()<<"commonNode size"<<commonNode.size()<<"way size:"<<mapWay.size()<<"village size"<<mapVillage.size();
      //qDebug()<<"---"<<Xml.doubleCoor.size();
      fileName.close();
      return 0;
}


Map::Map(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Map),
    m_ipManager(new QNetworkAccessManager(this)),
    m_locManager(new QNetworkAccessManager(this)),
    m_searchManager(new QNetworkAccessManager(this)),
    m_mapManager(new QNetworkAccessManager(this))
{
    ui->setupUi(this);
    QGraphicsScene *scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    QString qss;
    QFile qssFile(":/mapres/map/qss/myQss.qss");
    qssFile.open(QFile::ReadOnly);
    if(qssFile.isOpen())
    {
        qss = QLatin1String(qssFile.readAll());
        this->setStyleSheet(qss);
        qssFile.close();
    }
    XML.imortant();
    // 设置视图背景为透明
    ui->graphicsView->setStyleSheet("background: transparent;");
    // 设置 QLabel 的背景图片
    QPixmap backgroundPixmap(":/mapres/map/v2.png"); // 使用你自己的图片路径
    ui->piclabel->setPixmap(backgroundPixmap);
    ui->piclabel->setScaledContents(true);
    double initialScaleFactor = 2.30; // 例如设置初始缩放为1.5倍，可以根据需要调整
    ui->graphicsView->scale(initialScaleFactor, initialScaleFactor);
    // 注册事件过滤器
    installEventFilter(this);

    init(); // 初始化设置

    // 设置初始经纬度，例如显示北京的地图
    m_lng = 116.169754; // 北京的经度
    m_lat = 39.735139;  // 北京的纬度

    // 请求并显示初始经纬度的地图
    sendMapRequest();
    // 连接按钮点击信号到槽函数
    connect(ui->reduceBtn, &QPushButton::clicked, this, &Map::onReduceBtnClicked);
    connect(ui->enlargeBtn, &QPushButton::clicked, this, &Map::onEnlargeBtnClicked);
    connect(ui->searchBtn, &QPushButton::clicked, this, &Map::onSearchBtnClicked);
}
void Map::on_btnClose_clicked()
{
    QMainWindow *parent=static_cast<QMainWindow *>(this->parent());
    this->hide();
    parent->show();
}
void Map::onReduceBtnClicked() {
    ui->graphicsView->setVisible(false);
    ui->piclabel->setScaledContents(false);
    ui->piclabel->hide();
    // if (ui->graphicsView->scene()) {
    //     ui->graphicsView->scene()->clear();  // 清除场景中的所有项
    //     delete ui->graphicsView->scene();    // 删除场景对象
    //     ui->graphicsView->setScene(nullptr); // 解除 scene 的引用
    // }

}

void Map::onEnlargeBtnClicked() {
    ui->graphicsView->setVisible(false);
    ui->piclabel->setScaledContents(false);
    ui->piclabel->hide();
    // if (ui->graphicsView->scene()) {
    //     ui->graphicsView->scene()->clear();  // 清除场景中的所有项
    //     delete ui->graphicsView->scene();    // 删除场景对象
    //     ui->graphicsView->setScene(nullptr); // 解除 scene 的引用
    // }

}

void Map::onSearchBtnClicked() {
    ui->graphicsView->setVisible(false);
    ui->piclabel->setScaledContents(false);
ui->piclabel->hide();
    // if (ui->graphicsView->scene()) {
    //     ui->graphicsView->scene()->clear();  // 清除场景中的所有项
    //     delete ui->graphicsView->scene();    // 删除场景对象
    //     ui->graphicsView->setScene(nullptr); // 解除 scene 的引用
    // }
}
// Map::~Map()
// {
//     delete ui;
// }

void Map::init(){
    //网络管理对象
    m_ipManager =new QNetworkAccessManager(this);
    //请求响应事件
    connect(m_ipManager,SIGNAL(finished(QNetworkReply*)),this,SLOT(onGetIp(QNetworkReply*)));

    //网络管理对象
    m_locManager =new QNetworkAccessManager(this);
    //请求响应事件
    connect(m_locManager,SIGNAL(finished(QNetworkReply*)),this,SLOT(onGetCurrentLoc(QNetworkReply*)));

    m_searchManager=new QNetworkAccessManager(this);
    connect(m_searchManager,SIGNAL(finished(QNetworkReply*)),this,SLOT(onSearchLoc(QNetworkReply*)));

    //网络管理对象
    m_mapManager =new QNetworkAccessManager(this);


}

//获取当前主机ip   发送请求
void Map::getIp(){

    //请求http://httpbin.org/ip 获取外网ip

    //声明url 请求地址
    QUrl url("http://httpbin.org/ip");
    //声明请求对象
    QNetworkRequest request(url);
        //通过网络管理对象 发送get请求
    m_ipManager->get(request);

}

//处理服务器响应内容
void Map::onGetIp(QNetworkReply *reply){
    //reply->readAll()  服务响响应的正文内容
    //qDebug() << "Current IP:" << reply->readAll();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(reply->readAll());
    QJsonObject jsonObj = jsonDoc.object();
    currentIp=jsonObj.value("origin").toString();
    qDebug() << "Current IP:" << currentIp<<Qt::endl;

    //调用获取当前经纬度的函数
    getCurrentLoc();
}

//根据ip获取经纬度  发送请求
void Map::getCurrentLoc(){
    //url
    QString host= "http://api.map.baidu.com/location/ip";
    QString query_str=QString("ip=%1&coor=bd09ll&ak=%2")
                            .arg(currentIp).arg(ak);
    //请求地址
    QUrl url(host+"?"+query_str);
    //请求对象
    //声明请求对象
    QNetworkRequest request(url);
        //发送请求
    m_locManager->get(request);
}

//根据ip获取经纬度  处理服务器响应内容
void Map::onGetCurrentLoc(QNetworkReply *reply){
    //    qDebug() << reply->readAll() <<Qt::endl;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(reply->readAll());
    QJsonObject jsonObj = jsonDoc.object();
    QJsonObject jsonContent=jsonObj.value("content").toObject();
    QJsonObject jsonPonit=jsonContent.value("point").toObject();
    m_lng=jsonPonit.value("x").toString().toDouble();
    m_lat=jsonPonit.value("y").toString().toDouble();
    m_city=jsonContent.value("address_detail").toObject().value("city").toString();
    qDebug() << jsonPonit.value("x").toString() <<Qt::endl;
    qDebug() << jsonPonit.value("y").toString() <<Qt::endl;
    sendMapRequest();
}


// 发送请求  获取地图图片
void  Map::sendMapRequest(){
    //how

    //断调前一次请求
    if(m_mapReply!=NULL){
        m_mapReply->disconnect();
        //断掉事件连接
        disconnect(m_mapReply,&QIODevice::readyRead,this,&Map::onSendMapRequest);
    }

    //开始新的请求
    //url
    //请求地址
    QString host= "http://api.map.baidu.com/staticimage/v2";
    //请求参数
    QString query_str=QString("ak=%1&width=512&height=400&center=%2,%3&zoom=%4")
                            .arg(ak).arg(m_lng).arg(m_lat).arg(m_zoom);
    QUrl url(host+"?"+query_str);

    qDebug()<<host+"?"+query_str<<Qt::endl;

    QNetworkRequest request(url);
    //此处与前面的请求不同，等待服务器响应，
    m_mapReply= m_mapManager->get(request);
    //连接事件，处理服务器返回的 文件流
    connect(m_mapReply,&QIODevice::readyRead,this,&Map::onSendMapRequest);
}



//处理服务器返回地图图片
void  Map::onSendMapRequest(){

    //删除原有的地图图片 使用系统命令删除
    system("rm map.png");
    //文件对象
    mapFile.setFileName(m_mapFileName);

    //读取文件流，保存文件到本地,
    //open 没有则新建文件，打开
    mapFile.open(QIODevice::WriteOnly| QIODevice::Truncate);
    m_timer.start(2);
    connect(&m_timer,&QTimer::timeout,[=](){
        m_timer.stop();
        mapFile.write(m_mapReply->readAll());
        mapFile.close();

        QPixmap pixmap;
        if(pixmap.load(m_mapFileName)){
            ui->mapWidget->setStyleSheet("QWidget{border-image:url(./map.png);}");
        }

    });




}

Map::~Map()
{
    delete ui;
}

//搜索地址  发送请求
void Map::on_searchBtn_clicked()
{
    //1、取文本框的值
    qDebug()<<ui->edit_search->text()<<Qt::endl;

    //2、url
    QString host="http://api.map.baidu.com/place/v2/search";


    QString query_str=QString("query=%1&location=%2,%3&output=json&ak=%4&radius=20000")
                            .arg(ui->edit_search->text()).arg(m_lat).arg(m_lng).arg(ak);

    QList<QString> list;
    list.append("湖北");
    list.append("湖南");
    list.append("北京");
    if(list.contains(ui->edit_search->text())){
        query_str.append("&region=%1").arg(ui->edit_search->text());
    }else {
        query_str.append("&region=%1").arg(m_city);
    }

    QUrl url(host+"?"+query_str);
    //3、request
    QNetworkRequest request(url);
    //4、发送请求
    m_searchManager->get(request);

}
//搜索地址  处理响应内容
void Map::onSearchLoc(QNetworkReply *reply){
    //    qDebug()<<reply->readAll()<<Qt::endl;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(reply->readAll());
    reply->deleteLater();
    QJsonObject jsonObj = jsonDoc.object();
    QJsonArray addrArray= jsonObj.value("results").toArray();
    QJsonObject addrJson=addrArray.at(0).toObject();
    QJsonObject xyJson=addrJson.value("location").toObject();
    m_lng=xyJson.value("lng").toDouble();
    m_lat=xyJson.value("lat").toDouble();
    m_city=addrJson.value("city").toString();

    qDebug()<<m_lng<<Qt::endl;
    qDebug()<<m_lat<<Qt::endl;

    m_zoom=17;
    //调取地图图片的函数
    sendMapRequest();
}

//放大按钮，点击后改变m_zoom [3-18]
void Map::on_enlargeBtn_clicked()
{
    //判断m_zoom是否小于18，
    if(m_zoom<19){
        m_zoom+=1;
        //调用函数重新获取地图图片
        sendMapRequest();
    }
}

//缩小按钮，点击后改变m_zoom [3-18]
void Map::on_reduceBtn_clicked()
{
    if(m_zoom>3){
        m_zoom-=1;
        sendMapRequest();
    }
}



//过滤事件
bool  Map::eventFilter(QObject *watched, QEvent *event){

    //    qDebug()<<event->type()<<Qt::endl;
    if(event->type()==QEvent::MouseButtonPress){
        qDebug()<<event->type()<< cursor().pos().x()<<":"<<cursor().pos().y()<<Qt::endl;
        isPress=true;
        startPoint.setX(cursor().pos().x());
        startPoint.setY(cursor().pos().y());
    }

    if(event->type()==QEvent::MouseButtonRelease){
        qDebug()<<event->type()<< cursor().pos().x()<<":"<<cursor().pos().y()<<Qt::endl;
        isRelease=true;
        endPoint.setX(cursor().pos().x());
        endPoint.setY(cursor().pos().y());
    }

    if(isPress&&isRelease){
        isPress=false;
        isRelease=false;
        //计算距离差
        mx=startPoint.x()-endPoint.x();
        my=startPoint.y()-endPoint.y();

        if(qAbs(mx)>5||qAbs(my)>5){
            m_lng+=mx*0.000002*(19-m_zoom)*(19-m_zoom);
            m_lat-=my*0.000002*(19-m_zoom)*(19-m_zoom);
            sendMapRequest();
        }
    }

    return QWidget::eventFilter(watched,event);
}



void Map::showComBox()
{
    for(auto it = mapVillage.begin();it != mapVillage.end();it++)
    {
        QString stt = it->first;
        ui->startBox->addItem(stt);
    }
    for(auto it = mapVillage.begin();it != mapVillage.end();it++)
    {
        QString stt = it->first;
        ui->endBox->addItem(stt);
    }
    qDebug()<<mapVillage.size();
}

void Map::zoomInOut()
{
    // 连接放大按钮
    connect(ui->InButton, &QPushButton::clicked, this, &Map::InButton_clicked);

    // 连接缩小按钮
    connect(ui->outButton, &QPushButton::clicked, this, &Map::OutButton_clicked);

    //连接最短路径按钮
    connect(ui->shortBtn, &QPushButton::clicked, this, &Map::shortBtnclicked);
}

void Map::InButton_clicked()
{
    qDebug() << "InButton was clicked or triggered!";
    double scaleFactor = 1.15;
    ui->graphicsView->scale(scaleFactor, scaleFactor);
}

void Map::OutButton_clicked()
{
    double scaleFactor = 1.15;
    ui->graphicsView->scale(1.0 / scaleFactor, 1.0 / scaleFactor);
}

void Map::showShortPath()
{
    QGraphicsScene *scene = ui->graphicsView->scene();
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    std::vector<QPointF> shortPath;
    QPainterPath pathVillage;

    // 构建路径点
    for(int i = 0; i < path.size(); i++)
    {
        int intId = path[i];
        QString StrID = villageToString[intId];
        coordinatesInt coorvillage = Xml.doubleCoorMap[mapVillage[StrID]];
        QPointF points;
        points.setX(coorvillage.x);
        points.setY(coorvillage.y);
        shortPath.push_back(points);
    }

    qDebug() << shortPath.size();
    int distance = 0;

    // 计算路径总距离
    for(int i = 1; i < path.size(); i++)
    {
        int intId1 = path[i-1];
        int intId2 = path[i];
        QString StrID1 = villageToString[intId1];
        QString StrID2 = villageToString[intId2];
        coordinates node1 = doubleMap[mapVillage[StrID1]];
        coordinates node2 = doubleMap[mapVillage[StrID2]];
        distance = Xml.calculateDistance(node1, node2);

        // totalDistance += distance;  // 累加总距离
    }

    // 如果总距离为零，则提示错误
    if (distance == 0) {
        ui->showDist->setText("Error: Total path distance is zero.");
        return;
    }

    QString setdist = QString::number(distance);
    setdist += " meters";
    ui->showDist->setText(setdist);

    if(!scene) {
        scene = new QGraphicsScene(this);
        ui->graphicsView->setScene(scene);
    }

    // 绘制路径
    for(int i = 1; i < shortPath.size(); i++)
    {
        QPen pen(Qt::red);
        pen.setWidth(1);
        QPointF point1 = shortPath[i-1];
        QPointF point2 = shortPath[i];
        scene->addLine(point1.x(), point1.y(), point2.x(), point2.y(), pen);
    }
}


void Map::floyd(int n)
{
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    prev[i][j] = k;
                }
            }
        }
    }
}

void Map::initDist()
{
    n = 23;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) dist[i][j] = 0;
            else  if ( j % 2 == 0)
            {
                QString s1 = villageToString[i];
                QString s2 = villageToString[j];
                coordinates node1 = doubleMap[mapVillage[s1]];
                coordinates node2 = doubleMap[mapVillage[s2]];
                int distancesss = Xml.calculateDistance(node1,node2);
                qDebug()<<"s="<<distancesss;
                dist[i][j] = distancesss;
            }
            /*else if (Matrix[i][j] == 0)
            {
                dist[i][j] = INT_MAX;
            }*/
            prev[i][j] = i;
        }
    }
}

void Map::getPath(int start, int end)
{
    if(start != end) getPath(start, prev[start][end]);
        path.push_back(end);
}

void Map::initMap()
{
    Matrix[0][32] = Matrix[32][0] = 1;
    Matrix[0][53] = Matrix[53][0] = 1;
    Matrix[0][48] = Matrix[48][0] = 1;
    Matrix[0][47] = Matrix[47][0] = 1;
    Matrix[0][49] = Matrix[49][0] = 1;
    Matrix[0][50] = Matrix[50][0] = 1;
    Matrix[0][51] = Matrix[51][0] = 1;
    Matrix[0][36] = Matrix[36][0] = 1;
    Matrix[0][35] = Matrix[35][0] = 1;
    Matrix[0][34] = Matrix[34][0] = 1;
    Matrix[0][37] = Matrix[37][0] = 1;
    Matrix[0][40] = Matrix[40][0] = 1;
    Matrix[0][50] = Matrix[50][0] = 1;
    Matrix[2][33] = Matrix[33][2] = 1;
    Matrix[2][3] = Matrix[3][2] = 1;
    Matrix[2][4] = Matrix[4][2] = 1;
    Matrix[4][3] = Matrix[3][4] = 1;
    Matrix[4][33] = Matrix[33][4] = 1;
    Matrix[5][8] = Matrix[8][5] = 1;
    Matrix[5][9] = Matrix[9][5] = 1;
    Matrix[5][10] = Matrix[10][5] = 1;
    Matrix[7][6] = Matrix[6][7] = 1;
    Matrix[7][4] = Matrix[4][7] = 1;
    Matrix[11][43] = Matrix[43][11] = 1;
    Matrix[11][45] = Matrix[45][11] = 1;
    Matrix[11][42] = Matrix[42][11] = 1;
    Matrix[12][13] = Matrix[13][12] = 1;
    Matrix[12][14] = Matrix[14][12] = 1;
    Matrix[12][15] = Matrix[15][12] = 1;
    Matrix[16][20] = Matrix[20][16] = 1;
    Matrix[17][19] = Matrix[19][17] = 1;
    Matrix[17][18] = Matrix[18][17] = 1;
    Matrix[20][17] = Matrix[17][20] = 1;
    Matrix[20][18] = Matrix[18][20] = 1;
    Matrix[20][19] = Matrix[19][20] = 1;
    Matrix[21][22] = Matrix[22][21] = 1;
    Matrix[21][23] = Matrix[23][21] = 1;
    Matrix[21][26] = Matrix[26][21] = 1;
    Matrix[26][27] = Matrix[27][26] = 1;
    Matrix[26][24] = Matrix[24][26] = 1;
    Matrix[24][25] = Matrix[25][24] = 1;
    Matrix[25][31] = Matrix[31][25] = 1;
    Matrix[28][29] = Matrix[29][28] = 1;
    Matrix[28][30] = Matrix[30][28] = 1;
    Matrix[34][36] = Matrix[36][34] = 1;
    Matrix[35][36] = Matrix[36][35] = 1;
    Matrix[40][34] = Matrix[34][40] = 1;
    Matrix[40][37] = Matrix[37][40] = 1;
    Matrix[41][37] = Matrix[37][41] = 1;
    Matrix[41][34] = Matrix[34][41] = 1;

    Matrix[44][39] = Matrix[39][44] = 1;

    Matrix[39][38] = Matrix[38][39] = 1;
}

// void Map::click()
// {
//     test newobj(this);
//     newobj.useMapUI();

// }

void Map::paintEvent(QPaintEvent *event)
{
    QMainWindow::paintEvent(event);

    QGraphicsScene *scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing); //抗锯齿
    std::vector<std::vector<QPointF>>roads;
    for(auto it = mapWay.begin();it != mapWay.end();it++)
    {
        std::vector<QString> vectorStr = it->second;
        std::vector<QPointF>roadWay;
        for(int i = 0;i < vectorStr.size();i++)
        {
            QString wayStr = vectorStr[i];
            coordinatesInt coorWay;
            coorWay = Xml.doubleCoorMap[wayStr];
            QPoint pointWay;
            pointWay.setX(coorWay.x);
            pointWay.setY(coorWay.y);
            roadWay.push_back(pointWay);
        }
        roads.push_back(roadWay);
        roadWay.clear();
    }

    for (const std::vector<QPointF> &road : roads) {
        QPainterPath pathsss;
        pathsss.moveTo(road[0]);
        for (int i = 1; i < road.size(); ++i)
        {
            pathsss.lineTo(road[i]);
        }
        QGraphicsPathItem *pathItem = new QGraphicsPathItem(pathsss);
        scene->addItem(pathItem);

        // 可选：设置道路的样式
        QPen roadPen(Qt::blue, 1);  // 示例：蓝色，线宽为2
        pathItem->setPen(roadPen);
    }

    // 示例点位和名字
    int len = nodeVillage.size();
    QList<QPointF> points;
    for(int i = 0;i < len;i++)
    {
        QString villageNode = mapVillage[nodeVillage[i]];
        QPoint ppp;
        coordinatesInt coo = Xml.doubleCoorMap[villageNode];
        ppp.setX(coo.x);
        ppp.setY(coo.y);
        points.push_back(ppp);
        //qDebug()<<points.size();
    }

    for(int i = 0; i < nodeVillage.size(); ++i)
    {
        // 为每个点位创建一个小的椭圆
        QGraphicsEllipseItem *ellipse = scene->addEllipse(points[i].x() - 5, points[i].y() - 5, 10, 10, QPen(Qt::black), QBrush(Qt::red));

        // 创建一个文本项以显示名字
        QGraphicsTextItem *text = scene->addText(nodeVillage[i]);
        text->setPos(points[i].x() + 10, points[i].y() - text->boundingRect().height() / 2);
    }
}
class CustomGraphicsView : public QGraphicsView //放大缩小只能点击，不能使用滚轮
{
    Q_OBJECT
public:
    explicit CustomGraphicsView(QWidget* parent = nullptr)
        : QGraphicsView(parent) {}

protected:
    void wheelEvent(QWheelEvent* event) override
    {

    }
};


void Map::shortBtnclicked()
{

    initDist();
    floyd(23);
    QString textBox1 = ui->startBox->currentText();
    QString textBox2 = ui->endBox->currentText();
    int idx1 = villageToInt[textBox1];
    int idx2 = villageToInt[textBox2];
    //grap.printShortestPath(idx1,idx2);
    getPath(idx1,idx2);
    showShortPath();
    //path.clear();
}

void Map::closeEvent(QCloseEvent *event){
    emit mapClose();
}
