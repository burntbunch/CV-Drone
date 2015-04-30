#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <vector>
#include <QMainWindow>
#include <VideoSettingsWindow.h>
#include <CommandDebugWindow.h>
#include <NavdataDebugWindow.h>
#include <OpenCVDebugWindow.h>
#include <ControlWindow.h>
#include <CVDrone.h>
#include <VideoService.h>
#include <CommandService.h>
#include <NavdataService.h>
#include <ObjectDetector.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(Drone::CVDrone *cvDrone, ObjectDetection::ObjectDetector *objectDetector, QWidget *parent = 0);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent *event) override;

private:
    Ui::MainWindow *ui;
    VideoSettingsWindow *videoSettings;
    CommandDebugWindow *commandDebug;
    NavdataDebugWindow *navdataDebug;
    OpenCVDebugWindow *openCVDebug;
    ControlWindow *controlWindow;
    ObjectDetection::ObjectDetector *objectDetector;
    Drone::CVDrone *cvDrone;
    Drone::CommandService *commandService;
    Drone::NavdataService *navdataService;
    Drone::VideoService *videoService;
    cv::Mat img;

signals:
    void closed();

public slots:
    void toggleControlWindow(bool toggle);
    void toggleVideoSettings(bool toggle);
    void toggleCommandDebug(bool toggle);
    void toggleNavdataDebug(bool toggle);
    void toggleOpenCVDebug(bool toggle);
    void toggleTakeOffLand(bool toggle);
    void detectToggled(bool toggle);
    void controlWindowClosed();
    void commandDebugWindowClosed();
    void navdataDebugWindowClosed();
    void openCVDebugWindowClosed();
    void videoSettingsWindowClosed();
    void showFrame(QPixmap pixmap);
};

#endif // MAINWINDOW_H
