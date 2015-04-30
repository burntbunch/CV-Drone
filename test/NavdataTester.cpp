#include "NavdataTester.h"

namespace Test
{
	NavdataTester::NavdataTester() : QObject()
	{
	}

	void NavdataTester::printQDebug(QString string)
	{
	    qDebug() << string;
	}	
}

