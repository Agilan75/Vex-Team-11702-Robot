#ifndef AUTONSUBSYSTEM_H
#define AUTONSUBSYSTEM_H

#include "vex.h"
using namespace vex;

#include "DriveSubsystem.h"
#include "ArmSubsystem.h"
#include "IntakeSubsystem.h"
#include "OdometrySubsystem.h"
#include "SensorSubsystem.h"
#include "Subsystem.h"

class AutonSubsystem {
private:
    DriveSubsystem driveSubsystem;
    ArmSubsystem armSubsystem;
    IntakeSubsystem intakeSubsystem;
    OdometrySubsystem odometrySubsystem;
    SensorSubsystem sensorSubsystem;

public:
    AutonSubsystem(DriveSubsystem drive, ArmSubsystem arm, IntakeSubsystem intake, 
                   OdometrySubsystem odometry, SensorSubsystem sensor);

    void moveForward(double speed, double distance);
    void turnToAngle(double angle);
    void alignToVisionTarget();
    void stopAtDistance(double targetDistance);
    void placeRingInHighGoal();
    void pickUpRing();

    void autonomousRoutine1();
    void autonomousRoutine2();
};

#endif
