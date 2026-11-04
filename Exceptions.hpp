#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
#include <string>
#include "UnoCard.h" // Assuming UnoCard defines Color and Value

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
    UnoCard::Color expected;
    UnoCard::Color actual;
public:
    // Precondition: message must be a valid string, expectedColor and actualColor must be valid UnoCard::Color values
    // Postcondition: Initializes the exception with the specified message, expected color, and actual color
    InvalidColorSubmissionException(const std::string& message, UnoCard::Color expectedColor, UnoCard::Color actualColor)
        : std::runtime_error(message), expected(expectedColor), actual(actualColor) {}
    
    UnoCard::Color getExpected() const { return expected; }
    UnoCard::Color getActual() const { return actual; }
};

class InvalidValueSubmissionException : public std::runtime_error {
private:
    UnoCard::Value expected;
    UnoCard::Value actual;
public:
    // Precondition: message must be a valid string, expectedValue and actualValue must be valid UnoCard::Value values
    // Postcondition: Initializes the exception with the specified message, expected value, and actual value
    InvalidValueSubmissionException(const std::string& message, UnoCard::Value expectedValue, UnoCard::Value actualValue)
        : std::runtime_error(message), expected(expectedValue), actual(actualValue) {}
    
    UnoCard::Value getExpected() const { return expected; }
    UnoCard::Value getActual() const { return actual; }
};

#endif // EXCEPTIONS_H