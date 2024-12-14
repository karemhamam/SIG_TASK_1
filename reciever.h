/**
 * @file reciever.h
 * @brief Header file for the Reciever application.
 * 
 * This contains the declarations for the signal handler
 * and initialization function for the Reciever application.
 */
#ifndef RECIEVER_H
#define RECIEVER_H

#include <stdio.h>   // for I/O functions like printf
#include <stdlib.h>  // for general utilities like exit() and abort()
#include <signal.h>  // for signal handling functions ans structures.
#include <unistd.h>  // for functions like getpid() and pause().

/**
 * @brief Signal handler for handling real-time signals.
 *
 * This function handled the `SIGRTMIN` signal and performs actions
 * based on the recieved date (terminate or abort).
 *
 * @param sig     The signal number.
 * @param si      Pointer to the signal information structure.
 * @param context Unused context parameter (for compatibility).
*/
void handle_signal(int sig , siginfo_t *si , void *context);




#endif