#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
#include <string>

class InvalidPlayerTurnException : public std::runtime_error {
private:
    std::string playerId;
public:
    // Precondition: message must be a valid string, pid must be a valid player ID
    // Postcondition: Initializes the exception with the specified message and player ID
    InvalidPlayerTurnException(const std::string& message, const std::string& pid)
        : std::runtime_error(message), playerId(pid) {}
    
    std::string getPlayerId() const { return playerId; }
};

class InvalidColorSubmissionException : public std::runtime_error {
private:
    int expected;
    int actual;
public:
    // Precondition: message must be a valid string, expectedColor and actualColor must be valid 
    // Postcondition: Initializes the exception with the specified message, expected color, and actual color
    InvalidColorSubmissionException(const std::string& message, int expectedColor, int actualColor)
        : std::runtime_error(message), expected(expectedColor), actual(actualColor) {}
    
    int getExpected() const { return expected; }
    int getActual() const { return actual; }
};

class InvalidValueSubmissionException : public std::runtime_error {
private:
    int expected;
    int actual;
public:
    // Precondition: message must be a valid string, expectedValue and actualValue must be valid 
    // Postcondition: Initializes the exception with the specified message, expected value, and actual value
    InvalidValueSubmissionException(const std::string& message, int expectedValue, int actualValue)
        : std::runtime_error(message), expected(expectedValue), actual(actualValue) {}
    
    int getExpected() const { return expected; }
    int getActual() const { return actual; }
};

#endif // EXCEPTIONS_H
