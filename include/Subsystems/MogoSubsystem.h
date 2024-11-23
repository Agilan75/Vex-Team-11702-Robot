#ifndef MOGOSUBSYSTEM_H
#define MOGOSUBSYSTEM_H

#include "vex.h"
using namespace vex;

class MogoSubsystem {
private: 
    digital_out mogoPneumatic; 

public: 
    MogoSubsystem(); 
    void controlPneumatics(controller::button extendButton, controller::button retractButton); 
};

#endif
