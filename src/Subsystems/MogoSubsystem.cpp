#include "vex.h"
#include "Subsystem.h"
using namespace vex;

brain Brain;

class PneumaticSubsystem {
private:
    digital_out clampPneumatic;

public:
    PneumaticSubsystem() : clampPneumatic(digital_out(Brain.ThreeWirePort.A)) {}

    void controlPneumatics(controller::button extendButton, controller::button retractButton) {
        if (extendButton.pressing()) {
            clampPneumatic.set(true);
        } else if (retractButton.pressing()) {
            clampPneumatic.set(false);
        }
    }
};
