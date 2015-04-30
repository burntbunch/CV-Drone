#include "ControlWindow.h"
#include "ui_ControlWindow.h"

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

ControlWindow::ControlWindow(Drone::CVDrone *cvDrone, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ControlWindow)
{
    flying = false;

    ui->setupUi(this);
    this->cvDrone = cvDrone;

    setFocusPolicy(Qt::FocusPolicy::NoFocus);

    connect(ui->buttonDown,     SIGNAL(pressed()), cvDrone,   SLOT(moveDown()));
    connect(ui->buttonUp,       SIGNAL(pressed()), cvDrone,   SLOT(moveUp()));
    connect(ui->buttonLeft,     SIGNAL(pressed()), cvDrone,   SLOT(moveLeft()));
    connect(ui->buttonRight,    SIGNAL(pressed()), cvDrone,   SLOT(moveRight()));
    connect(ui->buttonForward,  SIGNAL(pressed()), cvDrone,   SLOT(moveForward()));
    connect(ui->buttonBackward, SIGNAL(pressed()), cvDrone,   SLOT(moveBackward()));
    connect(ui->buttonTurnLeft, SIGNAL(pressed()), cvDrone,   SLOT(turnLeft()));
    connect(ui->buttonTurnRight,SIGNAL(pressed()), cvDrone,   SLOT(turnRight()));

    connect(ui->buttonDown,     SIGNAL(released()), cvDrone,  SLOT(hover()));
    connect(ui->buttonUp,       SIGNAL(released()), cvDrone,  SLOT(hover()));
    connect(ui->buttonLeft,     SIGNAL(released()), cvDrone,  SLOT(hover()));
    connect(ui->buttonRight,    SIGNAL(released()), cvDrone,  SLOT(hover()));
    connect(ui->buttonForward,  SIGNAL(released()), cvDrone,  SLOT(hover()));
    connect(ui->buttonBackward, SIGNAL(released()), cvDrone,  SLOT(hover()));
    connect(ui->buttonTurnLeft, SIGNAL(released()), cvDrone,  SLOT(hover()));
    connect(ui->buttonTurnRight,SIGNAL(released()), cvDrone,  SLOT(hover()));
}

ControlWindow::~ControlWindow()
{
    delete ui;
}

/*!
 * \brief ControlWindow::closeEvent emits the closed() event
 * \param event this parameter is ignored, but requiered by the super class
 */
void ControlWindow::closeEvent(QCloseEvent *event)
{
    emit closed();
}

void ControlWindow::keyPressEvent(QKeyEvent *event)
{
    if(!event->isAutoRepeat())
    {
        switch(event->key())
        {
            case Qt::Key_W:
                cvDrone->moveForward();
                return;
            case Qt::Key_A:
                cvDrone->moveLeft();
                return;
            case Qt::Key_S:
                cvDrone->moveBackward();
                return;
            case Qt::Key_D:
                cvDrone->moveRight();
                return;
            case Qt::Key_Up:
                cvDrone->moveUp();
                return;
            case Qt::Key_Down:
                cvDrone->moveDown();
                return;
            case Qt::Key_Left:
                cvDrone->turnLeft();
                return;
            case Qt::Key_Right:
                cvDrone->turnRight();
                return;
            case Qt::Key_Space:
                if(flying)
                    cvDrone->land();
                else
                    cvDrone->takeOff();
                flying = !flying;
                return;
            case Qt::Key_Escape:
                cvDrone->emergency();
                return;
        }
        QWidget::keyPressEvent(event);
    }
}

void ControlWindow::keyReleaseEvent(QKeyEvent *event)
{
    if(!event->isAutoRepeat() & event->key() != Qt::Key_Escape & event->key() != Qt::Key_Space)
    {
        cvDrone->hover();
        return;
    }
    QWidget::keyReleaseEvent(event);
}
