#include "CommandService.h"

/*
 * CV-Drone
 * Copyright (C) 2015 www.burntbunch.org
 *
 * This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation; either version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License along with this library;
 * if not, write to the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110, USA
 */

namespace Drone
{
    /*!
     * \brief CommandService::CommandService
     * \param droneIP the ip of the drone
     * \param port the port number of the command port
     * \param parent QObject parent
     * The service will send the given AT*Command to the drone.
     * The command will be send every 200ms with increased sequence number until you change it.
     */
    CommandService::CommandService(QString droneIP, int port, QObject *parent) :
        CuteService(droneIP, port, parent)
    {
        socket = new QUdpSocket(this);
        timer->setInterval(200);
        reconTimer = new QTimer(this);
        reconTimer->setInterval(2500);
        reconTimer->setSingleShot(true);
        connect(timer,          SIGNAL(timeout()),      this,   SLOT(sendCommand(void)));
        connect(workerThread,   SIGNAL(started()),      timer,  SLOT(start()));
        connect(workerThread,   SIGNAL(started()),      this,   SLOT(provision()));
        connect(reconTimer,     SIGNAL(timeout()),      this,   SLOT(processReconnect()));
        command = new Drone::Command::FTRIMCommand();
    }

    CommandService::~CommandService()
    {
        stop();
        if(verbose)
            emit nextVerboseString("CommandService destroyed");
    }

    /*!
     * \brief CommandService::setCommand updates the commmands that will the send.
     * \param command the command to send.
     * If the given command equals the current command nothing will happen.
     * If the command differs, the service will interrupt the timer and adapt the new command.
     */
    void CommandService::setCommand(CuteCommand* command)
    {
        if(this->command == command)
            return;
        if(timer->isActive())
        {
            QMetaObject::invokeMethod(timer, "stop", Qt::QueuedConnection);
            delete this->command;
            this->command = command;
            QMetaObject::invokeMethod(timer, "start", Qt::QueuedConnection);
        }
        else
        {
            delete this->command;
            this->command = command;
        }
        if(verbose)
            emit nextVerboseString("Changed command.");
    }

    /*!
     * \brief CommandService::reconnect stops the timer and flushes the socket.
     * The processReconnect() method will be called after 2500ms.
     */
    void CommandService::reconnect()
    {
        timer->stop();
        socket->close();
        reconTimer->start();
    }

    /*!
     * \brief CommandService::sendCommand send the current command to the drone (every 200ms).
     */
    void CommandService::sendCommand()
    {
        if(verbose)
        {
            QString stringCommand = command->getCommand();
            socket->writeDatagram(stringCommand.toLatin1(), QHostAddress(droneIP), port);
            emit nextVerboseString(stringCommand.remove("\r").append("\\r"));
        }
        else
            socket->writeDatagram(command->getRAWCommand(), QHostAddress(droneIP), port);
    }

    /*!
     * \brief CommandService::provision is called when the object thread is started.
     * This object will be moved to the object thread.
     */
    void CommandService::provision()
    {
        moveToThread(workerThread);
    }

    /*!
     * \brief CommandService::processReconnect starts the send timer and emits the reconnected() signal.
     */
    void CommandService::processReconnect()
    {
        timer->start();
        emit reconnected();
    }

    /*!
     * \brief CommandService::start starts the object thread.
     */
    void CommandService::start()
    {
        workerThread->start();
    }

    /*!
     * \brief CommandService::stop stops the timer and the object thread.
     */
    void CommandService::stop()
    {
        timer->stop();
        workerThread->quit();
        workerThread->wait();
    }
}
