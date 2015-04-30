#ifndef REFCOMMAND_H
#define REFCOMMAND_H

#include <CuteCommand.h>

namespace Drone
{
    namespace Command
    {
        class REFCommand : public CuteCommand
        {
        public:
            enum class State : int {
                TAKEOFF = (0|(1<<18)|(1<<20)|(1<<22)|(1<<24)|(1<<28)|(1<<9)),
                LAND = TAKEOFF &~(1<<9),
                EMERGENCY = LAND |(1<<8)
            };
            REFCommand(State state);
            ~REFCommand();
            bool operator ==(CuteCommand* t) const;
            QString getCommand() override;

        private:
            State state;
        };
    }
}
#endif // REFCOMMAND_H
