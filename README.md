
# Signal Handling Application

This project demonstrates the use of **real-time signals** in a Linux environment. The application consists of two components:
1. **Receiver**: A program that listens for real-time signals (`SIGRTMIN`) and handles them based on the data sent.
2. **Sender**: A program that sends real-time signals with data (`0` for termination, `1` for abort with a core dump) to the Receiver.

## Project Structure

The project is organized into the following files:
- **Receiver Application**:
  - `receiver.h`: Header file for the Receiver.
  - `receiver.c`: Implementation of the Receiver.
- **Sender Application**:
  - `sender.h`: Header file for the Sender.
  - `sender.c`: Implementation of the Sender.

## Compilation

### Requirements
- A Linux-based system (tested on Ubuntu)
- GCC or Clang for compiling C programs

### Steps to Compile:
1. **Receiver**:
   - Compile the Receiver files:
     ```bash
     gcc -o receiver receiver.c
     ```
   
2. **Sender**:
   - Compile the Sender files:
     ```bash
     gcc -o sender sender.c
     ```

## Usage

### 1. Running the Receiver:
To start the Receiver, open a terminal and execute:
```bash
./receiver
```
This will display the PID of the Receiver and wait for incoming signals. The Receiver listens for real-time signals (`SIGRTMIN`), which it handles based on the data sent (0 or 1).

### 2. Sending Signals from the Sender:
To send a signal from the Sender, run the following command:
```bash
./sender <receiver_pid> <data>
```
Where:
- `<receiver_pid>` is the PID of the running Receiver (you can get it from the output of the Receiver).
- `<data>` is the data to be sent with the signal. It can be either `0` (to terminate the Receiver) or `1` (to abort the Receiver with a core dump).

Example:
```bash
./sender 12345 0   # This will terminate the Receiver normally.
./sender 12345 1   # This will abort the Receiver with a core dump.
```

### Signal Handling
- If the data sent is `0`, the Receiver will terminate normally.
- If the data sent is `1`, the Receiver will abort and generate a core dump.

## Files Overview

### `receiver.h`
Header file containing function declarations for the Receiver application:
- **`handle_signal`**: Signal handler that processes the incoming signals.
- **`start_receiver`**: Initializes the signal handler and starts the Receiver.

### `receiver.c`
Implementation of the Receiver application. It listens for real-time signals (`SIGRTMIN`) and takes actions based on the received data:
- If data is `0`, the Receiver terminates normally.
- If data is `1`, the Receiver aborts and generates a core dump.

### `sender.h`
Header file containing function declarations for the Sender application:
- **`send_signal`**: Sends a real-time signal (`SIGRTMIN`) with data (0 or 1) to the Receiver.

### `sender.c`
Implementation of the Sender application. It sends a real-time signal (`SIGRTMIN`) with specified data to the Receiver:
- Takes the PID of the Receiver and the data (0 or 1) as input.
