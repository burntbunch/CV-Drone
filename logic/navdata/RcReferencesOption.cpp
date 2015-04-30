#include "RcReferencesOption.h"

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
        RcReferencesOption::RcReferencesOption(QByteArray& rawData):
            CuteNavdataOption(static_cast<int>(CuteNavdataOption::Tag::RC_REFERENCES))
        {
            rcRefPitch = fetchInt32(rawData);
            rcRefRoll  = fetchInt32(rawData);
            rcRefYaw   = fetchInt32(rawData);
            rcRefGaz   = fetchInt32(rawData);
            rcRefAg    = fetchInt32(rawData);
        }

        RcReferencesOption::RcReferencesOption():
            CuteNavdataOption(static_cast<int>(CuteNavdataOption::Tag::RC_REFERENCES))
        {

        }

        RcReferencesOption::~RcReferencesOption()
        {

        }

        int32_t RcReferencesOption::getRcRefPitch()
        {
            return rcRefPitch;
        }

        int32_t RcReferencesOption::getRcRefRoll()
        {
            return rcRefRoll;
        }

        int32_t RcReferencesOption::getRcRefYaw()
        {
            return rcRefYaw;
        }

        int32_t RcReferencesOption::getRcRefGaz()
        {
            return rcRefGaz;
        }

        int32_t RcReferencesOption::getRcRefAg()
        {
            return rcRefAg;
        }
    }
}
