#ifndef ODOMETRY_SUBSYSTEM_H
#define ODOMETRY_SUBSYSTEM_H

#include "vex.h"

class OdometrySubsystem {
private:
    vex::motor_group& leftMotors;
    vex::motor_group& rightMotors;
    vex::encoder& leftEncoder;
    vex::encoder& rightEncoder;
    vex::inertial& inertialSensor;

    const float WHEEL_DIAMETER = 3.0;
    const float TICKS_PER_REV = 360.0;
    const float TRACK_WIDTH = 1.486; 

    float x;    
    float y;    
    float heading;

    float distanceTraveled(vex::encoder& encoder);

    const float HEADING_KP = 0.5;
    const float FORWARD_KP = 0.3;

public:
    OdometrySubsystem(vex::motor_group& leftMotors, vex::motor_group& rightMotors, 
                      vex::encoder& leftEncoder, vex::encoder& rightEncoder, 
                      vex::inertial& inertialSensor);

    void resetPosition();

    void update();

    void autoAlign(float targetX, float targetY, float targetHeading);

    float getX() const;
    float getY() const;
    float getHeading() const;
};

#endif
