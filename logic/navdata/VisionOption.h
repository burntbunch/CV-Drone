#ifndef VISIONOPTION_H
#define VISIONOPTION_H

#include <QByteArray>

#include <CuteNavdataOption.h>

namespace Drone
{
    namespace Navdata
    {
        class VisionOption : public CuteNavdataOption
        {
        public:
            VisionOption(QByteArray& rawData);
            VisionOption();
            ~VisionOption();
            int32_t getVisionState() const;
            int32_t getVisionMisc() const;
            float getVisionPhiTrim() const;
            float getVisionPhiRefProp() const;
            float getVisionThetaTrim() const;
            float getVisionThetaRefProp() const;
            int32_t getNewRawPicture() const;
            float getThetaCapture() const;
            float getPhiCapture() const;
            float getPsiCapture() const;
            int32_t getAltitudeCapture() const;
            int32_t getTimeCapture() const;
            vector<float> getBodyV() const;
            float getDeltaPhi() const;
            float getDeltaTheta() const;
            float getDeltaPsi() const;
            int32_t getGoldDefined() const;
            int32_t getGoldReset() const;
            float getGoldX() const;
            float getGoldY() const;

        private:
            int32_t         visionState;
            int32_t         visionMisc;
            float           visionPhiTrim;
            float           visionPhiRefProp;
            float           visionThetaTrim;
            float           visionThetaRefProp;
            int32_t         newRawPicture;
            float           thetaCapture;
            float           phiCapture;
            float           psiCapture;
            int32_t         altitudeCapture;
            int32_t         timeCapture;
            vector<float>   bodyV;
            float           deltaPhi;
            float           deltaTheta;
            float           deltaPsi;
            int32_t         goldDefined;
            int32_t         goldReset;
            float           goldX;
            float           goldY;
        };
    }
}

#endif // VISIONOPTION_H
