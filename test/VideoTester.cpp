#include "VideoTester.h"

namespace Test
{
	VideoTester::VideoTester(QObject *parent) :
	    QObject(parent)
	{
	}

	void VideoTester::printQDebug(QString string)
	{
	    qDebug() << string;
	}

	void VideoTester::printFrameInfo(cv::Mat &frame)
	{
	    qDebug() << "Cols: " << frame.cols;
	    qDebug() << "Rows: " << frame.rows;
	}	
}

