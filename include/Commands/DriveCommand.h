#ifndef DRIVECOMMAND_H
#define DRIVECOMMAND_H

#include "Subsystems/DriveSubsystem.h"
#include <functional> 

class DriveCommand{
private:
    DriveSubsystem* driveSubsystem;
    std::function<double()> leftInputProvider; 
    std::function<double()> rightInputProvider;
    bool isFinishedCheck;

public:
    DriveCommand(DriveSubsystem *dt, std::function<double()> leftSpeed, std::function<double()> rightSpeed);
    void initialize();
    void execute();
    bool isFinished();
    void end();
};

#endif