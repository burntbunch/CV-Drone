#ifndef CUTECOMMAND_H
#define CUTECOMMAND_H

#include <QByteArray>
#include <QString>
#include <QObject>
#include <typeinfo>

namespace Drone
{
    namespace Command
    {
        class CuteCommand : public QObject
        {
            Q_OBJECT

        public:
            virtual QString getCommand() = 0;
            virtual ~CuteCommand() { }
            QByteArray getRAWCommand();
        protected:
            CuteCommand(QObject* parent);
            unsigned int getNextSequenceNumber();
        private:
            static unsigned int sequenceCounter;
        };
    }
}

#endif // CUTECOMMAND_H
