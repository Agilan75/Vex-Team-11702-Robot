#include "vex.h"
#include "OdometrySubsystem.h"
#include "Constants.h"

OdometrySubsystem::OdometrySubsystem(vex::motor_group& leftMotors, vex::motor_group& rightMotors, 
                                     vex::encoder& leftEncoder, vex::encoder& rightEncoder, 
                                     vex::inertial& inertialSensor)
    : leftMotors(leftMotors), rightMotors(rightMotors), 
      leftEncoder(leftEncoder), rightEncoder(rightEncoder), 
      inertialSensor(inertialSensor), x(0), y(0), heading(0) {}

float OdometrySubsystem::distanceTraveled(vex::encoder& encoder) {
    return (encoder.position(vex::rotationUnits::deg) / TICKS_PER_REV) * (WHEEL_DIAMETER * 3.14159);
}

void OdometrySubsystem::resetPosition() {
    x = 0;
    y = 0;
    heading = 0;
    leftEncoder.resetRotation();
    rightEncoder.resetRotation();
    inertialSensor.setHeading(0, vex::rotationUnits::deg);
}

void OdometrySubsystem::update() {
    float currentLeftDist = distanceTraveled(leftEncoder);
    float currentRightDist = distanceTraveled(rightEncoder);

    x = (currentLeftDist + currentRightDist) / 2.0;
    heading = inertialSensor.heading(vex::rotationUnits::deg);
}

void OdometrySubsystem::autoAlign(float targetX, float targetY, float targetHeading) {
  
    float currentLeftDist = distanceTraveled(leftEncoder);
    float currentRightDist = distanceTraveled(rightEncoder);
    float currentX = (currentLeftDist + currentRightDist) / 2.0;
    float currentHeading = inertialSensor.heading(vex::rotationUnits::deg);

    float deltaX = targetX - currentX;
    float deltaHeading = targetHeading - currentHeading;

    if (fabs(deltaHeading) > 5.0) {
        float turnPower = deltaHeading * HEADING_KP;
        leftMotors.spin(vex::directionType::rev, turnPower, vex::percentUnits::pct);
        rightMotors.spin(vex::directionType::fwd, turnPower, vex::percentUnits::pct);
        vex::task::sleep(500);
        leftMotors.stop();
        rightMotors.stop();
    }

    if (fabs(deltaX) > 2.0) {
        float forwardPower = deltaX * FORWARD_KP;
        leftMotors.spin(vex::directionType::fwd, forwardPower, vex::percentUnits::pct);
        rightMotors.spin(vex::directionType::fwd, forwardPower, vex::percentUnits::pct);
        vex::task::sleep(500); 
        leftMotors.stop();
        rightMotors.stop();
    }
}

float OdometrySubsystem::getX() const {
    return x;
}

float OdometrySubsystem::getY() const {
    return y;
}

float OdometrySubsystem::getHeading() const {
    return heading;
}

