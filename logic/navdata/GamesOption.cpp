#include "GamesOption.h"

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
        GamesOption::GamesOption(QByteArray& rawData):
            CuteNavdataOption(static_cast<int>(CuteNavdataOption::Tag::GAMES))
        {
            doubleTapCounter    =   fetchUnsignedInt32(rawData);
            finishLineCounter   =   fetchUnsignedInt32(rawData);
        }

        GamesOption::GamesOption():
            CuteNavdataOption(static_cast<int>(CuteNavdataOption::Tag::GAMES))
        {

        }

        GamesOption::~GamesOption()
        {

        }

        u_int32_t GamesOption::getDoubleTapCounter()
        {
            return doubleTapCounter;
        }

        u_int32_t GamesOption::getFinishLineCounter()
        {
            return finishLineCounter;
        }

    }
}
