#include "PCMD_MAGCommand.h"

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
         * \brief PCMD_MAGCommand::PCMD_MAGCommand Send progressive commands - makes the drone move (translate/rotate)
         *
         * This command controls the drone flight motions.
         * Always set the flag (argument 2) bit zero to one to make the drone consider the other argu-
         * ments. Setting it to zero makes the drone enter hovering mode (staying on top of the same point
         * on the ground)
         *
         * The left-right tilt (aka. "drone roll" or phi angle) argument is a percentage of the maximum
         * inclination as configured here. A negative value makes the drone tilt to its left, thus flying
         * leftward. A positive value makes the drone tilt to its right, thus flying rightward.
         *
         * The front-back tilt (aka. "drone pitch" or theta angle) argument is a percentage of the maximum
         * inclination as configured here. A negative value makes the drone lower its nose, thus flying
         * frontward. A positive value makes the drone raise its nose, thus flying backward.
         * The drone translation speed in the horizontal plane depends on the environment and cannot
         * be determined. With roll or pitch values set to 0, the drone will stay horizontal but continue
         * sliding in the air because of its inertia. Only the air resistance will then make it stop.
         *
         * The vertical speed (aka. "gaz") argument is a percentage of the maximum vertical speed as
         * defined here. A positive value makes the drone rise in the air. A negative value makes it go down.
         * The angular speed argument is a percentage of the maximum angular speed as defined here.
         * A positive value makes the drone spin right; a negative value makes it spin left.
         *
         * The psi argument is a normalized psi angle from north provided by magnetometer sensor as
         * defined here. An angle value of 0 means that the controller is facing north. A positive value
         * means that the controller is oriented to the east and a negative value is orienting to the west. 1
         * and -1 value are the same orientation. (only for AT*PCMD_MAG)
         *
         * The psi accuracy argument is an accuracy of the magnetometer sensor. This value represents
         * the maximum deviation of where the magnetic heading may differ from the actual geomagnetic
         * heading in degrees. Negative values indicates the invalid heading. (only for AT*PCMD_MAG)
         *
         * \param Mode mode
         * \param float roll
         * \param float pitch
         * \param float gaz
         * \param float yaw
         * \param float magnetoPsy
         * \param float magnetoPsyAccuracy
         */
        PCMD_MAGCommand::PCMD_MAGCommand(Mode mode,float roll, float pitch, float gaz, float yaw , float magnetoPsy, float magnetoPsyAccuracy ) : CuteCommand(NULL)
        {
            this->mode                  = mode;
            this->roll                  = roll;
            this->pitch                 = pitch;
            this->gaz                   = gaz;
            this->yaw                   = yaw;
            this->magnetoPsy            = magnetoPsy;
            this->magnetoPsyAccuracy    = magnetoPsyAccuracy;

        }
        /*!
         * \brief PCMD_MAGCommand::checkParams checks the given parameters of validity
         *
         *  This function has to be called before building a CuteCommand
         *
         * \param float roll
         * \param float pitch
         * \param float gaz
         * \param float yaw
         * \param float magnetoPsy
         * \param float magnetoPsyAccuracy
         * \return bool status of validity
         */
        bool PCMD_MAGCommand::checkParams(float roll, float pitch, float gaz, float yaw , float magnetoPsy, float magnetoPsyAccuracy )
        {
            if(roll < -1.0f || roll > 1.0f)
                return false;
            if(pitch < -1.0f || pitch > 1.0f)
                return false;
            if(gaz < -1.0f || gaz > 1.0f)
                return false;
            if(yaw < -1.0f || yaw > 1.0f)
                return false;
            if(magnetoPsy < -1.0f || magnetoPsy > 1.0f)
                return false;
            if(magnetoPsyAccuracy < -1.0f || magnetoPsyAccuracy > 1.0f)
                return false;
            return true;
        }
        /*!
         * \brief PCMD_MAGCommand::getCommand Creates the explicit CuteCommand of this type
         *
         * The sequence number is incremented with every call
         *
         * \return QString
         */
        QString PCMD_MAGCommand::getCommand()
        {
            return QString("AT*PCMD_MAG=%1,%2,%3,%4,%5,%6,%7,%8\r")
                    .arg(getNextSequenceNumber())
                    .arg((int)mode)
                    .arg(reinterpret_cast<int&>(roll))
                    .arg(reinterpret_cast<int&>(pitch))
                    .arg(reinterpret_cast<int&>(gaz))
                    .arg(reinterpret_cast<int&>(yaw))
                    .arg(reinterpret_cast<int&>(magnetoPsy))
                    .arg(reinterpret_cast<int&>(magnetoPsyAccuracy));
        }

        PCMD_MAGCommand::~PCMD_MAGCommand()
        {

        }

        /*!
         * \brief PCMD_MAGCommand::operator == Correct overriden equals method
         *
         * The equals method is transitiv, reflexiv and semetric
         *
         * \param CuteCommand* t
         * \return bool
         */
        bool PCMD_MAGCommand::operator ==(CuteCommand *t) const
        {
            if(typeid(*t).name() == typeid(*this).name())
            {
                PCMD_MAGCommand *tmp = dynamic_cast<PCMD_MAGCommand*>(t);
                if(tmp->gaz == this->gaz && tmp->magnetoPsy == this->magnetoPsy && tmp->magnetoPsyAccuracy == this->magnetoPsyAccuracy && tmp->mode == this->mode
                   && tmp->pitch == this->pitch && tmp->roll == this->roll && tmp->yaw == this->yaw)
                {
                    return true;
                }
            }
            return false;
        }
    }
}
