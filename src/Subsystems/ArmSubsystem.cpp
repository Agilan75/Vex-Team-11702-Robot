#include "vex.h"
#include "ArmSubsystem.h"
#include "Constants.h"
#include "Log.h"
#include "Subsystem.h"

using namespace vex;

ArmSubsystem::ArmSubsystem()
    : armMotor(Constants::ARM_MOTOR_PORT, Constants::ARM_MOTOR_REVERSED) {
    armMotor.setBrake(hold);
    // Log::log("ArmSubsystem - Initialized with motor on port: ", Constants::ARM_MOTOR_PORT,
    //          " | Gear ratio: ", Constants::ARM_MOTOR_GEAR_RATIO,
    //          " | Reversed: ", Constants::ARM_MOTOR_REVERSED);
    armMotor.setPosition(0, degrees);
}

void ArmSubsystem:: resetArm(){
    armMotor.setPosition(0, degrees);
}

void ArmSubsystem::setArm(double spinDeg){
    double motorDegrees = spinDeg * Constants::ARM_MOTOR_RATIO;
    armMotor.spinToPosition(motorDegrees, degrees, false);
}