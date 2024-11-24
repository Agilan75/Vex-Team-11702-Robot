#include "vex.h"
#include "DriveSubsystem.h"
#include "Constants.h"
#include "Subsystem.h"

using namespace vex;

DriveSubsystem ::DriveSubsystem() :
    leftMotorA(Constants::LEFT_MOTOR_A_PORT, false),
    leftMotorB(Constants::LEFT_MOTOR_B_PORT, false),
    leftMotorC(Constants::LEFT_MOTOR_C_PORT, false),
    rightMotorA(Constants::RIGHT_MOTOR_A_PORT, true),
    rightMotorB(Constants::RIGHT_MOTOR_B_PORT, true),
    rightMotorC(Constants::RIGHT_MOTOR_C_PORT, true),
    leftMotors(leftMotorA, leftMotorB, leftMotorC),
    rightMotors(rightMotorA, rightMotorB, rightMotorC),
    drivetrain(leftMotors, rightMotors,
                Constants::WHEEL_TRAVEL,
                Constants::TRACK_WIDTH,
                Constants::WHEEL_BASE,
                vex::distanceUnits::mm,
                Constants::EXTERNAL_GEAR_RATIO)
    {}

void DriveSubsystem :: drive(double leftSpeed, double rightSpeed){
    leftMotors.spin(forward, leftSpeed, percent);
    rightMotors.spin(forward, rightSpeed, percent);
}

void DriveSubsystem :: stop() {
    leftMotors.spin(forward, 0, percent);
    rightMotors.spin(forward, 0, percent);
}
