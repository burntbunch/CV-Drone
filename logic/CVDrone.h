#ifndef CVDRONE_H
#define CVDRONE_H

#include <QObject>
#include <string>
#include <CuteCommand.h>
#include <PCMDCommand.h>
#include <PCMD_MAGCommand.h>
#include <FTRIMCommand.h>
#include <CALIBCommand.h>
#include <REFCommand.h>
#include <CONFIGCommand.h>
#include <PMODECommand.h>
#include <ConfigFile.h>
#include <CommandService.h>
#include <NavdataService.h>
#include <VideoService.h>
#include <QTimer>

using namespace Drone::Command;

namespace Drone
{
    class CVDrone : public QObject {
        Q_OBJECT

    public:
        static CVDrone& getInstance();
        ~CVDrone();
        NavdataService* getNavdataService();
        CommandService* getCommandService();
        VideoService*   getVideoService();

    public slots:
        void emergency();
        void takeOff();
        void land();
        void hover();
        void turnLeft();
        void turnRight();
        void moveForward();
        void moveBackward();
        void moveLeft();
        void moveRight();
        void moveUpperRight();
        void moveUpperLeft();
        void moveLowerRight();
        void moveLowerLeft();
        void moveUp();
        void moveDown();
        void setMode();

    private:
         CVDrone();
         CVDrone(CVDrone const&);
         void operator =(CVDrone const&);
         QThread* thread;
         QTimer* timer;
         ConfigFile      *configFile;
         NavdataService  *navdataService;
         CommandService  *commandService;
         VideoService    *videoService;
         float speed, speedAltitude;
         bool flying;
    };

}

#endif // CVDRONE_H

