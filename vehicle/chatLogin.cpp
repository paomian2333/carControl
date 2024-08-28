#include "chatLogin.h"
#include "ui_chatLogin.h"
#include<QToolButton>
#include<QPixmap>
#include "widget.h"
Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::chatLogin)
{
    QVector<QToolButton*> vector;
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/images/qq.png"));
    this->setWindowTitle("聊天");
    //用户名列表
    QStringList list;
    list<<"性感小飞侠"<<"闷骚男"<<"韩国欧巴"<<"神经病一枚"<<"笨笨猪"<<"狗头"<<"蛇精病"<<"赵四"<<"本山兄弟";
    //图片资源列表
    QStringList listIcon;
    listIcon<<"spqy"<<"ymrl"<<"qq"<<"Cherry"<<"dr"<<"jj"<<"lswh"<<"qmnn"<<"spqy";

    for(int i=0;i<9;i++){
       QToolButton *btn=new QToolButton(this);
       btn->setIcon(QPixmap(QString(":/images/%1.png").arg(listIcon[i])));
       btn->setIconSize(QPixmap(QString(":/images/%1.png").arg(listIcon[i])).size());
      //透明
       btn->setAutoRaise(true);
        //设置网名
       btn->setText(QString("%1").arg(list[i]));
       //设置显示格式
       btn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
       ui->vlayout->addWidget(btn);
       vector.push_back(btn);
       isShow.push_back(false);
    }
    for(int i=0;i<9;i++){
        connect(vector[i],&QToolButton::clicked,[=](){
            if(true==isShow[i]){
                QMessageBox::warning(this,"警告","改聊天框已被打开");
                return;
            }
            isShow[i]=true;
            Widget *widget=new Widget(0,vector[i]->text());
            widget->setWindowIcon(vector[i]->icon());
            widget->setWindowTitle(vector[i]->text());
            widget->show();
            //关闭聊天框时将对于的isShow跟改为false
            connect(widget,&Widget::closeWidget,[=](){
                isShow[i]=false;
            });
         });
    }
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{
    QMainWindow *parent=static_cast<QMainWindow *>(this->parent());
    this->hide();
    parent->show();
}

