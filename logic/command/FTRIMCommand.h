#ifndef FTRIMCOMMAND_H
#define FTRIMCOMMAND_H


#include <CuteCommand.h>

namespace Drone
{

    namespace Command
    {
        class FTRIMCommand : public CuteCommand
        {
        public:
            FTRIMCommand();
            ~FTRIMCommand();
            bool operator ==(CuteCommand* t) const;
            QString getCommand() override;
        };

    }
}

#endif // FTRIMCOMMAND_H
