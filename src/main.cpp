#include "vex.h"

using namespace vex;

// Initialize components
brain Brain;
controller Controller;
motor leftMotorA = motor(PORT1, false);
motor leftMotorB = motor(PORT2, false);
motor rightMotorA = motor(PORT3, true);
motor rightMotorB = motor(PORT4, true);

// Group motors
motor_group leftMotors(leftMotorA, leftMotorB);
motor_group rightMotors(rightMotorA, rightMotorB);

// 4 motor drivetrain object
drivetrain Drivetrain = drivetrain(leftMotors, rightMotors, 259.34, 320, 40, mm, 1);

// PID control variables
double Kp = 0.3;  // Proportional gain
double Ki = 0.0;  // Integral gain
double Kd = 0.05;  // Derivative gain

double leftError, rightError;
double leftPrevError = 0, rightPrevError = 0;
double leftIntegral = 0, rightIntegral = 0;
double leftDerivative, rightDerivative;
double leftTargetSpeed, rightTargetSpeed;

void userControlLoop() {
    // Set initial velocity and stopping type
    Drivetrain.setStopping(brake);

    while (true) {
        // Get joystick positions for forward and turning
        int forwardSpeed = Controller.Axis2.position() * 3;
        int turnSpeed = Controller.Axis1.position() * 3;

        // Calculate target speeds for each motor group
        leftTargetSpeed = forwardSpeed + turnSpeed;
        rightTargetSpeed = forwardSpeed - turnSpeed;

        // Get current motor speeds
        double leftCurrentSpeed = leftMotors.velocity(percent);
        double rightCurrentSpeed = rightMotors.velocity(percent);

        // Calculate PID error for left side
        leftError = leftTargetSpeed - leftCurrentSpeed;
        leftIntegral += leftError;  // Accumulate error for integral term
        leftDerivative = leftError - leftPrevError;  // Difference for derivative term

        // Calculate PID output for left side
        double leftOutput = (Kp * leftError) + (Ki * leftIntegral) + (Kd * leftDerivative);
        leftMotors.spin(forward, leftOutput, percent);

        // Update previous error for left side
        leftPrevError = leftError;

        // Calculate PID error for right side
        rightError = rightTargetSpeed - rightCurrentSpeed;
        rightIntegral += rightError;  // Accumulate error for integral term
        rightDerivative = rightError - rightPrevError;  // Difference for derivative term

        // Calculate PID output for right side
        double rightOutput = (Kp * rightError) + (Ki * rightIntegral) + (Kd * rightDerivative);
        rightMotors.spin(forward, rightOutput, percent);

        // Update previous error for right side
        rightPrevError = rightError;

        // If both joysticks are centered, stop the motors
        if (forwardSpeed == 0 && turnSpeed == 0) {
            leftMotors.stop();
            rightMotors.stop();
        }

        // Small delay for stability
        vex::task::sleep(20);
    }
}

int main() {
    // Start the user control loop
    userControlLoop();
}
