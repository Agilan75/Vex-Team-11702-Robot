#include "vex.h"
#include "SensorSubsystem.h"
#include "Constants.h"
#include "Log.h"
#include "Subsystem.h"

using namespace vex;

// SensorSubsystem::SensorSubsystem() 
//     : bumperSensor(Brain.ThreeWirePort.A), 
//       inertialSensor(Constants::INERTIAL_SENSOR_PORT),                 
//       distanceSensor(Constants::DISTANCE_SENSOR_PORT),               
//       rotationSensor(Constants::ROTATIONAL_SENSOR_PORT),
//       visionSensor(Constants::VISION_SENSOR_PORT) {  // Include vision sensor initialization

//     Log::log("SensorSubsystem - Initializing sensors...");

//     inertialSensor.calibrate();
//     Log::log("SensorSubsystem - Calibrating inertial sensor...");
//     while (inertialSensor.isCalibrating()) {
//         vex::task::sleep(100);
//     }
//     Log::log("SensorSubsystem - Inertial sensor calibration complete.");

//     rotationSensor.resetRotation();
//     Log::log("SensorSubsystem - Rotation sensor reset.");
// }

// bool SensorSubsystem::isBumperPressed() {
//     bool pressed = bumperSensor.pressing();
//     Log::log("SensorSubsystem - Bumper sensor state: ", pressed);
//     return pressed;
// }

// double SensorSubsystem::getInertialHeading() {
//     double heading = inertialSensor.heading(degrees);
//     Log::log("SensorSubsystem - Inertial heading: ", heading);
//     return heading;
// }

// double SensorSubsystem::getDistance() {
//     double distance = distanceSensor.objectDistance(mm);
//     Log::log("SensorSubsystem - Distance sensor value: ", distance, " mm");
//     return distance;
// }

// double SensorSubsystem::getRotation() {
//     double rotation = rotationSensor.position(degrees);
//     Log::log("SensorSubsystem - Rotation sensor value: ", rotation, " degrees");
//     return rotation;
// }

// void SensorSubsystem::resetInertial() {
//     inertialSensor.setHeading(0, degrees);
//     Log::log("SensorSubsystem - Inertial heading reset to 0 degrees.");
// }

// void SensorSubsystem::resetRotation() {
//     rotationSensor.resetRotation();
//     Log::log("SensorSubsystem - Rotation sensor reset.");
// }

// int SensorSubsystem::getVisionObject() {
//     vision::object largestObject = visionSensor.largestObject;
//     int centerX = largestObject.exists ? largestObject.centerX : -1;
//     if (largestObject.exists) {
//         Log::log("SensorSubsystem - Vision sensor detected object. Center X: ", centerX);
//     } else {
//         Log::log("SensorSubsystem - No object detected by vision sensor.");
//     }
//     return centerX;
// }

