#include "vex.h"

using namespace vex;

class IntakeSubsystem {
private:
    motor intakeMotor;

public:
    IntakeSubsystem() : intakeMotor(motor(PORT7)) {}

    void controlIntake(controller::button intakeIn, controller::button intakeOut) {
        if (intakeIn.pressing()) {
            intakeMotor.spin(forward, 100, percent);
        } else if (intakeOut.pressing()) {
            intakeMotor.spin(reverse, 100, percent);
        } else {
            intakeMotor.stop();
        }
    }
};
