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

placeholder_Usage_Code

### Providing a CAN Send Function:

For the library to work, you must provide a function that implements the actual CAN message sending mechanism. The function should have the following signature:

placeholder_Function_Signature

**Note**: This function should return `true` when the CAN message is sent successfully, and `false` otherwise.

### Implementing the Library:

placeholder_Library_Implementation

## Methods Overview

placeholder_Methods_Overview

## Contributing

Feel free to open issues or pull requests if you'd like to enhance the library, introduce new features, or fix existing bugs. Your feedback and contributions are much appreciated!
