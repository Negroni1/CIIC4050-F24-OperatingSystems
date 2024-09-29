#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <sys/time.h>

#include "functions.h"

void* CalculateSegment1(void* arg);
void* CalculateSegment2(void* arg);
void* CalculateSegment3(void* arg);
void* CalculateSegment4(void* arg);
void* CalculateSegment5(void* arg);

void* Total(void* arg);
pthread_mutex_t mutex;

double result_1;
double result_2;
double result_3;
double result_4;
double result_5;

struct timeval time1, time2, time3, time4, time5;

pthread_cond_t cond_threads_done;

double array[1000000];
int completed_threads;

long get_elapsed_time(struct timeval start, struct timeval end) {
    return ((end.tv_sec - start.tv_sec) * 1000) + ((end.tv_usec - start.tv_usec) / 1000);
}

void* CalculateSegment1(void* arg) {
    pthread_mutex_lock(&mutex);

    for (int i = 0; i < 200000; i++) {
        result_1 += array[i];
    }
    completed_threads++;
    if (completed_threads == 5) {
        pthread_cond_signal(&cond_threads_done);
    }
    gettimeofday(&time1, NULL); 
    pthread_mutex_unlock(&mutex);
    return NULL;
}

void* CalculateSegment2(void* arg) {
    pthread_mutex_lock(&mutex);

    for (int i = 200000; i < 400000; i++) {
        result_2 += array[i];
    }
    completed_threads++;
    if (completed_threads == 5) {
        pthread_cond_signal(&cond_threads_done);
    }
    gettimeofday(&time2, NULL); 
    pthread_mutex_unlock(&mutex);
    return NULL;
}

void* CalculateSegment3(void* arg) {
    pthread_mutex_lock(&mutex);

    for (int i = 400000; i < 600000; i++) {
        result_3 += array[i];
    }
    completed_threads++;
    if (completed_threads == 5) {
        pthread_cond_signal(&cond_threads_done);
    }
    gettimeofday(&time3, NULL); 
    pthread_mutex_unlock(&mutex);
    return NULL;
}

void* CalculateSegment4(void* arg) {
    pthread_mutex_lock(&mutex);

    for (int i = 600000; i < 800000; i++) {
        result_4 += array[i];
    }
    completed_threads++;
    if (completed_threads == 5) {
        pthread_cond_signal(&cond_threads_done);
    }
    gettimeofday(&time4, NULL); 
    pthread_mutex_unlock(&mutex);
    return NULL;
}

void* CalculateSegment5(void* arg) {
    pthread_mutex_lock(&mutex);

    for (int i = 800000; i < 1000000; i++) {
        result_5 += array[i];
    }
    completed_threads++;
    if (completed_threads == 5) {
        pthread_cond_signal(&cond_threads_done);
    }
    gettimeofday(&time5, NULL); 
    pthread_mutex_unlock(&mutex);
    return NULL;
}

void* Total(void* arg) {
    pthread_mutex_lock(&mutex);

    pthread_cond_wait(&cond_threads_done, &mutex);

    printf("Total: %f\n", result_1 + result_2 + result_3 + result_4 + result_5);
    pthread_mutex_unlock(&mutex);
    return NULL;
}
