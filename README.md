# CANSendQueue Library

The `CANSendQueue` library offers a non-blocking approach to queue CAN messages for transmission on Arduino platforms. **Importantly, this library does not handle the actual transmission of the CAN message; instead, you must provide this function. The library then leverages your function to queue and manage the sending of the message.** This design ensures the library's adaptability and compatibility across various CAN hardware and libraries.

The library further supports configurable retries, overwrites the oldest message if the queue becomes full, and tracks transmission failures.

## Features

- **Non-blocking Operation**: The library efficiently handles your CAN messages without blocking your main application.
- **Configurable Retries**: You can set the number of times the library should attempt to resend a failed message.
- **Overwriting Capability**: If the queue is full and a new message needs to be added, the oldest message will be overwritten, ensuring that the newest data is always prioritized.
- **Transmission Failure Tracking**: Keep tabs on the number of failed transmissions, giving you insight into potential communication issues.
- **Configurable Queue Size**: The queue size defaults to 10 but can be customized during instantiation of the `CANSendQueue` object.
- **Versatility**: Adapt to various CAN hardware or libraries by providing your own sending function.


## Usage

```
#include <CANSendQueue.h>

bool yourSendFunction(uint16_t id, uint8_t* array, uint8_t length) {
    // Implement your CAN sending logic here
    // Return true on success, false on failure
}

CANSendQueue canQueue(yourSendFunction, 15);  // 15 is the custom queue size

void setup() {
    // Your setup code
}

void loop() {
    // Your loop code, use canQueue.enqueue(), canQueue.send(), etc.
}

```

### Providing a CAN Send Function:

For the library to work, you must provide a function that implements the actual CAN message sending mechanism. The function should have the following signature:

```
bool yourSendFunction(uint16_t id, uint8_t* data, uint8_t length);
```

**Note**: This function should return `true` when the CAN message is sent successfully, and `false` otherwise.

### Implementing the Library:


```
#include <CANSendQueue.h>

bool yourSendFunction(uint16_t id, uint8_t* array, uint8_t length) {
    // Implement your CAN sending logic here
    // Return true on success, false on failure
}

CANSendQueue canQueue(yourSendFunction);  // Uses the default queue size

void setup() {
    // Your setup code
}

void loop() {
    // Your loop code, use canQueue.enqueue(), canQueue.send(), etc.
}
```


## Methods Overview

- `bool enqueue(const CANMessage& msg)`: Adds a CAN message to the queue. If the queue is full, it overwrites the oldest message. Returns `true` on successful enqueue.
- `void setMaxRetries(uint8_t retries)`: Configures the maximum number of retry attempts for failed message transmissions.
- `uint32_t getFailedCount() const`: Retrieves the number of failed message transmissions.
- `void resetFailedCount()`: Resets the count of failed message transmissions to zero.
- `void send()`: Initiates the sending process for the message at the front of the queue. This method is non-blocking.
- `bool isFull() const`: Checks if the queue is full. Returns `true` if full, otherwise `false`.
- `bool isEmpty() const`: Checks if the queue is empty. Returns `true` if empty, otherwise `false`.
- `int howManyInQueue() const`: Provides the number of messages currently in the queue.


## Contributing

Feel free to open issues or pull requests if you'd like to enhance the library, introduce new features, or fix existing bugs. Your feedback and contributions are much appreciated!
