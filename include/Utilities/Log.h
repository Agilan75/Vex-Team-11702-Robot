#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <sstream>
#include <string>

class Log {
public:
    // Constructor (optional)
    Log() = default;

    // Log a single message
    static void log(const std::string& message) {
        std::cout << message << std::endl;
    }

    // Log a message with a single variable
    template <typename T>
    static void log(const std::string& message, T variable) {
        std::cout << message << variable << std::endl;
    }

    // Log a message with multiple variables using variadic templates
    template <typename... Args>
    static void log(const std::string& message, Args... args) {
        std::cout << format(message, args...) << std::endl;
    }

    // Specific Logs for Subsystems
    static void logDriveSubsystem(double leftSpeed, double rightSpeed) {
        log("DriveSubsystem - Left Speed: ", leftSpeed, " | Right Speed: ", rightSpeed);
    }

    static void logArmSubsystem(double motorSpeed, double targetPosition = -1) {
        if (targetPosition >= 0) {
            log("ArmSubsystem - Motor Speed: ", motorSpeed, 
                " | Target Position: ", targetPosition);
        } else {
            log("ArmSubsystem - Motor Speed: ", motorSpeed);
        }
    }

    static void logPneumaticSubsystem(bool clampState) {
        log("PneumaticSubsystem - Clamp State: ", clampState ? "Engaged" : "Released");
    }

    static void logOdometrySubsystem(double xPosition, double yPosition, double heading) {
        log("OdometrySubsystem - Position (x, y): (", xPosition, ", ", yPosition, 
            ") | Heading: ", heading);
    }

    static void logIntakeSubsystem(double motorSpeed, bool isIntaking) {
        log("IntakeSubsystem - Motor Speed: ", motorSpeed, 
            " | Action: ", isIntaking ? "Intaking" : "Reversing");
    }

    static void logSensorSubsystem(double distance, double heading, bool bumperPressed, double rotation) {
        log("SensorSubsystem - Distance: ", distance, 
            " | Heading: ", heading, 
            " | Bumper: ", bumperPressed ? "Pressed" : "Not Pressed", 
            " | Rotation: ", rotation);
    }

    static void logVisionSubsystem(int objectCenterX, bool objectExists) {
        log("VisionSubsystem - Object Center X: ", objectCenterX, 
            " | Exists: ", objectExists ? "Yes" : "No");
    }

private:
    // Helper to format messages with variables
    template <typename... Args>
    static std::string format(const std::string& message, Args... args) {
        std::ostringstream stream;
        formatHelper(stream, message, args...);
        return stream.str();
    }

    // Recursive helper to append arguments to the message
    template <typename T, typename... Args>
    static void formatHelper(std::ostringstream& stream, const std::string& message, T first, Args... rest) {
        stream << message << first;
        formatHelper(stream, "", rest...);
    }

    // Base case for recursion
    static void formatHelper(std::ostringstream& stream, const std::string& message) {
        stream << message;
    }
};

#endif
