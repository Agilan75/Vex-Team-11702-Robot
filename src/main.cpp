#include "vex.h"
using namespace vex;

int main() {
    controller Controller;
    DrivetrainSubsystem drivetrain;
    IntakeSubsystem intake;
    PneumaticSubsystem  pneumatics;

    while (true) {
        drivetrain.drive(Controller.Axis2.position(), Controller.Axis1.position());

        intake.controlIntake(Controller.ButtonR1, Controller.ButtonR2);

        pneumatics.controlPneumatics(Controller.ButtonL1, Controller.ButtonL2);

        vex::task::sleep(20);
    }
}
