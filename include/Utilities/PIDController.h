#ifndef PID_H
#define PID_H

class PIDController{

private:
    double kP;
    double kI;
    double kD;

    double integral; 
    double previousError;

public: 
    PIDController(double kP, double kI, double kD);

    void reset();
    double calculate(double setpoint, double current);

}; 

#endif