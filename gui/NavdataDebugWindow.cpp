#include "NavdataDebugWindow.h"
#include "ui_NavdataDebugWindow.h"

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

/*!
 * \brief NavdataDebugWindow::NavdataDebugWindow creates a NavdataDebugWindow
 *
 * A window, that shows debug messages from the NavdataService
 * \param service
 * \param parent
 */
NavdataDebugWindow::NavdataDebugWindow(Drone::NavdataService *service, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NavdataDebugWindow)
{
    ui->setupUi(this);

    this->service = service;
    service->setVerbose(true);

    connect(service, SIGNAL(nextAdcDataFrameOptionReady(AdcDataFrameOption)),        this, SLOT(adcDataFrameOptionReceived(AdcDataFrameOption)));
    connect(service, SIGNAL(nextAltitudeOptionReady(AltitudeOption)),                this, SLOT(altitudeOptionReceived(AltitudeOption)));
    connect(service, SIGNAL(nextCksOptionReady(CksOption)),                          this, SLOT(cksOptionReceived(CksOption)));
    connect(service, SIGNAL(nextDemoOptionReady(DemoOption)),                        this, SLOT(demoOptionReceived(DemoOption)));
    connect(service, SIGNAL(nextEulerAnglesOptionReady(EulerAnglesOption)),          this, SLOT(eulerAnglesOptionReceived(EulerAnglesOption)));
    connect(service, SIGNAL(nextGamesOptionReady(GamesOption)),                      this, SLOT(gamesOptionReceived(GamesOption)));
    connect(service, SIGNAL(nextGyrosOffsetsOptionReady(GyrosOffsetsOption)),        this, SLOT(gyrosOffsetsOptionReceived(GyrosOffsetsOption)));
    connect(service, SIGNAL(nextHdvideoStreamOptionReady(HdvideoStreamOption)),      this, SLOT(hdvideoStreamOptionReceived(HdvideoStreamOption)));
    connect(service, SIGNAL(nextKalmanPressureOptionReady(KalmanPressureOption)),    this, SLOT(kalmanPressureOptionReceived(KalmanPressureOption)));
    connect(service, SIGNAL(nextMagnetoOptionReady(MagnetoOption)),                  this, SLOT(magnetoOptionReceived(MagnetoOption)));
    connect(service, SIGNAL(nextPhysMeasuresOptionReady(PhysMeasuresOption)),        this, SLOT(physMeasuresOptionReceived(PhysMeasuresOption)));
    connect(service, SIGNAL(nextPressureRawOptionReady(PressureRawOption)),          this, SLOT(pressureRawOptionReceived(PressureRawOption)));
    connect(service, SIGNAL(nextPwmOptionReady(PwmOption)),                          this, SLOT(pwmOptionReceived(PwmOption)));
    connect(service, SIGNAL(nextRawMeasuresOptionReady(RawMeasuresOption)),          this, SLOT(rawMeasuresOptionReceived(RawMeasuresOption)));
    connect(service, SIGNAL(nextRcReferencesOptionReady(RcReferencesOption)),        this, SLOT(rcReferencesOptionReceived(RcReferencesOption)));
    connect(service, SIGNAL(nextReferencesOptionReady(ReferencesOption)),            this, SLOT(referencesOptionReceived(ReferencesOption)));
    connect(service, SIGNAL(nextTimeOptionReady(TimeOption)),                        this, SLOT(timeOptionReceived(TimeOption)));
    connect(service, SIGNAL(nextTrackersSendOptionReady(TrackersSendOption)) ,       this, SLOT(trackersSendOptionReceived(TrackersSendOption)));
    connect(service, SIGNAL(nextTrimsOptionReady(TrimsOption)),                      this, SLOT(trimsOptionReceived(TrimsOption)));
    connect(service, SIGNAL(nextVideoStreamOptionReady(VideoStreamOption)),          this, SLOT(videoStreamOptionReceived(VideoStreamOption)));
    connect(service, SIGNAL(nextVisionDetectOptionReady(VisionDetectOption)),        this, SLOT(visionDetectOptionReceived(VisionDetectOption)));
    connect(service, SIGNAL(nextVisionOfOptionReady(VisionOfOption)),                this, SLOT(visionOfOptionReceived(VisionOfOption)));
    connect(service, SIGNAL(nextVisionOptionReady(VisionOption)),                    this, SLOT(visionOptionReceived(VisionOption)));
    connect(service, SIGNAL(nextVisionPerfOptionReady(VisionPerfOption)),            this, SLOT(visionPerfOptionReceived(VisionPerfOption)));
    connect(service, SIGNAL(nextVisionRawOptionReady(VisionRawOption)),              this, SLOT(visionRawOptionReceived(VisionRawOption)));
    connect(service, SIGNAL(nextWatchdogOptionReady(WatchdogOption)),                this, SLOT(watchdogOptionReceived(WatchdogOption)));
    connect(service, SIGNAL(nextWifiOptionReady(WifiOption)),                        this, SLOT(wifiOptionReceived(WifiOption)));
    connect(service, SIGNAL(nextWindOptionReady(WindOption)),                        this, SLOT(windOptionReceived(WindOption)));
    connect(service, SIGNAL(nextZimmu3000OptionReady(Zimmu3000Option)),              this, SLOT(zimmu3000OptionReceived(Zimmu3000Option)));

    connect(service, SIGNAL(nextVerboseString(QString)),                             this, SLOT(navdataDebugMessageReceived(QString)));

    connect(ui->buttonNavdataShow,   SIGNAL(clicked(bool)),                          service,    SLOT(setVerbose(bool)));
}

/*!
 * \brief NavdataDebugWindow::~NavdataDebugWindow deletes the NavdataDebugWindow
 */
NavdataDebugWindow::~NavdataDebugWindow()
{
    service->setVerbose(false);
    delete ui;
}

/*!
 * \brief NavdataDebugWindow::closeEvent emits the closed() event
 * \param event this parameter is ignored, but requiered by the super class
 */
void NavdataDebugWindow::closeEvent(QCloseEvent *event)
{
    emit closed();
}

/*!
 * \brief NavdataDebugWindow::adcDataFrameOptionReceived displays data from the AdcDataFrameOption
 * \param option
 */
void NavdataDebugWindow::adcDataFrameOptionReceived(AdcDataFrameOption option)
{
    ui->lineEditAcdDataFrame->setText(QString::number(option.getVersion()));
}

/*!
 * \brief NavdataDebugWindow::altitudeOptionReceived displays data from the AltitudeOption
 * \param option
 */
void NavdataDebugWindow::altitudeOptionReceived(AltitudeOption option)
{
    ui->lineEditAltitude->setText(QString::number(option.getAltitudeRaw()));
}

/*!
 * \brief NavdataDebugWindow::cksOptionReceived displays data from the CksOption
 * \param option
 */
void NavdataDebugWindow::cksOptionReceived(CksOption option)
{
    ui->lineEditCks->setText(QString::number(option.getCks()));
}

/*!
 * \brief NavdataDebugWindow::demoOptionReceived displays data from the DemoOption
 * \param option
 */
void NavdataDebugWindow::demoOptionReceived(DemoOption option)
{
    ui->lineEditDemo->setText(QString::number(option.getPhi(), 'g', 2) + " " +
                              QString::number(option.getPsi(), 'g', 2) + " " +
                              QString::number(option.getTheta(), 'g', 2));
}

/*!
 * \brief NavdataDebugWindow::eulerAnglesOptionReceived displays data from the EulerAnglesOption
 * \param option
 */
void NavdataDebugWindow::eulerAnglesOptionReceived(EulerAnglesOption option)
{
    ui->lineEditEulerAngles->setText(QString::number(option.getPhiA(), 'g', 2) + " " + QString::number(option.getThetaA(), 'g', 2));
}

/*!
 * \brief NavdataDebugWindow::gamesOptionReceived displays data from the GamesOption
 * \param option
 */
void NavdataDebugWindow::gamesOptionReceived(GamesOption option)
{
    ui->lineEditGames->setText(QString::number(option.getDoubleTapCounter(), 'g', 2));
}

/*!
 * \brief NavdataDebugWindow::gyrosOffsetsOptionReceived displays data from the GyrosOffsetsOption
 * \param option
 */
void NavdataDebugWindow::gyrosOffsetsOptionReceived(GyrosOffsetsOption option)
{
    QString string;
    for(float f : option.getOffsetG())
        string.append(QString::number(f, 'g', 2)).append(" ");
    ui->lineEditGyrosOffsets->setText(string);
}

/*!
 * \brief NavdataDebugWindow::hdvideoStreamOptionReceived displays data from the HdvideoStreamOption
 * \param option
 */
void NavdataDebugWindow::hdvideoStreamOptionReceived(HdvideoStreamOption option)
{
    ui->lineEditHdvideoStream->setText(QString::number(option.getFrameNumber(), 'g', 2));
}

/*!
 * \brief NavdataDebugWindow::kalmanPressureOptionReceived displays data from the KalmanPressureOption
 * \param option
 */
void NavdataDebugWindow::kalmanPressureOptionReceived(KalmanPressureOption option)
{
    ui->lineEditKalmanPressure->setText(QString::number(option.getOffsetPressure(), 'g', 2));
}

/*!
 * \brief NavdataDebugWindow::magnetoOptionReceived displays data from the MagnetoOption
 * \param option
 */
void NavdataDebugWindow::magnetoOptionReceived(MagnetoOption option)
{
    QString string;
    for(float f : option.getMagnetoRaw())
        string.append(QString::number(f, 'g', 2)).append(" ");
    ui->lineEditMagneto->setText(string);
}

/*!
 * \brief NavdataDebugWindow::physMeasuresOptionReceived displays data from the PhysMeasuresOption
 * \param option
 */
void NavdataDebugWindow::physMeasuresOptionReceived(PhysMeasuresOption option)
{
    ui->lineEditPhysMeasures->setText(QString::number(option.getAccsTemp(), 'g', 2));
}

/*!
 * \brief NavdataDebugWindow::pressureRawOptionReceived displays data from the PressureRawOption
 * \param option
 */
void NavdataDebugWindow::pressureRawOptionReceived(PressureRawOption option)
{
    ui->lineEditPressureRaw->setText(QString::number(option.getPressionMeas(), 'g', 2));
}

/*!
 * \brief NavdataDebugWindow::pwmOptionReceived displays data from the PwmOption
 * \param option
 */
void NavdataDebugWindow::pwmOptionReceived(PwmOption option)
{
    ui->lineEditPwm->setText(QString::number(option.getMotor1()) + " "
                             + QString::number(option.getMotor2()) + " " + QString::number(option.getMotor3())
                             + " " + QString::number(option.getMotor4()));
}

/*!
 * \brief NavdataDebugWindow::rawMeasuresOptionReceived displays data from the RawMeasuresOption
 * \param option
 */
void NavdataDebugWindow::rawMeasuresOptionReceived(RawMeasuresOption option)
{
    ui->lineEditRawMeasures->setText(QString::number(option.getSumEcho()));
}

/*!
 * \brief NavdataDebugWindow::rcReferencesOptionReceived displays data from the RcReferencesOption
 * \param option
 */
void NavdataDebugWindow::rcReferencesOptionReceived(RcReferencesOption option)
{
    ui->lineEditRcReferences->setText(QString::number(option.getRcRefAg()));
}

/*!
 * \brief NavdataDebugWindow::referencesOptionReceived displays data from the ReferencesOption
 * \param option
 */
void NavdataDebugWindow::referencesOptionReceived(ReferencesOption option)
{
    ui->lineEditReferences->setText(QString::number(option.getRefYaw()));
}

/*!
 * \brief NavdataDebugWindow::timeOptionReceived displays data from the TimeOption
 * \param option
 */
void NavdataDebugWindow::timeOptionReceived(TimeOption option)
{
    ui->lineEditTime->setText(QString::number(option.getTime()));
}

/*!
 * \brief NavdataDebugWindow::trackersSendOptionReceived displays data from the TrackersSendOption
 * \param option
 */
void NavdataDebugWindow::trackersSendOptionReceived(TrackersSendOption option)
{
    QString string;
    for(int f : option.getLocked())
        string.append(QString::number(f)).append(" ");
    ui->lineEditTrackersSend->setText(string);
}

/*!
 * \brief NavdataDebugWindow::trimsOptionReceived displays data from the TrimsOption
 * \param option
 */
void NavdataDebugWindow::trimsOptionReceived(TrimsOption option)
{
    ui->lineEditTrims->setText(QString::number(option.getAngularRatesTrimR()));
}

/*!
 * \brief NavdataDebugWindow::videoStreamOptionReceived displays data from the VideoStreamOption
 * \param option
 */
void NavdataDebugWindow::videoStreamOptionReceived(VideoStreamOption option)
{
    ui->lineEditVideoStream->setText(QString::number(option.getFrameNumber()));
}

/*!
 * \brief NavdataDebugWindow::visionDetectOptionReceived displays data from the VisionDetectOption
 * \param option
 */
void NavdataDebugWindow::visionDetectOptionReceived(VisionDetectOption option)
{
    ui->lineEditVisionDetect->setText(QString::number(option.getNbDetected()));
}

/*!
 * \brief NavdataDebugWindow::visionOfOptionReceived displays data from the VisionOfOption
 * \param option
 */
void NavdataDebugWindow::visionOfOptionReceived(VisionOfOption option)
{
    QString string;
    for(float f : option.getOfDx())
        string.append(QString::number(f, 'g', 2)).append(" ");
    for(float f : option.getOfDy())
        string.append(QString::number(f, 'g', 2)).append(" ");
    ui->lineEditVisionOf->setText(string);
}

/*!
 * \brief NavdataDebugWindow::visionOptionReceived displays data from the VisionOption
 * \param option
 */
void NavdataDebugWindow::visionOptionReceived(VisionOption option)
{
    ui->lineEditVision->setText(QString::number(option.getNewRawPicture()));
}

/*!
 * \brief NavdataDebugWindow::visionPerfOptionReceived displays data from the VisionPerfOption
 * \param option
 */
void NavdataDebugWindow::visionPerfOptionReceived(VisionPerfOption option)
{
    ui->lineEditVisionPerf->setText(QString::number(option.getTimeUpdate(), 'g', 2));
}

/*!
 * \brief NavdataDebugWindow::visionRawOptionReceived displays data from the VisionRawOption
 * \param option
 */
void NavdataDebugWindow::visionRawOptionReceived(VisionRawOption option)
{
    ui->lineEditVisionRaw->setText(QString::number(option.getVisionTxRaw(), 'g', 2) + " "
                                   + QString::number(option.getVisionTyRaw(), 'g', 2) + " "
                                   + QString::number(option.getVisionTzRaw(), 'g', 2));
}

/*!
 * \brief NavdataDebugWindow::watchdogOptionReceived displays data from the WatchdogOption
 * \param option
 */
void NavdataDebugWindow::watchdogOptionReceived(WatchdogOption option)
{
    ui->lineEditWatchdog->setText(QString::number(option.getWatchdog()));
}

/*!
 * \brief NavdataDebugWindow::wifiOptionReceived displays data from the WifiOption
 * \param option
 */
void NavdataDebugWindow::wifiOptionReceived(WifiOption option)
{
    ui->lineEditWifi->setText(QString::number(option.getLinkQuality(), 'g', 2));
}

/*!
 * \brief NavdataDebugWindow::windOptionReceived displays data from the WindOption
 * \param option
 */
void NavdataDebugWindow::windOptionReceived(WindOption option)
{
    ui->lineEditWind->setText(QString::number(option.getWindSpeed(), 'g', 2));
}

/*!
 * \brief NavdataDebugWindow::zimmu3000OptionReceived displays data from the Zimmu3000Option
 * \param option
 */
void NavdataDebugWindow::zimmu3000OptionReceived(Zimmu3000Option option)
{
    ui->lineEditZimmu3000->setText(QString::number(option.getVzimmuLsb()));
}

/*!
 * \brief NavdataDebugWindow::navdataDebugMessageReceived receives a message and displays it
 * \param message
 */
void NavdataDebugWindow::navdataDebugMessageReceived(QString message)
{
    QString string = ui->textNavdataDebug->toPlainText().append("\n"+message);
    if(string.count("\n") > 100)
        string = string.remove(0, string.indexOf("\n") + 1);
    ui->textNavdataDebug->setPlainText(string);
    QTextCursor c = ui->textNavdataDebug->textCursor();
    c.movePosition(QTextCursor::End);
    ui->textNavdataDebug->setTextCursor(c);
}
