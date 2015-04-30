#ifndef REFERENCESOPTION_H
#define REFERENCESOPTION_H

#include <QByteArray>

#include <CuteNavdataOption.h>

namespace Drone
{
    namespace Navdata
    {
        class ReferencesOption : public CuteNavdataOption
        {
        public:
            ReferencesOption(QByteArray& rawData);
            ReferencesOption();
            ~ReferencesOption();
            int32_t getRefTheta();
            int32_t getRefPhi();
            int32_t getRefThetaI();
            int32_t getRefPhiI();
            int32_t getRefPitch();
            int32_t getRefRoll();
            int32_t getRefYaw();
            int32_t getRefPsi();
            float getVxRef();
            float getVyRef();
            float getThetaMod();
            float getPhiMod();
            float getkVX();
            float getkVY();
            u_int32_t getkMode();
            float getUiTime();
            float getUiTheta();
            float getUiPhi();
            float getUiPsi();
            float getUiPsiAccuracy();
            int32_t getUiSeq();
        private:
            int32_t refTheta;
            int32_t refPhi;
            int32_t refThetaI;
            int32_t refPhiI;
            int32_t refPitch;
            int32_t refRoll;
            int32_t refYaw;
            int32_t refPsi;
            float vxRef;
            float vyRef;
            float thetaMod;
            float phiMod;
            float kVX;
            float kVY;
            u_int32_t kMode;
            float uiTime;
            float uiTheta;
            float uiPhi;
            float uiPsi;
            float uiPsiAccuracy;
            int32_t uiSeq;
        };
    }
}

#endif // REFERENCESOPTION_H
