#include "COMWDGCommand.h"

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
         * \brief COMWDGCommand::COMWDGCommand reset communication watchdog
         *
         * Resets the communication watchdog. No parameters required
         */
        COMWDGCommand::COMWDGCommand() : CuteCommand(NULL)
        {
            //No Data Required
        }

        /*!
         * \brief COMWDGCommand::getCommand Creates the explicit CuteCommand of this type
         *
         * The sequence number is incremented with every call
         *
         * \return QString
         */
        QString COMWDGCommand::getCommand()
        {
            return QString("AT*COMWDG=%1\r").arg(getNextSequenceNumber());
        }

        COMWDGCommand::~COMWDGCommand()
        {

        }

        /*!
         * \brief COMWDGCommand::operator == Correct overriden equals method
         *
         * The equals method is transitiv, reflexiv and semetric
         *
         * \param CuteCommand* t
         * \return bool
         */
        bool COMWDGCommand::operator ==(CuteCommand *t) const
        {
            if(typeid(*t).name() == typeid(*this).name())
            {
                return true;
            }
            return false;
        }
    }
}

