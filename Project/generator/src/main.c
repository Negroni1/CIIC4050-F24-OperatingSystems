#include <errno.h>
#include <fcntl.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define SHM_SIZE (2000 * sizeof(double))  // Shared memory size
#define SEM_GENERATOR "/generator"
#define SEM_ANALYZER "/analyzer"
#define SEM_PLOT "/plot"

// Initialize shared memory and semaphores, writes data to shared memory, and
// coordinates with other processes using semaphores
int main() {
  key_t key;
  int shmid;
  double* data;
  key = ftok("/tmp", 65);

  // Create or open semaphores
  sem_t* semaphore_generator =
      sem_open(SEM_GENERATOR, O_CREAT | O_EXCL, 0666, 0);
  if (semaphore_generator == SEM_FAILED) {
    if (errno == EEXIST) {
      semaphore_generator = sem_open(SEM_GENERATOR, 0);
      if (semaphore_generator == SEM_FAILED) {
        perror("sem_open failed for generator");
        exit(EXIT_FAILURE);
      }
    } else {
      perror("sem_open failed for generator");
      exit(EXIT_FAILURE);
    }
  }

  sem_t* semaphore_analyzer = sem_open(SEM_ANALYZER, O_CREAT | O_EXCL, 0666, 0);
  if (semaphore_analyzer == SEM_FAILED) {
    if (errno == EEXIST) {
      semaphore_analyzer = sem_open(SEM_ANALYZER, 0);
      if (semaphore_analyzer == SEM_FAILED) {
        perror("sem_open failed for analyzer");
        exit(EXIT_FAILURE);
      }
    } else {
      perror("sem_open failed for analyzer");
      exit(EXIT_FAILURE);
    }
  }

  sem_t* semaphore_plot = sem_open(SEM_PLOT, O_CREAT | O_EXCL, 0666, 0);
  if (semaphore_plot == SEM_FAILED) {
    if (errno == EEXIST) {
      semaphore_plot = sem_open(SEM_PLOT, 0);
      if (semaphore_plot == SEM_FAILED) {
        perror("sem_open failed for plot");
        exit(EXIT_FAILURE);
      }
    } else {
      perror("sem_open failed for plot");
      exit(EXIT_FAILURE);
    }
  }

  shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);
  if (shmid == -1) {
    perror("shmget failed");
    exit(EXIT_FAILURE);
  }

  data = (double*)shmat(shmid, NULL, 0);
  if (data == (void*)-1) {
    perror("shmat failed");
    exit(EXIT_FAILURE);
  }

  double number = 0.0;
  printf("Starting generator\n");
  for (int i = 0; i < 1000; i++) {
    data[i] = number;
    number += 0.02;
    printf("Generator: Writing %.2f to shared memory.\n", data[i]);

    if (sem_post(semaphore_generator) == -1) {
      perror("sem_post failed for generator");
      exit(EXIT_FAILURE);
    }

    // Wait for analyzer to be ready
    if (sem_wait(semaphore_analyzer) == -1) {
      perror("sem_wait failed for analyzer");
      exit(EXIT_FAILURE);
    }
  }

  printf("Generator finished\n");

  if (sem_close(semaphore_generator) == -1) {
    perror("sem_close failed for generator");
    exit(EXIT_FAILURE);
  }
  if (sem_close(semaphore_analyzer) == -1) {
    perror("sem_close failed for analyzer");
    exit(EXIT_FAILURE);
  }
  if (sem_close(semaphore_plot) == -1) {
    perror("sem_close failed for plot");
    exit(EXIT_FAILURE);
  }

  if (shmdt(data) == -1) {
    perror("shmdt failed");
    exit(EXIT_FAILURE);
  }

  return 0;
}
