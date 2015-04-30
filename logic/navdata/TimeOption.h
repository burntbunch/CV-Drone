#ifndef TIMEOPTION_H
#define TIMEOPTION_H

#include <QByteArray>

#include <CuteNavdataOption.h>

namespace Drone
{
    namespace Navdata
    {
        class TimeOption : public CuteNavdataOption
        {
        public:
            TimeOption(QByteArray& rawData);
            TimeOption();
            ~TimeOption();
            u_int32_t getTime();
        private:
            u_int32_t time;
        };
    }
}

#endif // TIMEOPTION_H
