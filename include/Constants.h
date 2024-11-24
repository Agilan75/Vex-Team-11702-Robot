#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace Constants
{
    constexpr int LEFT_MOTOR_A_PORT = 1;
    constexpr int LEFT_MOTOR_B_PORT = 2;
    constexpr int LEFT_MOTOR_C_PORT = 3;
    constexpr int RIGHT_MOTOR_A_PORT = 4;
    constexpr int RIGHT_MOTOR_B_PORT = 5;
    constexpr int RIGHT_MOTOR_C_PORT = 6;

    constexpr double WHEEL_TRAVEL = 259.34;     
    constexpr double TRACK_WIDTH = 320.0;      
    constexpr double WHEEL_BASE = 40.0;         
    constexpr double EXTERNAL_GEAR_RATIO = 1.0;

    constexpr int INTAKE_MOTOR_PORT = 7;

    constexpr int ARM_MOTOR_PORT = 8;
    constexpr double ARM_MOTOR_GEAR_RATIO = 36.0;

    const bool ARM_MOTOR_REVERSED = false;
    
    const double ARM_LIFT_SPEED = 50.0; 
    const double ARM_LOWER_SPEED = 30.0;

    constexpr int INERTIAL_SENSOR_PORT = 9;
    constexpr int DISTANCE_SENSOR_PORT = 10;
    constexpr int ROTATIONAL_SENSOR_PORT = 11;

}

#endif