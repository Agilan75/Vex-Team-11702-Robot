#include "vex.h"
#include "DriveSubsystem.h"
#include "MogoSubsystem.h"
#include "IntakeSubsystem.h"
#include "DriveCommand.h"

using namespace vex;

// create objects
brain Brain;
controller Controller;
competition Competition;
DriveSubsystem driveSubsystem;
MogoSubsystem mogoSubsystem;
IntakeSubsystem intakeSubsystem;

void auton()
{
    // auton in here eventually
}

void userControlLoop()
{
    while (true)
    {
        DriveCommand driveCommand(&driveSubsystem, 1000, 1000);
        wait(20, sec);
    }
}

int main()
{
    Competition.autonomous(auton);
    Competition.drivercontrol(userControlLoop);
    userControlLoop();
}
