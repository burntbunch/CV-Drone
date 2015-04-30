#include "ConfigFile.h"

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
     * \brief ConfigFile::ConfigFile Creates an Object of a ConfigFile and fills the object with default values
     */
    ConfigFile::ConfigFile()
    {
        resetToDefault();
    }

    /*!
     * \brief ConfigFile::writeToFile Writes the given Config to the specified file given in the constructor
     *
     * This Method writes the Config variables to the file which was given in the Constructor of the ConfigFile class.
     * It is writen in JSON syntax with the following structure:
     *
     * "ip"             , ip (String)
     * "NavdataPort"    , navdataPort (int)
     * "VideoPort"      , videoPort (int)
     * "CommandPort"    , commandPort (int)
     * "speed"          , speed (int)
     * "speedAltitude"  , speedAltitude (int)
     * "minR"           , minR (int)
     * "minG"           , minG (int)
     * "minB"           , minB (int)
     * "maxR"           , minR (int)
     * "maxG"           , maxG (int)
     * "maxB"           , maxB (int)
     * "radius"         , radius (int)
     *
     * \return the status of the saving process (as a boolean)
     */
    bool ConfigFile::writeToFile()
    {
        mutex.lock();

        QFile saveFile(fileName);

        if(saveFile.open(QIODevice::WriteOnly)){
            serialize();

            QJsonDocument sv(jsonObject);

            saveFile.write(sv.toJson());
            mutex.unlock();
            return true;
        }
        mutex.unlock();

        return false;
    }

    /*!
     * \brief ConfigFile::resetToDefault restores the default values
     *
     * Restores the default values and resialize the jsonObject.
     */
    void ConfigFile::resetToDefault()
    {
        fileName        = "save.json";
        ip              = "192.168.1.1";
        navdataPort     = 5554;
        videoPort       = 5555;
        commandPort     = 5556;
        speed           = 0.08f;
        //TODO: 0.3f
        speedAltitude   = 0.4f;
        minR            = 100;
        minG            = 20;
        minB            = 20;
        maxR            = 255;
        maxG            = 41;
        maxB            = 41;
        radius          = 50;
        serialize();
    }

    /*!
     * \brief ConfigFile::getInstance returns a static Object of the ConfigFile class
     *
     * \return a static Object of the ConfigFile class
     */
    ConfigFile &ConfigFile::getInstance()
    {
        static ConfigFile instance;
        return instance;
    }


    /*!
     * \brief ConfigFile::readFromFile reads the configuration from a file, given in the Constructor of this class
     *
     * \return the status of the reading process (as boolean)
     */
    bool ConfigFile::readFromFile()
    {
        mutex.lock();

        QFile loadFile(fileName);

        if(!loadFile.exists())
        {
            mutex.unlock();
            if(!writeToFile())
            {
                qWarning("Can't write to file!");
                mutex.unlock();
                return false;
            }
        }
        if (!loadFile.open(QIODevice::ReadOnly))
        {
            qWarning("Couldn't open save file.");
            mutex.unlock();
            return false;
        }

        QByteArray saveData = loadFile.readAll();

        QJsonDocument loadDoc(QJsonDocument::fromJson(saveData));
        jsonObject = loadDoc.object();

        deserialize();

        mutex.unlock();

        return true;
    }

    /*!
     * \brief ConfigFile::serialize writes all data to the jsonObject
     */
    void ConfigFile::serialize()
    {
        jsonObject.insert("ip", QJsonValue(ip));
        jsonObject.insert("navdataPort", QJsonValue(navdataPort));
        jsonObject.insert("videoPort", QJsonValue(videoPort));
        jsonObject.insert("commandPort", QJsonValue(commandPort));
        jsonObject.insert("speed", QJsonValue(speed*100));
        jsonObject.insert("speedAltitude", QJsonValue(speedAltitude*100));
        jsonObject.insert("minR", QJsonValue(minR));
        jsonObject.insert("minG", QJsonValue(minG));
        jsonObject.insert("minB", QJsonValue(minB));
        jsonObject.insert("maxR", QJsonValue(maxR));
        jsonObject.insert("maxG", QJsonValue(maxG));
        jsonObject.insert("maxB", QJsonValue(maxB));
        jsonObject.insert("radius", QJsonValue(radius));
    }

    /*!
     * \brief ConfigFile::deserialize reads all data from the jsonObject
     */
    void ConfigFile::deserialize()
    {
        ip              = jsonObject["ip"].toString();
        navdataPort     = jsonObject["navdataPort"].toInt();
        videoPort       = jsonObject["videoPort"].toInt();
        commandPort     = jsonObject["commandPort"].toInt();
        speed           = jsonObject["speed"].toInt()/100.0;
        speedAltitude   = jsonObject["speedAltitude"].toInt()/100.0;
        minR            = jsonObject["minR"].toInt();
        minG            = jsonObject["minG"].toInt();
        minB            = jsonObject["minB"].toInt();
        maxR            = jsonObject["maxR"].toInt();
        maxG            = jsonObject["maxG"].toInt();
        maxB            = jsonObject["maxB"].toInt();
        radius          = jsonObject["radius"].toInt();
    }

    /*!
     * \brief ConfigFile::getRadius returns the radius in which an object is detected
     *
     * \return
     */
    int ConfigFile::getRadius() const
    {
        return radius;
    }

    /*!
     * \brief ConfigFile::setRadius sets the radius in which an object is detected
     *
     * \param value
     */
    void ConfigFile::setRadius(int value)
    {
        radius = value;
    }

    /*!
     * \brief ConfigFile::getMaxB returns the maximum value of the colorcode blue for the ObjectDetector
     *
     * \return
     */
    int ConfigFile::getMaxB() const
    {
        return maxB;
    }

    /*!
     * \brief ConfigFile::setMaxB sets the maximum value of the colorcode blue for the ObjectDetector
     *
     * \param value
     */
    void ConfigFile::setMaxB(int value)
    {
        maxB = value;
    }

    /*!
     * \brief ConfigFile::getMaxG returns the maximum value of the colorcode green for the ObjectDetector
     *
     * \return
     */
    int ConfigFile::getMaxG() const
    {
        return maxG;
    }

    /*!
     * \brief ConfigFile::setMaxG sets the maximum value of the colorcode green for the ObjectDetector
     *
     * \param value
     */
    void ConfigFile::setMaxG(int value)
    {
        maxG = value;
    }

    /*!
     * \brief ConfigFile::getMaxR returns the maximum value of the colorcode red for the ObjectDetector
     *
     * \return
     */
    int ConfigFile::getMaxR() const
    {
        return maxR;
    }

    /*!
     * \brief ConfigFile::setMaxR sets the maximum value of the colorcode red for the ObjectDetector
     *
     * \param value
     */
    void ConfigFile::setMaxR(int value)
    {
        maxR = value;
    }

    /*!
     * \brief ConfigFile::getMinB returns the minimum value of the colorcode blue for the ObjectDetector
     *
     * \return
     */
    int ConfigFile::getMinB() const
    {
        return minB;
    }

    /*!
     * \brief ConfigFile::setMinB sets the minimum value of the colorcode blue for the ObjectDetector
     *
     * \param value
     */
    void ConfigFile::setMinB(int value)
    {
        minB = value;
    }

    /*!
     * \brief ConfigFile::getMinG returns the minimum value of the colorcode green for the ObjectDetector
     *
     * \return
     */
    int ConfigFile::getMinG() const
    {
        return minG;
    }

    /*!
     * \brief ConfigFile::setMinG sets the minimum value of the colorcode green for the ObjectDetector
     *
     * \param value
     */
    void ConfigFile::setMinG(int value)
    {
        minG = value;
    }

    /*!
     * \brief ConfigFile::getMinR returns minimum value of the colorcode red for the ObjectDetector
     *
     * \return
     */
    int ConfigFile::getMinR() const
    {
        return minR;
    }

    /*!
     * \brief ConfigFile::setMinR sets the minimum value of the colorcode red for the ObjectDetector
     *
     * \param value
     */
    void ConfigFile::setMinR(int value)
    {
        minR = value;
    }

    /*!
     * \brief ConfigFile::getFileName returns the current FileName as a QString
     *
     * \return the current FileName as a QString
     */
    QString ConfigFile::getFileName()
    {
        return fileName;
    }

    /*!
     * \brief ConfigFile::setFileName sets the current FileName
     *
     * \param fileName
     */
    void ConfigFile::setFileName(QString fileName)
    {
        this->fileName = fileName;
    }

    /*!
     * \brief ConfigFile::getNavdataPort returns the NavdataPort of a given configuration
     *
     * \return navdataPort
     */
    int ConfigFile::getNavdataPort() const
    {
        return navdataPort;
    }

    /*!
     * \brief ConfigFile::getVideoPort returns the VideoPort of a given configuration
     *
     * \return videoPort
     */
    int ConfigFile::getVideoPort() const
    {
        return videoPort;
    }

    /*!
     * \brief ConfigFile::getCommandPort returns the CommandPort of a given configuration
     *
     * \return commandPort
     */
    int ConfigFile::getCommandPort() const
    {
        return commandPort;
    }

    /*!
     * \brief ConfigFile::getIp returns the IP of the Drone from a given configuration
     *
     * \return ip
     */
    QString ConfigFile::getIp() const
    {
        return ip;
    }
    /*!
     * \brief ConfigFile::getSpeed returns the speed of the Drone from a given configuration
     *
     * \return speed
     */
    float ConfigFile::getSpeed() const
    {
        return speed;
    }

    /*!
     * \brief ConfigFile::getSpeedAltitude returns the speedAltitude of the Drone from a given configuration
     *
     * \return speedAltitude
     */
    float ConfigFile::getSpeedAltitude() const
    {
        return speedAltitude;
    }
}
