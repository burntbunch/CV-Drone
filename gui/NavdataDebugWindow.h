#ifndef NAVDATADEBUGWINDOW_H
#define NAVDATADEBUGWINDOW_H

#include <QWidget>
#include <NavdataService.h>

using namespace Drone::Navdata;

namespace Ui {
class NavdataDebugWindow;
}

class NavdataDebugWindow : public QWidget
{
    Q_OBJECT

public:
    explicit NavdataDebugWindow(Drone::NavdataService *service, QWidget *parent = 0);
    ~NavdataDebugWindow();

protected:
    void closeEvent(QCloseEvent *event) override;

private:
    Ui::NavdataDebugWindow *ui;
    Drone::NavdataService *service;

signals:
    void closed();

private slots:
    void  adcDataFrameOptionReceived(AdcDataFrameOption option);
    void  altitudeOptionReceived(AltitudeOption option);
    void  cksOptionReceived(CksOption option);
    void  demoOptionReceived(DemoOption option);
    void  eulerAnglesOptionReceived(EulerAnglesOption option);
    void  gamesOptionReceived(GamesOption option);
    void  gyrosOffsetsOptionReceived(GyrosOffsetsOption option);
    void  hdvideoStreamOptionReceived(HdvideoStreamOption option);
    void  kalmanPressureOptionReceived(KalmanPressureOption option);
    void  magnetoOptionReceived(MagnetoOption option);
    void  physMeasuresOptionReceived(PhysMeasuresOption option);
    void  pressureRawOptionReceived(PressureRawOption option);
    void  pwmOptionReceived(PwmOption option);
    void  rawMeasuresOptionReceived(RawMeasuresOption option);
    void  rcReferencesOptionReceived(RcReferencesOption option);
    void  referencesOptionReceived(ReferencesOption option);
    void  timeOptionReceived(TimeOption option);
    void  trackersSendOptionReceived(TrackersSendOption option);
    void  trimsOptionReceived(TrimsOption option);
    void  videoStreamOptionReceived(VideoStreamOption option);
    void  visionDetectOptionReceived(VisionDetectOption option);
    void  visionOfOptionReceived(VisionOfOption option);
    void  visionOptionReceived(VisionOption option);
    void  visionPerfOptionReceived(VisionPerfOption option);
    void  visionRawOptionReceived(VisionRawOption option);
    void  watchdogOptionReceived(WatchdogOption option);
    void  wifiOptionReceived(WifiOption option);
    void  windOptionReceived(WindOption option);
    void  zimmu3000OptionReceived(Zimmu3000Option option);
    void  navdataDebugMessageReceived(QString message);
};

#endif // NAVDATADEBUGWINDOW_H
