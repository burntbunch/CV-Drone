#ifndef EULERANGLESOPTION_H
#define EULERANGLESOPTION_H

#include <QByteArray>

#include <CuteNavdataOption.h>

namespace Drone
{
    namespace Navdata
    {
        class EulerAnglesOption : public CuteNavdataOption
        {
        public:
            EulerAnglesOption(QByteArray& rawData);
            EulerAnglesOption();
            ~EulerAnglesOption();
            float getThetaA();
            float getPhiA();
        private:
            float thetaA;
            float phiA;
        };
    }
}

#endif // EULERANGLESOPTION_H
