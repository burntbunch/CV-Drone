#ifndef TRIMSOPTION_H
#define TRIMSOPTION_H

#include <QByteArray>

#include <CuteNavdataOption.h>

namespace Drone
{
    namespace Navdata
    {
        class TrimsOption : public CuteNavdataOption
        {
        public:
            TrimsOption(QByteArray& rawData);
            TrimsOption();
            ~TrimsOption();
            float getAngularRatesTrimR();
            float getEulerAnglesTrimTheta();
            float getEulerAnglesTrimPhi();
        private:
            float angularRatesTrimR;
            float eulerAnglesTrimTheta;
            float eulerAnglesTrimPhi;
        };
    }
}

#endif // TRIMSOPTION_H
