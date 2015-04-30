#ifndef COMWDGCOMMAND_H
#define COMWDGCOMMAND_H

#include <CuteCommand.h>

namespace Drone
{

    namespace Command
    {

        class COMWDGCommand : public CuteCommand
        {
        public:
            COMWDGCommand();
            ~COMWDGCommand();
            bool operator ==(CuteCommand* t) const;
            QString getCommand() override;
        };

    }
}
#endif // COMWDGCOMMAND_H
