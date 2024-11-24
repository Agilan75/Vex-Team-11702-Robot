#ifndef DRIVESUBSYSTEM_H
#define DRIVESUBSYSTEM_H

#include "vex.h"
#include "Subsystem.h"
using namespace vex;

class DriveSubsystem : public Subsystem {
private:
    motor leftMotorA, leftMotorB, leftMotorC, rightMotorA, rightMotorB, rightMotorC;

    motor_group leftMotors, rightMotors;

    drivetrain drivetrain;

public:
    DriveSubsystem();
    void drive(double leftSpeed, double rightSpeed);
    void stop();
};

#endif