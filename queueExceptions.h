#ifndef QUEUE_EXCEPTIONS_H
#define QUEUE_EXCEPTIONS_H

#include <stdexcept>

class QueueUnderflowException: public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: queue underflow.\n";
    }
};

#endif //QUEUE_EXCEPTIONS_H
