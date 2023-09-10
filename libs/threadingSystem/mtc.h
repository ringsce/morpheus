#ifndef MTC_H
#define MTC_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  //Header file for sleep(). man 3 sleep for details.
#include <pthread.h>
void *print_message_function( void *ptr );

#endif // MTC_H
