#include "vex.h"
#include "MogoSubsystem.h"
#include "Constants.h"
#include "Log.h"
#include "Subsystem.h"

using namespace vex;

brain Brain;

MogoSubsystem::MogoSubsystem() 
    : mogoPneumatic(digital_out(Brain.ThreeWirePort.B)) { 
    mogoPneumatic.set(false);
    Log::log("PneumaticSubsystem - Pneumatic initialized and set to default (retracted).");
}

void MogoSubsystem::controlPneumatics(controller::button extendButton, controller::button retractButton) {
    if (extendButton.pressing()) {
        mogoPneumatic.set(true);
        Log::log("Pneumaticubsystem - Pneumatic extended.");
    } else if (retractButton.pressing()) {
        mogoPneumatic.set(false);
        Log::log("PneumaticSubsystem - Pneumatic retracted.");
    }
}


