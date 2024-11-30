#ifndef ARMSUBSYSTEM_H
#define ARMSUBSYSTEM_H

#include "vex.h"
using namespace vex;

class ArmSubsystem {
private:
    motor armMotor;    
    
public:
    ArmSubsystem();
    
    void setArm(double spinDeg);
    void resetArm();

};

#endif
