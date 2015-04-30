#include "FTRIMCommand.h"

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
         * \brief FTRIMCommand::FTRIMCommand Flat trims - Tells the drone it is lying horizontally
         *
         * \warning This command MUST NOT be sent when the AR.Drone is flying!
         *
         * This command sets a reference of the horizontal plane for the drone internal control system.
         * It must be called after each drone start up, while making sure the drone actually sits on a
         * horizontal ground. Not doing so before taking-off will result in the drone not being able to
         * stabilize itself when flying, as it would not be able to know its actual tilt.
         *
         * When receiving this command, the drone will automatically adjust the trim on pitch and roll
         * controls.
         *
         */
        FTRIMCommand::FTRIMCommand() : CuteCommand(NULL)
        {
            //no Data Required
        }

        /*!
         * \brief FTRIMCommand::getCommand Creates the explicit CuteCommand of this type
         *
         * The sequence number is incremented with every call
         *
         * \return QString
         */
        QString FTRIMCommand::getCommand()
        {
            return QString("AT*FTRIM=%1\r")
                    .arg(getNextSequenceNumber());
        }

        FTRIMCommand::~FTRIMCommand()
        {

        }

        /*!
         * \brief FTRIMCommand::operator == Correct overriden equals method
         *
         * The equals method is transitiv, reflexiv and semetric
         *
         * \param CuteCommand* t
         * \return bool
         */
        bool FTRIMCommand::operator ==(CuteCommand *t) const
        {
            if(typeid(*t).name() == typeid(*this).name())
            {
                return true;
            }
            return false;
        }
    }
}
