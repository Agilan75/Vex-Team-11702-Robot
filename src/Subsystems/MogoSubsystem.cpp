#include "vex.h"
#include "MogoSubsystem.h"
#include "Constants.h"
using namespace vex;

MogoSubsystem::MogoSubsystem() 
    : mogoPneumatic(digital_out(Brain.ThreeWirePort.B)) { 
    mogoPneumatic.set(false);
}

void MogoSubsystem::controlPneumatics(controller::button extendButton, controller::button retractButton) {
    if (extendButton.pressing()) {
        mogoPneumatic.set(true); 
    } else if (retractButton.pressing()) {
        mogoPneumatic.set(false); 
    }
}

