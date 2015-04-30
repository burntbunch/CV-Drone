#include "MagnetoOption.h"

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
        MagnetoOption::MagnetoOption(QByteArray& rawData):
            CuteNavdataOption(static_cast<int>(CuteNavdataOption::Tag::MAGNETO))
        {
            mx                     = fetchInt16(rawData);
            my                     = fetchInt16(rawData);
            mz                     = fetchInt16(rawData);
            magnetoRaw             = fetchFloatVector(rawData, 3);
            magnetoRectified       = fetchFloatVector(rawData, 3);
            magnetoOffset          = fetchFloatVector(rawData, 3);
            headingUnwrapped       = fetchFloat(rawData);
            headingGyroUnwrapped   = fetchFloat(rawData);
            headingFusionUnwrapped = fetchFloat(rawData);
            magnetoCalibrationOk   = fetchUnsignedInt16(rawData);
            magnetoState           = fetchUnsignedInt32(rawData);
            magnetoRadius          = fetchFloat(rawData);
            errorMean              = fetchFloat(rawData);
            errorVar               = fetchFloat(rawData);
        }

        MagnetoOption::MagnetoOption():
            CuteNavdataOption(static_cast<int>(CuteNavdataOption::Tag::MAGNETO))
        {

        }

        MagnetoOption::~MagnetoOption()
        {

        }

        int16_t MagnetoOption::getMx()
        {
            return mx;
        }

        int16_t MagnetoOption::getMy()
        {
            return my;
        }

        int16_t MagnetoOption::getMz()
        {
            return mz;
        }

        vector<float> MagnetoOption::getMagnetoRaw()
        {
            return magnetoRaw;
        }

        vector<float> MagnetoOption::getMagnetoRectified()
        {
            return magnetoRectified;
        }

        vector<float> MagnetoOption::getMagnetoOffset()
        {
            return magnetoOffset;
        }

        float MagnetoOption::getHeadingUnwrapped()
        {
            return headingUnwrapped;
        }

        float MagnetoOption::getHeadingGyroUnwrapped()
        {
            return headingGyroUnwrapped;
        }

        float MagnetoOption::getHeadingFusionUnwrapped()
        {
            return headingFusionUnwrapped;
        }

        u_int16_t MagnetoOption::getMagnetoCalibrationOk()
        {
            return magnetoCalibrationOk;
        }

        u_int32_t MagnetoOption::getMagnetoState()
        {
            return magnetoState;
        }

        float MagnetoOption::getMagnetoRadius()
        {
            return magnetoRadius;
        }

        float MagnetoOption::getErrorMean()
        {
            return errorMean;
        }

        float MagnetoOption::getErrorVar()
        {
            return errorVar;
        }
    }
}
