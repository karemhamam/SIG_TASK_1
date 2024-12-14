/**
* @file sender.c
* @brief Implementation of the Sender application.
*
* Thes Sender applicatin sends data to the Reciever application
* with data (0 or 1).
*/

#include "sender.h"

/**
* @brief Main function for the Sender application.
* 
* This function parses command-line arguments and calls `send_signals` 
* to send a real-time signal to the Reciever application.
*
* @param argc Agument count.
* @param argv Argument vector.
* @return 0 onsuccess , 1 on failure.
*/
int main (int argc , char *argv[])
{
    if (argc != 3 )
    {
        fprintf(stderr , "Usage: %s <reciever-pid> <data>\n" , argv[0]);
        return 1; 
    }

    pid_t reciever_pid = atoi(argv[1]);
    int data = atoi(argv[2]);
//    if (data != 0 && data != 1 )
//     {
//         fprintf(stderr , "Data must be 0 or 1 ( >︿< )\n");
//         return 1; 
//     }

    return send_signal(reciever_pid , data );
}

int send_signal(pid_t reciever_pid , int data)
{
    union sigval value ;
    value.sival_int = data ;

    if (sigqueue(reciever_pid , SIGRTMIN , value ) == -1 )
    {
        perror("sigqueue");
        return -1 ;
    }

    printf ("Sent signal to PID %d with data %d\n" , reciever_pid , data );
    return 0 ;
}