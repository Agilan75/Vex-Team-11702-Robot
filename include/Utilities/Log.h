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