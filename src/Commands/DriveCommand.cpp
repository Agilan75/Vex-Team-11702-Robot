#include "DriveCommand.h"
#include "vex.h"

DriveCommand ::DriveCommand(DriveSubsystem *dt, int leftSpeed, int rightSpeed) :
    driveSubsystem(dt),
    leftSpeed(leftSpeed),
    rightSpeed(rightSpeed),
    isFinished(false)
{}

void DriveCommand :: initialize() {
    driveSubsystem->drive(leftSpeed, rightSpeed);
     
}
