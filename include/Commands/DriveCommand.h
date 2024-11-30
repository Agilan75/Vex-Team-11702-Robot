#ifndef DRIVECOMMAND_H
#define DRIVECOMMAND_H

#include "Command.h"
#include "Subsystems/DriveSubsystem.h"
#include <functional> 


class DriveCommand : public Command{
private:
    DriveSubsystem* driveSubsystem;
    std::function<double()> leftInputProvider; 
    std::function<double()> rightInputProvider;
    bool isFinishedBool;

public:
    DriveCommand(DriveSubsystem* dt, std::function<double()> leftSpeed, std::function<double()> rightSpeed);
    
    void initialize() override;
    void execute() override;
    bool isFinished() override;
    void end() override; //ADD THE FUNNY REQUIRMENTS
};

#endif