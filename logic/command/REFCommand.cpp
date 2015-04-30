#include "REFCommand.h"

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
         * \brief REFCommand::REFCommand Controls the basic behaviour of the drone (take-off/landing, emergency/stop/reset)
         *
         * The basic commands are packed in ENUMS for this function
         *
         * \param State state
         */
        REFCommand::REFCommand(State state) : CuteCommand(NULL)
        {
            this->state = state;
        }

        /*!
         * \brief REFCommand::getCommand Creates the explicit CuteCommand of this type
         *
         * The sequence number is incremented with every call
         *
         * \return QString
         */

        QString REFCommand::getCommand()
        {
            return QString("AT*REF=%1,%2\r")
                    .arg(getNextSequenceNumber())
                    .arg((int)state);
        }

        REFCommand::~REFCommand()
        {

        }

        /*!
         * \brief REFCommand::operator == Correct overriden equals method
         *
         * The equals method is transitiv, reflexiv and semetric
         *
         * \param CuteCommand* t
         * \return bool
         */
        bool REFCommand::operator ==(CuteCommand *t) const
        {
            if(typeid(*t).name() == typeid(*this).name())
            {
                REFCommand *tmp = dynamic_cast<REFCommand*>(t);
                if(tmp->state == this->state)
                {
                    return true;
                }
            }
            return false;
        }
    }
}

