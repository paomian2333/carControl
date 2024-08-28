#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include <QFileInfo>
#include <QLabel>
#include <QMainWindow>
#include <QPushButton>
#include <QScrollArea>
#include <QTreeView>
#include <opencv2/opencv.hpp>

class ImageViewer : public QMainWindow
{
    Q_OBJECT

public:
    ImageViewer(QWidget *parent = nullptr);
    ~ImageViewer();


private slots:
    void on_selectHomeDir_clicked();
    void on_selectImageFile_clicked();
    void on_readPrevImage_clicked();
    void on_readNextImage_clicked();
    void on_refreshImage_clicked();
    void on_rotateImage_clicked();
    void on_flipImage_clicked();
    void on_zoomInImage_clicked();
    void on_zoomOutImage_clicked();
    void on_extendImage_clicked();

private:
    QLabel *imgArea;
    QScrollArea *scrollArea;
    QLabel *fileIndexLabel;
    QLabel *filePathLabel;
    QLabel *fileSizeLabel;
    QLabel *fileModDateLabel;
        QLabel *imageSizeLabel;
    QLabel *imageScaleLabel;

    QFileInfo fileInfo;
    QStringList files;
    int current_index = 0;
    cv::Mat originImage;
    QSize imgSize;
    double scaleVar;
    void initUI();
    void initToolBar();
    void initStatusBar();

    void readFile(QString filePath);
    void readDir(QString dirPath);

    void loadFile();
    void loadImage(QString loadType);
    void computeScaleWithView();
    void displayImage(cv::Mat orgImage);
    cv::Mat resizeImage(cv::Mat orgImage);
    cv::Mat rotateImage(cv::Mat orgImage);
    cv::Mat flipImage(cv::Mat orgImage);
    void zoomInImage();
    void zoomOutImage();
    void extendImage();



    void keyPressEvent(QKeyEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
};
#endif // IMAGEVIEWER_H
