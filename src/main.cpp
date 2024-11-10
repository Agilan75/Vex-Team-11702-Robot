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

// initialize
motor leftMotorA(PORT1, false);
motor leftMotorB(PORT2, false);
motor rightMotorA(PORT3, true);
motor rightMotorB(PORT4, true);

motor_group leftMotors(leftMotorA, leftMotorB);
motor_group rightMotors(rightMotorA, rightMotorB);

drivetrain Drivetrain(leftMotors, rightMotors, 259.34, 320, 40, mm, 1);

// set constant for joysticks (I think this what im meant to do)
controller Controller;
const float Kp = 0.5;   
const float Ki = 0.01;  
const float Kd = 0.1;   
const float Kf = 0.2;  

// for error tracking
float targetX = 0;
float targetY = 0;
float errorX, errorY, prevErrorX = 0, prevErrorY = 0;
float integralX = 0, integralY = 0;
float derivativeX, derivativeY;

// feed-forward stuffs
float feedForward(float joystickVal) {
    return joystickVal * Kf;
}

// to get pid output
float pid(float target, float current, float &prevError, float &integral) {
    float error = target - current;
    integral += error;
    float derivative = error - prevError;
    prevError = error;
    return (Kp * error) + (Ki * integral) + (Kd * derivative);
}

//the main drive loop
void usercontrol() {
    while (true) {
        // get joystick vals
        float joystickX = Controller.Axis4.position();
        float joystickY = Controller.Axis3.position();

        // use feedforward to get needed speed
        float feedForwardX = feedForward(joystickX);
        float feedForwardY = feedForward(joystickY);

        // update it
        float currentX = leftMotors.position(degrees) - rightMotors.position(degrees);
        float currentY = (leftMotors.position(degrees) + rightMotors.position(degrees)) / 2;

        float pidAdjustX = pidControl(feedForwardX, currentX, prevErrorX, integralX);
        float pidAdjustY = pidControl(feedForwardY, currentY, prevErrorY, integralY);

        leftMotors.spin(forward, feedForwardY + pidAdjustY, velocityUnits::pct);
        rightMotors.spin(forward, feedForwardY - pidAdjustY, velocityUnits::pct);

        wait(20, msec);
    }
}

int main() {
    usercontrol();
}
