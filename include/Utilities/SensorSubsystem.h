#ifndef SENSORSUBSYSTEM_H
#define SENSORSUBSYSTEM_H

#include "vex.h"
using namespace vex;

class SensorSubsystem {
private:
    bumper bumperSensor;   
    inertial inertialSensor;
    distance distanceSensor; 
    rotation rotationSensor; 

public:
    SensorSubsystem(); 

    bool isBumperPressed();
    double getInertialHeading();
    double getDistance();
    double getRotation();

    void resetInertial();
    void resetRotation();
};

#endif
