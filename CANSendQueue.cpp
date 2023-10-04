#include "CANSendQueue.h"

CANSendQueue::CANSendQueue() : front(0), rear(0), failedCount(0), maxRetries(3) {}

bool CANSendQueue::enqueue(const CANMessage& msg) {
    if (!isFull()) {
        queue[rear] = msg;
        retryCount[rear] = 0;
        rear = (rear + 1) % queueSize;
        return true;
    }
    return false; // Queue is full
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
        front = (front + 1) % queueSize; // Move to next message if successfully sent
    } else {
        retryCount[front]++;
        if(retryCount[front] >= maxRetries) {
            failedCount++;
            front = (front + 1) % queueSize; // Move to the next message after reaching max retries
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
    // Replace with your actual implementation of sending CAN messages
    Serial.println("Sending CAN message:");
    Serial.print("Address: ");
    Serial.println(msg.address, HEX);
    Serial.print("Data: ");
    for (uint8_t i = 0; i < msg.length; i++) {
        Serial.print(msg.data[i], HEX);
        Serial.print(" ");
    }
    Serial.println();

    // Return true if sending was successful, false otherwise
    return true; // Replace with actual condition
}
