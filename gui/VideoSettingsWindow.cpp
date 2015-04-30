#include "VideoSettingsWindow.h"
#include "ui_VideoSettingsWindow.h"

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
 * \brief VideoSettingsWindow::VideoSettingsWindow creates a VideoSettingsWindow
 * \param detector
 * \param parent
 */
VideoSettingsWindow::VideoSettingsWindow(ObjectDetection::ObjectDetector *detector, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VideoSettingsWindow)
{
    ui->setupUi(this);

    confirmed       = false;
    configFile      = &Drone::ConfigFile::getInstance();
    this->detector  = detector;

    connect(ui->sliderMinR,     SIGNAL(valueChanged(int)), detector, SLOT(setMinR(int)));
    connect(ui->sliderMinG,     SIGNAL(valueChanged(int)), detector, SLOT(setMinG(int)));
    connect(ui->sliderMinB,     SIGNAL(valueChanged(int)), detector, SLOT(setMinB(int)));
    connect(ui->sliderMaxR,     SIGNAL(valueChanged(int)), detector, SLOT(setMaxR(int)));
    connect(ui->sliderMaxG,     SIGNAL(valueChanged(int)), detector, SLOT(setMaxG(int)));
    connect(ui->sliderMaxB,     SIGNAL(valueChanged(int)), detector, SLOT(setMaxB(int)));
    connect(ui->sliderRadius,   SIGNAL(valueChanged(int)), detector, SLOT(setRadius(int)));

    connect(ui->buttonReset,    SIGNAL(clicked()),         this,     SLOT(reset()));
    connect(ui->buttonCancel,   SIGNAL(clicked()),         this,     SLOT(cancel()));
    connect(ui->buttonOK,       SIGNAL(clicked()),         this,     SLOT(confirm()));

    loadFromConfig();
}

/*!
 * \brief VideoSettingsWindow::~VideoSettingsWindow deletes the VideoSettingsWindow
 */
VideoSettingsWindow::~VideoSettingsWindow()
{
    delete ui;
}

/*!
 * \brief VideoSettingsWindow::show sets confirmed to false
 */
void VideoSettingsWindow::show()
{
    QWidget::show();
    confirmed = false;
}

/*!
 * \brief VideoSettingsWindow::closeEvent emits the closed() event
 * \param event this parameter is ignored, but requiered by the super class
 * If the confirmed variable is set to true the current state of the config file will be written.
 */
void VideoSettingsWindow::closeEvent(QCloseEvent *event)
{
    if(confirmed)
        configFile->writeToFile();
    emit closed();
}

/*!
 * \brief VideoSettingsWindow::loadFromConfig sets the slider values to the values in the config file.
 */
void VideoSettingsWindow::loadFromConfig()
{
    ui->sliderMinR->setValue(configFile->getMinR());
    ui->sliderMinG->setValue(configFile->getMinG());
    ui->sliderMinB->setValue(configFile->getMinB());

    ui->sliderMaxR->setValue(configFile->getMaxR());
    ui->sliderMaxG->setValue(configFile->getMaxG());
    ui->sliderMaxB->setValue(configFile->getMaxB());

    ui->sliderRadius->setValue(configFile->getRadius());
}

/*!
 * \brief VideoSettingsWindow::reset resets the config file to default and calls loadFromConfig()
 */
void VideoSettingsWindow::reset()
{
    configFile->resetToDefault();
    loadFromConfig();
}

/*!
 * \brief VideoSettingsWindow::cancel closes the window.
 */
void VideoSettingsWindow::cancel()
{
    close();
}

/*!
 * \brief VideoSettingsWindow::confirm sets confirmed to true and closes the window.
 */
void VideoSettingsWindow::confirm()
{
    confirmed = true;
    close();
}
