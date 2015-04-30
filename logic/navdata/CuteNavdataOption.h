#ifndef CUTENAVDATAOPTION_H
#define CUTENAVDATAOPTION_H

#include <QObject>
#include <cstdint>
#include <vector>

using std::vector;

namespace Drone
{
    namespace Navdata
    {
        class CuteNavdataOption
        {
        public:
            u_int16_t getTag();
            virtual ~CuteNavdataOption();
            enum class Tag : u_int16_t {
                DEMO            =   0,
                TIME            =   1,
                RAW_MEASURES    =   2,
                PHYS_MEASURES   =   3,
                GYROS_OFFSETS   =   4,
                EULER_ANGLES    =   5,
                REFERENCES      =   6,
                TRIMS           =   7,
                RC_REFERENCES   =   8,
                PWM             =   9,
                ALTITUDE        =   10,
                VISION_RAW      =   11,
                VISION_OF       =   12,
                VISION          =   13,
                VISION_PERF     =   14,
                TRACKERS_SEND   =   15,
                VISION_DETECT   =   16,
                WATCHDOG        =   17,
                ADC_DATA_FRAME  =   18,
                VIDEO_STREAM    =   19,
                GAMES           =   20,
                PRESSURE_RAW    =   21,
                MAGNETO         =   22,
                WIND            =   23,
                KALMAN_PRESSURE =   24,
                HDVIDEO_STREAM  =   25,
                WIFI            =   26,
                ZIMMU_3000      =   27,
                NOT_DEFINED     =   1337, // self defined
                CKS             =   65535
            };

            static u_int16_t decodeTag(Tag tag);
            static Tag decodeTag(u_int16_t tag);

            static bool fetchBool(QByteArray& data);

            static int8_t fetchInt8(QByteArray &data);
            static int16_t fetchInt16(QByteArray &data, bool swapEndian = true);
            static int32_t fetchInt32(QByteArray& data, bool swapEndian = true);

            static u_int8_t fetchUnsignedInt8(QByteArray& data);
            static u_int16_t fetchUnsignedInt16(QByteArray& data, bool swapEndian = true);
            static u_int32_t fetchUnsignedInt32(QByteArray& data, bool swapEndian = true);

            static float fetchFloat(QByteArray& data, bool swapEndian = true);
            static double fetchDouble(QByteArray &data, bool swapEndian = true);

            static vector<int8_t> fetchInt8Vector(QByteArray &data, int length);
            static vector<int16_t> fetchInt16Vector(QByteArray &data, int length, bool swapEndian = true);
            static vector<int32_t> fetchInt32Vector(QByteArray &data, int length, bool swapEndian = true);

            static vector<u_int8_t> fetchUnsignedInt8Vector(QByteArray &data, int length);
            static vector<u_int16_t> fetchUnsignedInt16Vector(QByteArray &data, int length, bool swapEndian = true);
            static vector<u_int32_t> fetchUnsignedInt32Vector(QByteArray &data, int length, bool swapEndian = true);

            static vector<float> fetchFloatVector(QByteArray &data, int length, bool swapEndian = true);
            static vector<vector<float>> fetchFloatMatrix(QByteArray &data, int rows, int columns, bool swapEndian = true);

        protected:
            CuteNavdataOption(u_int16_t tag);
            int tag;
        };
    }
}

#endif // CUTENAVDATAOPTION_H
