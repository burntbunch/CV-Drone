#include "HdvideoStreamOption.h"

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
        HdvideoStreamOption::HdvideoStreamOption(QByteArray& rawData):
            CuteNavdataOption(static_cast<int>(CuteNavdataOption::Tag::HDVIDEO_STREAM))
        {
            hdvideoState            = decodeHdvideoState(fetchUnsignedInt32(rawData));
            storageFifoNbPackets    = fetchUnsignedInt32(rawData);
            storageFifoSize         = fetchUnsignedInt32(rawData);
            usbkeySize              = fetchUnsignedInt32(rawData);
            usbkeyFreespace         = fetchUnsignedInt32(rawData);
            frameNumber             = fetchUnsignedInt32(rawData);
            usbkeyRemainingTime     = fetchUnsignedInt32(rawData);
        }

        HdvideoStreamOption::HdvideoStreamOption():
            CuteNavdataOption(static_cast<int>(CuteNavdataOption::Tag::HDVIDEO_STREAM))
        {

        }

        HdvideoStreamOption::~HdvideoStreamOption()
        {

        }

        u_int32_t HdvideoStreamOption::decodeHdvideoState(HdvideoStreamOption::HdvideoState state)
        {
            return static_cast<u_int32_t>(state);
        }

        HdvideoStreamOption::HdvideoState HdvideoStreamOption::decodeHdvideoState(u_int32_t state)
        {
            if(state == 0 ||
                    state < 8 ||
                    state > 10)
                return static_cast<HdvideoState>(state);
            return static_cast<HdvideoState>(HdvideoState::NOT_DEFINED);
        }

        HdvideoStreamOption::HdvideoState HdvideoStreamOption::getHdvideoState()
        {
            return hdvideoState;
        }

        u_int32_t HdvideoStreamOption::getStorageFifoNbPackets()
        {
            return storageFifoNbPackets;
        }

        u_int32_t HdvideoStreamOption::getStorageFifoSize()
        {
            return storageFifoSize;
        }

        u_int32_t HdvideoStreamOption::getUsbkeySize()
        {
            return usbkeySize;
        }

        u_int32_t HdvideoStreamOption::getUsbkeyFreespace()
        {
            return usbkeyFreespace;
        }

        u_int32_t HdvideoStreamOption::getFrameNumber()
        {
            return frameNumber;
        }

        u_int32_t HdvideoStreamOption::getUsbkeyRemainingTime()
        {
            return usbkeyRemainingTime;
        }
    }
}
