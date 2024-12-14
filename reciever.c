/**
 * @file reciever.c
 * @brief Implementation of the Reciever application.
 * 
 * The Reciever application waits for real-time signals (`SIGRTMIN`)
 * and processes the data sent with the signals.
 */

#include "reciever.h"


int main ()
{
    struct sigaction sa ;
    sa.sa_flags     = SA_SIGINFO ;
    sa.sa_sigaction = handle_signal ;

    if (sigaction(SIGRTMIN , &sa , NULL ) == -1 )
    {
        perror("sigaction");
        exit(1);
    }

    printf("Reciever runnig with PID: %d\n",getpid());
    printf("Waiting for signals.....\n");

    while(1)
    {
        pause();
    }

    return 0 ; 
}

void handle_signal(int sig , siginfo_t *si , void *context)
{
    printf("Recieved signal %d with data %d\n", sig , si->si_value.sival_int);

    if (si->si_value.sival_int == 0 )
    {
        printf ("Terminating :'(\n");
        exit(0);
    }else if (si->si_value.sival_int == 1 )
    {
        printf ("Aborting with core dump >_<\n");
        abort();
    }else
    {
        /* I'm sure that the Sender applicaion won't send any other data */
        printf("Invalid data \n Ignored \n ");
       
    }
}