#include "AltitudeOption.h"

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
        AltitudeOption::AltitudeOption(QByteArray& rawData):
            CuteNavdataOption(static_cast<int>(CuteNavdataOption::Tag::ALTITUDE))
        {
            altitudeVersion = fetchInt32(rawData);
            altitudeVz      = fetchFloat(rawData);
            altitudeRef     = fetchInt32(rawData);
            altitudeRaw     = fetchInt32(rawData);
            obsAccZ         = fetchFloat(rawData);
            obsAlt          = fetchFloat(rawData);
            obsX            = fetchFloatVector(rawData, 3);
            obsState        = fetchUnsignedInt32(rawData);
            estVb           = fetchFloatVector(rawData, 2);
            estState        = fetchUnsignedInt32(rawData);
        }

        AltitudeOption::AltitudeOption():
            CuteNavdataOption(static_cast<int>(CuteNavdataOption::Tag::ALTITUDE))
        {

        }

        AltitudeOption::~AltitudeOption()
        {

        }

        int32_t AltitudeOption::getAltitudeVision()
        {
            return altitudeVersion;
        }

        float AltitudeOption::getAltitudeVz()
        {
            return altitudeVz;
        }

        int32_t AltitudeOption::getAltitudeRef()
        {
            return altitudeRef;
        }

        int32_t AltitudeOption::getAltitudeRaw()
        {
            return altitudeRaw;
        }

        float AltitudeOption::getObsAccZ()
        {
            return obsAccZ;
        }

        float AltitudeOption::getObsAlt()
        {
            return obsAlt;
        }

        vector<float> AltitudeOption::getObsX()
        {
            return obsX;
        }

        u_int32_t AltitudeOption::getObsState()
        {
            return obsState;
        }

        vector<float> AltitudeOption::getEstVb()
        {
            return estVb;
        }

        u_int32_t AltitudeOption::getEstState()
        {
            return estState;
        }

    }
}
