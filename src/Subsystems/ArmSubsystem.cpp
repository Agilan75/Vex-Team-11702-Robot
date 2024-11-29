#include "vex.h"
#include "ArmSubsystem.h"
#include "Constants.h"
#include "Log.h"
#include "Subsystem.h"

using namespace vex;

ArmSubsystem::ArmSubsystem()
    : armMotor(Constants::ARM_MOTOR_PORT, Constants::ARM_MOTOR_GEAR_RATIO, Constants::ARM_MOTOR_REVERSED) {
    armMotor.setBrake(brakeType::hold);
    Log::log("ArmSubsystem - Initialized with motor on port: ", Constants::ARM_MOTOR_PORT,
             " | Gear ratio: ", Constants::ARM_MOTOR_GEAR_RATIO,
             " | Reversed: ", Constants::ARM_MOTOR_REVERSED);
}

void ArmSubsystem::liftArm() {
    armMotor.spin(directionType::fwd, Constants::ARM_LIFT_SPEED, percentUnits::pct);
    Log::log("ArmSubsystem - Lifting arm with speed: ", Constants::ARM_LIFT_SPEED, "%");
}

void ArmSubsystem::lowerArm() {
    armMotor.spin(directionType::rev, Constants::ARM_LOWER_SPEED, percentUnits::pct);
    Log::log("ArmSubsystem - Lowering arm with speed: ", Constants::ARM_LOWER_SPEED, "%");
}

void ArmSubsystem::stopArm() {
    armMotor.stop();
    Log::log("ArmSubsystem - Stopped the arm motor.");
}

void ArmSubsystem::moveToPosition(double targetDegrees, double speed) {
    armMotor.startRotateTo(targetDegrees, rotationUnits::deg, speed, velocityUnits::pct);
    Log::log("ArmSubsystem - Moving arm to position: ", targetDegrees, " degrees at speed: ", speed, "%");

    while (armMotor.isSpinning()) {
        Log::log("ArmSubsystem - Arm motor spinning... Current position: ", armMotor.position(rotationUnits::deg), " degrees");
        vex::task::sleep(20);
    }

    armMotor.stop();
    Log::log("ArmSubsystem - Reached target position: ", targetDegrees, " degrees");
}

void ArmSubsystem::setLiftSpeed(double speed) {
    liftSpeed = speed;
    Log::log("ArmSubsystem - Set lift speed to: ", liftSpeed, "%");
}

void ArmSubsystem::setLowerSpeed(double speed) {
    lowerSpeed = speed;
    Log::log("ArmSubsystem - Set lower speed to: ", lowerSpeed, "%");
}
