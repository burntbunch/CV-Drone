#ifndef WINDOPTION_H
#define WINDOPTION_H

#include <QByteArray>

#include <CuteNavdataOption.h>

namespace Drone
{
    namespace Navdata
    {
        class WindOption : public CuteNavdataOption
        {
        public:
            WindOption(QByteArray& rawData);
            WindOption();
            ~WindOption();
            float getWindSpeed() const;
            float getWindAngle() const;
            float getWindCompensationTheta() const;
            float getWindCompensationPhi() const;
            float getStateX1() const;
            float getStateX2() const;
            float getStateX3() const;
            float getStateX4() const;
            float getStateX5() const;
            float getStateX6() const;
            float getMagnetoDebug1() const;
            float getMagnetoDebug2() const;
            float getMagnetoDebug3() const;

        private:
            float windSpeed;
            float windAngle;
            float windCompensationTheta;
            float windCompensationPhi;
            float stateX1;
            float stateX2;
            float stateX3;
            float stateX4;
            float stateX5;
            float stateX6;
            float magnetoDebug1;
            float magnetoDebug2;
            float magnetoDebug3;
        };
    }
}

#endif // WINDOPTION_H
