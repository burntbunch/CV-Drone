#ifndef ADCDATAFRAMEOPTION_H
#define ADCDATAFRAMEOPTION_H

#include <QByteArray>

#include <CuteNavdataOption.h>

namespace Drone
{
    namespace Navdata
    {
        class AdcDataFrameOption : public CuteNavdataOption
        {
        public:
            AdcDataFrameOption(QByteArray& rawData);
            AdcDataFrameOption();
            ~AdcDataFrameOption();
            int getVersion();
            vector<int8_t> getDataFrame();
        private:
            int version;
            vector<int8_t> dataFrame;
        };
    }
}

#endif // ADCDATAFRAMEOPTION_H
