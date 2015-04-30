#include "VisionOption.h"

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
        VisionOption::VisionOption(QByteArray& rawData):
            CuteNavdataOption(static_cast<int>(CuteNavdataOption::Tag::VISION))
        {
            visionState                     = fetchUnsignedInt32(rawData);
            visionMisc                      = fetchInt32(rawData);
            visionPhiTrim                   = fetchFloat(rawData);
            visionPhiRefProp                = fetchFloat(rawData);
            visionThetaTrim                 = fetchFloat(rawData);
            visionThetaRefProp              = fetchFloat(rawData);
            newRawPicture                   = fetchInt32(rawData);
            thetaCapture                    = fetchFloat(rawData);
            phiCapture                      = fetchFloat(rawData);
            psiCapture                      = fetchFloat(rawData);
            altitudeCapture                 = fetchInt32(rawData);
            // The 11 most significant bits represents the seconds,
            // and the 21 least significant bits are the microseconds
            u_int32_t buffer                = fetchUnsignedInt32(rawData);
            u_int32_t seconds               = buffer >> 21;
            u_int32_t microseconds          = (buffer << 11) >> 11;
            // Convert to milliseconds
            timeCapture                     = seconds*1000 + microseconds/1000;
            bodyV                           = fetchFloatVector(rawData, 3);
            deltaPhi                        = fetchFloat(rawData);
            deltaTheta                      = fetchFloat(rawData);
            deltaPsi                        = fetchFloat(rawData);
            goldDefined                     = fetchUnsignedInt32(rawData);
            goldReset                       = fetchUnsignedInt32(rawData);
            goldX                           = fetchFloat(rawData);
            goldY                           = fetchFloat(rawData);
        }

        VisionOption::VisionOption():
            CuteNavdataOption(static_cast<int>(CuteNavdataOption::Tag::VISION))
        {

        }

        VisionOption::~VisionOption()
        {

        }
        int32_t VisionOption::getVisionState() const
        {
            return visionState;
        }

        int32_t VisionOption::getVisionMisc() const
        {
            return visionMisc;
        }

        float VisionOption::getVisionPhiTrim() const
        {
            return visionPhiTrim;
        }

        float VisionOption::getVisionPhiRefProp() const
        {
            return visionPhiRefProp;
        }

        float VisionOption::getVisionThetaTrim() const
        {
            return visionThetaTrim;
        }

        float VisionOption::getVisionThetaRefProp() const
        {
            return visionThetaRefProp;
        }

        int32_t VisionOption::getNewRawPicture() const
        {
            return newRawPicture;
        }

        float VisionOption::getThetaCapture() const
        {
            return thetaCapture;
        }

        float VisionOption::getPhiCapture() const
        {
            return phiCapture;
        }

        float VisionOption::getPsiCapture() const
        {
            return psiCapture;
        }

        int32_t VisionOption::getAltitudeCapture() const
        {
            return altitudeCapture;
        }

        int32_t VisionOption::getTimeCapture() const
        {
            return timeCapture;
        }

        vector<float> VisionOption::getBodyV() const
        {
            return bodyV;
        }

        float VisionOption::getDeltaPhi() const
        {
            return deltaPhi;
        }

        float VisionOption::getDeltaTheta() const
        {
            return deltaTheta;
        }

        float VisionOption::getDeltaPsi() const
        {
            return deltaPsi;
        }

        int32_t VisionOption::getGoldDefined() const
        {
            return goldDefined;
        }

        int32_t VisionOption::getGoldReset() const
        {
            return goldReset;
        }

        float VisionOption::getGoldX() const
        {
            return goldX;
        }

        float VisionOption::getGoldY() const
        {
            return goldY;
        }
    }
}
