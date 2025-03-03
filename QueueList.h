#ifndef QUEUE_LIST_H
#define QUEUE_LIST_H

#include "Queue.h"

template <class T>
class QueueList: public Queue<T> {
public:

    QueueList() {

    }

    QueueList(const QueueList& other) {

    }

    QueueList(const QueueList&& other) noexcept {

    }

    QueueList& operator=(const QueueList& other) {

    }

    QueueList& operator=(const QueueList&& other) {

    }

    ~Queue {

    }

    T deQueue() override {
        if (head_ == nullptr) {
            throw
        }
        if (head_->nextNode_ == nullptr) {
            T result = head_->data_;
            delete head_;
            head_ = nullptr;
            return result;
        }

        T newHead = head_

    }

    void enQueue(const T& element) override {
        if (head_ == nullptr) {
            head_ = new Node(element, nullptr);
            return;
        }

        Node* lastNode = head_;
        while (lastNode->nextNode_ != nullptr) {
            lastNode = lastNode->nextNode_;
        }
        lastNode->nextNode = new Node(element, nullptr);
    }

    bool isEmpty() override {
        return head_ == nullptr;
    }
private:
    class Node {
        T data_;
        Node* nextNode_;

        Node(T data, Node* nextNode):
            data_(data),
            nextNode_(nextNode)
        { }
    };

    Node* head_ = nullptr;

    void swap(QueueList& other) noexcept {

    }
};
#endif //QUEUE_LIST_H
