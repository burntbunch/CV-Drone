#include "VisionRawOption.h"

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
        VisionRawOption::VisionRawOption(QByteArray& rawData):
            CuteNavdataOption(static_cast<int>(CuteNavdataOption::Tag::VISION_RAW))
        {
            visionTxRaw = fetchFloat(rawData);
            visionTyRaw = fetchFloat(rawData);
            visionTzRaw = fetchFloat(rawData);
        }

        VisionRawOption::VisionRawOption():
            CuteNavdataOption(static_cast<int>(CuteNavdataOption::Tag::VISION_RAW))
        {

        }

        VisionRawOption::~VisionRawOption()
        {

        }
        float VisionRawOption::getVisionTxRaw() const
        {
            return visionTxRaw;
        }

        float VisionRawOption::getVisionTyRaw() const
        {
            return visionTyRaw;
        }

        float VisionRawOption::getVisionTzRaw() const
        {
            return visionTzRaw;
        }
    }
}
