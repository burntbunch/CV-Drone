#ifndef PMODECOMMAND_H
#define PMODECOMMAND_H

#include <CuteCommand.h>

namespace Drone
{

    namespace Command
    {
        class PMODECommand : public CuteCommand
        {
        public:
            PMODECommand();
            ~PMODECommand();
            bool operator ==(CuteCommand* t) const;
            QString getCommand() override;
        };

    }
}

#endif // PMODECOMMAND_H
