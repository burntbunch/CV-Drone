#ifndef DEMOOPTION_H
#define DEMOOPTION_H

#include <QByteArray>

#include <CuteNavdataOption.h>

namespace Drone
{
    namespace Navdata
    {
        class DemoOption : public CuteNavdataOption
        {
        public:
            DemoOption(QByteArray& rawData);
            DemoOption();
            ~DemoOption();
            enum class ControlState : u_int8_t {
                DEFAULT         =   0,
                INIT            =   1,
                LANDED          =   2,
                FLYING          =   3,
                HOVERING        =   4,
                TEST            =   5,
                TRANS_TAKEOFF   =   6,
                TRANS_GOTOFIX   =   7,
                TRANS_LANDING   =   8,
                TRANS_LOOPING   =   9,
                NOT_DEFINED     =   10  // self defined
            };

            enum class FlyingState : u_int8_t {
                LANDED          =   0,
                FLYING          =   1,
                TAKE_OFF        =   2,
                LANDING         =   3,
                NOT_DEFINED     =   4  // self defined
            };

            static u_int8_t decodeControlState(ControlState state);
            static ControlState decodeControlState(u_int8_t state);

            static u_int8_t decodeFlyingState(FlyingState state);
            static FlyingState decodeFlyingState(u_int8_t state);

            static FlyingState mapControlStateToFlyingState(ControlState state);

            ControlState getCtrlState();
            FlyingState getFlyingState();
            u_int32_t getVbatFlyingPercentage();
            float getTheta();
            float getPhi();
            float getPsi();
            int32_t getAltitude();
            float getVx();
            float getVy();
            float getVz();
        private:
            ControlState controlState;
            FlyingState flyingState;
            u_int32_t vbatFlyingPercentage;
            float theta;
            float phi;
            float psi;
            int32_t altitude;
            float vx;
            float vy;
            float vz;
        };
    }
}

#endif // DEMOOPTION_H
