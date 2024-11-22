#ifndef INTAKESUBSYSTEM_H
#define INTAKESUBSYSTEM_H

#include "vex.h" 
using namespace vex;

class IntakeSubsystem {
private:
    motor intake;

public:
    IntakeSubsystem();
    void setIntake(double speed); 
    void stop(); 
};

#endif