#ifndef VIDEOSERVICE_H
#define VIDEOSERVICE_H

#include <cmath>
#include <QObject>
#include <opencv2/opencv.hpp>

#include <CuteService.h>

namespace Drone
{
    class VideoService : public CuteService
    {
        Q_OBJECT
    public:
        explicit VideoService(QString droneIP, int port, QObject *parent = 0);
        ~VideoService();
        int getFps() const;
        cv::Mat getMatrix();
    private:
        cv::VideoCapture* capture;
        QString tcpString;
        int fps;
        cv::Mat frame;
        bool lostConnection;
        QTimer *lostTimer;
    signals:
        void nextFrameReady();
        void connectionLost();

    public slots:
        void start() override;
        void stop() override;
        void reconnect();
    private slots:
        void checkFrame();
        void connectToDrone();
        void provision();
        void checkLost();
    };
}

#endif // VIDEOSERVICE_H
