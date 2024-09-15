// reader.c
#include <fcntl.h>  // For O_* constants
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SHM_SIZE 1024 * sizeof(char)  // Shared memory size

#define SEM_PRODUCER "/producer"
#define SEM_CONSUMER "/consumer"

int main() {
  key_t key;
  int shmid;
  char *data;
  int sum = 0;

  // Create a unique key for the shared memory
  key = ftok("/tmp", 65);

  if (key == -1) {
    perror("ftok");
    return 1;
  }

  // sem_unlink(SEM_PRODUCER);
  // sem_unlink(SEM_CONSUMER);

  sem_t *semaphore_producer = sem_open(SEM_PRODUCER, O_CREAT, 0666, 0);
  if (semaphore_producer == SEM_FAILED) {
    perror("error opening producer semaphore");
    exit(EXIT_FAILURE);
  }

  sem_t *semaphore_consumer = sem_open(SEM_CONSUMER, O_CREAT, 0666, 1);
  if (semaphore_consumer == SEM_FAILED) {
    perror("error opening consumer semaphore");
    exit(EXIT_FAILURE);
  }

  // Locate the shared memory segment
  // shmid = shmget(key, SHM_SIZE, 0666);
  shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);
  if (shmid == -1) {
    perror("shmget failed");
    exit(1);
  }

  // map the block into the process adress space
  data = (char *)shmat(shmid, NULL, 0);

  printf("address of the block: %s\n", data);

  if (data == (char *)-1) {
    perror("shmat failed");
    exit(1);
  }

  // Read from shared memory
    sem_unlink(SEM_PRODUCER);
    sem_unlink(SEM_CONSUMER);
  // while (1) {
  //   sem_wait(semaphore_producer);
  //   if (strlen(data) > 0) {
  //     printf("Reader: Reading from shared memory: %s\n", data);
  //     data[0] = 0;
  //   }
  //   sum++;
  //   sem_post(semaphore_consumer);
  // }
  // printf("Total sum: %d", sum);

  //     sem_unlink(SEM_PRODUCER);
  //   sem_unlink(SEM_CONSUMER);
  // sem_close(semaphore_consumer);
  // sem_close(semaphore_producer);

  // // Detach from shared memory
  // shmdt(data);

  // // Optionally, destroy the shared memory segment
  // shmctl(shmid, IPC_RMID, NULL);

  return 0;
}