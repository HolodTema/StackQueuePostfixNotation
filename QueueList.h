#ifndef QUEUE_LIST_H
#define QUEUE_LIST_H

#include "Queue.h"
#include "queueExceptions.h"

template <class T>
class QueueList: public Queue<T> {
public:
    QueueList() = default;

    QueueList(const QueueList& other) {
        if (other.head_ != nullptr) {
            head_ = new Node(other.head_->data, nullptr, nullptr);

            tail_ = head_;
            Node* otherNode = other.head_->nextNode_;

            while (otherNode != nullptr) {
                tail_->nextNode = new Node(otherNode.data_, tail_, nullptr);
                otherNode = otherNode->nextNode_;
                node = node->nextNode_;
            }
        }
    }

    QueueList(const QueueList&& other) noexcept:
        head_(other.head_),
        tail_(other.tail_)
    {

    }

    ~QueueList() override {
        if (head_ != nullptr) {
            while (head_->nextNode_ != nullptr) {
                const Node* exHead = head_;
                head_ = head_->nextNode;
                delete exHead;
            }
            delete head_;
        }
    }

    QueueList& operator=(const QueueList& other) {
        if (&other != this) {
            QueueList& otherCopy(other);
            swap(otherCopy);
        }
        return *this;
    }

    QueueList& operator=(QueueList&& other) noexcept {
        if (&other != this) {
            head_ = other.head_;
            tail_ = other.tail_;
        }
        return *this;
    }

    T deQueue() override {
        if (head_ == nullptr) {
            throw QueueUnderflowException();
        }
        if (head_->nextNode_ == nullptr) {
            T result = head_->data_;
            delete head_;
            head_ = nullptr;
            return result;
        }

        T newHead = head_;
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
        Node* prevNode_;
        Node* nextNode_;

        Node(T data, Node* prevNode, Node* nextNode):
            data_(data),
            prevNode_(prevNode),
            nextNode_(nextNode)
        { }
    };

    Node* head_ = nullptr;
    Node* tail_ = nullptr;

    void swap(QueueList& other) noexcept {
        head_ = other.head_;
        tail_ = other.tail_;
    }
};
#endif //QUEUE_LIST_H
