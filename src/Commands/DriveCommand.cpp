#include "DriveCommand.h"
#include "DriveSubsystem.h"
#include "vex.h"
#include <functional>
#include <iostream>
#include "Log.h"

DriveCommand ::DriveCommand(DriveSubsystem *dt, std::function<double()> leftSpeed, std::function<double()> rightSpeed) :
    driveSubsystem(dt),
    leftInputProvider(leftSpeed),
    rightInputProvider(rightSpeed),
    isFinishedCheck(false)
{}

void DriveCommand :: initialize() {
}

void DriveCommand ::execute(){
    driveSubsystem->drive(leftInputProvider(), rightInputProvider());
    Log::log("rightSpeed", leftInputProvider());
    Log::log("rightSpeed", rightInputProvider());
}

void DriveCommand ::end()
{
    driveSubsystem->stop();
}

bool DriveCommand ::isFinished() {
    return isFinishedCheck;
}