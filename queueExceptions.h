#ifndef QUEUE_EXCEPTIONS_H
#define QUEUE_EXCEPTIONS_H

#include <stdexcept>

class WrongQueueSizeException: public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: wrong queue size.\n";
    }
};

class QueueUnderflowException: public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: queue underflow.\n";
    }
};

class QueueOverflowException: public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: queue overflow.\n";
    }
};

#endif //QUEUE_EXCEPTIONS_H
