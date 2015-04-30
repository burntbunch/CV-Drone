#include "RawMeasuresOption.h"

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
    namespace Navdata
    {
        RawMeasuresOption::RawMeasuresOption(QByteArray& rawData):
            CuteNavdataOption(static_cast<int>(CuteNavdataOption::Tag::RAW_MEASURES))
        {
            rawAccs             =   fetchUnsignedInt16Vector(rawData, 3);
            rawGyros            =   fetchInt16Vector(rawData, 3);
            rawGyros110         =   fetchInt16Vector(rawData, 2);
            vbatRaw             =   fetchUnsignedInt32(rawData);
            usDebutEcho         =   fetchUnsignedInt16(rawData);
            usFinEcho           =   fetchUnsignedInt16(rawData);
            usAssociationEcho   =   fetchUnsignedInt16(rawData);
            usDistanceEcho      =   fetchUnsignedInt16(rawData);
            usCourbeTemps       =   fetchUnsignedInt16(rawData);
            usCourbeValeur      =   fetchUnsignedInt16(rawData);
            usCourbeRef         =   fetchUnsignedInt16(rawData);
            flagEchoIni         =   fetchUnsignedInt16(rawData);
            nbEcho              =   fetchUnsignedInt16(rawData);
            sumEcho             =   fetchUnsignedInt32(rawData);
            altTempRaw          =   fetchInt32(rawData);
            gradient            =   fetchInt16(rawData);
        }

        RawMeasuresOption::RawMeasuresOption():
            CuteNavdataOption(static_cast<int>(CuteNavdataOption::Tag::RAW_MEASURES))
        {

        }

        RawMeasuresOption::~RawMeasuresOption()
        {

        }

        vector<u_int16_t> RawMeasuresOption::getRawAccs()
        {
            return rawAccs;
        }

        vector<int16_t> RawMeasuresOption::getRawGyros()
        {
            return rawGyros;
        }

        vector<int16_t> RawMeasuresOption::getRawGyros110()
        {
            return rawGyros110;
        }

        u_int16_t RawMeasuresOption::getVbatRaw()
        {
            return vbatRaw;
        }

        u_int16_t RawMeasuresOption::getUsDebutEcho()
        {
            return usDebutEcho;
        }

        u_int16_t RawMeasuresOption::getUsFinEcho()
        {
            return usFinEcho;
        }

        u_int16_t RawMeasuresOption::getUsAssociationEcho()
        {
            return usAssociationEcho;
        }

        u_int16_t RawMeasuresOption::getUsDistanceEcho()
        {
            return usDistanceEcho;
        }

        u_int16_t RawMeasuresOption::getUsCourbeTemps()
        {
            return usCourbeTemps;
        }

        u_int16_t RawMeasuresOption::getUsCourbeValeur()
        {
            return usCourbeValeur;
        }

        u_int16_t RawMeasuresOption::getUsCourbeRef()
        {
            return usCourbeRef;
        }

        u_int16_t RawMeasuresOption::getFlagEchoIni()
        {
            return flagEchoIni;
        }

        u_int16_t RawMeasuresOption::getNbEcho()
        {
            return nbEcho;
        }

        u_int32_t RawMeasuresOption::getSumEcho()
        {
            return sumEcho;
        }

        int32_t RawMeasuresOption::getAltTempRaw()
        {
            return altTempRaw;
        }

        int16_t RawMeasuresOption::getGradient()
        {
            return gradient;
        }
    }
}
