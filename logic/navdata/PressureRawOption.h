#ifndef PRESSURERAWOPTION_H
#define PRESSURERAWOPTION_H

#include <QByteArray>

#include <CuteNavdataOption.h>

namespace Drone
{
    namespace Navdata
    {
        class PressureRawOption : public CuteNavdataOption
        {
        public:
            PressureRawOption(QByteArray& rawData);
            PressureRawOption();
            ~PressureRawOption();
            int32_t getUp();
            int16_t getUt();
            int32_t getTemperatureMeas();
            int32_t getPressionMeas();
        private:
            int32_t up;
            int16_t ut;
            int32_t temperatureMeas;
            int32_t pressionMeas;
        };
    }
}

#endif // PRESSURERAWOPTION_H
