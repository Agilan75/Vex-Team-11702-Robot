#include "vex.h"

using namespace vex;

class DrivetrainSubsystem { 

private:
    motor_group leftMotors;
    motor_group rightMotors;
    drivetrain Drivetrain;
    double Kp, Ki, Kd;
    double leftPrevError, rightPrevError;
    double leftIntegral, rightIntegral;
    double maxIntegral;

public:

    // constructor
    DrivetrainSubsystem()
        : leftMotors(motor(PORT1), motor(PORT2), motor(PORT3)),
          rightMotors(motor(PORT4, true), motor(PORT5, true), motor(PORT6, true)),
          Drivetrain(leftMotors, rightMotors, 259.34, 320, 40, mm, 1),
          Kp(0.3), Ki(0.0), Kd(0.05), leftPrevError(0), rightPrevError(0), 
          leftIntegral(0), rightIntegral(0), maxIntegral(50) {}

    
    void drive(int forwardSpeed, int turnSpeed, int deadband = 5, int scaleFactor = 3) { 
        forwardSpeed *= scaleFactor;
        turnSpeed *= scaleFactor;

        if (abs(forwardSpeed) < deadband && abs(turnSpeed) < deadband) {
            forwardSpeed = 0;
            turnSpeed = 0;
        }

        // speeds
        double leftTargetSpeed = forwardSpeed + turnSpeed;
        double rightTargetSpeed = forwardSpeed - turnSpeed;
        double leftCurrentSpeed = leftMotors.velocity(percent);
        double rightCurrentSpeed = rightMotors.velocity(percent);

        // pid for left motor
        double leftError = leftTargetSpeed - leftCurrentSpeed;
        leftIntegral += leftError;
        double leftDerivative = leftError - leftPrevError;
        double leftOutput = (Kp * leftError) + (Ki * leftIntegral) + (Kd * leftDerivative);
        leftMotors.spin(forward, leftOutput, percent);
        leftPrevError = leftError;

        // pid for right motor
        double rightError = rightTargetSpeed - rightCurrentSpeed;
        rightIntegral += rightError;
        double rightDerivative = rightError - rightPrevError;
        double rightOutput = (Kp * rightError) + (Ki * rightIntegral) + (Kd * rightDerivative);
        rightMotors.spin(forward, rightOutput, percent);
        rightPrevError = rightError;

        if (forwardSpeed == 0 && turnSpeed == 0) {
            leftMotors.stop();
            rightMotors.stop();
        }
    }
};