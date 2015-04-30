#include "VideoService.h"

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
     * \brief VideoService::VideoService The service will provide the video from the drone.
     * \param droneIP the ip of the drone
     * \param port the port number of the video port
     * \param parent QObject parent
     *
     * The current frame can be accessed with getMatrix(), when the nextFrameReady() signal is emited.
     */
    VideoService::VideoService(QString droneIP, int port, QObject *parent) :
        CuteService(droneIP, port, parent)
    {
        capture = new cv::VideoCapture();
        fps = -1;
        lostConnection = true;
        lostTimer = new QTimer(this);
        lostTimer->setInterval(2000);
        timer->setInterval(100000);

        connect(lostTimer,      SIGNAL(timeout()), this,    SLOT(checkLost()));
        connect(timer,          SIGNAL(timeout()), this,    SLOT(checkFrame()));
        connect(workerThread,   SIGNAL(started()), this,    SLOT(provision()));
        connect(workerThread,   SIGNAL(started()), timer,   SLOT(start()));

        tcpString = "tcp://" + droneIP + ":" + QString::number(port);
        moveToThread(workerThread);
    }

    VideoService::~VideoService()
    {
        stop();
        delete capture;
        if(verbose)
            emit nextVerboseString("VideoService destroyed");
    }

    /*!
     * \brief VideoService::getFps returns the current fps or -1 when the camera couldn't be opened.
     * \return
     */
    int VideoService::getFps() const
    {
        return fps;
    }

    /*!
     * \brief VideoService::getMatrix returns the current frame.
     * \return
     */
    cv::Mat VideoService::getMatrix()
    {
        return frame.clone();
    }

    /*!
     * \brief VideoService::start starts the object thread.
     */
    void VideoService::start()
    {
        workerThread->start();
    }

    /*!
     * \brief VideoService::stop stops the timers and the object thread.
     */
    void VideoService::stop()
    {
        lostTimer->stop();
        timer->stop();
        workerThread->quit();
        workerThread->wait();
    }

    /*!
     * \brief VideoService::reconnect stops the timer and flushes the socket.
     * The connectToDrone() method will be called after 500ms.
     */
    void VideoService::reconnect()
    {
        if(timer->isActive())
            timer->stop();
        capture->release();
        delete capture;
        QThread::msleep(500);
        capture = new cv::VideoCapture();
        connectToDrone();
    }

    /*!
     * \brief VideoService::provision is called when the object thread is started.
     * The service will call connectToDrone() and starts the lostTimer.
     */
    void VideoService::provision()
    {
        connectToDrone();
        lostTimer->start();
    }

    /*!
     * \brief VideoService::checkLost checks the state of the connection (every 2000ms).
     * If the connection is lost the connectionLost() signal is emited.
     */
    void VideoService::checkLost()
    {
        if(lostConnection)
            emit connectionLost();
        lostConnection = true;
    }

    /*!
     * \brief VideoService::checkFrame Tries to receive a new frame every (1000 / fps)-10ms.
     * The nextFrameReady() signal is emited, when a new frame is received.
     */
    void VideoService::checkFrame()
    {
        if(fps == -1)
        {
            if(verbose)
                emit nextVerboseString("Invalid FPS. Stopping");
            timer->stop();
            return;
        }
        cv::Mat frame;
        if(!capture->read(frame))
        {
            if(verbose)
                emit nextVerboseString("Can't read from capture");
            return;
        }

        if(frame.rows <=  0 || frame.cols <= 0)
        {
            if(verbose)
                emit nextVerboseString("Invalid capture read");
            return;
        }

        int currentFps = capture->get(CV_CAP_PROP_FPS);
        if(fps != currentFps)
        {
            fps = currentFps;
            /* Set timeout interval. The default is 1 second */
            timer->stop();
            timer->setInterval((fps == -1) ? 1000 : std::round(1000.0f / fps) - 10);
            timer->start();
            if(verbose)
                emit nextVerboseString("FPS changed to: " + QString::number(fps));
        }
        this->frame = frame;
        lostConnection = false;
        emit nextFrameReady();
    }

    /*!
     * \brief VideoService::connectToDrone tries to connect to the drone and se the fps.
     */
    void VideoService::connectToDrone()
    {
        if(!capture->open(tcpString.toStdString()))
        {
            if(verbose)
                emit nextVerboseString("Can't open VideoCapture on: " + tcpString);
        }
        else
        {
            if(verbose)
                emit nextVerboseString("Successfully opened VideoCapture on: " + tcpString);
        }
        fps = capture->get(CV_CAP_PROP_FPS);
        if(verbose)
            emit nextVerboseString("FPS is set to:" + QString::number(fps));
        if(fps <= 10)
            fps = -1;

        /* Read frames to clear FFMPEG-buffer */
        cv::Mat frame;
        for(int i = 0; i <= 1500; i++)
            capture->read(frame);
        /* Set timeout interval. The default is 1 second */
        timer->stop();
        timer->setInterval((fps == -1) ? 1000 : std::round(1000.0f / fps) - 10);
        timer->start();
    }

}

