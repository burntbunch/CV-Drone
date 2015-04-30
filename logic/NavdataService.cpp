#include "NavdataService.h"

/*
 * CV-Drone
 * Copyright (C) 2015 www.burntbunch.org
 *
 * This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation; either version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License along with this library;
 * if not, write to the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110, USA
 */

namespace Drone
{
    /*!
     * \brief NavdataService::NavdataService The service will provide the Navdata from the drone.
     * \param droneIP the ip of the drone
     * \param port the port number of the video port
     * \param parent QObject parent
     *
     * Received options can be accessed by the signals. The service has a throttle to receive only in a 50ms interval.
     */
    NavdataService::NavdataService(QString droneIP, int port, QObject *parent) :
        CuteService(droneIP, port, parent)
    {
        socket = new QUdpSocket(this);
        timer->setInterval(50);
        lastSequence = 0;
        wasConnected = false;
        isConnected = false;
        isListening = false;

        connect(socket,         SIGNAL(readyRead()),    this,   SLOT(receivedNewData()));
        connect(workerThread,   SIGNAL(started()),      this,   SLOT(sendClientHello()));

        connect(timer,          SIGNAL(timeout()),      this,   SLOT(checkConnected()));
        connect(workerThread,   SIGNAL(started()),      timer,  SLOT(start()));

        connect(timer,          SIGNAL(timeout()),      this,   SLOT(toggleListening()));

        if(!socket->bind(QHostAddress::Any, port))
            if(verbose)
                emit nextVerboseString("Couldn't bind socket!");

    }

    NavdataService::~NavdataService()
    {
        stop();
        if(verbose)
            emit nextVerboseString("NavdataService destroyed");
    }

    /*!
     * \brief NavdataService::decodeDroneState Returns the value of the enum.
     * \param state the enum
     * \return
     */
    u_int8_t NavdataService::decodeDroneState(NavdataService::DroneState state)
    {
        return static_cast<u_int8_t>(state);
    }

    /*!
     * \brief NavdataService::decodeDroneState Tries to find an enum for the given value.
     * \param state the value
     * \return NOT_DEFINED if the value couldn't be found.
     */
    NavdataService::DroneState NavdataService::decodeDroneState(u_int8_t state)
    {
        if(state < 32)
            return static_cast<DroneState>(state);
        return DroneState::NOT_DEFINED;
    }

    /*!
     * \brief NavdataService::decodeNavdataOption Tries to create a NavdataOption.
     * \param tag the type (enum) of option
     * \param rawData the byte-array with the values
     * \return a pointer to the created option. Return an UnkownOption if the type is invalid.
     */
    CuteNavdataOption* NavdataService::decodeNavdataOption(CuteNavdataOption::Tag tag, QByteArray &rawData)
    {
        switch (tag) {
        case CuteNavdataOption::Tag::ADC_DATA_FRAME:
            if(verbose)
                emit nextVerboseString("Got an AdcDataFrameOption");
            return new AdcDataFrameOption(rawData);
        case CuteNavdataOption::Tag::ALTITUDE:
            if(verbose)
                emit nextVerboseString("Got an AltitudeOption");
            return new AltitudeOption(rawData);
        case CuteNavdataOption::Tag::DEMO:
            if(verbose)
                emit nextVerboseString("Got a DemoOption");
            return new DemoOption(rawData);
        case CuteNavdataOption::Tag::EULER_ANGLES:
            if(verbose)
                emit nextVerboseString("Got an EulerAnglesOption");
            return new EulerAnglesOption(rawData);
        case CuteNavdataOption::Tag::GAMES:
            if(verbose)
                emit nextVerboseString("Got a GamesOption");
            return new GamesOption(rawData);
        case CuteNavdataOption::Tag::GYROS_OFFSETS:
            if(verbose)
                emit nextVerboseString("Got a GyrosOffsetsOption");
            return new GyrosOffsetsOption(rawData);
        case CuteNavdataOption::Tag::HDVIDEO_STREAM:
            if(verbose)
                emit nextVerboseString("Got a HdvideoStreamOption");
            return new HdvideoStreamOption(rawData);
        case CuteNavdataOption::Tag::KALMAN_PRESSURE:
            if(verbose)
                emit nextVerboseString("Got a KalmanPressureOption");
            return new KalmanPressureOption(rawData);
        case CuteNavdataOption::Tag::MAGNETO:
            if(verbose)
                emit nextVerboseString("Got a MagnetoOption");
            return new MagnetoOption(rawData);
        case CuteNavdataOption::Tag::PHYS_MEASURES:
            if(verbose)
                emit nextVerboseString("Got a PhysMeasuresOption");
            return new PhysMeasuresOption(rawData);
        case CuteNavdataOption::Tag::PRESSURE_RAW:
            if(verbose)
                emit nextVerboseString("Got a PressureRawOption");
            return new PressureRawOption(rawData);
        case CuteNavdataOption::Tag::PWM:
            if(verbose)
                emit nextVerboseString("Got a PwmOption");
            return new PwmOption(rawData);
        case CuteNavdataOption::Tag::RAW_MEASURES:
            if(verbose)
                emit nextVerboseString("Got a RawMeasuresOption");
            return new RawMeasuresOption(rawData);
        case CuteNavdataOption::Tag::RC_REFERENCES:
            if(verbose)
                emit nextVerboseString("Got a RcReferencesOption");
            return new RcReferencesOption(rawData);
        case CuteNavdataOption::Tag::REFERENCES:
            if(verbose)
                emit nextVerboseString("Got a ReferencesOption");
            return new ReferencesOption(rawData);
        case CuteNavdataOption::Tag::TIME:
            if(verbose)
                emit nextVerboseString("Got an TimeOption");
            return new TimeOption(rawData);
        case CuteNavdataOption::Tag::TRACKERS_SEND:
            if(verbose)
                emit nextVerboseString("Got a TrackersSendOption");
            return new TrackersSendOption(rawData);
        case CuteNavdataOption::Tag::TRIMS:
            if(verbose)
                emit nextVerboseString("Got a TrimsOption");
            return new TrimsOption(rawData);
        case CuteNavdataOption::Tag::VIDEO_STREAM:
            if(verbose)
                emit nextVerboseString("Got a VideoStreamOption");
            return new VideoStreamOption(rawData);
        case CuteNavdataOption::Tag::VISION:
            if(verbose)
                emit nextVerboseString("Got a VisionOption");
            return new VisionOption(rawData);
        case CuteNavdataOption::Tag::VISION_DETECT:
            if(verbose)
                emit nextVerboseString("Got a VisionDetectOption");
            return new VisionDetectOption(rawData);
        case CuteNavdataOption::Tag::VISION_OF:
            if(verbose)
                emit nextVerboseString("Got a VisionOfOption");
            return new VisionOfOption(rawData);
        case CuteNavdataOption::Tag::VISION_PERF:
            if(verbose)
                emit nextVerboseString("Got a VisionPerfOption");
            return new VisionPerfOption(rawData);
        case CuteNavdataOption::Tag::VISION_RAW:
            if(verbose)
                emit nextVerboseString("Got a VisionRawOption");
            return new VisionRawOption(rawData);
        case CuteNavdataOption::Tag::WATCHDOG:
            if(verbose)
                emit nextVerboseString("Got a WatchdogOption");
            return new WatchdogOption(rawData);
        case CuteNavdataOption::Tag::WIFI:
            if(verbose)
                emit nextVerboseString("Got a WifiOption");
            return new WifiOption(rawData);
        case CuteNavdataOption::Tag::WIND:
            if(verbose)
                emit nextVerboseString("Got a WindOption");
            return new WindOption(rawData);
        case CuteNavdataOption::Tag::ZIMMU_3000:
            if(verbose)
                emit nextVerboseString("Got a Zimmu3000Option");
            return new Zimmu3000Option(rawData);
        default:
            if(verbose)
                emit nextVerboseString("Got an UnknownOption");
            QByteArray arr;
            return new CksOption(arr);
        }
    }

    /*!
     * \brief NavdataService::emitNavdataOption emits the signal for the given option.
     * \param option a pointer to the option
     */
    void NavdataService::emitNavdataOption(CuteNavdataOption* option)
    {
        switch (option->decodeTag(option->getTag())) {
        case CuteNavdataOption::Tag::ADC_DATA_FRAME:
            emit nextAdcDataFrameOptionReady(*static_cast<AdcDataFrameOption*>(option));
            if(verbose)
                emit nextVerboseString("Got an AdcDataFrameOption");
            break;
        case CuteNavdataOption::Tag::ALTITUDE:
            emit nextAltitudeOptionReady(*static_cast<AltitudeOption*>(option));
            if(verbose)
                emit nextVerboseString("Got an AltitudeOption");
            break;
        case CuteNavdataOption::Tag::CKS:
            nextCksOptionReady(*static_cast<CksOption*>(option));
            if(verbose)
                emit nextVerboseString("Got a CksOption");
            break;
        case CuteNavdataOption::Tag::DEMO:
            emit nextDemoOptionReady(*static_cast<DemoOption*>(option));
            if(verbose)
                emit nextVerboseString("Got a DemoOption");
            break;
        case CuteNavdataOption::Tag::EULER_ANGLES:
            emit nextEulerAnglesOptionReady(*static_cast<EulerAnglesOption*>(option));
            if(verbose)
                emit nextVerboseString("Got an EulerAnglesOption");
            break;
        case CuteNavdataOption::Tag::GAMES:
            emit nextGamesOptionReady(*static_cast<GamesOption*>(option));
            if(verbose)
                emit nextVerboseString("Got a GamesOption");
            break;
        case CuteNavdataOption::Tag::GYROS_OFFSETS:
            emit nextGyrosOffsetsOptionReady(*static_cast<GyrosOffsetsOption*>(option));
            if(verbose)
                emit nextVerboseString("Got a GyrosOffsetsOption");
            break;
        case CuteNavdataOption::Tag::HDVIDEO_STREAM:
            emit nextHdvideoStreamOptionReady(*static_cast<HdvideoStreamOption*>(option));
            if(verbose)
                emit nextVerboseString("Got a HdvideoStreamOption");
            break;
        case CuteNavdataOption::Tag::KALMAN_PRESSURE:
            emit nextKalmanPressureOptionReady(*static_cast<KalmanPressureOption*>(option));
            if(verbose)
                emit nextVerboseString("Got a KalmanPressureOption");
            break;
        case CuteNavdataOption::Tag::MAGNETO:
            emit nextMagnetoOptionReady(*static_cast<MagnetoOption*>(option));
            if(verbose)
                emit nextVerboseString("Got a MagnetoOption");
            break;
        case CuteNavdataOption::Tag::PHYS_MEASURES:
            emit nextPhysMeasuresOptionReady(*static_cast<PhysMeasuresOption*>(option));
            if(verbose)
                emit nextVerboseString("Got a PhysMeasuresOption");
            break;
        case CuteNavdataOption::Tag::PRESSURE_RAW:
            emit nextPressureRawOptionReady(*static_cast<PressureRawOption*>(option));
            if(verbose)
                emit nextVerboseString("Got a PressureRawOption");
            break;
        case CuteNavdataOption::Tag::PWM:
            emit nextPwmOptionReady(*static_cast<PwmOption*>(option));
            if(verbose)
                emit nextVerboseString("Got a PwmOption");
            break;
        case CuteNavdataOption::Tag::RAW_MEASURES:
            emit nextRawMeasuresOptionReady(*static_cast<RawMeasuresOption*>(option));
            if(verbose)
                emit nextVerboseString("Got a RawMeasuresOption");
            break;
        case CuteNavdataOption::Tag::RC_REFERENCES:
            emit nextRcReferencesOptionReady(*static_cast<RcReferencesOption*>(option));
            if(verbose)
                emit nextVerboseString("Got a RcReferencesOption");
            break;
        case CuteNavdataOption::Tag::REFERENCES:
            emit nextReferencesOptionReady(*static_cast<ReferencesOption*>(option));
            if(verbose)
                emit nextVerboseString("Got a ReferencesOption");
            break;
        case CuteNavdataOption::Tag::TIME:
            emit nextTimeOptionReady(*static_cast<TimeOption*>(option));
            if(verbose)
                emit nextVerboseString("Got an TimeOption");
            break;
        case CuteNavdataOption::Tag::TRACKERS_SEND:
            emit nextTrackersSendOptionReady(*static_cast<TrackersSendOption*>(option));
            if(verbose)
                emit nextVerboseString("Got a TrackersSendOption");
            break;
        case CuteNavdataOption::Tag::TRIMS:
            emit nextTrimsOptionReady(*static_cast<TrimsOption*>(option));
            if(verbose)
                emit nextVerboseString("Got a TrimsOption");
            break;
        case CuteNavdataOption::Tag::VIDEO_STREAM:
            emit nextVideoStreamOptionReady(*static_cast<VideoStreamOption*>(option));
            if(verbose)
                emit nextVerboseString("Got a VideoStreamOption");
            break;
        case CuteNavdataOption::Tag::VISION:
            emit nextVisionOptionReady(*static_cast<VisionOption*>(option));
            if(verbose)
                emit nextVerboseString("Got a VisionOption");
            break;
        case CuteNavdataOption::Tag::VISION_DETECT:
            emit nextVisionDetectOptionReady(*static_cast<VisionDetectOption*>(option));
            if(verbose)
                emit nextVerboseString("Got a VisionDetectOption");
            break;
        case CuteNavdataOption::Tag::VISION_OF:
            emit nextVisionOfOptionReady(*static_cast<VisionOfOption*>(option));
            if(verbose)
                emit nextVerboseString("Got a VisionOfOption");
            break;
        case CuteNavdataOption::Tag::VISION_PERF:
            emit nextVisionPerfOptionReady(*static_cast<VisionPerfOption*>(option));
            if(verbose)
                emit nextVerboseString("Got a VisionPerfOption");
            break;
        case CuteNavdataOption::Tag::VISION_RAW:
            emit nextVisionRawOptionReady(*static_cast<VisionRawOption*>(option));
            if(verbose)
                emit nextVerboseString("Got a VisionRawOption");
            break;
        case CuteNavdataOption::Tag::WATCHDOG:
            emit nextWatchdogOptionReady(*static_cast<WatchdogOption*>(option));
            if(verbose)
                emit nextVerboseString("Got a WatchdogOption");
            break;
        case CuteNavdataOption::Tag::WIFI:
            emit nextWifiOptionReady(*static_cast<WifiOption*>(option));
            if(verbose)
                emit nextVerboseString("Got a WifiOption");
            break;
        case CuteNavdataOption::Tag::WIND:
            emit nextWindOptionReady(*static_cast<WindOption*>(option));
            if(verbose)
                emit nextVerboseString("Got a WindOption");
            break;
        case CuteNavdataOption::Tag::ZIMMU_3000:
            emit nextZimmu3000OptionReady(*static_cast<Zimmu3000Option*>(option));
            if(verbose)
                emit nextVerboseString("Got a Zimmu3000Option");
            break;
        default:
            emit gotUnknownOption();
            if(verbose)
                emit nextVerboseString("Got an UnknownOption");
            break;
        }
    }

    /*!
     * \brief NavdataService::start starts the object thread.
     */
    void NavdataService::start()
    {
        workerThread->start();
    }

    /*!
     * \brief NavdataService::stop closes the socket and stops the object thread.
     */
    void NavdataService::stop()
    {
        socket->close();
        timer->stop();
        workerThread->quit();
        workerThread->wait();
    }

    /*!
     * \brief NavdataService::reconnect drops every unprocessed package and calls sendClientHello().
     */
    void NavdataService::reconnect()
    {
        socket->flush();
        sendClientHello();
    }

    /*!
     * \brief NavdataService::sendClientHello sends a binary one to the drone in order to aquire new packages.
     */
    void NavdataService::sendClientHello()
    {
        QByteArray message;
        message.resize(4);
        message[0] = 0x01;
        message[1] = 0x00;
        message[2] = 0x00;
        message[3] = 0x00;
        socket->writeDatagram(message, QHostAddress(droneIP), port);
        if(verbose)
            emit nextVerboseString("Sent client hello");
        if(this->thread()->currentThreadId() != workerThread->currentThreadId())
            moveToThread(workerThread);
    }

    /*!
     * \brief NavdataService::receivedNewData is called every time a new package is reveived.
     * If the package header is invalid of the checksum doesn't match it will emit the gotInvalidPackage() signal.
     * If one Option seems to be invalid it emits the gotInvalidPackage() signal.
     * If the package seems to be valid it will call the corresponding signals.
     */
    void NavdataService::receivedNewData()
    {
        isConnected = true;

        QByteArray datagram;
        QHostAddress address(droneIP);
        quint16 port = this->port;
        datagram.resize(socket->pendingDatagramSize());
        socket->readDatagram(datagram.data(), datagram.size(),
                            &address, &port);
        if(!isListening)
            return;

        int32_t expectedChecksum = 0;
        int32_t checksum = 0;
        if(datagram.size() < 16)
        {
            emit gotInvalidPackage();
            return;
        }

        /* Calculate the checksum. Includes the header and ignores the CksOption itself (end - 8-byte) */
        for(int i = 0; i < datagram.size() - 8; i++)
            expectedChecksum += datagram.at(i) & 0xFF;

        /* Check header */
        u_int32_t header = CuteNavdataOption::fetchUnsignedInt32(datagram);
        if(header != 0x55667788 && header != 0x55667789)
        {
            emit gotInvalidPackage();
            if(verbose)
                emit nextVerboseString("Invalid packet header");
            return;
        }

        /* The drone state is not always defined... */
        u_int32_t droneState = CuteNavdataOption::fetchUnsignedInt32(datagram);

        /* Check sequence number */
        u_int32_t sequence = CuteNavdataOption::fetchUnsignedInt32(datagram);
        if(sequence <= lastSequence && sequence != 1)
        {
            emit gotInvalidPackage();
            if(verbose)
                emit nextVerboseString("Invalid sequence number");
            return;
        }

        lastSequence = sequence;

        bool visionDefined = CuteNavdataOption::fetchBool(datagram);

        bool foundCks = false;

        vector<CuteNavdataOption*> options;
        CksOption* cks;

        while(!datagram.isEmpty() && !foundCks)
        {
            CuteNavdataOption::Tag tag = CuteNavdataOption::decodeTag(
                        CuteNavdataOption::fetchUnsignedInt16(datagram));

            // Length includes header size (4 bytes)
            u_int16_t size = CuteNavdataOption::fetchUnsignedInt16(datagram) - 4;

            if(size == 0)
            {
                emit gotInvalidPackage();
                if(verbose)
                    emit nextVerboseString("invalid option size");
                return;
            }

            QByteArray slice;
            slice.resize(size);
            for(int i = 0; i < size; i++)
                slice[i] = datagram[i];
            datagram.remove(0, size);

            if(tag == CuteNavdataOption::Tag::CKS)
            {
                cks = new CksOption(slice);
                checksum = cks->getCks();
                options.push_back(cks);
                foundCks = true;
                continue;
            }
            options.push_back(decodeNavdataOption(tag, slice));
        }

        if(!foundCks || checksum != expectedChecksum)
        {
            emit gotInvalidPackage();
            if(verbose)
                emit nextVerboseString("Invalid checksum");
            return;
        }
        else if(verbose)
            emit nextVerboseString("Valid checksum ;-)");

        emit nextDroneState(decodeDroneState(droneState));
        emit nextVisionDefined(visionDefined);
        for(CuteNavdataOption* c : options)
        {
            emitNavdataOption(c);
            delete c;
        }
        isListening = false;
    }

    /*!
     * \brief NavdataService::checkConnected checks the connection state every 50ms.
     * Emits the signal connectionStatusChanged(bool) when the state changed.
     */
    void NavdataService::checkConnected()
    {
        if(isConnected == wasConnected)
        {
            isConnected = false;
            return;
        }
        wasConnected = isConnected;
        emit connectionStatusChanged(isConnected);
        if(verbose)
            emit nextVerboseString("Changed connection state");
    }

    /*!
     * \brief NavdataService::toggleListening activates the 50ms throttle.
     */
    void NavdataService::toggleListening()
    {
        isListening = true;
    }

}
