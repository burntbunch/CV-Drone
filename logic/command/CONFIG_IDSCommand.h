#ifndef CONFIG_IDSCOMMAND_H
#define CONFIG_IDSCOMMAND_H

#include <CuteCommand.h>

namespace Drone
{

    namespace Command
    {
        class CONFIG_IDSCommand : public CuteCommand
        {
        public:
            CONFIG_IDSCommand(QString currentSessionID, QString currentUserID, QString currentApplicaationID);
            ~CONFIG_IDSCommand();
            bool operator ==(CuteCommand *t) const;
            QString getCommand() override;

        private:
            QString currentSessionID, currentUserID, currentApplicaationID;
        };
    }
}



#endif // CONFIG_IDSCOMMAND_H
