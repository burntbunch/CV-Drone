#include "MainWindow.h"
#include "ui_MainWindow.h"

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
 * \brief MainWindow::MainWindow creates a MainWindow and connects all signals and slots
 *
 * \param *cvDrone
 * \param *objectDetector
 * \param *parent
 */
MainWindow::MainWindow(Drone::CVDrone *cvDrone, ObjectDetection::ObjectDetector *objectDetector, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->objectDetector    = objectDetector;
    this->cvDrone           = cvDrone;
    this->commandService    = cvDrone->getCommandService();
    this->navdataService    = cvDrone->getNavdataService();
    this->videoService      = cvDrone->getVideoService();

    ui->videoContainer->setScaledContents(true);

    connect(ui->actionControl_Window,   SIGNAL(toggled(bool)),              this,           SLOT(toggleControlWindow(bool)));
    connect(ui->actionVideo_Options,    SIGNAL(toggled(bool)),              this,           SLOT(toggleVideoSettings(bool)));
    connect(ui->actionCommands,         SIGNAL(toggled(bool)),              this,           SLOT(toggleCommandDebug(bool)));
    connect(ui->actionNavdata,          SIGNAL(toggled(bool)),              this,           SLOT(toggleNavdataDebug(bool)));
    connect(ui->actionOpenCV,           SIGNAL(toggled(bool)),              this,           SLOT(toggleOpenCVDebug(bool)));

    connect(ui->actionReconnect,        SIGNAL(triggered()),                commandService, SLOT(reconnect()));
    connect(ui->actionNavdata_Service,  SIGNAL(triggered()),                navdataService, SLOT(reconnect()));
    connect(ui->actionVideo_Service,    SIGNAL(triggered()),                videoService,   SLOT(reconnect()));

    connect(ui->buttonStart,            SIGNAL(clicked(bool)),              this,           SLOT(toggleTakeOffLand(bool)));
    connect(ui->buttonEmergency,        SIGNAL(clicked()),                  cvDrone,        SLOT(emergency()));
    connect(ui->buttonDetect,           SIGNAL(toggled(bool)),              objectDetector, SLOT(setActivated(bool)));
    connect(ui->buttonAutopilot,        SIGNAL(toggled(bool)),              objectDetector, SLOT(setAutopilot(bool)));
    connect(ui->buttonDetect,           SIGNAL(toggled(bool)),              this,           SLOT(detectToggled(bool)));

    connect(objectDetector,             SIGNAL(moveLeft()),                 cvDrone,        SLOT(moveLeft()));
    connect(objectDetector,             SIGNAL(moveRight()),                cvDrone,        SLOT(moveRight()));
    connect(objectDetector,             SIGNAL(moveUp()),                   cvDrone,        SLOT(moveUp()));
    connect(objectDetector,             SIGNAL(moveDown()),                 cvDrone,        SLOT(moveDown()));
    connect(objectDetector,             SIGNAL(moveUpRight()),              cvDrone,        SLOT(moveUpperRight()));
    connect(objectDetector,             SIGNAL(moveUpLeft()),               cvDrone,        SLOT(moveUpperLeft()));
    connect(objectDetector,             SIGNAL(moveDownRight()),            cvDrone,        SLOT(moveLowerRight()));
    connect(objectDetector,             SIGNAL(moveDownLeft()),             cvDrone,        SLOT(moveLowerLeft()));
    connect(objectDetector,             SIGNAL(inCenter()),                 cvDrone,        SLOT(hover()));

    connect(videoService,               SIGNAL(nextFrameReady()),           objectDetector, SLOT(colorFilter()));
    connect(videoService,               SIGNAL(connectionLost()),           objectDetector, SLOT(connectionLost()));

    connect(objectDetector,             SIGNAL(nextFrameReady(QPixmap)),    this,           SLOT(showFrame(QPixmap)));
}

/*!
 * \brief MainWindow::MainWindow deletes the MainWindow.
 */
MainWindow::~MainWindow()
{
    disconnect();
    delete ui;
}

/*!
 * \brief MainWindow::closeEvent emits the closed() event
 * \param event this parameter is ignored, but requiered by the super class
 */
void MainWindow::closeEvent(QCloseEvent *event)
{
    emit closed();
}

/*!
 * \brief MainWindow::toggleControlWindow either opens or closes the ControlWindow
 */
void MainWindow::toggleControlWindow(bool toggle)
{
    if(toggle)
    {
        controlWindow = new ControlWindow(cvDrone);
        connect(controlWindow,  SIGNAL(closed()),   this,           SLOT(controlWindowClosed()));
        connect(this,           SIGNAL(closed()),   controlWindow,  SLOT(close()));
        controlWindow->show();
    }
    else
        controlWindow->close();
}

/*!
 * \brief MainWindow::toggleVideoSettings either opens or closes the VideoSettingsWindow
 */
void MainWindow::toggleVideoSettings(bool toggle)
{
    if(toggle)
    {
        videoSettings = new VideoSettingsWindow(objectDetector);
        connect(videoSettings,  SIGNAL(closed()),   this,           SLOT(videoSettingsWindowClosed()));
        connect(this,           SIGNAL(closed()),   videoSettings,  SLOT(close()));
        videoSettings->show();
    }
    else
        videoSettings->close();
}

/*!
 * \brief MainWindow::toggleCommandDebug either opens or closes the CommandDebugWindow
 */
void MainWindow::toggleCommandDebug(bool toggle)
{
    if(toggle)
    {
        commandDebug = new CommandDebugWindow(commandService);
        connect(commandDebug,  SIGNAL(closed()),   this,            SLOT(commandDebugWindowClosed()));
        connect(this,          SIGNAL(closed()),   commandDebug,    SLOT(close()));
        commandDebug->show();
    }
    else
        commandDebug->close();
}

/*!
 * \brief MainWindow::toggleNavdataDebug either opens or closes the NavdataDebugWindow
 */
void MainWindow::toggleNavdataDebug(bool toggle)
{
    if(toggle)
    {
        navdataDebug = new NavdataDebugWindow(navdataService);
        connect(navdataDebug,  SIGNAL(closed()),   this,            SLOT(navdataDebugWindowClosed()));
        connect(this,          SIGNAL(closed()),   navdataDebug,    SLOT(close()));
        navdataDebug->show();
    }
    else
        navdataDebug->close();
}

/*!
 * \brief MainWindow::toggleOpenCVDebug either opens or closes the OpenCVDebugWindow
 */
void MainWindow::toggleOpenCVDebug(bool toggle)
{
    if(toggle)
    {
        openCVDebug = new OpenCVDebugWindow(videoService, objectDetector);
        connect(openCVDebug,    SIGNAL(closed()),   this,           SLOT(openCVDebugWindowClosed()));
        connect(this,           SIGNAL(closed()),   openCVDebug,    SLOT(close()));
        openCVDebug->show();
    }
    else
        openCVDebug->close();
}

/*!
 * \brief MainWindow::toggleTakeOffLand either starts or lands the Drone
 */
void MainWindow::toggleTakeOffLand(bool toggle)
{
    if(toggle)
    {
        ui->buttonStart->setText("Land");
        cvDrone->takeOff();
    }
    else
    {
        ui->buttonStart->setText("Start");
        cvDrone->land();
    }
}

void MainWindow::detectToggled(bool toggle)
{
    if(!toggle)
        ui->buttonAutopilot->setChecked(false);
}

/*!
 * \brief MainWindow::controlWindowClosed is processed when ethe ControlWindow is closed.
 * The corresponding checkBox will be unchecked.
 */
void MainWindow::controlWindowClosed()
{
    ui->actionControl_Window->setChecked(false);
    controlWindow->disconnect();
    delete controlWindow;
}

/*!
 * \brief MainWindow::commandDebugWindowClosed is processed when ethe CommandDebugWindow is closed.
 * The corresponding checkBox will be unchecked.
 */
void MainWindow::commandDebugWindowClosed()
{
    ui->actionCommands->setChecked(false);
    commandDebug->disconnect();
    delete commandDebug;
}

/*!
 * \brief MainWindow::navdataDebugWindowClosed is processed when ethe NavdataDebugWindow is closed.
 * The corresponding checkBox will be unchecked.
 */
void MainWindow::navdataDebugWindowClosed()
{
    ui->actionNavdata->setChecked(false);
    navdataDebug->disconnect();
    delete navdataDebug;
}

/*!
 * \brief MainWindow::openCVDebugWindowClosed is processed when ethe OpenCVDebugWindow is closed.
 * The corresponding checkBox will be unchecked.
 */
void MainWindow::openCVDebugWindowClosed()
{
    ui->actionOpenCV->setChecked(false);
    openCVDebug->disconnect();
    delete openCVDebug;
}

/*!
 * \brief MainWindow::videoSettingsWindowClosed is processed when ethe VideoSettingsWindow is closed.
 * The corresponding checkBox will be unchecked.
 */
void MainWindow::videoSettingsWindowClosed()
{
    ui->actionVideo_Options->setChecked(false);
    videoSettings->disconnect();
    delete videoSettings;
}

/*!
 * \brief MainWindow::showFrame shows the pixmap on the videoLabel.
 * \param pixmap the pixmap to show.
 */
void MainWindow::showFrame(QPixmap pixmap)
{
    ui->videoContainer->setPixmap(pixmap);
}
