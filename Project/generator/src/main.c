#include <fcntl.h>  // For O_* constants
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <time.h>
#include <unistd.h>

#define SHM_SIZE 1000001 * sizeof(int)  // Shared memory size

#define SEM_GENERATOR "/generator"
#define SEM_ANALYZER "/analyzer"

/**
 * This program creates a shared memory segment, writes integers to it in a loop, and uses semaphores
 * for synchronization between producer and consumer processes.
 */
int main() {
  key_t key;
  int shmid;
  int* data;

  // Create a unique key for the shared memory
  key = ftok("/tmp", 65);

  sem_t* semaphore_generator = sem_open(SEM_GENERATOR, O_CREAT, 0666, 1);
  sem_t* semaphore_analyzer = sem_open(SEM_ANALYZER, O_CREAT, 0666, 0);

  // Create a shared memory segment
  shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);

  // Attach to the shared memory segment
  data = (int*)shmat(shmid, NULL, 0);

  // Write to shared memory
  double numbers = 0;
  for (int i = 0; i <= 2000; i ++) {
    sem_wait(semaphore_analyzer);  // Wait for consumer to be ready
    data[i] = numbers;
    printf("\rGenerator: Writing %f to shared memory.", numbers);
    fflush(stdout);                // Ensure the output is printed immediately
    numbers += 0.02;                   // Write integer to shared memory
    sem_post(semaphore_generator);  // Signal producer has written
  }
  printf("\n");
  // Close semaphores
  sem_close(semaphore_analyzer); // Close
  sem_close(semaphore_generator); // Close
  sem_unlink(SEM_ANALYZER); // Close memory
  sem_unlink(SEM_GENERATOR); // Close
  // Detach from shared memory
  shmdt(data);

  return 0;
}
