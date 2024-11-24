#ifndef COMMAND_H
#define COMMAND_H

#include <set> // For managing dependencies (subsystems)

class Subsystem; // Forward declaration

class Command
{
public:
    virtual ~Command() = default; // Virtual destructor for proper cleanup of derived classes

    // Lifecycle methods
    virtual void initialize() {}               // Called once when the command is first scheduled
    virtual void execute() {}                  // Called periodically while the command is active
    virtual void end() {}                      // Called once when the command finishes or is canceled
    virtual bool isFinished() { return true; } // Determines if the command is complete

    // Define which subsystems this command requires
    virtual std::set<Subsystem*> getRequirements() const { return {}; }
};

#endif // COMMAND_H