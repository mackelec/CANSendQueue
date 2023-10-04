#ifndef CANQueueLib_h
#define CANQueueLib_h

#include "Arduino.h"

struct CANMessage {
  uint16_t address;
  uint8_t data[8];
  uint8_t length;
};

class CANQueue {
public:
  CANQueue();

  bool enqueue(const CANMessage& msg);
  void setMaxRetries(uint8_t retries);
  uint32_t getFailedCount() const;
  void resetFailedCount();
  void Send();

private:
  static const int queueSize = 10;
  CANMessage queue[queueSize];
  uint8_t retryCount[queueSize];
  int front, rear;
  uint32_t failedCount;
  uint8_t maxRetries;

  bool isFull() const;
  bool isEmpty() const;
  bool sendCANMessage(const CANMessage& msg);
};

#endif
