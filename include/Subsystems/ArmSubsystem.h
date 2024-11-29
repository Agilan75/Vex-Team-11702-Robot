#ifndef ARMSUBSYSTEM_H
#define ARMSUBSYSTEM_H

#include "vex.h"
using namespace vex;

class ArmSubsystem {
private:
    motor armMotor;     
    
public:
    ArmSubsystem();
    
    void liftArm();
    void lowerArm();
    void stopArm();

    void moveToPosition(double targetDegrees, double speed = 50);
};

#endif
