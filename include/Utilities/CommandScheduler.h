#ifndef COMMAND_SCHEDULER 
#define COMMAND_SCHEDULER

#include <vector>
#include <map>
#include <algorithm>
#include "Command.h"
#include "Subsystem.h"

class CommandScheduler {

private:
    std::vector<Command*> activeCommands;
    std::map<Subsystem *, Command *> subsystemOwnership;

public:
    void schedule(Command *command);
    void run();
    void cancel(Command *command);
    void clear(); 

};

#endif

