#ifndef PHYSMEASURESOPTION_H
#define PHYSMEASURESOPTION_H

#include <QByteArray>

#include <CuteNavdataOption.h>

namespace Drone
{
    namespace Navdata
    {
        class PhysMeasuresOption : public CuteNavdataOption
        {
        public:
            PhysMeasuresOption(QByteArray& rawData);
            PhysMeasuresOption();
            ~PhysMeasuresOption();
            float getAccsTemp();
            u_int16_t getGyroTemp();
            vector<float> getPhysAccs();
            vector<float> getPhysGyros();
            u_int32_t getAlim3v3();
            u_int32_t getVrefEpson();
            u_int32_t getVrefIdg();
        private:
            float accsTemp;
            u_int16_t gyroTemp;
            vector<float> physAccs;
            vector<float> physGyros;
            u_int32_t alim3v3;
            u_int32_t vrefEpson;
            u_int32_t vrefIdg;
        };
    }
}

#endif // PHYSMEASURESOPTION_H
