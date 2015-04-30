#include "VisionDetectOption.h"

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
        VisionDetectOption::VisionDetectOption(QByteArray& rawData):
            CuteNavdataOption(static_cast<int>(CuteNavdataOption::Tag::VISION_DETECT))
        {
            int nbDetections                                = 4; //NB_DETECTIONS
            nbDetected                                      = fetchUnsignedInt32(rawData);
            type                                            = fetchUnsignedInt32Vector(rawData,nbDetections);
            xc                                              = fetchUnsignedInt32Vector(rawData, nbDetections);
            yc                                              = fetchUnsignedInt32Vector(rawData, nbDetections);
            width                                           = fetchUnsignedInt32Vector(rawData, nbDetections);
            height                                          = fetchUnsignedInt32Vector(rawData, nbDetections);
            distance                                        = fetchUnsignedInt32Vector(rawData, nbDetections);
            orientationAngle                                = fetchFloatVector(rawData, nbDetections);

            for(int i=0;i<nbDetections;i++)
                rotation.push_back(fetchFloatMatrix(rawData,3,3));

            for(int i=0; i<nbDetections;i++)
                translation.push_back(fetchFloatVector(rawData,3));

            cameraSource                                    = fetchUnsignedInt32Vector(rawData, nbDetections);

        }

        VisionDetectOption::VisionDetectOption():
            CuteNavdataOption(static_cast<int>(CuteNavdataOption::Tag::VISION_DETECT))
        {

        }

        VisionDetectOption::~VisionDetectOption()
        {

        }

        u_int32_t VisionDetectOption::getNbDetected() const
        {
            return nbDetected;
        }

        vector<u_int32_t> VisionDetectOption::getType() const
        {
            return type;
        }

        vector<u_int32_t> VisionDetectOption::getXc() const
        {
            return xc;
        }

        vector<u_int32_t> VisionDetectOption::getYc() const
        {
            return yc;
        }

        vector<u_int32_t> VisionDetectOption::getWidth() const
        {
            return width;
        }

        vector<u_int32_t> VisionDetectOption::getHeight() const
        {
            return height;
        }

        vector<u_int32_t> VisionDetectOption::getDistance() const
        {
            return distance;
        }

        vector<float> VisionDetectOption::getOrientationAngle() const
        {
            return orientationAngle;
        }

        vector<vector<vector<float> > > VisionDetectOption::getRotation() const
        {
            return rotation;
        }

        vector<vector<float> > VisionDetectOption::getTranslation() const
        {
            return translation;
        }

        vector<u_int32_t> VisionDetectOption::getCameraSource() const
        {
            return cameraSource;
        }
    }
}
