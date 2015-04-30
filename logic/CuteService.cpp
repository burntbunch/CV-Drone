#include "CuteService.h"

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
        CuteService::CuteService(QString droneIP, int port, QObject *parent = 0) :
            QObject(parent)
        {
            verbose = false;
            workerThread = new QThread(this);
            timer = new QTimer(this);
            this->droneIP = droneIP;
            this->port = port;
            connect(workerThread, SIGNAL(started()), timer, SLOT(start()));
        }

        /*!
         * \brief CuteService::getVerbose returns true if the debug messages are enabled.
         * \return
         */
        bool CuteService::getVerbose() const
        {
            return verbose;
        }

        /*!
         * \brief CuteService::setVerbose enables or disables debug messages.
         * \param value
         */
        void CuteService::setVerbose(bool value)
        {
            verbose = value;
        }

}

