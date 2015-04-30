#ifndef VISIONRAWOPTION_H
#define VISIONRAWOPTION_H

#include <QByteArray>

#include <CuteNavdataOption.h>

namespace Drone
{
    namespace Navdata
    {
        class VisionRawOption : public CuteNavdataOption
        {
        public:
            VisionRawOption(QByteArray& rawData);
            VisionRawOption();
            ~VisionRawOption();
            float getVisionTxRaw() const;
            float getVisionTyRaw() const;
            float getVisionTzRaw() const;

        private:
            float visionTxRaw;
            float visionTyRaw;
            float visionTzRaw;
        };
    }
}

#endif // VISIONRAWOPTION_H
