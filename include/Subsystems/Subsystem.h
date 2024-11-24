#ifndef SUBSYSTEM_H
#define SUBSYSTEM_H

class Subsystem
{
public:
    virtual ~Subsystem() = default; // Virtual destructor for proper cleanup

    virtual void initialize() {} // Called to initialize the subsystem
    virtual void reset() {}      // Reset subsystem to default state
};

#endif 