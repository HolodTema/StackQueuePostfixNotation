#ifndef QUEUE_EXCEPTIONS_H
#define QUEUE_EXCEPTIONS_H

#include <stdexcept>

class WrongQueueSizeException: public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: wrong queue size.\n";
    }
};

#endif //QUEUE_EXCEPTIONS_H
