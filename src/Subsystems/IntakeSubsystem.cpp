#include "vex.h"
#include "IntakeSubsystem.h"
#include "Constants.h"
#include "Log.h"
#include "Subsystem.h"

using namespace vex;

IntakeSubsystem::IntakeSubsystem()
    : intake(Constants::INTAKE_MOTOR_PORT, true) {
    intake.setBrake(coast);
    //Log::log("IntakeSubsystem - Initialized intake motor at port ", Constants::INTAKE_MOTOR_PORT);
}

void IntakeSubsystem::setIntake(double speed) {
    intake.spin(forward, speed, percent);
    //Log::log("IntakeSubsystem - Intake motor set to speed: ", speed, "%");
}

void IntakeSubsystem::stop() {
    intake.spin(forward, 0, percent);
    //Log::log("IntakeSubsystem - Intake motor stopped.");
}

    