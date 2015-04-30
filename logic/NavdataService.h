#ifndef NAVDATASERVICE_H
#define NAVDATASERVICE_H

#include <QObject>
#include <QUdpSocket>
#include <QByteArray>

#include <CuteService.h>
#include <navdata/CuteNavdataOption.h>

#include <navdata/AdcDataFrameOption.h>
#include <navdata/AltitudeOption.h>
#include <navdata/CksOption.h>
#include <navdata/DemoOption.h>
#include <navdata/EulerAnglesOption.h>
#include <navdata/GamesOption.h>
#include <navdata/GyrosOffsetsOption.h>
#include <navdata/HdvideoStreamOption.h>
#include <navdata/KalmanPressureOption.h>
#include <navdata/MagnetoOption.h>
#include <navdata/PhysMeasuresOption.h>
#include <navdata/PressureRawOption.h>
#include <navdata/PwmOption.h>
#include <navdata/RawMeasuresOption.h>
#include <navdata/RcReferencesOption.h>
#include <navdata/ReferencesOption.h>
#include <navdata/TimeOption.h>
#include <navdata/TrackersSendOption.h>
#include <navdata/TrimsOption.h>
#include <navdata/VideoStreamOption.h>
#include <navdata/VisionDetectOption.h>
#include <navdata/VisionOfOption.h>
#include <navdata/VisionOption.h>
#include <navdata/VisionPerfOption.h>
#include <navdata/VisionRawOption.h>
#include <navdata/WatchdogOption.h>
#include <navdata/WifiOption.h>
#include <navdata/WindOption.h>
#include <navdata/Zimmu3000Option.h>

using namespace Drone::Navdata;

namespace Drone
{
    class NavdataService : public CuteService
    {
        Q_OBJECT
    public:
        explicit NavdataService(QString droneIP, int port, QObject *parent = 0);

        enum class DroneState : u_int8_t
        {
                    FLYING                          = 0,
                    VIDEO_ENABLED                   = 1,
                    VISION_ENABLED                  = 2,
                    CONTROL_ALGORITHM               = 3,
                    ALTITUDE_CONTROL_ALGORITHM      = 4,
                    START_BUTTON_STATE              = 5,
                    CONTROL_COMMAND_ACK             = 6,
                    CAMERA_READY                    = 7,
                    TRAVELLING_ENABLED              = 8,
                    USB_READY                       = 9,
                    NAVDATA_DEMO                    = 10,
                    NAVDATA_BOOTSTRAP               = 11,
                    MOTOR_PROBLEM                   = 12,
                    COMMUNICATION_LOST              = 13,
                    SOFTWARE_FAULT                  = 14,
                    LOW_BATTERY                     = 15,
                    USER_EMERGENCY_LANDING          = 16,
                    TIMER_ELAPSED                   = 17,
                    MAGNOMETER_NEEDS_CALIBRATION    = 18,
                    ANGLES_OUT_OF_RANGE             = 19,
                    TOO_MUCH_WIND                   = 20,
                    ULTRASONIC_SENSOR_DEAF          = 21,
                    CUTOUT_DETECTED                 = 22,
                    PIC_VERSION_NUMBER_OK           = 23,
                    AT_CODEC_THREAD_ON              = 24,
                    NAVDATA_THREAD_ON               = 25,
                    VIDEO_THREAD_ON                 = 26,
                    ACQUISITION_THREAD_ON           = 27,
                    CONTROL_WATCHDOG_DELAY          = 28,
                    ADC_WATCHDOG_DELAY              = 29,
                    COM_WATCHDOG_PROBLEM            = 30,
                    EMERGENCY_LANDING               = 31,
                    NOT_DEFINED                     = 32
        };

        u_int8_t decodeDroneState(DroneState state);
        DroneState decodeDroneState(u_int8_t state);

        ~NavdataService();
    private:
        QUdpSocket* socket;
        u_int32_t lastSequence;
        bool isConnected, wasConnected;
        bool isListening;

        CuteNavdataOption* decodeNavdataOption(CuteNavdataOption::Tag tag, QByteArray& rawData);
        void emitNavdataOption(CuteNavdataOption* option);

    signals:
        void nextAdcDataFrameOptionReady(AdcDataFrameOption option);
        void nextAltitudeOptionReady(AltitudeOption option);
        void nextCksOptionReady(CksOption option);
        void nextDemoOptionReady(DemoOption option);
        void nextEulerAnglesOptionReady(EulerAnglesOption option);
        void nextGamesOptionReady(GamesOption option);
        void nextGyrosOffsetsOptionReady(GyrosOffsetsOption option);
        void nextHdvideoStreamOptionReady(HdvideoStreamOption option);
        void nextKalmanPressureOptionReady(KalmanPressureOption option);
        void nextMagnetoOptionReady(MagnetoOption option);
        void nextPhysMeasuresOptionReady(PhysMeasuresOption option);
        void nextPressureRawOptionReady(PressureRawOption option);
        void nextPwmOptionReady(PwmOption option);
        void nextRawMeasuresOptionReady(RawMeasuresOption option);
        void nextRcReferencesOptionReady(RcReferencesOption option);
        void nextReferencesOptionReady(ReferencesOption option);
        void nextTimeOptionReady(TimeOption option);
        void nextTrackersSendOptionReady(TrackersSendOption option);
        void nextTrimsOptionReady(TrimsOption option);
        void nextVideoStreamOptionReady(VideoStreamOption option);
        void nextVisionDetectOptionReady(VisionDetectOption option);
        void nextVisionOfOptionReady(VisionOfOption option);
        void nextVisionOptionReady(VisionOption option);
        void nextVisionPerfOptionReady(VisionPerfOption option);
        void nextVisionRawOptionReady(VisionRawOption option);
        void nextWatchdogOptionReady(WatchdogOption option);
        void nextWifiOptionReady(WifiOption option);
        void nextWindOptionReady(WindOption option);
        void nextZimmu3000OptionReady(Zimmu3000Option option);

        void gotInvalidPackage();
        void nextDroneState(DroneState state);
        void nextVisionDefined(bool defined);
        void gotUnknownOption();

        void connectionStatusChanged(bool connected);
    public slots:
        void start() override;
        void stop() override;
        void reconnect();
    private slots:
        void sendClientHello();
        void receivedNewData();
        void checkConnected();
        void toggleListening();
    };
}

#endif // NAVDATASERVICE_H
