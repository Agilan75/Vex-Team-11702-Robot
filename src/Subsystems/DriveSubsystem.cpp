#include "vex.h"
#include "DriveSubsystem.h"
#include "Constants.h"
#include "Log.h"
#include "Subsystem.h"

using namespace vex;

DriveSubsystem::DriveSubsystem()
    : leftMotorA(Constants::LEFT_MOTOR_A_PORT, false),
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
                 Constants::EXTERNAL_GEAR_RATIO) {
    Log::log("DriveSubsystem - Initialized with motors: Left - ", Constants::LEFT_MOTOR_A_PORT, ", ", Constants::LEFT_MOTOR_B_PORT, ", ", Constants::LEFT_MOTOR_C_PORT, 
             " | Right - ", Constants::RIGHT_MOTOR_A_PORT, ", ", Constants::RIGHT_MOTOR_B_PORT, ", ", Constants::RIGHT_MOTOR_C_PORT);
}

void DriveSubsystem::drive(double leftSpeed, double rightSpeed) {
    leftMotors.spin(forward, leftSpeed, percent);
    rightMotors.spin(forward, rightSpeed, percent);
    Log::log("DriveSubsystem - Driving with left speed: ", leftSpeed, "% | right speed: ", rightSpeed, "%");
}

void DriveSubsystem::stop() {
    leftMotors.spin(forward, 0, percent);
    rightMotors.spin(forward, 0, percent);
    Log::log("DriveSubsystem - Stopped all motors.");
}
