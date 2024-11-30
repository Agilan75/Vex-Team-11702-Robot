#include "CommandScheduler.h"
#include <vector>
#include "Command.h"
#include "Constants.h"
#include "Subsystem.h"
#include "vex.h"

using namespace vex;

void CommandScheduler::schedule(Command *command){
    auto requirements = command->getRequirements();

    for (Subsystem *subsystem : requirements){
        if (subsystemOwnership.count(subsystem)){
            return;
        }
    }
    for (Subsystem *subsystem : requirements){
        subsystemOwnership[subsystem] = command;
    }

    activeCommands.push_back(command);
    command->initialize();
}

void CommandScheduler::run(){
    for(auto it = activeCommands.begin(); it != activeCommands.end(); ){
        Command* command = *it; 
        
        if (!command->isFinished()){
            command->execute();
            ++it;
        }
        else{
            command->end();
            auto requirements = command->getRequirements();

            for (Subsystem *subsystem : requirements){
                    subsystemOwnership.erase(subsystem);
                }
            }
        }
}

void CommandScheduler::cancel(Command *command){
    command->end();
    auto requirements = command->getRequirements();
    for (Subsystem *subsystem : requirements){
        subsystemOwnership.erase(subsystem);
    }

    activeCommands.erase(std::remove(activeCommands.begin(), activeCommands.end(), command), activeCommands.end());
}

void CommandScheduler::clear(){
    for (Command *command : activeCommands){
        command->end();
    }
    activeCommands.clear();
    subsystemOwnership.clear();
}

//ADD COMMAND GROUPS SOON