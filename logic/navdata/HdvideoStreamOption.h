#ifndef HDVIDEOSTREAMOPTION_H
#define HDVIDEOSTREAMOPTION_H

#include <QByteArray>

#include <CuteNavdataOption.h>

namespace Drone
{
    namespace Navdata
    {
        class HdvideoStreamOption : public CuteNavdataOption
        {
        public:
            HdvideoStreamOption(QByteArray& rawData);
            HdvideoStreamOption();
            ~HdvideoStreamOption();
            enum class HdvideoState : u_int32_t {
                STORAGE_FIFO_IS_FULL    =   0,
                USBKEY_IS_PRESENT       =   8,
                USBKEY_IS_RECORDING     =   9,
                USBKEY_IS_FULL          =   10,
                NOT_DEFINED             =   1337    // self defined
            };

            static u_int32_t decodeHdvideoState(HdvideoState state);
            static HdvideoState decodeHdvideoState(u_int32_t state);

            HdvideoState getHdvideoState();
            u_int32_t getStorageFifoNbPackets();
            u_int32_t getStorageFifoSize();
            u_int32_t getUsbkeySize();
            u_int32_t getUsbkeyFreespace();
            u_int32_t getFrameNumber();
            u_int32_t getUsbkeyRemainingTime();
        private:
            HdvideoState hdvideoState;
            u_int32_t storageFifoNbPackets;
            u_int32_t storageFifoSize;
            u_int32_t usbkeySize;
            u_int32_t usbkeyFreespace;
            u_int32_t frameNumber;
            u_int32_t usbkeyRemainingTime;
        };
    }
}

#endif // HDVIDEOSTREAMOPTION_H
