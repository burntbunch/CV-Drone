#include "CONFIGCommand.h"

/*
 * CV-Drone
 * Copyright (C) 2015 www.burntbunch.org
 *
 * This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation; either version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License along with this library;
 * if not, write to the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * */

namespace Drone
{
    namespace Command
    {
         /*!
         * \brief CONFIGCommand::CONFIGCommand Sets an configurable option on the drone
         *
         *  This special constructor is only useable for the following ConfigTypes:
         *
         *  ConfigType::NUM_VERSION_SOFT:           ex:         "2.1.18"
         *  ConfigType::SOFT_BUILD_DATE:            ex:         "2012-04-06 12:09"
         *  ConfigType::OWNER_MAC:                  ex:         "00:00:00:00:00:00"
         *  ConfigType::DRONE_SERIAL:               ex:         "XXXXXXXXXX"
         *  ConfigType::ARDRONE_NAME:               ex:         "My ARDrone"
         *  ConfigType::SSID_MULTI_PLAYER:          ex:         "ardrone2_XXXX"
         *  ConfigType::SSID_SINGLE_PLAYER:         ex:         "ardrone2_XXXX"
         *  ConfigType::APPLICATION_DESC:           ex:         "Default application configuration"
         *  ConfigType::PROFILE_DESC:               ex:         "Default profile configuration"
         *  ConfigType::SESSION_DESC:               ex:         "Default session configuration"
         *
         *  The value to be set for the special ConfigType has to be put as a QString and without the double exclemation marks
         *
         * \param ConfigType configType
         * \param QString valueString
         */
        CONFIGCommand::CONFIGCommand(ConfigType configType, QString valueString) : CuteCommand(NULL)
        {

            switch (configType) {
            case ConfigType::NUM_VERSION_SOFT:
            case ConfigType::SOFT_BUILD_DATE:
            case ConfigType::OWNER_MAC:
            case ConfigType::DRONE_SERIAL:
            case ConfigType::ARDRONE_NAME:
            case ConfigType::SSID_MULTI_PLAYER:
            case ConfigType::SSID_SINGLE_PLAYER:
            case ConfigType::APPLICATION_DESC:
            case ConfigType::PROFILE_DESC:
            case ConfigType::SESSION_DESC:
                this->configType = configType;
                this->value = "\"" + valueString + "\"";
                break;
            default:
                //throw std::exception;
                break;
            }


        }
        /*!
         * \brief CONFIGCommand::CONFIGCommand Sets an configurable option on the drone
         *
         *  This special constructor is only useable for the following ConfigTypes:
         *
         *  ConfigType::NUM_VERSION_CONFIG:
         *  ConfigType::NUM_VERSION_MB:
         *  ConfigType::FLYING_TIME:
         *  ConfigType::COM_WATCHDOG:
         *  ConfigType::VBAT_MIN:
         *  ConfigType::PWM_REF_GYROS:
         *  ConfigType::OSCTUN_VALUE:
         *  ConfigType::ALTITUDE_MAX:
         *  ConfigType::ALTITUDE_MIN:
         *  ConfigType::CONTROL_LEVEL:
         *  ConfigType::FLYING_MODE:
         *  ConfigType::WIFI_MODE:
         *  ConfigType::WIFI_RATE:
         *  ConfigType::ULTRASOUND_FREQ:
         *  ConfigType::ULTRASOUND_WATCHDOG:
         *  ConfigType::PIC_VERSION:
         *  ConfigType::CAMIF_FPS:
         *  ConfigType::CODEC_FPS:
         *  ConfigType::CAMIF_BUFFERS:
         *  ConfigType::NUM_TRACKERS:
         *  ConfigType::VIDEO_CODEC:
         *  ConfigType::VIDEO_LIVE_SOCKET:
         *  ConfigType::VIDEO_STORAGE_SPACE:
         *  ConfigType::BITRATE:
         *  ConfigType::MAX_BITRATE:
         *  ConfigType::BITRATE_CTRL_MODE:
         *  ConfigType::BITRATE_STORAGE:
         *  ConfigType::VIDEO_CHANNEL:
         *  ConfigType::VIDEO_FILE_INDEX:
         *  ConfigType::ENEMY_COLORS:
         *  ConfigType::GROUNDSTRIPE_COLORS:
         *  ConfigType::ENEMY_WITHOUT_SHELL:
         *  ConfigType::DETECT_TYPE:
         *  ConfigType::DETECTIONS_SELECT_H:
         *  ConfigType::DETECTIONS_SELECT_V_HSYNC:
         *  ConfigType::DETECTIONS_SELECT_V:
         *  ConfigType::OUTPUT:
         *  ConfigType::MAX_SIZE:
         *  ConfigType::NB_FILES:
         *  ConfigType::USERBOX_CMD:
         *  ConfigType::APPLICATION_ID:
         *  ConfigType::PROFILE_ID:
         *  ConfigType::SESSION_ID:
         *
         * \param QString configType
         * \param int valueInt
         */
        CONFIGCommand::CONFIGCommand(ConfigType configType, int valueInt) : CuteCommand(NULL)
        {
            QString str;
            switch (configType) {
            case ConfigType::NUM_VERSION_CONFIG:
            case ConfigType::NUM_VERSION_MB:
            case ConfigType::FLYING_TIME:
            case ConfigType::COM_WATCHDOG:
            case ConfigType::VBAT_MIN:
            case ConfigType::PWM_REF_GYROS:
            case ConfigType::OSCTUN_VALUE:
            case ConfigType::ALTITUDE_MAX:
            case ConfigType::ALTITUDE_MIN:
            case ConfigType::CONTROL_LEVEL:
            case ConfigType::FLYING_MODE:
            case ConfigType::WIFI_MODE:
            case ConfigType::WIFI_RATE:
            case ConfigType::ULTRASOUND_FREQ:
            case ConfigType::ULTRASOUND_WATCHDOG:
            case ConfigType::PIC_VERSION:
            case ConfigType::CAMIF_FPS:
            case ConfigType::CODEC_FPS:
            case ConfigType::CAMIF_BUFFERS:
            case ConfigType::NUM_TRACKERS:
            case ConfigType::VIDEO_CODEC:
            case ConfigType::VIDEO_LIVE_SOCKET:
            case ConfigType::VIDEO_STORAGE_SPACE:
            case ConfigType::BITRATE:
            case ConfigType::MAX_BITRATE:
            case ConfigType::BITRATE_CTRL_MODE:
            case ConfigType::BITRATE_STORAGE:
            case ConfigType::VIDEO_CHANNEL:
            case ConfigType::VIDEO_FILE_INDEX:
            case ConfigType::ENEMY_COLORS:
            case ConfigType::GROUNDSTRIPE_COLORS:
            case ConfigType::ENEMY_WITHOUT_SHELL:
            case ConfigType::DETECT_TYPE:
            case ConfigType::DETECTIONS_SELECT_H:
            case ConfigType::DETECTIONS_SELECT_V_HSYNC:
            case ConfigType::DETECTIONS_SELECT_V:
            case ConfigType::OUTPUT:
            case ConfigType::MAX_SIZE:
            case ConfigType::NB_FILES:
            case ConfigType::USERBOX_CMD:
            case ConfigType::APPLICATION_ID:
            case ConfigType::PROFILE_ID:
            case ConfigType::SESSION_ID:

                this->configType = configType;
                str = QString::fromStdString(to_string(valueInt));
                this->value = "\"" + str + "\"";
                break;

            default:

                break;
            }

        }

        /*!
         * \brief CONFIGCommand::CONFIGCommand Sets an configurable option on the drone
         *
         *  This special constructor is only useable for the following ConfigTypes:
         *
         *  MAGNETO_RADIUS:
         *  GYRO_OFFSET_THR_X:
         *  GYRO_OFFSET_THR_Y:
         *  GYRO_OFFSET_THR_Z:
         *  EULER_ANGLE_MAX:
         *  CONTROL_IPHONE_TILT:
         *  CONTROL_VZ_MAX:
         *  CONTROL_YAW:
         *  INDOOR_EULER_ANGLE_MAX:
         *  INDOOR_CONTROL_VZ_MAX:
         *  INDOOR_CONTROL_YAW:
         *  OUTDOOR_EULER_ANGLE_MAX:
         *  OUTDOOR_CONTROL_VZ_MAX:
         *  OUTDOOR_CONTROL_YAW:
         *
         * \param ConfigType configType
         * \param float valueFloat
         */

        CONFIGCommand::CONFIGCommand(ConfigType configType, float valueFloat) : CuteCommand(NULL)
        {
            QString str;
            switch (configType) {
            case ConfigType::MAGNETO_RADIUS:
            case ConfigType::GYRO_OFFSET_THR_X:
            case ConfigType::GYRO_OFFSET_THR_Y:
            case ConfigType::GYRO_OFFSET_THR_Z:
            case ConfigType::EULER_ANGLE_MAX:
            case ConfigType::CONTROL_IPHONE_TILT:
            case ConfigType::CONTROL_VZ_MAX:
            case ConfigType::CONTROL_YAW:
            case ConfigType::INDOOR_EULER_ANGLE_MAX:
            case ConfigType::INDOOR_CONTROL_VZ_MAX:
            case ConfigType::INDOOR_CONTROL_YAW:
            case ConfigType::OUTDOOR_EULER_ANGLE_MAX:
            case ConfigType::OUTDOOR_CONTROL_VZ_MAX:
            case ConfigType::OUTDOOR_CONTROL_YAW:

                this->configType = configType;
                str = QString::fromStdString(to_string(valueFloat));
                this->value = "\"" + str + "\"";

                break;
            default:
                break;
            }
        }

        /*!
         * \brief CONFIGCommand::CONFIGCommand Sets an configurable option on the drone
         *
         *  This special constructor is only useable for the following ConfigTypes:
         *
         *  MOTOR_1_SOFT:
         *  MOTOR_1_SUPPLIER:
         *  MOTOR_2_SOFT:
         *  MOTOR_2_HARD:
         *  MOTOR_2_SUPPLIER:
         *  MOTOR_3_SOFT:
         *  MOTOR_3_HARD:
         *  MOTOR_3_SUPPLIER:
         *  MOTOR_4_SOFT:
         *  MOTOR_4_HARD:
         *  MOTOR_4_SUPPLIER:
         *
         *
         * \param ConfigType configType
         * \param double valueDouble
         */
        CONFIGCommand::CONFIGCommand(ConfigType configType, double valueDouble) : CuteCommand(NULL)
        {
            QString str;
            switch (configType) {
            case ConfigType::MOTOR_1_SOFT:
            case ConfigType::MOTOR_1_SUPPLIER:
            case ConfigType::MOTOR_2_SOFT:
            case ConfigType::MOTOR_2_HARD:
            case ConfigType::MOTOR_2_SUPPLIER:
            case ConfigType::MOTOR_3_SOFT:
            case ConfigType::MOTOR_3_HARD:
            case ConfigType::MOTOR_3_SUPPLIER:
            case ConfigType::MOTOR_4_SOFT:
            case ConfigType::MOTOR_4_HARD:
            case ConfigType::MOTOR_4_SUPPLIER:
                this->configType = configType;
                str = QString::fromStdString(to_string(valueDouble));
                this->value = "\"" + str + "\"";
                break;
            default:
                break;
            }
        }

        /*!
         * \brief CONFIGCommand::CONFIGCommand Sets an configurable option on the drone
         *
         *  This special constructor is only useable for the following ConfigTypes:
         *
         *  FLYING_ANIM:                ex:             0,0
         *  LEDS_ANIM:                  ex:             0,0,0
         *
         *  The length of the vector should be :
         *
         *  2   for     FLIGHT_ANIM
         *  3   for     LED_ANIM
         *
         *
         * \param ConfigType configType
         * \param vector<int> valueIntArray
         */

        CONFIGCommand::CONFIGCommand(ConfigType configType, vector<int> valueIntArray) : CuteCommand(NULL)
        {
            QString str;

            switch (configType) {
            case ConfigType::FLIGHT_ANIM:
                if(valueIntArray.size() == 2)
                {
                    this->configType = configType;
                    str.append("{ ");
                    for (const int& i : valueIntArray)
                    {
                        str.append(QString::fromStdString(to_string(i)));
                        str.append(" ");
                    }
                    str.append("}");
                    this->value = "\"" + str + "\"";
                } else
                    std::cerr << "Wrong size of vector for ConfigType : FLIGHT_ANIM" << std::endl;
                break;
            case ConfigType::LEDS_ANIM:
                if(valueIntArray.size() == 3)
                {
                    this->configType = configType;
                    str.append("{ ");
                    for (const int& i : valueIntArray)
                    {
                        str.append(QString::fromStdString(to_string(i)));
                        str.append(" ");
                    }
                    str.append("}");
                    this->value = "\"" + str + "\"";
                    break;
                } else
                    std::cerr << "Wrong size of vector for ConfigType : LEDS_ANIM" << std::endl;
                break;
            default:
                break;
            }
        }

        /*!
         * \brief CONFIGCommand::CONFIGCommand Sets an configurable option on the drone
         *
         *  This special constructor is only useable for the following ConfigTypes:
         *
         *  ACCS_OFFSET:                ex:             { -2.0952554e+03 2.0413781e+03 2.0569382e+03 }
         *  ACCS_GAINS:                 ex:             { 9.8449361e-01 6.2035387e-03 1.4683655e-02 -2.0475569e-03 -9.9886459e-01 -9.5556228e-04 2.9887848e-03 -1.9088354e-02 -9.8093420e-01 }
         *  GYROS_OFFSET:               ex:             { -3.8548752e+01 -1.0268125e+02 -4.3712502e+00 }
         *  GYROS_GAINS:                ex:             { 1.0711575e-03 -1.0726772e-03 -1.0692523e-03 }
         *  GYROS_110_OFFSET:           ex:             { 1.6625000e+03 1.6625000e+03 }
         *  GYROS_110_GAINS:            ex:             { 1.5271631e-03 -1.5271631e-03 }
         *  MAGNETO_OFFSET:             ex:             { 1.2796108e+01 -2.0355328e+02 -5.8370575e+02 }
         *
         *  The length of the vector should be :
         *
         *  3   for     ACCS_OFFSET
         *  9   for     ACCS_GAINS
         *  3   for     GYROS_OFFSET
         *  3   for     GYROS_GAINS
         *  2   for     GYROS_110_OFFSET
         *  2   for     GYROS_110_GAINS
         *  3   for     MAGNETO_OFFSET
         *
         *
         *
         * \param configType
         * \param valueFloatArray
         */

        CONFIGCommand::CONFIGCommand(ConfigType configType, vector<float> valueFloatArray) : CuteCommand(NULL)
        {
            QString str;

            switch (configType) {
            case ConfigType::ACCS_OFFSET:
                if(valueFloatArray.size() == 3)
                {
                    this->configType = configType;
                    str.append("{ ");
                    for(const float& i : valueFloatArray)
                    {
                        str.append(QString::fromStdString(to_string(i)));
                        str.append(" ");
                    }
                    str.append("}");
                    this->value = "\"" + str + "\"";
                } else
                    std::cerr << "Wrong size of vector for ConfigType : ACCS_OFFSET" << std::endl;
                break;
            case ConfigType::ACCS_GAINS:
                if(valueFloatArray.size() == 9)
                {
                    this->configType = configType;
                    str.append("{ ");
                    for(const float& i : valueFloatArray)
                    {
                        str.append(QString::fromStdString(to_string(i)));
                        str.append(" ");
                    }
                    str.append("}");
                    this->value = "\"" + str + "\"";
                } else
                    std::cerr << "Wrong size of vector for ConfigType : ACCS_GAINS" << std::endl;
                break;
            case ConfigType::GYROS_OFFSET:
                if(valueFloatArray.size() == 3)
                {
                    this->configType = configType;
                    str.append("{ ");
                    for(const float& i : valueFloatArray)
                    {
                        str.append(QString::fromStdString(to_string(i)));
                        str.append(" ");
                    }
                    str.append("}");
                    this->value = "\"" + str + "\"";
                } else
                    std::cerr << "Wrong size of vector for ConfigType : GYROS_OFFSET" << std::endl;
                break;
            case ConfigType::GYROS_GAINS:
                if(valueFloatArray.size() == 3)
                {
                    this->configType = configType;
                    str.append("{ ");
                    for(const float& i : valueFloatArray)
                    {
                        str.append(QString::fromStdString(to_string(i)));
                        str.append(" ");
                    }
                    str.append("}");
                    this->value = "\"" + str + "\"";
                } else
                    std::cerr << "Wrong size of vector for ConfigType : GYROS_GAINS" << std::endl;
                break;
            case ConfigType::GYROS_110_OFFSET:
                if(valueFloatArray.size() == 2)
                {
                    this->configType = configType;
                    str.append("{ ");
                    for(const float& i : valueFloatArray)
                    {
                        str.append(QString::fromStdString(to_string(i)));
                        str.append(" ");
                    }
                    str.append("}");
                    this->value = "\"" + str + "\"";
                } else
                    std::cerr << "Wrong size of vector for ConfigType : GYROS_110_OFFSET" << std::endl;
                break;
            case ConfigType::GYROS_110_GAINS:
                if(valueFloatArray.size() == 2)
                {
                    this->configType = configType;
                    str.append("{ ");
                    for(const float& i : valueFloatArray)
                    {
                        str.append(QString::fromStdString(to_string(i)));
                        str.append(" ");
                    }
                    str.append("}");
                    this->value = "\"" + str + "\"";
                } else
                    std::cerr << "Wrong size of vector for ConfigType : GYROS_110_GAINS" << std::endl;
                break;
            case ConfigType::MAGNETO_OFFSET:
                if(valueFloatArray.size() == 3)
                {
                    this->configType = configType;
                    str.append("{ ");
                    for(const float& i : valueFloatArray)
                    {
                        str.append(QString::fromStdString(to_string(i)));
                        str.append(" ");
                    }
                    str.append("}");
                    this->value = "\"" + str + "\"";
                } else
                    std::cerr << "Wrong size of vector for ConfigType : MAGNETO_OFFSET" << std::endl;
                break;
            default:
                break;
            }
        }

        /*!
         * \brief CONFIGCommand::CONFIGCommand Sets an configurable option on the drone
         *
         *  This special constructor is only useable for the following ConfigTypes:
         *
         *  NAVDATA_DEMO:
         *  VIDEO_ENABLE:
         *  VISION_ENABLE:
         *  OSCTUN_TEST:
         *  OUTDOOR:
         *  FLIGHT_WITHOUT_SHELL:
         *  AUTONOMOUS_FLIGHT:
         *  MANUAL_TRIM:
         *  VIDEO_ON_USB:
         *
         *
         * \param ConfigType configType
         * \param bool valueBool
         */
        CONFIGCommand::CONFIGCommand(ConfigType configType, bool valueBool) : CuteCommand(NULL)
        {

            QString str;

            switch (configType) {
            case ConfigType::NAVDATA_DEMO:
            case ConfigType::VIDEO_ENABLE:
            case ConfigType::VISION_ENABLE:
            case ConfigType::OSCTUN_TEST:
            case ConfigType::OUTDOOR:
            case ConfigType::FLIGHT_WITHOUT_SHELL:
            case ConfigType::AUTONOMOUS_FLIGHT:
            case ConfigType::MANUAL_TRIM:
            case ConfigType::VIDEO_ON_USB:
                this->configType = configType;
                if(valueBool)
                {
                    str = "TRUE";
                } else
                {
                    str = "FALSE";
                }
                this->value = "\"" + str + "\"";
                break;
            default:
                break;
            }
        }
        /*!
         * \brief CONFIGCommand::getCommand Creates the explicit CuteCommand of this type
         *
         * The sequence number is incremented with every call
         *
         * \return QString
         */
        QString CONFIGCommand::getCommand()
        {
            return QString("AT*CONFIG=%1,%2,%3\r")
                   .arg(getNextSequenceNumber())
                   .arg(toString.at(static_cast<int>(configType)))
                    .arg(value);
        }

        CONFIGCommand::~CONFIGCommand()
        {

        }

        /*!
         * \brief CONFIGCommand::operator == Correct overriden equals method
         *
         * The equals method is transitiv, reflexiv and semetric
         *
         * \param CuteCommand* t
         * \return bool
         */
        bool CONFIGCommand::operator ==(CuteCommand *t) const
        {
            if(typeid(*t).name() == typeid(*this).name())
            {
                CONFIGCommand *tmp = dynamic_cast<CONFIGCommand*>(t);
                if(tmp->configType == this->configType && tmp->value == this->value)
                {
                    return true;
                }
            }
            return false;
        }
    }
}

