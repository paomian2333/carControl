#ifndef CHATLOGIN_H
#define CHATLOGIN_H
#include<QVector>
#include <QWidget>
#include <QMainWindow>
#include<QMessageBox>

namespace Ui {
class chatLogin;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

signals:
    void chatClose();

private slots:
    void on_pushButton_clicked();

private:
    Ui::chatLogin *ui;
    //初始状态为未打开登录后的界面
    QVector<bool> isShow;
};

#endif // CHATLOGIN_H
