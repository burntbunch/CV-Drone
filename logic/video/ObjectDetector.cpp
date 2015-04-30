#include "ObjectDetector.h"

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

namespace ObjectDetection
{

    ObjectDetector::ObjectDetector(Drone::VideoService *service, QObject *parent) : QObject(parent)
    {
        lastSeenIn = -1;
        config          = &Drone::ConfigFile::getInstance();
        this->service   = service;
        thread = new QThread(this);
        verbose         = false;
        autopilot       = false;
        activated       = false;
        searchEmited    = false;

        thread->start();
        moveToThread(thread);
    }

    ObjectDetector::~ObjectDetector()
    {
        thread->quit();
        thread->wait();
    }

    /*!
     * \brief ObjectDetector::connectionLost
     *
     * If no frame could be received from the AR Drone a black screen with
     * the text "No frame found!" is displayed.
     *
     */
    void ObjectDetector::connectionLost()
    {
        Mat frame=Mat::zeros(480, 640, CV_8UC3);
        int baseline=0;
        int fontFace=CV_FONT_HERSHEY_SIMPLEX;
        std::string text="No frame found!";
        Size textSize = getTextSize(text, fontFace,
                                    1, 2, &baseline);
        baseline += 2;
        Point textOrg((frame.cols - textSize.width)/2,
                      (frame.rows + textSize.height)/2);
        putText(frame, text, textOrg, fontFace, 1, Scalar(255,255,255),2);
        cv::cvtColor(frame, frame, CV_BGR2RGB);
        QImage image = QImage((uchar*) frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888);
        emit nextFrameReady(QPixmap::fromImage(image, Qt::AutoColor));
    }

    /*!
     * \brief ObjectDetector::colorFilter Filters Object from given Colorspectrum
     *
     * Minimum and maximum values for the Colorspectrum are set in the GUI. The opencv
     * function inRange filters the given matrix for the colorspectrum and paints
     * everything in range white. The opencv function findContours searches in the matrix
     * for contours. All contours are saved in a vector, if contours are found opencv
     * RotatedRect are build the largest found object is the detected object. If no
     * contours could be found a signal is emitted to search for an object.
     *
     * \param frame Given Frame from VideoService
     *
     */
    void ObjectDetector::colorFilter()
    {
        frame = service->getMatrix();
        if(!activated)
        {
            cv::cvtColor(frame, frame, CV_BGR2RGB);
            QImage image = QImage((uchar*) frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888);
            emit nextFrameReady(QPixmap::fromImage(image, Qt::AutoColor));
            return;
        }

        Mat frameRedFilter;
        //everything within range is displayed white the rest is displayed black
        Scalar minBGR(getMinB(), getMinG(), getMinR());
        Scalar maxBGR(getMaxB(), getMaxG(), getMaxR());
        inRange(frame, minBGR, maxBGR, frameRedFilter);
        vector<vector<Point> > contours;
        vector<Vec4i> hierarchy;
        //looks for contours
        findContours(frameRedFilter, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));
        if(contours.size()!=0)
        {
            emit objectFound();
            searchEmited = false;
            vector<RotatedRect> minRect(contours.size());

            for (uint i=0; i < contours.size(); i++)
            {
                minRect[i]=minAreaRect(Mat(contours[i]));
            }

            for (uint i=0; i < contours.size(); i++)
            {
                Point2f rect_points[4];
                minRect[i].points( rect_points );
            }
            int maxIndex=0;
            for (uint  i= 0; i < minRect.size(); i++)
            {
                if(minRect[i].size.area()>minRect[maxIndex].size.area())
                    maxIndex=i;
            }

            Point2f rectPoints[4];
            Scalar color(0,255,0);
            minRect[maxIndex].points( rectPoints );
            for (uint i = 0; i < 4; i++)
            {
                line( frame, rectPoints[i], rectPoints[(i+1)%4], color, 1, 8 );
            }

            emit nextVerboseString("Found Object in: x=" + (QString::number(minRect[maxIndex].center.x)) + "\t y=" + QString::number(minRect[maxIndex].center.y) + "\t");
            createPolygons();
            if(autopilot)
            {
                movementSignal(minRect[maxIndex].center);
            }
        }
        else
        {
            createPolygons();
            if(verbose)
                emit nextVerboseString("Warning: No Object found!");
            if(!searchEmited)
            {
                emit searchObject();
                searchEmited = true;
            }
        }
        cv::cvtColor(frame, frame, CV_BGR2RGB);
        QImage image = QImage((uchar*) frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888);
        emit nextFrameReady(QPixmap::fromImage(image, Qt::AutoColor));
    }

    /*!
     * \brief ObjectDetector::createPolygons calculates the image into 9 parts
     *
     * Parts:
     * top: 0
     * left: 1
     * bottom: 2
     * right: 3
     * top right:    4
     * top left:     5
     * bottom left:  6
     * bottom right: 7
     * center: 8
     * For calculating the parts of the image a circle is drawn from a given Radius,
     * the circle is divided into 8 parts of equal size. The method computes a line
     * from each point on the circle to the center of the image. The intercept point
     * between every lines and the periphery of the matrix is calculated. The Polygons
     * are computed from two points of the center and two points of the periphery of
     * the matrix (at the edges a fifth point is used to calculate polygon).
     *
     * \param frame Reference of the frame to be used
     */
    void ObjectDetector::createPolygons()
    {
        int width   = frame.size().width;
        int height  = frame.size().height;
        contoursVec.clear();
        //calculate center of image
        Point2d center(width/2, height/2);

        vector<double> angles;

        for(uint i=0;i<8;i++)
        {
            angles.push_back(((45*i)+22.5)*M_PI/180);
        }
        vector<Point2d> pointOnCircle;
        vector<Point2d> pointOnEdge;

        for(uint i=0;i<8;i++)
        {
            Point2d help;
            help.x=center.x+getRadius()*cos(angles[i]);
            help.y=center.y-getRadius()*sin(angles[i]);

            pointOnCircle.push_back(help);
            circle(frame,pointOnCircle[i],3,Scalar(0,0,255),-1);
            Point2d help2;
            double angle=tan(22.5*M_PI/180);
            switch(i)
            {
                case 0:
                    help2.x=width;
                    help2.y=center.y-(angle*width/2);
                    break;
                case 1:
                    help2.x=center.x+(angle*height/2);
                    help2.y=0;
                    break;
                case 2:
                    help2.x=center.x-(angle*height/2);
                    help2.y=0;
                    break;
                case 3:
                    help2.x=0;
                    help2.y=center.y-(angle*width/2);
                    break;
                case 4:
                    help2.x=0;
                    help2.y=center.y+(angle*width/2);
                    break;
                case 5:
                    help2.x=center.x-(angle*height/2);
                    help2.y=height;
                    break;
                case 6:
                    help2.x=center.x+(angle*height/2);
                    help2.y=height;
                    break;
                case 7:
                    help2.x=width;
                    help2.y=center.y+(angle*width/2);
                    break;
            }
            pointOnEdge.push_back(help2);
        }

        /* Calculate Polygons on top, left, right, bottom (includes 4 points)
         * top:     0
         * left:    1
         * bottom:  2
         * right:   3
        */
        for (uint i = 1;  i< 8; i+=2)
        {
            vector<Point> helpVec1;

            //1. Gerade
            helpVec1.push_back(pointOnCircle[i]);
            helpVec1.push_back(pointOnEdge[i]);

            //2. Gerade
            helpVec1.push_back(pointOnEdge[i]);
            helpVec1.push_back(pointOnEdge[(i+1)%8]);

            //3. Gerade
            helpVec1.push_back(pointOnEdge[(i+1)%8]);
            helpVec1.push_back(pointOnCircle[(i+1)%8]);

            //4. Gerade
            helpVec1.push_back(pointOnCircle[i]);
            helpVec1.push_back(pointOnCircle[(i+1)%8]);

            contoursVec.push_back(helpVec1);
        }

        /* Calculate Polygons on edges, topright, topleft, bottomright, bottomleft
         * top right:    4
         * top left:     5
         * bottom left:  6
         * bottom right: 7
        */
        for (uint i = 0; i < 8; i+=2)
        {
            vector<Point> helpVec1;
            Point edge;

            switch(i)
            {
                case 0:
                    edge.x=width;
                    edge.y=0;
                    break;
                case 2:
                    edge.x=0;
                    edge.y=0;
                    break;
                case 4:
                    edge.x=0;
                    edge.y=height;
                    break;
                case 6:
                    edge.x=width;
                    edge.y=height;
            }

            //1. Gerade
            helpVec1.push_back(pointOnCircle[i]);
            helpVec1.push_back(pointOnEdge[i]);

            //2. Gerade
            helpVec1.push_back(pointOnEdge[i]);
            helpVec1.push_back(edge);

            //3. Gerade
            helpVec1.push_back(edge);
            helpVec1.push_back(pointOnEdge[(i+1)%8]);

            //4. Gerade
            helpVec1.push_back(pointOnEdge[(i+1)%8]);
            helpVec1.push_back(pointOnCircle[(i+1)%8]);

            //5. Gerade
            helpVec1.push_back(pointOnCircle[(i+1)%8]);
            helpVec1.push_back(pointOnCircle[i]);

            contoursVec.push_back(helpVec1);
        }

        /*Calculate Polygon for center
         * center:  8
        */
        vector<Point> helpVec1;
        for (uint i = 0; i < 8; i++)
        {

            helpVec1.push_back(pointOnCircle[i]);
        }
        contoursVec.push_back(helpVec1);

        //Draw the calculated Polygons
        for (uint i = 0; i < contoursVec.size(); i++)
            drawContours(frame, contoursVec, i, Scalar(255,0,0));
    }

    /*!
     * \brief ObjectDetector::movementSignal Tests in which Polygon the detected Object is and emits a signal
     *
     * With the opencv function pointPolygonTest() the method checks in which polygon the centerpoint of the
     * detected object is and emits the matching signal.
     *
     * \param point The centerpoint of the computed rotatedRect
     * \param frame Reference of the frame to be used
     */
    void ObjectDetector::movementSignal(Point2f point)
    {

        //Test if point is within one of the calculated Polygons
        int polygonNr=-1;
        for (uint i = 0; i < contoursVec.size(); i++)
        {
            vector<Point> contours=contoursVec[i];
            if(pointPolygonTest(contours, point, false)==1)
            {
                polygonNr=i;
                break;
            }
        }
        circle(frame,point,2,Scalar(0,255,0),-1);

        if(polygonNr == lastSeenIn)
            return;
        if(verbose)
            emit nextVerboseString("Object found in Polygon Nr: " + QString::number(polygonNr));
        lastSeenIn = polygonNr;

        switch (polygonNr) {
            case 0:
                emit moveUp();
                break;
            case 1:
                emit moveLeft();
                break;
            case 2:
                emit moveDown();
                break;
            case 3:
                emit moveRight();
                break;
            case 4:
                emit moveUpRight();
                break;
            case 5:
                emit moveUpLeft();
                break;
            case 6:
                emit moveDownLeft();
                break;
            case 7:
                emit moveDownRight();
                break;
            case 8:
                emit inCenter();
                break;
        }
    }

    int ObjectDetector::getMinR()
    {
       return config->getMinR();
    }

    int ObjectDetector::getMinG()
    {
       return config->getMinG();
    }

    int ObjectDetector::getMinB()
    {
       return config->getMinB();
    }

    int ObjectDetector::getMaxR()
    {
       return config->getMaxR();
    }

    int ObjectDetector::getMaxG()
    {
       return config->getMaxG();
    }

    int ObjectDetector::getMaxB()
    {
       return config->getMaxB();
    }

    int ObjectDetector::getRadius()
    {
        return config->getRadius();
    }

    bool ObjectDetector::getVerbose() const
    {
        return verbose;
    }

    void ObjectDetector::setVerbose(bool value)
    {
        this->verbose = value;
    }

    void ObjectDetector::setMinR(int minR)
    {
        config->setMinR(minR);
    }

    void ObjectDetector::setMinG(int minG)
    {
        config->setMinG(minG);
    }

    void ObjectDetector::setMinB(int minB)
    {
        config->setMinB(minB);
    }

    void ObjectDetector::setMaxR(int maxR)
    {
        config->setMaxR(maxR);
    }

    void ObjectDetector::setMaxG(int maxG)
    {
        config->setMaxG(maxG);
    }

    void ObjectDetector::setMaxB(int maxB)
    {
        config->setMaxB(maxB);
    }

    void ObjectDetector::setRadius(int radius)
    {
        config->setRadius(radius);
    }
    bool ObjectDetector::getActivated() const
    {
        return activated;
    }

    void ObjectDetector::setActivated(bool value)
    {
        activated = value;
    }

    bool ObjectDetector::getAutopilot() const
    {
        return autopilot;
    }

    void ObjectDetector::setAutopilot(bool value)
    {
        autopilot = value;
    }

}
