#include <stdio.h>
#include <sched.h>
#include <sys/time.h>
#include <pthread.h>
#include "functions.h"

void* ThreadFunc(void* arg) {
    ThreadArgs *thread_args = (ThreadArgs*) arg;

    int policy;
    struct sched_param param;
    pthread_getschedparam(pthread_self(), &policy, &param);

    const char *policy_str = (policy == SCHED_FIFO) ? "SCHED_FIFO" :
                             (policy == SCHED_RR) ? "SCHED_RR" :
                             (policy == SCHED_OTHER) ? "SCHED_OTHER" : "UNKNOWN";

    printf("Thread %lu is running with policy %s and priority %d\n", pthread_self(), policy_str, param.sched_priority);

    int i = 0;
    while (i < 200) {
        for (volatile long j = 0; j < 1000000000; j++);
        printf("Thread %d running. iteration %d\n", thread_args->id, i);
        i++;
    }

    struct timeval end;
    gettimeofday(&end, NULL);
    thread_args->time = end;

    return NULL;
}

long GetElapsedTime(struct timeval start, struct timeval end) {
    return ((end.tv_sec - start.tv_sec)) +
           ((end.tv_usec - start.tv_usec) / 1000000);
}
