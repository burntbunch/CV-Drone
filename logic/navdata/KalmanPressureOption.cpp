#include "KalmanPressureOption.h"

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
        KalmanPressureOption::KalmanPressureOption(QByteArray& rawData):
            CuteNavdataOption(static_cast<int>(CuteNavdataOption::Tag::KALMAN_PRESSURE))
        {
            offsetPressure      = fetchFloat(rawData);
            estZ                = fetchFloat(rawData);
            estZdot             = fetchFloat(rawData);
            estBiasPwm          = fetchFloat(rawData);
            estBiaisPression    = fetchFloat(rawData);
            offsetUs            = fetchFloat(rawData);
            predictionUs        = fetchFloat(rawData);
            covAlt              = fetchFloat(rawData);
            covPwm              = fetchFloat(rawData);
            covVitesse          = fetchFloat(rawData);
            boolEffetSol        = fetchBool(rawData);
            sommeInno           = fetchFloat(rawData);
            flagRejetUs         = fetchBool(rawData);
            uMultisinus         = fetchFloat(rawData);
            gazAltitude         = fetchFloat(rawData);
            flagMultisinus      = fetchBool(rawData);
            flagMultisinusDebut = fetchBool(rawData);
        }

        KalmanPressureOption::KalmanPressureOption():
            CuteNavdataOption(static_cast<int>(CuteNavdataOption::Tag::KALMAN_PRESSURE))
        {

        }

        KalmanPressureOption::~KalmanPressureOption()
        {

        }

        float KalmanPressureOption::getOffsetPressure()
        {
            return offsetPressure;
        }

        float KalmanPressureOption::getEstZ()
        {
            return estZ;
        }

        float KalmanPressureOption::getEstZdot()
        {
            return estZdot;
        }

        float KalmanPressureOption::getEstBiasPwm()
        {
            return estBiasPwm;
        }

        float KalmanPressureOption::getEstBiaisPression()
        {
            return estBiaisPression;
        }

        float KalmanPressureOption::getOffsetUs()
        {
            return offsetUs;
        }

        float KalmanPressureOption::getPredictionUs()
        {
            return predictionUs;
        }

        float KalmanPressureOption::getCovAlt()
        {
            return covAlt;
        }

        float KalmanPressureOption::getCovPwm()
        {
            return covPwm;
        }

        float KalmanPressureOption::getCovVitesse()
        {
            return covVitesse;
        }

        bool KalmanPressureOption::isBoolEffetSol()
        {
            return boolEffetSol;
        }

        float KalmanPressureOption::getSommeInno()
        {
            return sommeInno;
        }

        bool KalmanPressureOption::isFlagRejetUs()
        {
            return flagRejetUs;
        }

        float KalmanPressureOption::getuMultisinus()
        {
            return uMultisinus;
        }

        float KalmanPressureOption::getGazAltitude()
        {
            return gazAltitude;
        }

        bool KalmanPressureOption::isFlagMultisinus()
        {
            return flagMultisinus;
        }

        bool KalmanPressureOption::isFlagMultisinusDebut()
        {
            return flagMultisinusDebut;
        }
    }
}
