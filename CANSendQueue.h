#ifndef CANSendQueue_h
#define CANSendQueue_h

#include "Arduino.h"

struct CANMessage {
  uint16_t address;
  uint8_t data[8];
  uint8_t length;
};

class CANSendQueue {
public:
  typedef bool (*SendFunction)(uint16_t id, uint8_t* array, uint8_t length);

  CANSendQueue(SendFunction sendFunc, int customQueueSize = defaultQueueSize);
  ~CANSendQueue();

  bool enqueue(const CANMessage& msg);
  void setMaxRetries(uint8_t retries);
  uint32_t getFailedCount() const;
  void resetFailedCount();
  void send();

  bool isFull() const;
  bool isEmpty() const;
  int howManyInQueue() const;

private:
  static const int defaultQueueSize = 10;
  int queueSize;
  CANMessage* queue;
  uint8_t* retryCount;
  int front, rear;
  uint32_t failedCount;
  uint8_t maxRetries;
  SendFunction sendFunction;

  bool sendCANMessage(const CANMessage& msg);
};

#endif
