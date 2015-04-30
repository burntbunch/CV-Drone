#ifndef OBJECTDETECTOR_H
#define OBJECTDETECTOR_H

#include <QObject>
#include <QThread>
#include <QPixmap>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <math.h>
#include <ConfigFile.h>
#include <VideoService.h>
#include <string>

using namespace cv;

namespace ObjectDetection
{
    class ObjectDetector : public QObject
    {
            Q_OBJECT
        public:
            explicit ObjectDetector(Drone::VideoService *service, QObject *parent = 0);
            ~ObjectDetector();
            bool isOpened();
            void movementSignal(Point2f point);
            void createPolygons();
            int getMinR();
            int getMinG();
            int getMinB();
            int getMaxR();
            int getMaxG();
            int getMaxB();
            int getRadius();
            bool getVerbose() const;
            bool getAutopilot() const;
            bool getActivated() const;

    signals:
            void moveLeft();
            void moveRight();
            void moveUp();
            void moveDown();
            void moveUpRight();
            void moveUpLeft();
            void moveDownRight();
            void moveDownLeft();
            void searchObject();
            void inCenter();
            void objectFound();
            void nextVerboseString(QString message);
            void nextFrameReady(QPixmap);

        public slots:
            void setVerbose(bool value);
            void colorFilter();
            void connectionLost();
            void setMinR(int minR);
            void setMinG(int minG);
            void setMinB(int minB);
            void setMaxR(int maxR);
            void setMaxG(int maxG);
            void setMaxB(int maxB);
            void setRadius(int radius);
            void setAutopilot(bool value);
            void setActivated(bool value);

        private:
            bool verbose, autopilot, activated, searchEmited;
            vector<vector<Point>> contoursVec;
            Drone::ConfigFile *config;
            Drone::VideoService *service;
            QThread* thread;
            cv::Mat frame;
            int lastSeenIn;
    };
}
#endif // OBJECTDETECTOR_H
