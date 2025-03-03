#ifndef STACK_EXCEPTIONS_H
#define STACK_EXCEPTIONS_H

#include <stdexcept>

class StackOverflowException final: public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: stack overflow.\n";
    }
};

class StackUnderflowException final: public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: stack underflow.\n";
    }
};

class WrongStackSizeException final: public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: wrong stack size.\n";
    }
};

#endif //STACK_EXCEPTIONS_H
