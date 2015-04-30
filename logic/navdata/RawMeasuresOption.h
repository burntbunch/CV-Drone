#ifndef RAWMEASURESOPTION_H
#define RAWMEASURESOPTION_H

#include <QByteArray>

#include <CuteNavdataOption.h>

namespace Drone
{
    namespace Navdata
    {
        class RawMeasuresOption : public CuteNavdataOption
        {
        public:
            RawMeasuresOption(QByteArray& rawData);
            RawMeasuresOption();
            ~RawMeasuresOption();
            vector<u_int16_t> getRawAccs();
            vector<int16_t> getRawGyros();
            vector<int16_t> getRawGyros110();
            u_int16_t getVbatRaw();
            u_int16_t getUsDebutEcho();
            u_int16_t getUsFinEcho();
            u_int16_t getUsAssociationEcho();
            u_int16_t getUsDistanceEcho();
            u_int16_t getUsCourbeTemps();
            u_int16_t getUsCourbeValeur();
            u_int16_t getUsCourbeRef();
            u_int16_t getFlagEchoIni();
            u_int16_t getNbEcho();
            u_int32_t getSumEcho();
            int32_t getAltTempRaw();
            int16_t getGradient();
        private:
            vector<u_int16_t> rawAccs;
            vector<int16_t> rawGyros;
            vector<int16_t> rawGyros110;
            u_int16_t vbatRaw;
            u_int16_t usDebutEcho;
            u_int16_t usFinEcho;
            u_int16_t usAssociationEcho;
            u_int16_t usDistanceEcho;
            u_int16_t usCourbeTemps;
            u_int16_t usCourbeValeur;
            u_int16_t usCourbeRef;
            u_int16_t flagEchoIni;
            u_int16_t nbEcho;
            u_int32_t sumEcho;
            int32_t altTempRaw;
            int16_t gradient;
        };
    }
}

#endif // RAWMEASURESOPTION_H
