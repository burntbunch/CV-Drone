#include "VideoStreamOption.h"

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
        VideoStreamOption::VideoStreamOption(QByteArray& rawData):
            CuteNavdataOption(static_cast<int>(CuteNavdataOption::Tag::VIDEO_STREAM))
        {
            quant           = fetchUnsignedInt8(rawData);
            frameSize       = fetchUnsignedInt32(rawData);
            frameNumber     = fetchUnsignedInt32(rawData);
            atcmdRefSeq     = fetchUnsignedInt32(rawData);
            atcmdMeanRefGap = fetchUnsignedInt32(rawData);
            atcmdVarRefGap  = fetchFloat(rawData);
            atcmdRefQuality = fetchUnsignedInt32(rawData);
            outBitrate      = fetchUnsignedInt32(rawData);
            desiredBitrate  = fetchUnsignedInt32(rawData);
            data1           = fetchInt32(rawData);
            data2           = fetchInt32(rawData);
            data3           = fetchInt32(rawData);
            data4           = fetchInt32(rawData);
            data5           = fetchInt32(rawData);
            tcpQueueLevel   = fetchUnsignedInt32(rawData);
            fifoQueueLevel  = fetchUnsignedInt32(rawData);
        }

        VideoStreamOption::VideoStreamOption():
            CuteNavdataOption(static_cast<int>(CuteNavdataOption::Tag::VIDEO_STREAM))
        {

        }

        VideoStreamOption::~VideoStreamOption()
        {

        }

        u_int8_t VideoStreamOption::getQuant()
        {
            return quant;
        }

        u_int32_t VideoStreamOption::getFrameSize()
        {
            return frameSize;
        }

        u_int32_t VideoStreamOption::getFrameNumber()
        {
            return frameNumber;
        }

        u_int32_t VideoStreamOption::getAtcmdRefSeq()
        {
            return atcmdRefSeq;
        }

        u_int32_t VideoStreamOption::getAtcmdMeanRefGap()
        {
            return atcmdMeanRefGap;
        }

        float VideoStreamOption::getAtcmdVarRefGap()
        {
            return atcmdVarRefGap;
        }

        u_int32_t VideoStreamOption::getAtcmdRefQuality()
        {
            return atcmdRefQuality;
        }

        u_int32_t VideoStreamOption::getOutBitrate()
        {
            return outBitrate;
        }

        u_int32_t VideoStreamOption::getDesiredBitrate()
        {
            return desiredBitrate;
        }

        int32_t VideoStreamOption::getData1()
        {
            return data1;
        }

        int32_t VideoStreamOption::getData2()
        {
            return data2;
        }

        int32_t VideoStreamOption::getData3()
        {
            return data3;
        }

        int32_t VideoStreamOption::getData4()
        {
            return data4;
        }

        int32_t VideoStreamOption::getData5()
        {
            return data5;
        }

        u_int32_t VideoStreamOption::getTcpQueueLevel()
        {
            return tcpQueueLevel;
        }

        u_int32_t VideoStreamOption::getFifoQueueLevel()
        {
            return fifoQueueLevel;
        }
    }
}
