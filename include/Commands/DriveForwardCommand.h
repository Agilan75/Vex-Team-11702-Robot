#ifndef DRIVE_FORWARD_COMMAND 
#define DRIVE_FORWARD_COMMAND

#include "Command.h"
#include "Subsystems/DriveSubsystem.h"
#include <functional>

class DriveForwardCommand: public Command {

private:
    DriveSubsystem *driveSubsystem;
    bool isFinishedBool;
    double travelDis;

public:
    DriveForwardCommand(DriveSubsystem *dt, double travelDis);

    void initialize() override;
    void execute() override;
    bool isFinished() override;
    void end() override; 
};

#endif