#ifndef VIDEOSETTINGSWINDOW_H
#define VIDEOSETTINGSWINDOW_H

#include <QMainWindow>
#include <ObjectDetector.h>

namespace Ui {
class VideoSettingsWindow;
}

class VideoSettingsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit VideoSettingsWindow(ObjectDetection::ObjectDetector *detector, QWidget *parent = 0);
    ~VideoSettingsWindow();
    void show();

protected:
    void closeEvent(QCloseEvent *event) override;

private:
    Ui::VideoSettingsWindow *ui;
    ObjectDetection::ObjectDetector *detector;
    Drone::ConfigFile *configFile;
    void loadFromConfig();
    bool confirmed;

signals:
    void closed();

private slots:
    void reset();
    void cancel();
    void confirm();
};

#endif // VIDEOSETTINGSWINDOW_H
