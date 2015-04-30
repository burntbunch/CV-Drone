#ifndef GAMESOPTION_H
#define GAMESOPTION_H

#include <QByteArray>

#include <CuteNavdataOption.h>

namespace Drone
{
    namespace Navdata
    {
        class GamesOption : public CuteNavdataOption
        {
        public:
            GamesOption(QByteArray& rawData);
            GamesOption();
            ~GamesOption();
            u_int32_t getDoubleTapCounter();
            u_int32_t getFinishLineCounter();
        private:
            u_int32_t doubleTapCounter;
            u_int32_t finishLineCounter;
        };
    }
}

#endif // GAMESOPTION_H
