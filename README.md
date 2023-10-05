# CANSendQueue Library

The `CANSendQueue` library offers a non-blocking approach to queue CAN messages for transmission on Arduino platforms. **Importantly, this library does not handle the actual transmission of the CAN message; instead, you must provide this function. The library then leverages your function to queue and manage the sending of the message.** This design ensures the library's adaptability and compatibility across various CAN hardware and libraries.

The library further supports configurable retries, overwrites the oldest message if the queue becomes full, and tracks transmission failures.

## Features

placeholder_Features_List

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
