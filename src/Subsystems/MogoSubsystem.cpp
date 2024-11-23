#include "vex.h"
#include "MogoSubsystem.h"
#include "Constants.h"

using namespace vex;

MogoSubsystem ::MogoSubsystem() : clampPneumatic(Constants::PNEUMATIC_PORT) {}

void MogoSubsystem ::mogo(controller::button extendButton, controller::button retractButton)
{
    if (extendButton.pressing())
    {
        clampPneumatic.set(true);
    }
    else if (retractButton.pressing())
    {
        clampPneumatic.set(false);
    }
}
