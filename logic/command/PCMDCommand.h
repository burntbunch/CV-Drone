#ifndef PCMDCOMMAND_H
#define PCMDCOMMAND_H

#include <CuteCommand.h>

namespace Drone
{
    namespace Command
    {
        class PCMDCommand : public CuteCommand
        {
        public:
            enum class Mode : int{
              ABSOLUTE_CONTROL = 5,
              COMBINED_YAW = 3,
              PROGRESSIVE = 1,
              HOVER = 0
            };

            static bool checkParams(float roll, float pitch, float gaz, float yaw );
            PCMDCommand(Mode mode, float roll, float pitch, float gaz, float yaw );
            ~PCMDCommand();
            bool operator ==(CuteCommand* t) const;
            QString getCommand() override;

        private:
            Mode mode;
            float roll, pitch, gaz, yaw;
        };

    }
}

#endif // PCMDCOMMAND_H
