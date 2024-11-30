#include "DriveForwardCommand.h"
#include "DriveSubsystem.h"
#include "vex.h"
#include <functional>
#include <iostream>

DriveForwardCommand ::DriveForwardCommand(DriveSubsystem *dt, double travelDis):
    driveSubsystem(dt), 
    travelDis(travelDis),
    isFinishedBool(false)
{}

void DriveForwardCommand :: initialize()
{
    driveSubsystem->stop(); 
    driveSubsystem
}

void DriveForwardCommand :: execute() {
    //driveSubsystem->drive(1, 1); 
}

bool DriveForwardCommand :: isFinished(){
    return true; 
}