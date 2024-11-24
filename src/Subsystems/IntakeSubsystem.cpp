#include "vex.h"
#include "IntakeSubsystem.h"
#include "Constants.h"
#include "Subsystem.h"

using namespace vex;

IntakeSubsystem ::IntakeSubsystem(): 
    intake(Constants::INTAKE_MOTOR_PORT, true) {}


void IntakeSubsystem :: setIntake(double speed){
    intake.spin(forward, speed, percent); 

}

void IntakeSubsystem :: stop(){
    intake.spin(forward, 0, percent);
}
    