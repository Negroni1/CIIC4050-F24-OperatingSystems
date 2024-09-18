#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define SHM_SIZE (2000 * sizeof(double))  // Shared memory size
#define SEM_GENERATOR "/generator"
#define SEM_ANALYZER "/analyzer"
#define SEM_PLOT "/plot"

int main() {
    key_t key;
    int shmid;
    double* data;

    key = ftok("/tmp", 65);

    // Open semaphores
    sem_t* semaphore_analyzer = sem_open(SEM_ANALYZER, 0);
    if (semaphore_analyzer == SEM_FAILED) {
        perror("sem_open failed for analyzer");
        exit(EXIT_FAILURE);
    }

    sem_t* semaphore_plot = sem_open(SEM_PLOT, 0);
    if (semaphore_plot == SEM_FAILED) {
        perror("sem_open failed for plot");
        exit(EXIT_FAILURE);
    }

    shmid = shmget(key, SHM_SIZE, 0666);
    if (shmid == -1) {
        perror("shmget failed");
        exit(EXIT_FAILURE);
    }

    data = (double*)shmat(shmid, NULL, 0);
    if (data == (void*)-1) {
        perror("shmat failed");
        exit(EXIT_FAILURE);
    }

    printf("Starting plot\n");
    for (int i = 0; i < 1000; i++) {
        // Wait for analyzer to process data
        if (sem_wait(semaphore_plot) == -1) {
            perror("sem_wait failed for plot");
            exit(EXIT_FAILURE);
        }

        // Print the data
        printf("Number: %f - Sin: %f\n", data[i], data[i + 1000]);

        // Optional: Signal generator if needed
        // if (sem_post(semaphore_generator) == -1) {
        //     perror("sem_post failed for generator");
        //     exit(EXIT_FAILURE);
        // }
    }
    printf("Finished plot\n");

    // Close semaphores
    if (sem_close(semaphore_analyzer) == -1) {
        perror("sem_close failed for analyzer");
        exit(EXIT_FAILURE);
    }
    if (sem_close(semaphore_plot) == -1) {
        perror("sem_close failed for plot");
        exit(EXIT_FAILURE);
    }

    // Unlink semaphores (uncomment if you want to remove semaphores)
    // if (sem_unlink(SEM_GENERATOR) == -1) {
    //     perror("sem_unlink failed for generator");
    // }
    // if (sem_unlink(SEM_ANALYZER) == -1) {
    //     perror("sem_unlink failed for analyzer");
    // }
    if (sem_unlink(SEM_PLOT) == -1) {
        perror("sem_unlink failed for plot");
    }

    // Detach shared memory
    if (shmdt(data) == -1) {
        perror("shmdt failed");
        exit(EXIT_FAILURE);
    }

    return 0;
}

