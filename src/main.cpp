#include "vex.h"

using namespace vex;

brain Brain;
controller Controller;

motor leftMotorA = motor(PORT1, false);
motor leftMotorB = motor(PORT2, false);
motor rightMotorA = motor(PORT3, true);
motor rightMotorB = motor(PORT4, true);

motor_group leftMotors(leftMotorA, leftMotorB);
motor_group rightMotors(rightMotorA, rightMotorB);

drivetrain Drivetrain = drivetrain(leftMotors, rightMotors, 259.34, 320, 40, mm, 1);

double Kp = 0.3;
double Ki = 0.0;
double Kd = 0.05;

double leftError, rightError;
double leftPrevError = 0, rightPrevError = 0;
double leftIntegral = 0, rightIntegral = 0;
double leftDerivative, rightDerivative;
double leftTargetSpeed, rightTargetSpeed;

// capping integral so dont go too big to the point it dont work
double maxIntegral = 50;

// for joystick sensitivity when touching and inputs
int deadband = 5;
int scaleFactor = 3;

void userControlLoop() {
    Drivetrain.setStopping(brake);

    while (true) {
        // for joystcik movement
        int forwardSpeed = Controller.Axis2.position() * scaleFactor;
        int turnSpeed = Controller.Axis1.position() * scaleFactor;

        if (abs(forwardSpeed) < deadband && abs(turnSpeed) < deadband) {
            forwardSpeed = 0;
            turnSpeed = 0;
        }

        // speeds
        leftTargetSpeed = forwardSpeed + turnSpeed;
        rightTargetSpeed = forwardSpeed - turnSpeed;
        double leftCurrentSpeed = leftMotors.velocity(percent);
        double rightCurrentSpeed = rightMotors.velocity(percent);

        // pid for left motor
        leftError = leftTargetSpeed - leftCurrentSpeed;
        leftIntegral += leftError;
        leftDerivative = leftError - leftPrevError;
        double leftOutput = (Kp * leftError) + (Ki * leftIntegral) + (Kd * leftDerivative);
        leftMotors.spin(forward, leftOutput, percent);
        leftPrevError = leftError;

        // pid for right motor
        rightError = rightTargetSpeed - rightCurrentSpeed;
        rightIntegral += rightError;
        rightDerivative = rightError - rightPrevError;
        double rightOutput = (Kp * rightError) + (Ki * rightIntegral) + (Kd * rightDerivative);
        rightMotors.spin(forward, rightOutput, percent);
        rightPrevError = rightError;

        if (forwardSpeed == 0 && turnSpeed == 0) {
            leftMotors.stop();
            rightMotors.stop();
        }

        vex::task::sleep(20);
    }
}

int main() {
    userControlLoop();
}
