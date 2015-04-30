#include "CommandDebugWindow.h"
#include "ui_CommandDebugWindow.h"

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
 * \brief CommandDebugWindow::CommandDebugWindow creates a CommandDebugWindow
 *
 * A window, that shows debug messages from the CommandService
 * \param service
 * \param parent
 */
CommandDebugWindow::CommandDebugWindow(Drone::CommandService *service, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CommandDebugWindow)
{
    ui->setupUi(this);

    this->service = service;
    this->service->setVerbose(true);

    connect(service,                SIGNAL(nextVerboseString(QString)), this,       SLOT(commandDebugMessageReceived(QString)));
    connect(ui->buttonCommandStop,  SIGNAL(clicked(bool)),              service,    SLOT(setVerbose(bool)));
}

/*!
 * \brief CommandDebugWindow::~CommandDebugWindow deletes the CommandDebugWindow
 */
CommandDebugWindow::~CommandDebugWindow()
{
    this->service->setVerbose(false);
    delete ui;
}

/*!
 * \brief CommandDebugWindow::closeEvent emits the closed() event
 * \param event this parameter is ignored, but requiered by the super class
 */
void CommandDebugWindow::closeEvent(QCloseEvent *event)
{
    emit closed();
}

/*!
 * \brief CommandDebugWindow::commandDebugMessageReceived receives a message and displays it
 * \param message
 */
void CommandDebugWindow::commandDebugMessageReceived(QString message)
{
    QString string = ui->textCommandDebug->toPlainText().append("\n"+message);
    if(string.count("\n") > 100)
        string = string.remove(0, string.indexOf("\n") + 1);
    ui->textCommandDebug->setPlainText(string);
    QTextCursor c = ui->textCommandDebug->textCursor();
    c.movePosition(QTextCursor::End);
    ui->textCommandDebug->setTextCursor(c);
}
