#ifndef SENSORSUBSYSTEM_H
#define SENSORSUBSYSTEM_H

#include "vex.h"
#include "Subsystem.h"

using namespace vex;

class SensorSubsystem : public Subsystem{
private:
    bumper bumperSensor;
    inertial inertialSensor;
    distance distanceSensor;
    rotation rotationSensor;
    vision visionSensor

public: 

    SensorSubsystem();

    bool isBumperPressed();
    double getInertialHeading();
    double getDistance();
    double getRotation();
    int getVisionObject();

    void resetInertial();
    void resetRotation();
};

#endif
