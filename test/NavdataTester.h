#ifndef NAVDATATESTER_H
#define NAVDATATESTER_H

#include <QObject>
#include <QDebug>

namespace Test
{
	class NavdataTester : public QObject
	{
	    Q_OBJECT
	public:
	    NavdataTester();
	public slots:
	    void printQDebug(QString string);
	};	
}


#endif // NAVDATATESTER_H
