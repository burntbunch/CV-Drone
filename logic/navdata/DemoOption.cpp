#include "DemoOption.h"

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
        DemoOption::DemoOption(QByteArray& rawData):
            CuteNavdataOption(static_cast<int>(CuteNavdataOption::Tag::DEMO))
        {
            controlState            =   decodeControlState(
                        fetchUnsignedInt32(rawData) >> 16); //TODO: check right shift 16
            flyingState             =   mapControlStateToFlyingState(controlState);
            vbatFlyingPercentage    =   fetchUnsignedInt32(rawData);
            theta                   =   fetchFloat(rawData) / 1000.0f; //TODO: check 1000.0f
            phi                     =   fetchFloat(rawData) / 1000.0f;
            psi                     =   fetchFloat(rawData) / 1000.0f;
            altitude                =   fetchInt32(rawData);
            vx                      =   fetchFloat(rawData);
            vy                      =   fetchFloat(rawData);
            vz                      =   fetchFloat(rawData);
        }

        DemoOption::DemoOption():
            CuteNavdataOption(static_cast<int>(CuteNavdataOption::Tag::DEMO))
        {

        }

        DemoOption::~DemoOption()
        {

        }

        u_int8_t DemoOption::decodeControlState(ControlState state)
        {
            return static_cast<u_int8_t>(state);
        }


        DemoOption::ControlState DemoOption::decodeControlState(u_int8_t state)
        {
            if(state < 10)
                return static_cast<ControlState>(state);
            return static_cast<ControlState>(ControlState::NOT_DEFINED);
        }

        u_int8_t DemoOption::decodeFlyingState(FlyingState state)
        {
            return static_cast<u_int8_t>(state);
        }

        DemoOption::FlyingState DemoOption::decodeFlyingState(u_int8_t state)
        {
            if(state < 4)
                return static_cast<FlyingState>(state);
            return FlyingState::NOT_DEFINED;
        }


        DemoOption::FlyingState DemoOption::mapControlStateToFlyingState(ControlState state)
        {
            switch (state) {
            case ControlState::DEFAULT:
            case ControlState::INIT:
            case ControlState::LANDED:
            case ControlState::TEST:
                return FlyingState::LANDED;

            case ControlState::FLYING:
            case ControlState::HOVERING:
            case ControlState::TRANS_GOTOFIX:
            case ControlState::TRANS_LOOPING:
                return FlyingState::FLYING;

            case ControlState::TRANS_TAKEOFF:
                return FlyingState::TAKE_OFF;

            case ControlState::TRANS_LANDING:
                        return FlyingState::LANDING;
            default:
                return FlyingState::NOT_DEFINED;
            }
        }

        DemoOption::ControlState DemoOption::getCtrlState()
        {
            return controlState;
        }

        DemoOption::FlyingState DemoOption::getFlyingState()
        {
            return flyingState;
        }

        u_int32_t DemoOption::getVbatFlyingPercentage()
        {
            return vbatFlyingPercentage;
        }

        float DemoOption::getTheta()
        {
            return theta;
        }

        float DemoOption::getPhi()
        {
            return phi;
        }

        float DemoOption::getPsi()
        {
            return psi;
        }

        int32_t DemoOption::getAltitude()
        {
            return altitude;
        }

        float DemoOption::getVx()
        {
            return vx;
        }

        float DemoOption::getVy()
        {
            return vy;
        }

        float DemoOption::getVz()
        {
            return vz;
        }
    }
}
