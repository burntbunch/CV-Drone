#ifndef RCREFERENCESOPTION_H
#define RCREFERENCESOPTION_H

#include <QByteArray>

#include <CuteNavdataOption.h>

namespace Drone
{
    namespace Navdata
    {
        class RcReferencesOption : public CuteNavdataOption
        {
        public:
            RcReferencesOption(QByteArray& rawData);
            RcReferencesOption();
            ~RcReferencesOption();
            int32_t getRcRefPitch();
            int32_t getRcRefRoll();
            int32_t getRcRefYaw();
            int32_t getRcRefGaz();
            int32_t getRcRefAg();
        private:
            int32_t rcRefPitch;
            int32_t rcRefRoll;
            int32_t rcRefYaw;
            int32_t rcRefGaz;
            int32_t rcRefAg;
        };
    }
}

#endif // RCREFERENCESOPTION_H
