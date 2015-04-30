#ifndef ZIMMU3000OPTION_H
#define ZIMMU3000OPTION_H

#include <QByteArray>

#include <CuteNavdataOption.h>

namespace Drone
{
    namespace Navdata
    {
        class Zimmu3000Option : public CuteNavdataOption
        {
        public:
            Zimmu3000Option(QByteArray& rawData);
            Zimmu3000Option();
            ~Zimmu3000Option();
            int32_t getVzimmuLsb() const;
            float getVzfind() const;

        private:
            int32_t vzimmuLsb;
            float   vzfind;
        };
    }
}

#endif // ZIMMU3000OPTION_H
