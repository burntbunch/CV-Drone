#ifndef VISIONOFOPTION_H
#define VISIONOFOPTION_H

#include <QByteArray>

#include <CuteNavdataOption.h>

namespace Drone
{
    namespace Navdata
    {
        class VisionOfOption : public CuteNavdataOption
        {
        public:
            VisionOfOption(QByteArray& rawData);
            VisionOfOption();
            ~VisionOfOption();
            vector<float> getOfDx() const;
            vector<float> getOfDy() const;

        private:
            vector<float> ofDx;
            vector<float> ofDy;
        };
    }
}

#endif // VISIONOFOPTION_H
