#ifndef MAGNETOOPTION_H
#define MAGNETOOPTION_H

#include <QByteArray>

#include <CuteNavdataOption.h>

namespace Drone
{
    namespace Navdata
    {
        class MagnetoOption : public CuteNavdataOption
        {
        public:
            MagnetoOption(QByteArray& rawData);
            MagnetoOption();
            ~MagnetoOption();
            int16_t getMx();
            int16_t getMy();
            int16_t getMz();
            vector<float> getMagnetoRaw();
            vector<float> getMagnetoRectified();
            vector<float> getMagnetoOffset();
            float getHeadingUnwrapped();
            float getHeadingGyroUnwrapped();
            float getHeadingFusionUnwrapped();
            u_int16_t getMagnetoCalibrationOk();
            u_int32_t getMagnetoState();
            float getMagnetoRadius();
            float getErrorMean();
            float getErrorVar();
        private:
            int16_t mx;
            int16_t my;
            int16_t mz;
            vector<float> magnetoRaw;
            vector<float> magnetoRectified;
            vector<float> magnetoOffset;
            float headingUnwrapped;
            float headingGyroUnwrapped;
            float headingFusionUnwrapped;
            u_int16_t magnetoCalibrationOk; //Java char
            u_int32_t magnetoState;
            float magnetoRadius;
            float errorMean;
            float errorVar;
        };
    }
}

#endif // MAGNETOOPTION_H
