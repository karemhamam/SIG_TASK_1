/**
* @file Sender.h
* @brief Headr file for the Sender application.
* 
* This file contains the declations for functions to send real-time signals.
*/

#ifndef SENDER_H
#define SENDER_H

#include <stdio.h>   // for I/O functions like printf
#include <stdlib.h>  // for general utilities like exit() and abort()
#include <signal.h>  // for signal handling functions ans structures.
#include <unistd.h>  // for functions like getpid() and pause().

/**
* @brief Sends a real-time with associated data to the specified PID.
*
* This function sends the `SIGRTMIN` signal with data ( 0 or 1 ) to the Reciever application.
*
* @param reciever_pid The PID of the reciever process.
* @param data         The data to send `0` for terminate and `1` for abort.
* @return             `0` on success , -1 on failure.
*/
int send_signal(pid_t reciever_pid , int data);

#endif