#include "PhysMeasuresOption.h"

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
        PhysMeasuresOption::PhysMeasuresOption(QByteArray& rawData):
            CuteNavdataOption(static_cast<int>(CuteNavdataOption::Tag::PHYS_MEASURES))
        {
            accsTemp    =   fetchFloat(rawData);
            gyroTemp    =   fetchUnsignedInt16(rawData);
            physAccs    =   fetchFloatVector(rawData, 3);
            physGyros   =   fetchFloatVector(rawData, 3);
            alim3v3     =   fetchUnsignedInt32(rawData);
            vrefEpson   =   fetchUnsignedInt32(rawData);
            vrefIdg     =   fetchUnsignedInt32(rawData);
        }

        PhysMeasuresOption::PhysMeasuresOption():
            CuteNavdataOption(static_cast<int>(CuteNavdataOption::Tag::PHYS_MEASURES))
        {

        }

        PhysMeasuresOption::~PhysMeasuresOption()
        {

        }

        float PhysMeasuresOption::getAccsTemp()
        {
            return accsTemp;
        }

        u_int16_t PhysMeasuresOption::getGyroTemp()
        {
            return gyroTemp;
        }

        vector<float> PhysMeasuresOption::getPhysAccs()
        {
            return physAccs;
        }

        vector<float> PhysMeasuresOption::getPhysGyros()
        {
            return physGyros;
        }

        u_int32_t PhysMeasuresOption::getAlim3v3()
        {
            return alim3v3;
        }

        u_int32_t PhysMeasuresOption::getVrefEpson()
        {
            return vrefEpson;
        }

        u_int32_t PhysMeasuresOption::getVrefIdg()
        {
            return vrefIdg;
        }
    }
}
