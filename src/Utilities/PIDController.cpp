#include "vex.h"
#include "PIDController.h"
#include "Subsystem.h"
#include "Constants.h"

using namespace vex;

PIDController::PIDController(double kP, double kI, double kD):
    kP(kP), kI(kI), kD(kD), integral(0), previousError(0)
    {}

void PIDController::reset(){
    integral = 0;
    previousError = 0;
}

double PIDController::calculate(double setpoint, double current){
    double error = setpoint - current;
    integral += error;
    double derivative = error - previousError;

    double output = (kP * error) + (kI * integral) + (kD * derivative);

    previousError = error;

    return output;
}
