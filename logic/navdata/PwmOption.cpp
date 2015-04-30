#include "PwmOption.h"

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
    namespace Navdata
    {
        PwmOption::PwmOption(QByteArray& rawData):
            CuteNavdataOption(static_cast<int>(CuteNavdataOption::Tag::PWM))
        {
            motor1           = fetchUnsignedInt8(rawData);
            motor2           = fetchUnsignedInt8(rawData);
            motor3           = fetchUnsignedInt8(rawData);
            motor4           = fetchUnsignedInt8(rawData);
            satMotor1        = fetchUnsignedInt8(rawData);
            satMotor2        = fetchUnsignedInt8(rawData);
            satMotor3        = fetchUnsignedInt8(rawData);
            satMotor4        = fetchUnsignedInt8(rawData);
            gazFeedForward   = fetchFloat(rawData);
            gazAltitude      = fetchFloat(rawData);
            altitudeIntegral = fetchFloat(rawData);
            vzRef            = fetchFloat(rawData);
            uPitch           = fetchInt32(rawData);
            uRoll            = fetchInt32(rawData);
            uYaw             = fetchInt32(rawData);
            yawUI            = fetchFloat(rawData);
            uPitchPlanif     = fetchInt32(rawData);
            uRollPlanif      = fetchInt32(rawData);
            uYawPlanif       = fetchInt32(rawData);
            uGazPlanif       = fetchFloat(rawData);
            currentMotor1    = fetchUnsignedInt16(rawData);
            currentMotor2    = fetchUnsignedInt16(rawData);
            currentMotor3    = fetchUnsignedInt16(rawData);
            currentMotor4    = fetchUnsignedInt16(rawData);
            altitudeProp     = fetchFloat(rawData);
            altitudeDer      = fetchFloat(rawData);
        }

        PwmOption::PwmOption():
            CuteNavdataOption(static_cast<int>(CuteNavdataOption::Tag::PWM))
        {

        }

        PwmOption::~PwmOption()
        {

        }

        u_int8_t PwmOption::getMotor1()
        {
            return motor1;
        }

        u_int8_t PwmOption::getMotor2()
        {
            return motor2;
        }

        u_int8_t PwmOption::getMotor3()
        {
            return motor3;
        }

        u_int8_t PwmOption::getMotor4()
        {
            return motor4;
        }

        u_int8_t PwmOption::getSatMotor1()
        {
            return satMotor1;
        }

        u_int8_t PwmOption::getSatMotor2()
        {
            return satMotor2;
        }

        u_int8_t PwmOption::getSatMotor3()
        {
            return satMotor3;
        }

        u_int8_t PwmOption::getSatMotor4()
        {
            return satMotor4;
        }

        float PwmOption::getGazFeedForward()
        {
            return gazFeedForward;
        }

        float PwmOption::getGazAltitude()
        {
            return gazAltitude;
        }

        float PwmOption::getAltitudeIntegral()
        {
            return altitudeIntegral;
        }

        float PwmOption::getVzRef()
        {
            return vzRef;
        }

        int32_t PwmOption::getuPitch()
        {
            return uPitch;
        }

        int32_t PwmOption::getuRoll()
        {
            return uRoll;
        }

        int32_t PwmOption::getuYaw()
        {
            return uYaw;
        }

        float PwmOption::getYawUI()
        {
            return yawUI;
        }

        int32_t PwmOption::getuPitchPlanif()
        {
            return uPitchPlanif;
        }

        int32_t PwmOption::getuRollPlanif()
        {
            return uRollPlanif;
        }

        int32_t PwmOption::getuYawPlanif()
        {
            return uYawPlanif;
        }

        float PwmOption::getuGazPlanif()
        {
            return uGazPlanif;
        }

        int16_t PwmOption::getCurrentMotor1()
        {
            return currentMotor1;
        }

        int16_t PwmOption::getCurrentMotor2()
        {
            return currentMotor2;
        }

        int16_t PwmOption::getCurrentMotor3()
        {
            return currentMotor3;
        }

        int16_t PwmOption::getCurrentMotor4()
        {
            return currentMotor4;
        }

        float PwmOption::getAltitudeProp()
        {
            return altitudeProp;
        }

        float PwmOption::getAltitudeDer()
        {
            return altitudeDer;
        }
    }
}
