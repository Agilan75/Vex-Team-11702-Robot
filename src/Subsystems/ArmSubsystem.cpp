#include "vex.h"
#include "ArmSubsystem.h"
#include "Constants.h"
#include "Subsystem.h"

using namespace vex;

ArmSubsystem::ArmSubsystem()
    : armMotor(Constants::ARM_MOTOR_PORT, Constants::ARM_MOTOR_GEAR_RATIO, Constants::ARM_MOTOR_REVERSED) {
    armMotor.setBrake(brakeType::hold);
}

void ArmSubsystem::liftArm() {
    armMotor.spin(directionType::fwd, Constants::ARM_LIFT_SPEED, percentUnits::pct);
}

void ArmSubsystem::lowerArm() {
    armMotor.spin(directionType::rev, Constants::ARM_LOWER_SPEED, percentUnits::pct);
}

void ArmSubsystem::stopArm() {
    armMotor.stop();
}

void ArmSubsystem::moveToPosition(double targetDegrees, double speed) {
    armMotor.startRotateTo(targetDegrees, rotationUnits::deg, speed, velocityUnits::pct);

    while (armMotor.isSpinning()) {
        vex::task::sleep(20);
    }
    armMotor.stop();
}


void ArmSubsystem::setLiftSpeed(double speed) {
    liftSpeed = speed;
}

void ArmSubsystem::setLowerSpeed(double speed) {
    lowerSpeed = speed;
}
