#ifndef WIFIOPTION_H
#define WIFIOPTION_H

#include <QByteArray>

#include <CuteNavdataOption.h>

namespace Drone
{
    namespace Navdata
    {
        class WifiOption : public CuteNavdataOption
        {
        public:
            WifiOption(QByteArray& rawData);
            WifiOption();
            ~WifiOption();
            float getLinkQuality() const;

        private:
            float linkQuality;
        };
    }
}

#endif // WIFIOPTION_H
