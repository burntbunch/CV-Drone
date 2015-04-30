#include "OpenCVDebugWindow.h"
#include "ui_OpenCVDebugWindow.h"

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

OpenCVDebugWindow::OpenCVDebugWindow(Drone::VideoService *service, ObjectDetection::ObjectDetector *detector, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OpenCVDebugWindow)
{
    ui->setupUi(this);

    this->service = service;
    this->detector = detector;

    this->service->setVerbose(true);
    this->detector->setVerbose(true);

    connect(service,                SIGNAL(nextVerboseString(QString)), this,       SLOT(cvDebugMessageReceived(QString)));
    connect(detector,               SIGNAL(nextVerboseString(QString)), this,       SLOT(cvDebugMessageReceived(QString)));
    connect(ui->buttonOpenCVStop,   SIGNAL(clicked(bool)),              detector,    SLOT(setVerbose(bool)));
    connect(ui->buttonVideoStop,    SIGNAL(clicked(bool)),              service,   SLOT(setVerbose(bool)));
}

OpenCVDebugWindow::~OpenCVDebugWindow()
{
    this->service->setVerbose(false);
    this->detector->setVerbose(false);
    delete ui;
}

/*!
 * \brief OpenCVDebugWindow::closeEvent emits the closed() event
 * \param event this parameter is ignored, but requiered by the super class
 */
void OpenCVDebugWindow::closeEvent(QCloseEvent *event)
{
    emit closed();
}

/*!
 * \brief OpenCVDebugWindow::cvDebugMessageReceived appends a message to the textarea.
 * \param message the message to append.
 * The textarea is limited to 100 lines.
 */
void OpenCVDebugWindow::cvDebugMessageReceived(QString message)
{
    QString string = ui->textOpenCVDebug->toPlainText().append("\n"+message);
    if(string.count("\n") > 100)
        string = string.remove(0, string.indexOf("\n") + 1);
    ui->textOpenCVDebug->setPlainText(string);
    QTextCursor c = ui->textOpenCVDebug->textCursor();
    c.movePosition(QTextCursor::End);
    ui->textOpenCVDebug->setTextCursor(c);
}
