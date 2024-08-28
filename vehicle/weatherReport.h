#ifndef WEATHERREPORT_H
#define WEATHERREPORT_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class weatherReport;
}
QT_END_NAMESPACE

class weatherReport : public QMainWindow
{
    Q_OBJECT

public:
    weatherReport(QWidget *parent = nullptr);
    ~weatherReport();

private slots:
    void getWeather();  // 获取天气信息
    void on_pushButton_clicked();
    void on_plainTextEdit_textChanged();

private:
    Ui::weatherReport *ui;
};
#endif // WEATHERREPORT_H
