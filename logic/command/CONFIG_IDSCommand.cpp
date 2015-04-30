#include "CONFIG_IDSCommand.h"

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
         * \brief CONFIG_IDSCommand::CONFIG_IDSCommand Identifiers for the next CONFIGCommand
         *
         * While in multiconfiguration, you must send this command before every AT*CONFIG.
         * The config will only be applied if the ids must match the current ids on the AR.Drone.
         *
         * \param QString currentSessionID
         * \param QString currentUserID
         * \param QString currentApplicaationID
         */
        CONFIG_IDSCommand::CONFIG_IDSCommand(QString currentSessionID, QString currentUserID, QString currentApplicaationID) : CuteCommand(NULL)
        {
            this->currentSessionID              = currentSessionID;
            this->currentUserID                 = currentUserID;
            this->currentApplicaationID         = currentApplicaationID;
        }

        /*!
         * \brief CONFIG_IDSCommand::getCommand Creates the explicit CuteCommand of this type
         *
         * The sequence number is incremented with every call
         *
         * \return QString
         */
        QString CONFIG_IDSCommand::getCommand()
        {
            return QString("AT*CONFIG_IDS=%1,%2,%3,%4\r")
                    .arg(getNextSequenceNumber())
                    .arg(currentSessionID)
                    .arg(currentUserID)
                    .arg(currentApplicaationID);
        }

        CONFIG_IDSCommand::~CONFIG_IDSCommand()
        {

        }

        /*!
         * \brief CONFIG_IDSCommand::operator == Correct overriden equals method
         *
         * The equals method is transitiv, reflexiv and semetric
         *
         * \param CuteCommand* t
         * \return bool
         */
        bool CONFIG_IDSCommand::operator ==(CuteCommand *t) const
        {
            if(typeid(*t).name() == typeid(*this).name())
            {
                CONFIG_IDSCommand *tmp = dynamic_cast<CONFIG_IDSCommand*>(t);
                if(tmp->currentApplicaationID == this->currentApplicaationID &&
                        tmp->currentSessionID == this->currentSessionID && tmp->currentUserID == this->currentUserID)
                {
                    return true;
                }
            }
            return false;
        }

        }
}
