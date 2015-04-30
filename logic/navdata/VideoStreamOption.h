#ifndef VIDEOSTREAMOPTION_H
#define VIDEOSTREAMOPTION_H

#include <QByteArray>

#include <CuteNavdataOption.h>

namespace Drone
{
    namespace Navdata
    {
        class VideoStreamOption : public CuteNavdataOption
        {
        public:
            VideoStreamOption(QByteArray& rawData);
            VideoStreamOption();
            ~VideoStreamOption();
            u_int8_t getQuant();
            u_int32_t getFrameSize();
            u_int32_t getFrameNumber();
            u_int32_t getAtcmdRefSeq();
            u_int32_t getAtcmdMeanRefGap();
            float getAtcmdVarRefGap();
            u_int32_t getAtcmdRefQuality();
            u_int32_t getOutBitrate();
            u_int32_t getDesiredBitrate();
            int32_t getData1();
            int32_t getData2();
            int32_t getData3();
            int32_t getData4();
            int32_t getData5();
            u_int32_t getTcpQueueLevel();
            u_int32_t getFifoQueueLevel();
        private:
            u_int8_t quant;
            u_int32_t frameSize;
            u_int32_t frameNumber;
            u_int32_t atcmdRefSeq;
            u_int32_t atcmdMeanRefGap;
            float atcmdVarRefGap;
            u_int32_t atcmdRefQuality;
            u_int32_t outBitrate;
            u_int32_t desiredBitrate;
            int32_t data1;
            int32_t data2;
            int32_t data3;
            int32_t data4;
            int32_t data5;
            u_int32_t tcpQueueLevel;
            u_int32_t fifoQueueLevel;
        };
    }
}

#endif // VIDEOSTREAMOPTION_H
