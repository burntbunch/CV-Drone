#ifndef VISIONDETECTOPTION_H
#define VISIONDETECTOPTION_H

#include <QByteArray>

#include <CuteNavdataOption.h>

namespace Drone
{
    namespace Navdata
    {
        class VisionDetectOption : public CuteNavdataOption
        {
        public:
            VisionDetectOption(QByteArray& rawData);
            VisionDetectOption();
            ~VisionDetectOption();
            u_int32_t getNbDetected() const;
            vector<u_int32_t> getType() const;
            vector<u_int32_t> getXc() const;
            vector<u_int32_t> getYc() const;
            vector<u_int32_t> getWidth() const;
            vector<u_int32_t> getHeight() const;
            vector<u_int32_t> getDistance() const;
            vector<float> getOrientationAngle() const;
            vector<vector<vector<float> > > getRotation() const;
            vector<vector<float> > getTranslation() const;
            vector<u_int32_t> getCameraSource() const;

        private:
            u_int32_t                       nbDetected;
            vector<u_int32_t>               type;
            vector<u_int32_t>               xc;
            vector<u_int32_t>               yc;
            vector<u_int32_t>               width;
            vector<u_int32_t>               height;
            vector<u_int32_t>               distance;
            vector<float>                   orientationAngle;
            vector<vector<vector<float>>>   rotation;
            vector<vector<float>>           translation;
            vector<u_int32_t>               cameraSource;
        };
    }
}

#endif // VISIONDETECTOPTION_H
