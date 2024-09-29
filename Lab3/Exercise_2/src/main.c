#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <sys/time.h>

#include "functions.h"
int main() {
    for (int i = 0; i < 1000000; i++) {
        array[i] = tan(i);
    }
    completed_threads = 0;
    struct timeval start;
    gettimeofday(&start, NULL); 

    pthread_t p_main;
    pthread_t p_1;
    pthread_t p_2;
    pthread_t p_3;
    pthread_t p_4;
    pthread_t p_5;

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond_threads_done, NULL);

    pthread_create(&p_main, NULL, Total, NULL);
    pthread_create(&p_1, NULL, CalculateSegment1, NULL);
    pthread_create(&p_2, NULL, CalculateSegment2, NULL);
    pthread_create(&p_3, NULL, CalculateSegment3, NULL);
    pthread_create(&p_4, NULL, CalculateSegment4, NULL);
    pthread_create(&p_5, NULL, CalculateSegment5, NULL);

    pthread_join(p_main, NULL);
    pthread_join(p_1, NULL);
    pthread_join(p_2, NULL);
    pthread_join(p_3, NULL);
    pthread_join(p_4, NULL);
    pthread_join(p_5, NULL);

    pthread_cond_destroy(&cond_threads_done);
    pthread_mutex_destroy(&mutex);

    printf("Time elapsed for each thread\n");
    printf("+ Thread 1 time: %ldms\n", get_elapsed_time(start, time1));
    printf("+ Thread 2 time: %ldms\n", get_elapsed_time(start, time2));
    printf("+ Thread 3 time: %ldms\n", get_elapsed_time(start, time3));
    printf("+ Thread 4 time: %ldms\n", get_elapsed_time(start, time4));
    printf("+ Thread 5 time: %ldms\n", get_elapsed_time(start, time5));
    return 0;
}
