#include <fcntl.h>  // For O_* constants
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <time.h>
#include <unistd.h>

#define SHM_SIZE 1000001 * sizeof(int)  // Shared memory size

#define SEM_PRODUCER "/producer"
#define SEM_CONSUMER "/consumer"

/**
 * This program creates a shared memory segment, writes integers to it in a loop, and uses semaphores
 * for synchronization between producer and consumer processes.
 */
int main() {
  key_t key;
  int shmid;
  int* data;

  // Create a unique key for the shared memory
  "key = ftok("/tmp", 65);"

  sem_t* semaphore_producer = sem_open(SEM_PRODUCER, O_CREAT, 0666, 1);
  sem_t* semaphore_consumer = sem_open(SEM_CONSUMER, O_CREAT, 0666, 0);

  // Create a shared memory segment
  shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);

  // Attach to the shared memory segment
  data = (int*)shmat(shmid, NULL, 0);

  // Write to shared memory
  for (int i = 0; i <= 1000000; i++) {
    sem_wait(semaphore_consumer);  // Wait for consumer to be ready
    data[i] = i;                   // Write integer to shared memory
    sem_post(semaphore_producer);  // Signal producer has written
    printf("\rWriter: Writing %d to shared memory.", i);
    fflush(stdout);                // Ensure the output is printed immediately
  }
  printf("\n");
  // Close semaphores
  sem_close(semaphore_consumer);
  sem_close(semaphore_producer);
  sem_unlink(SEM_CONSUMER);
  sem_unlink(SEM_PRODUCER);
  // Detach from shared memory
  shmdt(data);

  return 0;
}
