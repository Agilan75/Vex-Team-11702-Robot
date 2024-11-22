#ifndef DRIVECOMMAND_H
#define DRIVECOMMAND_H

#include "Subsystems/DriveSubsystem.h"

class DriveCommand{
private:
    DriveSubsystem* driveSubsystem;
    int leftSpeed;
    int rightSpeed;
    bool isFinished;

public:
    DriveCommand(DriveSubsystem *dt, int leftSpeed, int rightSpeed);
    void initialize();
    void execute();
    bool isComplete();
    void end();
};

#endif