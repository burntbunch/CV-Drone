#ifndef VIDEOTESTER_H
#define VIDEOTESTER_H

#include <QObject>
#include <QDebug>
#include <opencv2/opencv.hpp>

using cv::Mat;

namespace Test
{
	class VideoTester : public QObject
	{
	    Q_OBJECT
	public:
	    explicit VideoTester(QObject *parent = 0);

	public slots:
	    void printQDebug(QString string);
	    void printFrameInfo(cv::Mat& frame);

	};	
}


#endif // VIDEOTESTER_H
