#ifndef CKSOPTION_H
#define CKSOPTION_H

#include <QByteArray>

#include <CuteNavdataOption.h>

namespace Drone
{
    namespace Navdata
    {
        class CksOption : public CuteNavdataOption
        {
        public:
            CksOption(QByteArray& rawData);
            CksOption();
            ~CksOption();
            u_int32_t getCks();
        private:
            u_int32_t cks;
        };
    }
}

#endif // CKSOPTION_H
