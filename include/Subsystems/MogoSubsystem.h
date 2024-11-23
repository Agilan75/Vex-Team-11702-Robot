#ifndef MOGOSUBSYSTEM_H
#define MOGOSUBSYSTEM_H

#include "vex.h"
using namespace vex;

class MogoSubsystem
{
private:
    digital_out clampPneumatic;

public:
    MogoSubsystem();
    void mogo(controller::button extendButton, controller::button retractButton);
    void stop();
};

#endif