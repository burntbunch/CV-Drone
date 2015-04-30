#ifndef WATCHDOGOPTION_H
#define WATCHDOGOPTION_H

#include <QByteArray>

#include <CuteNavdataOption.h>

namespace Drone
{
    namespace Navdata
    {
        class WatchdogOption : public CuteNavdataOption
        {
        public:
            WatchdogOption(QByteArray& rawData);
            WatchdogOption();
            ~WatchdogOption();
            int32_t getWatchdog() const;

        private:
            int32_t watchdog;
        };
    }
}

#endif // WATCHDOGOPTION_H
