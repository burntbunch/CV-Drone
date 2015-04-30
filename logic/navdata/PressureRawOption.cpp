#include "PressureRawOption.h"

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
        PressureRawOption::PressureRawOption(QByteArray& rawData):
            CuteNavdataOption(static_cast<int>(CuteNavdataOption::Tag::PRESSURE_RAW))
        {
            up              =   fetchInt32(rawData);
            ut              =   fetchInt16(rawData);
            temperatureMeas =   fetchInt32(rawData);
            pressionMeas    =   fetchInt32(rawData);
        }

        PressureRawOption::PressureRawOption():
            CuteNavdataOption(static_cast<int>(CuteNavdataOption::Tag::PRESSURE_RAW))
        {

        }

        PressureRawOption::~PressureRawOption()
        {

        }

        int32_t PressureRawOption::getUp()
        {
            return up;
        }

        int16_t PressureRawOption::getUt()
        {
            return ut;
        }

        int32_t PressureRawOption::getTemperatureMeas()
        {
            return temperatureMeas;
        }

        int32_t PressureRawOption::getPressionMeas()
        {
            return pressionMeas;
        }
    }
}
