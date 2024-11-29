#ifndef INTAKESUBSYSTEM_H
#define INTAKESUBSYSTEM_H

#include "vex.h"
#include "Subsystem.h"
using namespace vex;

class IntakeSubsystem : public Subsystem {
private:
    motor intake;

public:
    IntakeSubsystem();
    
    void setIntake(double speed); 
    void stop();
};

#endif