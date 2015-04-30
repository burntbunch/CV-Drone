#ifndef COMMANDSERVICE_H
#define COMMANDSERVICE_H

#include <QObject>
#include <QUdpSocket>
#include <QMetaObject>
#include <iostream>

#include <CuteService.h>
#include <command/CuteCommand.h>
#include <command/FTRIMCommand.h>

using Drone::Command::CuteCommand;

namespace Drone
{
    class CommandService : public CuteService
    {
        Q_OBJECT
    public:
        explicit CommandService(QString droneIP, int port, QObject *parent = 0);
        ~CommandService();
    private:
        CuteCommand* command;
        QUdpSocket* socket;
        QTimer* reconTimer;

    signals:
        void reconnected();

    public slots:
        void setCommand(CuteCommand* command);
        void reconnect();
        void start() override;
        void stop() override;

    private slots:
        void sendCommand();
        void provision();
        void processReconnect();

    };
}

#endif // COMMANDSERVICE_H
