#include "CANSendQueue.h"

CANSendQueue::CANSendQueue(SendFunction sendFunc, int customQueueSize) 
  : front(0), rear(0), failedCount(0), maxRetries(3), sendFunction(sendFunc), queueSize(customQueueSize) {
    queue = new CANMessage[queueSize];
    retryCount = new uint8_t[queueSize];
    for (int i = 0; i < queueSize; i++) {
        retryCount[i] = 0;
    }
}

CANSendQueue::~CANSendQueue() {
    delete[] queue;
    delete[] retryCount;
}

bool CANSendQueue::enqueue(const CANMessage& msg) {
    if (isFull()) {
        // If the queue is full, move the front pointer to discard the oldest message
        front = (front + 1) % queueSize;
    }
    queue[rear] = msg;
    retryCount[rear] = 0;
    rear = (rear + 1) % queueSize;
    return true;
}

void CANSendQueue::setMaxRetries(uint8_t retries) {
    maxRetries = retries;
}

uint32_t CANSendQueue::getFailedCount() const {
    return failedCount;
}

void CANSendQueue::resetFailedCount() {
    failedCount = 0;
}

void CANSendQueue::Send() {
    if(isEmpty()) return;

    if (sendCANMessage(queue[front])) {
        front = (front + 1) % queueSize;
    } else {
        retryCount[front]++;
        if(retryCount[front] >= maxRetries) {
            failedCount++;
            front = (front + 1) % queueSize;
        }
    }
}

bool CANSendQueue::isFull() const {
    return (rear + 1) % queueSize == front;
}

bool CANSendQueue::isEmpty() const {
    return rear == front;
}

bool CANSendQueue::sendCANMessage(const CANMessage& msg) {
    return sendFunction(msg.address, msg.data, msg.length);
}
