#ifndef SUBSYSTEM_H
#define SUBSYSTEM_H

class Subsystem
{
public:
    virtual ~Subsystem() = default; // Virtual destructor for proper cleanup

    // Optional common interface for all subsystems
    virtual void initialize() {} // Called to initialize the subsystem
    virtual void reset() {}      // Reset subsystem to default state
};

#endif // SUBSYSTEM_H