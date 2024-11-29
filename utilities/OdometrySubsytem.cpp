#include "vex.h"
#include "OdometrySubsystem.h"
#include "Constants.h"
#include "Log.h"

OdometrySubsystem::OdometrySubsystem(vex::motor_group& leftMotors, vex::motor_group& rightMotors, 
                                     vex::encoder& leftEncoder, vex::encoder& rightEncoder, 
                                     vex::inertial& inertialSensor)
    : leftMotors(leftMotors), rightMotors(rightMotors), 
      leftEncoder(leftEncoder), rightEncoder(rightEncoder), 
      inertialSensor(inertialSensor), x(0), y(0), heading(0) {
    Log::log("OdometrySubsystem - Initialized.");
}

float OdometrySubsystem::distanceTraveled(vex::encoder& encoder) {
    float distance = (encoder.position(vex::rotationUnits::deg) / TICKS_PER_REV) * (WHEEL_DIAMETER * 3.14159);
    Log::log("OdometrySubsystem - Encoder distance traveled: ", distance);
    return distance;
}

void OdometrySubsystem::resetPosition() {
    x = 0;
    y = 0;
    heading = 0;
    leftEncoder.resetRotation();
    rightEncoder.resetRotation();
    inertialSensor.setHeading(0, vex::rotationUnits::deg);
    Log::log("OdometrySubsystem - Position reset. X: ", x, ", Y: ", y, ", Heading: ", heading);
}

void OdometrySubsystem::update() {
    float currentLeftDist = distanceTraveled(leftEncoder);
    float currentRightDist = distanceTraveled(rightEncoder);

    x = (currentLeftDist + currentRightDist) / 2.0;
    heading = inertialSensor.heading(vex::rotationUnits::deg);

    Log::log("OdometrySubsystem - Updated position. X: ", x, ", Y: ", y, ", Heading: ", heading);
}

void OdometrySubsystem::autoAlign(float targetX, float targetY, float targetHeading) {
    Log::log("OdometrySubsystem - Starting autoAlign. Target X: ", targetX, ", Target Y: ", targetY, ", Target Heading: ", targetHeading);

    float currentLeftDist = distanceTraveled(leftEncoder);
    float currentRightDist = distanceTraveled(rightEncoder);
    float currentX = (currentLeftDist + currentRightDist) / 2.0;
    float currentHeading = inertialSensor.heading(vex::rotationUnits::deg);

    float deltaX = targetX - currentX;
    float deltaHeading = targetHeading - currentHeading;

    Log::log("OdometrySubsystem - Current X: ", currentX, ", Current Heading: ", currentHeading);
    Log::log("OdometrySubsystem - Delta X: ", deltaX, ", Delta Heading: ", deltaHeading);

    if (fabs(deltaHeading) > 5.0) {
        float turnPower = deltaHeading * HEADING_KP;
        Log::log("OdometrySubsystem - Aligning heading. Turn power: ", turnPower);
        leftMotors.spin(vex::directionType::rev, turnPower, vex::percentUnits::pct);
        rightMotors.spin(vex::directionType::fwd, turnPower, vex::percentUnits::pct);
        vex::task::sleep(500);
        leftMotors.stop();
        rightMotors.stop();
        Log::log("OdometrySubsystem - Heading alignment complete.");
    }

    if (fabs(deltaX) > 2.0) {
        float forwardPower = deltaX * FORWARD_KP;
        Log::log("OdometrySubsystem - Aligning position. Forward power: ", forwardPower);
        leftMotors.spin(vex::directionType::fwd, forwardPower, vex::percentUnits::pct);
        rightMotors.spin(vex::directionType::fwd, forwardPower, vex::percentUnits::pct);
        vex::task::sleep(500); 
        leftMotors.stop();
        rightMotors.stop();
        Log::log("OdometrySubsystem - Position alignment complete.");
    }
}

float OdometrySubsystem::getX() const {
    Log::log("OdometrySubsystem - Getting X position: ", x);
    return x;
}

float OdometrySubsystem::getY() const {
    Log::log("OdometrySubsystem - Getting Y position: ", y);
    return y;
}

float OdometrySubsystem::getHeading() const {
    Log::log("OdometrySubsystem - Getting Heading: ", heading);
    return heading;
}

