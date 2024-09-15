#include <fcntl.h> // For O_* constants
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define SHM_SIZE                                                               \
  1000000 * sizeof(int) // Shared memory size for 1 million integers

#define SEM_PRODUCER "/producer"
#define SEM_CONSUMER "/consumer"

int main() {
  key_t key;
  int shmid;
  int *data;
  long long sum = 0; // Use long long to avoid integer overflow

  // Create a unique key for the shared memory
  key = ftok("/tmp", 65);

  // Open the semaphores
  sem_t *semaphore_producer = sem_open(SEM_PRODUCER, 0);
  sem_t *semaphore_consumer = sem_open(SEM_CONSUMER, 0);

  // Locate the shared memory segment
  shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);

  // Attach the shared memory segment to the process address space
  data = (int *)shmat(shmid, NULL, 0);

  // Read and sum up from shared memory
  for (int i = 0; i <= 1000000; i++) {
    sem_wait(semaphore_producer); // Wait for the producer to write data
    sum += data[i];               // Sum up the value
    sem_post(
        semaphore_consumer); // Signal the consumer is ready for the next value
  }

  printf("Reader: Sum of all values in shared memory = %lld\n", sum);

  // Close the semaphores
  sem_close(semaphore_consumer);
  sem_close(semaphore_producer);

  // Detach from shared memory
  shmdt(data);

  // Optionally, destroy the shared memory segment if done
  shmctl(shmid, IPC_RMID, NULL);

  return 0;
}
