#ifndef VISIONPERFOPTION_H
#define VISIONPERFOPTION_H

#include <QByteArray>

#include <CuteNavdataOption.h>

namespace Drone
{
    namespace Navdata
    {
        class VisionPerfOption : public CuteNavdataOption
        {
        public:
            VisionPerfOption(QByteArray& rawData);
            VisionPerfOption();
            ~VisionPerfOption();
            float getTimeSzo() const;
            float getTimeCorners() const;
            float getTimeCompute() const;
            float getTimeTracking() const;
            float getTimeTrans() const;
            float getTimeUpdate() const;
            vector<float> getTimeCustom() const;

        private:
            float           timeSzo;
            float           timeCorners;
            float           timeCompute;
            float           timeTracking;
            float           timeTrans;
            float           timeUpdate;
            vector<float>   timeCustom;
        };
    }
}
#endif // VISIONPERFOPTION_H
