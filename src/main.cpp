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

void userControlLoop() {
    // inital velocity
    Drivetrain.setDriveVelocity(100, percent);
    Drivetrain.setStopping(brake);  // Stopping with brake

    while (true) {
        // get valyes for joystick positon
        int forwardSpeed = Controller.Axis2.position() * 0.65;
        int turnSpeed = Controller.Axis1.position() * 0.65;   

        // get speeds
        int leftSpeed = forwardSpeed + turnSpeed;
        int rightSpeed = forwardSpeed - turnSpeed;

        // controls to move
        leftMotors.spin(forward, leftSpeed, percent);
        rightMotors.spin(forward, rightSpeed, percent);

        // Stop motors if both joysticks are centered
        if (forwardSpeed == 0 && turnSpeed == 0) {
            leftMotors.stop();
            rightMotors.stop();
        }

    
    }
}

int main() {
    // Start the user control loop
    userControlLoop();
}
