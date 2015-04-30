#ifndef CUTESERVICE_H
#define CUTESERVICE_H

#include <QObject>
#include <QString>
#include <QThread>
#include <QTimer>

namespace Drone {
    class CuteService : public QObject
    {
        Q_OBJECT
    public:
        CuteService( QString droneIP, int port, QObject *parent);
        bool getVerbose() const;

    protected:
        QThread* workerThread;
        QTimer* timer;
        QString droneIP;
        int port;
        bool verbose;
    signals:
        void nextVerboseString(QString row);

    public slots:
        virtual void start() = 0;
        virtual void stop() = 0;
        void setVerbose(bool value);

    };
}


#endif // CUTESERVICE_H
