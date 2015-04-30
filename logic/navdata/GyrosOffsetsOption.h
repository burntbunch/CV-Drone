#ifndef GYROSOFFSETSOPTION_H
#define GYROSOFFSETSOPTION_H

#include <QByteArray>

#include <CuteNavdataOption.h>

namespace Drone
{
    namespace Navdata
    {
        class GyrosOffsetsOption : public CuteNavdataOption
        {
        public:
            GyrosOffsetsOption(QByteArray& rawData);
            GyrosOffsetsOption();
            ~GyrosOffsetsOption();
            vector<float> getOffsetG();
        private:
            vector<float> offsetG;
        };
    }
}

#endif // GYROSOFFSETSOPTION_H
