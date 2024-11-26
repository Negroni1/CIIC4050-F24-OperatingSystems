#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <sys/time.h>
#include <pthread.h>

typedef struct {
    int id;
    int priority;
    int policy;
    struct timeval time;
} ThreadArgs;  

void* ThreadFunc(void* arg);

long GetElapsedTime(struct timeval start, struct timeval end);

#endif  // FUNCTIONS_H
