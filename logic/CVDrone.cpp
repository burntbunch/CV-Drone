#include "CVDrone.h"

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
     * \brief CvDrone::CvDrone this is the private Constructor.
     *
     * The CvDrone is the Main Object of the CvDrone project.
     * It inherences all Services as well as the ObjectDetector.
     * The CvDrone class is a singelton, to minimize confusion or deadlocks with more than one AR.Drone.
     *
     * Within this method all Services are started, the Drone gets some callibration commands
     * and the ObjectDetector Signals are getting connected to the CvDrone slots
     */
    CVDrone::CVDrone()
    {
        thread          = new QThread(this);
        timer           = new QTimer(this);
        configFile      = &ConfigFile::getInstance();
        speed           = configFile->getSpeed();
        speedAltitude   = configFile->getSpeedAltitude();

        navdataService  = new NavdataService(configFile->getIp(),configFile->getNavdataPort());
        commandService  = new CommandService(configFile->getIp(), configFile->getCommandPort());
        videoService    = new VideoService(configFile->getIp(), configFile->getVideoPort());

        connect(commandService, SIGNAL(reconnected()),  navdataService, SLOT(reconnect()));
        connect(commandService, SIGNAL(reconnected()),  videoService,   SLOT(reconnect()));

        connect(this,           SIGNAL(destroyed()),    navdataService, SLOT(deleteLater()));
        connect(this,           SIGNAL(destroyed()),    commandService, SLOT(deleteLater()));
        connect(this,           SIGNAL(destroyed()),    videoService,   SLOT(deleteLater()));

        navdataService->start();
        commandService->start();
        videoService->start();

        thread->start();
        moveToThread(thread);
    }

    /*!
     * \brief CvDrone::~CvDrone Destructor for the CvDrone class
     *
     * The destructor disconnects all slots from the services as well as from the ObjectDetector
     * Also it stops the Services and delets all references
     *
     */
    CVDrone::~CVDrone()
    {
        commandService->stop();
        navdataService->stop();
        videoService->stop();
        thread->quit();
        thread->wait();
    }

    /*!
     * \brief CvDrone::getInstance for singelton implementation
     *
     * \return instance of CvDrone
     */
    CVDrone &CVDrone::getInstance()
    {
        static CVDrone instance;
        return instance;
    }

    /*!
     * \brief CvDrone::emergency() Slot put the Drone in Emergency-Mode
     */
    void CVDrone::emergency()
    {
        commandService->setCommand(new REFCommand(REFCommand::State::EMERGENCY));
    }

    /*!
     * \brief CvDrone::takeOff Slot to let the Drone start
     */
    void CVDrone::takeOff()
    {
        commandService->setCommand(new REFCommand(REFCommand::State::TAKEOFF));
        flying = true;
    }

    /*!
     * \brief CvDrone::land Slot to let the Drone land
     */
    void CVDrone::land()
    {
        commandService->setCommand(new REFCommand(REFCommand::State::LAND));
        flying = false;
    }

    /*!
     * \brief CvDrone::turnLeft Slot to let the Drone turn left
     */
    void CVDrone::turnLeft()
    {
        commandService->setCommand(new PCMDCommand(PCMDCommand::Mode::PROGRESSIVE,0,0,0,-speed));
    }

    /*!
     * \brief CvDrone::turnRight Slot to let the Drone turn right
     */
    void CVDrone::turnRight()
    {
        commandService->setCommand(new PCMDCommand(PCMDCommand::Mode::PROGRESSIVE,0,0,0,speed));
    }

    /*!
     * \brief CvDrone::hover Slot to let the Drone stand still
     */
    void CVDrone::hover()
    {
        commandService->setCommand(new PCMD_MAGCommand(PCMD_MAGCommand::Mode::HOVER,0,0,0,0,0,0));
    }

    /*!
     * \brief CvDrone::moveForward Slot to make the Drone move forward
     */
    void CVDrone::moveForward()
    {
        commandService->setCommand(new PCMDCommand(PCMDCommand::Mode::PROGRESSIVE,0,-speed,0,0));
    }

    /*!
     * \brief CvDrone::moveBackward Slot to make the Drone move backward
     */
    void CVDrone::moveBackward()
    {
        commandService->setCommand(new PCMDCommand(PCMDCommand::Mode::PROGRESSIVE,0,speed,0,0));
    }

    /*!
     * \brief CvDrone::moveLeft Slot to make the Drone move left
     */
    void CVDrone::moveLeft()
    {
        commandService->setCommand(new PCMDCommand(PCMDCommand::Mode::PROGRESSIVE,-speed,0,0,0));
    }

    /*!
     * \brief CvDrone::moveRight Slot to make the Drone move right
     */
    void CVDrone::moveRight()
    {
        commandService->setCommand(new PCMDCommand(PCMDCommand::Mode::PROGRESSIVE,speed,0,0,0));
    }

    /*!
     * \brief CvDrone::moveUp Slot to let the Drone rise a bit higher
     */
    void CVDrone::moveUp()
    {
        commandService->setCommand(new PCMDCommand(PCMDCommand::Mode::PROGRESSIVE,0,0,speedAltitude,0));
    }

    /*!
     * \brief CvDrone::moveDown Slot to let the Drone get a little lower
     */
    void CVDrone::moveDown()
    {
        commandService->setCommand(new PCMDCommand(PCMDCommand::Mode::PROGRESSIVE,0,0,-speedAltitude,0));
    }

    /*!
     * \brief CvDrone::moveUpperRight Slot to make the Drone move diagonal in the upper right direction
     */
    void CVDrone::moveUpperRight()
    {
        commandService->setCommand(new PCMDCommand(PCMDCommand::Mode::PROGRESSIVE,speed,0,speedAltitude,0));
    }

    /*!
     * \brief CvDrone::moveUpperLeft Slot to make the Drone move diagonal in the upper left direction
     */
    void CVDrone::moveUpperLeft()
    {
        commandService->setCommand(new PCMDCommand(PCMDCommand::Mode::PROGRESSIVE,-speed,0,speedAltitude,0));
    }

    /*!
     * \brief CvDrone::moveLowerRight Slot to make the Drone move diagonal in the lower right direction
     */
    void CVDrone::moveLowerRight()
    {
        commandService->setCommand(new PCMDCommand(PCMDCommand::Mode::PROGRESSIVE,speed,0,-speedAltitude,0));
    }

    /*!
     * \brief CvDrone::moveLowerLeft Slot to make the Drone move diagonal in the lower left direction
     */
    void CVDrone::moveLowerLeft()
    {
        commandService->setCommand(new PCMDCommand(PCMDCommand::Mode::PROGRESSIVE,-speed,0,-speedAltitude,0));
    }

    void CVDrone::setMode()
    {
        commandService->setCommand(new PMODECommand());
    }

    /*!
     * \brief CvDrone::getNavdataService returns a pointer of the NavdataService
     * \return NavdataService
     */
    NavdataService* CVDrone::getNavdataService()
    {
        return navdataService;
    }

    /*!
     * \brief CvDrone::getCommandService returns a pointer of the CommandService
     * \return CommandService
     */
    CommandService* CVDrone::getCommandService()
    {
        return commandService;
    }

    /*!
     * \brief CvDrone::getVideoService returns a pointer of the VideoService
     * \return VideoService
     */
    VideoService* CVDrone::getVideoService()
    {
        return videoService;
    }
}
