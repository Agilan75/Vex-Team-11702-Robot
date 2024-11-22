#include "DriveSubsystem.h"

DriveSubsystem ::DriveSubsystem(): 
    leftMotorA(PORT1, false),
    leftMotorB(PORT2, false),
    leftMotorC(PORT3, false),
    rightMotorA(PORT4, true),
    rightMotorB(PORT5, true),
    rightMotorC(PORT6, true),
    leftMotors(leftMotorA, leftMotorB, leftMotorC),
    rightMotors(rightMotorA, rightMotorB, rightMotorC),
    drivetrain(leftMotors, rightMotors, 259.34, 320, 40, mm, 1) {}

void DriveSubsystem :: drive(double leftSpeed, double rightSpeed){
    leftMotors.spin(forward, leftSpeed, percent);
    rightMotors.spin(forward, rightSpeed, percent);
}

void DriveSubsystem :: stop() {
    leftMotors.spin(forward, 0, percent);
    rightMotors.spin(forward, 0, percent);
}
