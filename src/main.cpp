#include "vex.h"

using namespace vex;

competition Competition;

brain Brain;
controller Controller;

motor leftMotorA = motor(PORT1, false);
motor leftMotorB = motor(PORT2, false);
motor leftMotorC = motor(PORT3, false);
motor rightMotorA = motor(PORT4, true);
motor rightMotorB = motor(PORT5, true);
motor rightMotorC = motor(PORT6, true);

motor_group leftMotors(leftMotorA, leftMotorB, leftMotorC);
motor_group rightMotors(rightMotorA, rightMotorB, rightMotorC);

drivetrain Drivetrain = drivetrain(leftMotors, rightMotors, 259.34, 320, 40, mm, 1);

motor intakeMotor = motor(PORT7, false);

digital_out mogoPneumatic = digital_out(Brain.ThreeWirePort.B);

int deadband = 5;
int scaleFactor = 3;

void pre_auton(void)
{

    // All activities that occur before the competition starts
    // Example: clearing encoders, setting servo positions, ...
}

void autonomous(void)
{
    // ..........................................................................
    // Insert autonomous user code here.
    // ..........................................................................
}

void usercontrol(void){
    Drivetrain.setStopping(brake);

    while (true) {
        // for joystcik movement
        int rightSpeed = Controller.Axis2.position() * scaleFactor;
        int leftSpeed = Controller.Axis1.position() * scaleFactor;

        if (abs(rightSpeed) < deadband && abs(leftSpeed) < deadband) {
            rightSpeed = 0;
            leftSpeed = 0;
        }

        leftMotors.spin(forward, leftSpeed, percent);
        rightMotors.spin(forward, rightSpeed, percent); 

           
        if (rightSpeed == 0 && leftSpeed == 0)
        {
            leftMotors.stop();
            rightMotors.stop();
        }

        if (Controller.ButtonR1.pressing())
        {
            intakeMotor.spin(forward, 100, percent);
        }
        else if (Controller.ButtonR2.pressing())
        {
            intakeMotor.spin(reverse, 100, percent);
        }
        else
        {
            intakeMotor.stop();
        }

        // pneumatic clamp
        if (Controller.ButtonL1.pressing()) {
            mogoPneumatic.set(true);
        } else if (Controller.ButtonL2.pressing()) {
            mogoPneumatic.set(false);
        }

        vex::task::sleep(20);

        // for intake
       

        // pneumatic clamp
        // if (Controller.ButtonL1.pressing()) {
        //     clampPneumatics.extend(); 
        // } else if (Controller.ButtonL2.pressing()) {
        //     clampPneumatics.retract(); 
        // }
    }
}




int main() {
    Competition.autonomous(autonomous);
    Competition.drivercontrol(usercontrol);

    // Run the pre-autonomous function.
    pre_auton();

    // Prevent main from exiting with an infinite loop.
    while (true)
    {
        wait(100, msec);
    }
}
