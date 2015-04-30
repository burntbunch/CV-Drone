#ifndef CONFIGFILE_H
#define CONFIGFILE_H

#include <QJsonObject>
#include <QJsonValue>
#include <QJsonDocument>
#include <QMutex>
#include <QFile>
#include <QDebug>


namespace Drone
{
    class ConfigFile
    {
    public:
        static ConfigFile& getInstance();
        bool readFromFile();
        bool writeToFile();
        void resetToDefault();
        QString getFileName();
        void setFileName(QString fileName);
        QString getIp() const;
        int getCommandPort() const;
        int getVideoPort() const;
        int getNavdataPort() const;
        float getSpeed() const;
        int getMinR() const;
        void setMinR(int value);
        int getMinG() const;
        void setMinG(int value);
        int getMinB() const;
        void setMinB(int value);
        int getMaxR() const;
        void setMaxR(int value);
        int getMaxG() const;
        void setMaxG(int value);
        int getMaxB() const;
        void setMaxB(int value);
        int getRadius() const;
        void setRadius(int value);
        float getSpeedAltitude() const;

    private:
        ConfigFile();
        ConfigFile(ConfigFile const&);
        void operator =(ConfigFile const&);
        void serialize();
        void deserialize();
        QMutex mutex;
        QJsonObject jsonObject;
        QString ip;
        QString fileName;
        int commandPort, videoPort, navdataPort;
        int minR, minG, minB, maxR, maxG, maxB;
        int radius;
        float speed, speedAltitude;
    };

}


#endif // CONFIGFILE_H
