#include <QMetaType>
#include <opencv2/opencv.hpp>

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

Q_DECLARE_METATYPE(cv::Mat)
Q_DECLARE_METATYPE(Drone::Navdata::AdcDataFrameOption)
Q_DECLARE_METATYPE(Drone::Navdata::AltitudeOption)
Q_DECLARE_METATYPE(Drone::Navdata::CksOption)
Q_DECLARE_METATYPE(Drone::Navdata::DemoOption)
Q_DECLARE_METATYPE(Drone::Navdata::EulerAnglesOption)
Q_DECLARE_METATYPE(Drone::Navdata::GamesOption)
Q_DECLARE_METATYPE(Drone::Navdata::GyrosOffsetsOption)
Q_DECLARE_METATYPE(Drone::Navdata::HdvideoStreamOption)
Q_DECLARE_METATYPE(Drone::Navdata::KalmanPressureOption)
Q_DECLARE_METATYPE(Drone::Navdata::MagnetoOption)
Q_DECLARE_METATYPE(Drone::Navdata::PhysMeasuresOption)
Q_DECLARE_METATYPE(Drone::Navdata::PressureRawOption)
Q_DECLARE_METATYPE(Drone::Navdata::PwmOption)
Q_DECLARE_METATYPE(Drone::Navdata::RawMeasuresOption)
Q_DECLARE_METATYPE(Drone::Navdata::RcReferencesOption)
Q_DECLARE_METATYPE(Drone::Navdata::ReferencesOption)
Q_DECLARE_METATYPE(Drone::Navdata::TimeOption)
Q_DECLARE_METATYPE(Drone::Navdata::TrackersSendOption)
Q_DECLARE_METATYPE(Drone::Navdata::TrimsOption)
Q_DECLARE_METATYPE(Drone::Navdata::VideoStreamOption)
Q_DECLARE_METATYPE(Drone::Navdata::VisionDetectOption)
Q_DECLARE_METATYPE(Drone::Navdata::VisionOfOption)
Q_DECLARE_METATYPE(Drone::Navdata::VisionOption)
Q_DECLARE_METATYPE(Drone::Navdata::VisionPerfOption)
Q_DECLARE_METATYPE(Drone::Navdata::VisionRawOption)
Q_DECLARE_METATYPE(Drone::Navdata::WatchdogOption)
Q_DECLARE_METATYPE(Drone::Navdata::WifiOption)
Q_DECLARE_METATYPE(Drone::Navdata::WindOption)
Q_DECLARE_METATYPE(Drone::Navdata::Zimmu3000Option)

namespace Provision
{
    /*!
     * \brief initQMetaTypes
     * This functions adds our custom data types the QT meta object types.
     */
    void initQMetaTypes()
    {
        qRegisterMetaType<cv::Mat>("cv::Mat&");
        qRegisterMetaType<Drone::Navdata::AdcDataFrameOption>("AdcDataFrameOption");
        qRegisterMetaType<Drone::Navdata::AltitudeOption>("AltitudeOption");
        qRegisterMetaType<Drone::Navdata::CksOption>("CksOption");
        qRegisterMetaType<Drone::Navdata::DemoOption>("DemoOption");
        qRegisterMetaType<Drone::Navdata::EulerAnglesOption>("EulerAnglesOption");
        qRegisterMetaType<Drone::Navdata::GamesOption>("GamesOption");
        qRegisterMetaType<Drone::Navdata::GyrosOffsetsOption>("GyrosOffsetsOption");
        qRegisterMetaType<Drone::Navdata::HdvideoStreamOption>("HdvideoStreamOption");
        qRegisterMetaType<Drone::Navdata::KalmanPressureOption>("KalmanPressureOption");
        qRegisterMetaType<Drone::Navdata::MagnetoOption>("MagnetoOption");
        qRegisterMetaType<Drone::Navdata::PhysMeasuresOption>("PhysMeasuresOption");
        qRegisterMetaType<Drone::Navdata::PressureRawOption>("PressureRawOption");
        qRegisterMetaType<Drone::Navdata::PwmOption>("PwmOption");
        qRegisterMetaType<Drone::Navdata::RawMeasuresOption>("RawMeasuresOption");
        qRegisterMetaType<Drone::Navdata::RcReferencesOption>("RcReferencesOption");
        qRegisterMetaType<Drone::Navdata::ReferencesOption>("ReferencesOption");
        qRegisterMetaType<Drone::Navdata::TimeOption>("TimeOption");
        qRegisterMetaType<Drone::Navdata::TrackersSendOption>("TrackersSendOption");
        qRegisterMetaType<Drone::Navdata::TrimsOption>("TrimsOption");
        qRegisterMetaType<Drone::Navdata::VideoStreamOption>("VideoStreamOption");
        qRegisterMetaType<Drone::Navdata::VisionDetectOption>("VisionDetectOption");
        qRegisterMetaType<Drone::Navdata::VisionOfOption>("VisionOfOption");
        qRegisterMetaType<Drone::Navdata::VisionOption>("VisionOption");
        qRegisterMetaType<Drone::Navdata::VisionPerfOption>("VisionPerfOption");
        qRegisterMetaType<Drone::Navdata::VisionRawOption>("VisionRawOption");
        qRegisterMetaType<Drone::Navdata::WatchdogOption>("WatchdogOption");
        qRegisterMetaType<Drone::Navdata::WifiOption>("WifiOption");
        qRegisterMetaType<Drone::Navdata::WindOption>("WindOption");
        qRegisterMetaType<Drone::Navdata::Zimmu3000Option>("Zimmu3000Option");
    }
}
