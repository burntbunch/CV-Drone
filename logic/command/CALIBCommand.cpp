#include "CALIBCommand.h"
#include <QDebug>

/*
 * CV-Drone
 * Copyright (C) 2015 www.burntbunch.org
 *
 * This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation; either version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License along with this library;
 * if not, write to the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * */

namespace Drone
{
    namespace Command
    {
        /*!
         * \brief CALIBCommand::CALIBCommand Tells the drone to calibrate its magnetometer
         *
         * Creates a new CuteCommand of the type "CALIBCommand"
         * which tells the Drone to calibrate its magnetometer.
         *
         * ARDRONE_CALIBRATION_DEVICE_MAGNETOMETER = 0
         * ARDRONE_CALIBRATION_DEVICE_NUMBER = 1
         *
         * \param bool callib represents a 0 or 1 decision explayned in the annotation abowth
         */
        CALIBCommand::CALIBCommand(bool callib) : CuteCommand(NULL)
        {
            this->callib = callib;
        }

        /*!
         * \brief CALIBCommand::getCommand Creates the explicit CuteCommand of this type
         *
         * The sequence number is incremented with every call
         *
         * \return QString
         */
        QString CALIBCommand::getCommand()
        {
            return QString("AT*CALIB=%1,%2\r")
                            .arg(getNextSequenceNumber())
                            .arg(callib ? 1 : 0);
        }

        CALIBCommand::~CALIBCommand()
        {

        }
        /*!
         * \brief CALIBCommand::operator == Correct overriden equals method
         *
         * The equals method is transitiv, reflexiv and semetric
         *
         * \param CuteCommand* t
         * \return bool
         */
        bool CALIBCommand::operator==(CuteCommand* t) const
        {
            qDebug() << typeid(*t).name();
            if(typeid(*t).name() == typeid(*this).name())
            {
                CALIBCommand *tmp = dynamic_cast<CALIBCommand*>(t);
                if(tmp->callib == this->callib)
                {
                    return true;
                }
            }
            return false;
        }
    }
}
