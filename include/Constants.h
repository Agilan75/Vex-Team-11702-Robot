#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace Constants
{
    // Motor Ports Drive Train
    constexpr int LEFT_MOTOR_A_PORT = 1;
    constexpr int LEFT_MOTOR_B_PORT = 2;
    constexpr int LEFT_MOTOR_C_PORT = 3;
    constexpr int RIGHT_MOTOR_A_PORT = 4;
    constexpr int RIGHT_MOTOR_B_PORT = 5;
    constexpr int RIGHT_MOTOR_C_PORT = 6;

    // Motor Ports Intake
    constexpr int INTAKE_MOTOR_PORT = 7;

    // Motor Ports Arm
    constexpr int ARM_MOTOR_PORT = 8;

    // 3-Pin Ports Pneumatics
    constexpr vex::triport::port &PNEUMATIC_PORT = Brain.ThreeWirePort.A;

    // Drivetrain Configuration
    constexpr double WHEEL_TRAVEL = 259.34;     // In mm
    constexpr double TRACK_WIDTH = 320.0;       // Distance between left and right wheels in mm
    constexpr double WHEEL_BASE = 40.0;         // Wheelbase in mm
    constexpr double EXTERNAL_GEAR_RATIO = 1.0; // Gear ratio
}

#endif