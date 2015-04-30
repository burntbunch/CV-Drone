#ifndef CALIBCOMMAND_H
#define CALIBCOMMAND_H

#include <CuteCommand.h>

namespace Drone
{

    namespace Command
    {
        class CALIBCommand : public CuteCommand
        {
        public:
            CALIBCommand(bool callib);
            bool operator==(CuteCommand* t) const;
            ~CALIBCommand();
            QString getCommand() override;

        private:
            bool callib;
        };
    }
}

#endif // CALIBCOMMAND_H
