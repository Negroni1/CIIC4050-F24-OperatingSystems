#include <errno.h>
#include <fcntl.h>
#include <math.h>
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


// This function performs data analysis by computing sine values and storing them in shared memory
int main() {
  key_t key;
  int shmid;
  double* data;

  key = ftok("/tmp", 65);

  // Open semaphores
  sem_t* semaphore_generator = sem_open(SEM_GENERATOR, 0);
  if (semaphore_generator == SEM_FAILED) {
    perror("sem_open failed for generator");
    exit(EXIT_FAILURE);
  }

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

  int pos = 0;
  printf("Starting analyzing\n");
  for (int i = 999; i >= 0; i--) {
    if (sem_wait(semaphore_generator) == -1) {
      perror("sem_wait failed for generator");
      exit(EXIT_FAILURE);
    }

    if (pos < 0 || pos >= 1000) {
      fprintf(stderr, "Index out of bounds: %d\n", pos);
      exit(EXIT_FAILURE);
    }

    data[i + 1000] = sin(data[pos]);  // Compute sine and store in second half
    printf("Analyzer: Computed sine %f\n", data[i + 1000]);
    pos++;

    if (sem_post(semaphore_analyzer) == -1) {
      perror("sem_post failed for analyzer");
      exit(EXIT_FAILURE);
    }
    if (sem_post(semaphore_plot) == -1) {
      perror("sem_post failed for plot");
      exit(EXIT_FAILURE);
    }
  }

  printf("Finished analyzing\n");

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
