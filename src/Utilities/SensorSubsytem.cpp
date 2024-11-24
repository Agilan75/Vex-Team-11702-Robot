#include "vex.h"
#include "SensorSubsystem.h"
#include "Constants.h"
#include "Subsystem.h"

using namespace vex;


SensorSubsystem::SensorSubsystem() 
    : bumperSensor(Brain.ThreeWirePort.A), 
      inertialSensor(Constants::INERTIAL_SENSOR_PORT),                 
      distanceSensor(Constants::DISTANCE_SENSOR_PORT),               
      rotationSensor(Constants::ROTATIONAL_SENSOR_PORT) {              
   
    inertialSensor.calibrate();
    while (inertialSensor.isCalibrating()) {
        vex::task::sleep(100);
    }
    rotationSensor.resetRotation();
}

bool SensorSubsystem::isBumperPressed() {
    return bumperSensor.pressing();
}

double SensorSubsystem::getInertialHeading() {
    return inertialSensor.heading(degrees); 
}

double SensorSubsystem::getDistance() {
    return distanceSensor.objectDistance(mm); 
}

double SensorSubsystem::getRotation() {
    return rotationSensor.position(degrees); 
}

void SensorSubsystem::resetInertial() {
    inertialSensor.setHeading(0, degrees);
}

void SensorSubsystem::resetRotation() {
    rotationSensor.resetRotation();
}
