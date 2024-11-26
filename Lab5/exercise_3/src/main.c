#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <sys/resource.h>
#include <sys/time.h>

#include "functions.h"

int main() {
    pthread_t t[4];
    struct timeval start;
    gettimeofday(&start, NULL);
    
    ThreadArgs threads[4];
    for (int i = 0; i < 4; i++) {
        threads[i].id = i;
        if (i % 2 == 0) {
            threads[i].policy = SCHED_FIFO;
        } else {
            threads[i].policy = SCHED_RR;
        }
    }

    // threads[0].priority = 50;
    // threads[1].priority = 50;
    // threads[2].priority = 50;
    // threads[3].priority = 50;

    struct sched_param param;
    pthread_attr_t attr;

    // for (int i = 0; i < 4; i++) {
    //     pthread_attr_init(&attr);
    //     pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);
    //     pthread_attr_setschedpolicy(&attr, threads[i].policy);
    //     param.sched_priority = threads[i].priority;
    //     pthread_attr_setschedparam(&attr, &param);
    //     pthread_create(&t[i], &attr, ThreadFunc, (void*)&threads[i]);
    // }


    pthread_attr_init(&attr);
    pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);
    pthread_attr_setschedpolicy(&attr, SCHED_FIFO);
    param.sched_priority = 50;
    pthread_attr_setschedparam(&attr, &param);
    pthread_create(&t[0], &attr,ThreadFunc, (void*)&threads[0]);

    pthread_attr_init(&attr);
    pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);
    pthread_attr_setschedpolicy(&attr, SCHED_RR);
    param.sched_priority = 50;
    pthread_attr_setschedparam(&attr, &param);
    pthread_create(&t[1], &attr,ThreadFunc, (void*)&threads[1]);

    pthread_attr_init(&attr);
    pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);
    pthread_attr_setschedpolicy(&attr, SCHED_FIFO);
    param.sched_priority = 50;
    pthread_attr_setschedparam(&attr, &param);
    pthread_create(&t[2], &attr,ThreadFunc, (void*)&threads[2]);

    pthread_attr_init(&attr);
    pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);
    pthread_attr_setschedpolicy(&attr, SCHED_RR);
    param.sched_priority = 50;
    pthread_attr_setschedparam(&attr, &param);
    pthread_create(&t[3], &attr,ThreadFunc, (void*)&threads[3]);

    for (int i = 0; i < 4; i++) {
        pthread_join(t[i], NULL);
    }

    for (int i = 0; i < 4; i++) {
        printf("Thread %d time taken: %ld s\n", threads[i].id, GetElapsedTime(start, threads[i].time));
    }

    return 0;
}
