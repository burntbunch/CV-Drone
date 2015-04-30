#ifndef KALMANPRESSUREOPTION_H
#define KALMANPRESSUREOPTION_H

#include <QByteArray>

#include <CuteNavdataOption.h>

namespace Drone
{
    namespace Navdata
    {
        class KalmanPressureOption : public CuteNavdataOption
        {
        public:
            KalmanPressureOption(QByteArray& rawData);
            KalmanPressureOption();
            ~KalmanPressureOption();
            float getOffsetPressure();
            float getEstZ();
            float getEstZdot();
            float getEstBiasPwm();
            float getEstBiaisPression();
            float getOffsetUs();
            float getPredictionUs();
            float getCovAlt();
            float getCovPwm();
            float getCovVitesse();
            bool isBoolEffetSol();
            float getSommeInno();
            bool isFlagRejetUs();
            float getuMultisinus();
            float getGazAltitude();
            bool isFlagMultisinus();
            bool isFlagMultisinusDebut();
        private:
            float offsetPressure;
            float estZ;
            float estZdot;
            float estBiasPwm;
            float estBiaisPression;
            float offsetUs;
            float predictionUs;
            float covAlt;
            float covPwm;
            float covVitesse;
            bool boolEffetSol;
            float sommeInno;
            bool flagRejetUs;
            float uMultisinus;
            float gazAltitude;
            bool flagMultisinus;
            bool flagMultisinusDebut;
        };
    }
}

#endif // KALMANPRESSUREOPTION_H
