#include "vex.h"
#include "IntakeSubsystem.h"

using namespace vex;

IntakeSubsystem ::IntakeSubsystem(): 
    intake(PORT11, true) {}


void IntakeSubsystem :: setIntake(double speed){
    intake.spin(forward, speed, percent); 

}

void IntakeSubsystem :: stop(){
    intake.spin(forward, 0, percent);
}
    