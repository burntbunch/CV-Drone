#include "ReferencesOption.h"

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
        ReferencesOption::ReferencesOption(QByteArray& rawData):
            CuteNavdataOption(static_cast<int>(CuteNavdataOption::Tag::REFERENCES))
        {
            refTheta      = fetchInt32(rawData);
            refPhi        = fetchInt32(rawData);
            refThetaI     = fetchInt32(rawData);
            refPhiI       = fetchInt32(rawData);
            refPitch      = fetchInt32(rawData);
            refRoll       = fetchInt32(rawData);
            refYaw        = fetchInt32(rawData);
            refPsi        = fetchInt32(rawData);
            vxRef         = fetchFloat(rawData);
            vyRef         = fetchFloat(rawData);
            thetaMod      = fetchFloat(rawData);
            phiMod        = fetchFloat(rawData);
            kVX           = fetchFloat(rawData);
            kVY           = fetchFloat(rawData);
            kMode         = fetchUnsignedInt32(rawData);
            uiTime        = fetchFloat(rawData);
            uiTheta       = fetchFloat(rawData);
            uiPhi         = fetchFloat(rawData);
            uiPsi         = fetchFloat(rawData);
            uiPsiAccuracy = fetchFloat(rawData);
            uiSeq         = fetchInt32(rawData);
        }

        ReferencesOption::ReferencesOption():
            CuteNavdataOption(static_cast<int>(CuteNavdataOption::Tag::REFERENCES))
        {

        }

        ReferencesOption::~ReferencesOption()
        {

        }

        int32_t ReferencesOption::getRefTheta()
        {
            return refTheta;
        }

        int32_t ReferencesOption::getRefPhi()
        {
            return refPhi;
        }

        int32_t ReferencesOption::getRefThetaI()
        {
            return refThetaI;
        }

        int32_t ReferencesOption::getRefPhiI()
        {
            return refPhiI;
        }

        int32_t ReferencesOption::getRefPitch()
        {
            return refPitch;
        }

        int32_t ReferencesOption::getRefRoll()
        {
            return refRoll;
        }

        int32_t ReferencesOption::getRefYaw()
        {
            return refYaw;
        }

        int32_t ReferencesOption::getRefPsi()
        {
            return refPsi;
        }

        float ReferencesOption::getVxRef()
        {
            return vxRef;
        }

        float ReferencesOption::getVyRef()
        {
            return vyRef;
        }

        float ReferencesOption::getThetaMod()
        {
            return thetaMod;
        }

        float ReferencesOption::getPhiMod()
        {
            return phiMod;
        }

        float ReferencesOption::getkVX()
        {
            return kVX;
        }

        float ReferencesOption::getkVY()
        {
            return kVY;
        }

        u_int32_t ReferencesOption::getkMode()
        {
            return kMode;
        }

        float ReferencesOption::getUiTime()
        {
            return uiTime;
        }

        float ReferencesOption::getUiTheta()
        {
            return uiTheta;
        }

        float ReferencesOption::getUiPhi()
        {
            return uiPhi;
        }

        float ReferencesOption::getUiPsi()
        {
            return uiPsi;
        }

        float ReferencesOption::getUiPsiAccuracy()
        {
            return uiPsiAccuracy;
        }

        int32_t ReferencesOption::getUiSeq()
        {
            return uiSeq;
        }
    }
}
