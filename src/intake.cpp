#include "vex.h"

using namespace vex;

class IntakeSubsystem {

private:
    motor intakeMotor;
    controller* control;


public:
    IntakeSubsystem(intakeMotor M, controller* c) : intakeMotor(M), control(c){}
    
    void controlIntake() {

        while true{

            if (contol -> ButtonA.pressing()) {
            intakeMotor.spin(forward, 100, percent);

        } else if (control -> ButtonB.pressing()) {
            intakeMotor.spin(reverse, 100, percent);

        } else {
            intakeMotor.stop();
        }

        wait(20, msec);

        }
        
    }

};
