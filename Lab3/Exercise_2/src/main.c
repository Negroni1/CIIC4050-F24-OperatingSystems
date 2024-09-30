#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <sys/time.h>

#include "functions.h"
int main() {
    for (int i = 0; i < SIZE_MAX; i++) {
        array[i] = tan(i);
    }
    
    completed_threads = 0;
    struct timeval start;
    gettimeofday(&start, NULL);

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond_threads_done, NULL);

    pthread_t p_main;
    pthread_t p_threads[AMOUNT_THREADS];
    int segment_starts[AMOUNT_THREADS];

    pthread_create(&p_main, NULL, Total, NULL);

    // Create threads to calculate segments
    for (int i = 0; i < AMOUNT_THREADS; i++) {
        segment_starts[i] = i * SIZE_SEGMENT;
        pthread_create(&p_threads[i], NULL, CalculateSegment, (void*) &segment_starts[i]);
    }

    pthread_join(p_main, NULL);
    for (int i = 0; i < AMOUNT_THREADS; i++) {
        pthread_join(p_threads[i], NULL);
    }

    pthread_cond_destroy(&cond_threads_done);
    pthread_mutex_destroy(&mutex);

    printf("Time elapsed for each thread:\n");
    for (int i = 0; i < AMOUNT_THREADS; i++) {
        printf("+ Thread %d time: %ld ms\n", i + 1, GetElapsedTime(start, time_taken[i]));
    }

    return 0;
}
