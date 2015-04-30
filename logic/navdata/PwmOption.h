#ifndef PWMOPTION_H
#define PWMOPTION_H

#include <QByteArray>

#include <CuteNavdataOption.h>

namespace Drone
{
    namespace Navdata
    {
        class PwmOption : public CuteNavdataOption
        {
        public:
            PwmOption(QByteArray& rawData);
            PwmOption();
            ~PwmOption();
            u_int8_t getMotor1();
            u_int8_t getMotor2();
            u_int8_t getMotor3();
            u_int8_t getMotor4();
            u_int8_t getSatMotor1();
            u_int8_t getSatMotor2();
            u_int8_t getSatMotor3();
            u_int8_t getSatMotor4();
            float getGazFeedForward();
            float getGazAltitude();
            float getAltitudeIntegral();
            float getVzRef();
            int32_t getuPitch();
            int32_t getuRoll();
            int32_t getuYaw();
            float getYawUI();
            int32_t getuPitchPlanif();
            int32_t getuRollPlanif();
            int32_t getuYawPlanif();
            float getuGazPlanif();
            int16_t getCurrentMotor1();
            int16_t getCurrentMotor2();
            int16_t getCurrentMotor3();
            int16_t getCurrentMotor4();
            float getAltitudeProp();
            float getAltitudeDer();
        private:
            u_int8_t motor1;
            u_int8_t motor2;
            u_int8_t motor3;
            u_int8_t motor4;
            u_int8_t satMotor1;
            u_int8_t satMotor2;
            u_int8_t satMotor3;
            u_int8_t satMotor4;
            float gazFeedForward;
            float gazAltitude;
            float altitudeIntegral;
            float vzRef;
            int32_t uPitch;
            int32_t uRoll;
            int32_t uYaw;
            float yawUI;
            int32_t uPitchPlanif;
            int32_t uRollPlanif;
            int32_t uYawPlanif;
            float uGazPlanif;
            int16_t currentMotor1;
            int16_t currentMotor2;
            int16_t currentMotor3;
            int16_t currentMotor4;
            float altitudeProp;
            float altitudeDer;
        };
    }
}

#endif // PWMOPTION_H
