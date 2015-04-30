#ifndef PCMD_MAGCOMMAND_H
#define PCMD_MAGCOMMAND_H

#include <CuteCommand.h>

namespace Drone
{
    namespace Command
    {

        class PCMD_MAGCommand : public CuteCommand
        {
        public:
            enum class Mode : int{
              ABSOLUTE_CONTROL = 5,
              COMBINED_YAW = 3,
              PROGRESSIVE = 1,
              HOVER = 0
            };
            static bool checkParams(float roll, float pitch, float gaz, float yaw , float magnetoPsy, float magnetoPsyAccuracy );
            PCMD_MAGCommand(Mode mode, float roll, float pitch, float gaz, float yaw, float magnetoPsy, float magnetoPsyAccuracy );
            ~PCMD_MAGCommand();
            bool operator ==(CuteCommand* t) const;
            QString getCommand() override;

        private:
            Mode mode;
            float roll, pitch, gaz, yaw, magnetoPsy, magnetoPsyAccuracy;
        };
    }
}
#endif // PCMD_MAGCOMMAND_H
