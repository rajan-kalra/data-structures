#include <iostream>
#include <string>
#include <unordered_map>

class Logger {
public:
    /** Initialize your data structure here. */
    Logger() {
        // The unordered_map is automatically initialized as an empty map.
        // No explicit constructor logic is needed here for this simple approach.
    }

    /** Returns true if the message should be printed in the given timestamp,
        otherwise returns false.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, std::string message) {
        // Use find() for a more robust check that handles potential
        // default-construction of keys if operator[] is used on a new key.
        auto it = message_last_print_time.find(message);

        // Case 1: The message has never been printed before.
        if (it == message_last_print_time.end()) {
            message_last_print_time[message] = timestamp;
            return true;
        }

        // Case 2: The message has been printed before.
        int last_timestamp = it->second;
        if (timestamp >= last_timestamp + 10) {
            // It has been 10 or more seconds since the last print.
            // Update the timestamp and return true.
            message_last_print_time[message] = timestamp;
            return true;
        }

        // Case 3: Less than 10 seconds have passed.
        return false;
    }

private:
    std::unordered_map<std::string, int> message_last_print_time;
};
    
int main() {
    Logger logger;
    // Test cases
    std::cout << std::boolalpha;
    std::cout << "logger.shouldPrintMessage(1, \"foo\"): " << logger.shouldPrintMessage(1, "foo") << " (expected: true)\n";
    std::cout << "logger.shouldPrintMessage(2, \"bar\"): " << logger.shouldPrintMessage(2, "bar") << " (expected: true)\n";
    std::cout << "logger.shouldPrintMessage(3, \"foo\"): " << logger.shouldPrintMessage(3, "foo") << " (expected: false)\n";
    std::cout << "logger.shouldPrintMessage(8, \"bar\"): " << logger.shouldPrintMessage(8, "bar") << " (expected: false)\n";
    std::cout << "logger.shouldPrintMessage(10, \"foo\"): " << logger.shouldPrintMessage(10, "foo") << " (expected: false)\n";
    std::cout << "logger.shouldPrintMessage(11, \"foo\"): " << logger.shouldPrintMessage(11, "foo") << " (expected: true)\n";
    std::cout << "logger.shouldPrintMessage(20, \"bar\"): " << logger.shouldPrintMessage(20, "bar") << " (expected: true)\n";
    std::cout << "logger.shouldPrintMessage(21, \"baz\"): " << logger.shouldPrintMessage(21, "baz") << " (expected: true)\n";
    std::cout << "logger.shouldPrintMessage(25, \"baz\"): " << logger.shouldPrintMessage(25, "baz") << " (expected: false)\n";
    return 0;
}