#ifndef DRIVESUBSYSTEM_H
#define DRIVESUBSYSTEM_H

#include "vex.h"
using namespace vex;

class DriveSubsystem {
private:
    motor leftMotorA;
    motor leftMotorB;
    motor leftMotorC;
    motor rightMotorA;
    motor rightMotorB;
    motor rightMotorC;

    motor_group leftMotors;
    motor_group rightMotors;

    drivetrain drivetrain;

public:
    DriveSubsystem();
    void drive(double leftSpeed, double rightSpeed);
    void stop(); 
};

#endif