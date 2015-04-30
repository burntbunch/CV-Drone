#ifndef TRACKERSSENDOPTION_H
#define TRACKERSSENDOPTION_H

#include <QByteArray>

#include <CuteNavdataOption.h>

namespace Drone
{
    namespace Navdata
    {
        class TrackersSendOption : public CuteNavdataOption
        {
        public:
            TrackersSendOption(QByteArray& rawData);
            TrackersSendOption();
            ~TrackersSendOption();
            vector<int32_t> getLocked();
            vector<vector<int32_t>> getPoints();
        private:
            vector<int32_t> locked;
            vector<vector<int32_t>> points;
        };
    }
}

#endif // TRACKERSSENDOPTION_H
