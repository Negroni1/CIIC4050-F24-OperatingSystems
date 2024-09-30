#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <sys/time.h>

#include "functions.h"

long GetElapsedTime(struct timeval start, struct timeval end) {
    return ((end.tv_sec - start.tv_sec) * 1000) + ((end.tv_usec - start.tv_usec) / 1000);
}

void* CalculateSegment(void* arg) {
    int start_index = *((int*) arg);
    
    pthread_mutex_lock(&mutex);

    for (int i = start_index; i < start_index + SIZE_SEGMENT; i++) {
        result[completed_threads] += array[i];
    }
    completed_threads++;

    // Signal when all threads have completed
    if (completed_threads == AMOUNT_THREADS) {
        pthread_cond_signal(&cond_threads_done);
    }
    
    gettimeofday(&time_taken[completed_threads - 1], NULL);
    
    pthread_mutex_unlock(&mutex);
    return NULL;
}

void* Total(void* arg) {
    pthread_mutex_lock(&mutex);

    pthread_cond_wait(&cond_threads_done, &mutex);
    
    double total = 0;
    for (int i = 0; i < AMOUNT_THREADS; i++) {
        total += result[i];
    }
    printf("Total: %f\n", total);

    pthread_mutex_unlock(&mutex);
    return NULL;
}
