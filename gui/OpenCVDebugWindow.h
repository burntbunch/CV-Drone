#ifndef OPENCVDEBUGWINDOW_H
#define OPENCVDEBUGWINDOW_H

#include <QWidget>
#include <VideoService.h>
#include <ObjectDetector.h>

namespace Ui {
class OpenCVDebugWindow;
}

class OpenCVDebugWindow : public QWidget
{
    Q_OBJECT

public:
    explicit OpenCVDebugWindow(Drone::VideoService *service, ObjectDetection::ObjectDetector *detector, QWidget *parent = 0);
    ~OpenCVDebugWindow();

protected:
    void closeEvent(QCloseEvent *event) override;

private:
    Ui::OpenCVDebugWindow *ui;
    Drone::VideoService *service;
    ObjectDetection::ObjectDetector *detector;

signals:
    void closed();

private slots:
    void cvDebugMessageReceived(QString message);
};

#endif // OPENCVDEBUGWINDOW_H
