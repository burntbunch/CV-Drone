#include "WindOption.h"

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
        WindOption::WindOption(QByteArray& rawData):
            CuteNavdataOption(static_cast<int>(CuteNavdataOption::Tag::WIND))
        {
            windSpeed             = fetchFloat(rawData);
            windAngle             = fetchFloat(rawData);
            windCompensationTheta = fetchFloat(rawData);
            windCompensationPhi   = fetchFloat(rawData);
            stateX1               = fetchFloat(rawData);
            stateX2               = fetchFloat(rawData);
            stateX3               = fetchFloat(rawData);
            stateX4               = fetchFloat(rawData);
            stateX5               = fetchFloat(rawData);
            stateX6               = fetchFloat(rawData);
            magnetoDebug1         = fetchFloat(rawData);
            magnetoDebug2         = fetchFloat(rawData);
            magnetoDebug3         = fetchFloat(rawData);
        }

        WindOption::WindOption():
            CuteNavdataOption(static_cast<int>(CuteNavdataOption::Tag::WIND))
        {

        }

        WindOption::~WindOption()
        {

        }
        float WindOption::getWindSpeed() const
        {
            return windSpeed;
        }

        float WindOption::getWindAngle() const
        {
            return windAngle;
        }

        float WindOption::getWindCompensationTheta() const
        {
            return windCompensationTheta;
        }

        float WindOption::getWindCompensationPhi() const
        {
            return windCompensationPhi;
        }

        float WindOption::getStateX1() const
        {
            return stateX1;
        }

        float WindOption::getStateX2() const
        {
            return stateX2;
        }

        float WindOption::getStateX3() const
        {
            return stateX3;
        }

        float WindOption::getStateX4() const
        {
            return stateX4;
        }

        float WindOption::getStateX5() const
        {
            return stateX5;
        }

        float WindOption::getStateX6() const
        {
            return stateX6;
        }

        float WindOption::getMagnetoDebug1() const
        {
            return magnetoDebug1;
        }

        float WindOption::getMagnetoDebug2() const
        {
            return magnetoDebug2;
        }

        float WindOption::getMagnetoDebug3() const
        {
            return magnetoDebug3;
        }
    }
}
