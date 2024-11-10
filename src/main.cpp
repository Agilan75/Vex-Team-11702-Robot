/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Team 11702                                                */
/*    Created:      11/5/2024, 6:11:26 PM                                     */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

using namespace vex;

// initalize things
brain Brain;
controller Controller;

motor leftMotorA = motor(PORT1, false);
motor leftMotorB = motor(PORT2, false);
motor rightMotorA = motor(PORT3, true);
motor rightMotorB = motor(PORT4, true);

// group motors
motor_group leftMotors(leftMotorA, leftMotorB);
motor_group rightMotors(rightMotorA, rightMotorB);

// 4 motor drivetrain object
drivetrain Drivetrain = drivetrain(leftMotors, rightMotors, 259.34, 320, 40, mm, 1);

void Drivetrain() {
    // setting the iniital speed
    Drivetrain.setDriveVelocity(100, percent);
    Drivetrain.setStopping(brake);  // Stopping with brake

    while (true) {
        // get valyes for joystick positon
        int forward = Controller.Axis2.position() * 0.65;
        int turn = Controller.Axis1.position() * 0.65;   
        
        // get speeds
        int left = forward + turn;
        int right = forward - turn;

        // controls to move
        leftMotors.spin(forward, left, percent);
        rightMotors.spin(forward, right, percent);

        // stop when nothing happening
        if (forwardSpeed == 0 && turnSpeed == 0) {
            leftMotors.stop();
            rightMotors.stop();
        }

    
    }
}

int main() {
    Drivetrain();
}
