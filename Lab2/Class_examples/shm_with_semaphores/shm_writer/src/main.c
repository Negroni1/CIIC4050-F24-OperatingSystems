// writer.c
#include <fcntl.h>  // For O_* constants
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
 
#define SHM_SIZE 1024 * sizeof(char)  // Shared memory size

#define SEM_PRODUCER "/producer"
#define SEM_CONSUMER "/consumer"

int main(int argc, char *argv[]) {
  key_t key;
  int shmid;
  char *data;

  if (argc < 2) {
    printf("Error: no message found\n");
    exit(EXIT_FAILURE);
  }

  // Create a unique key for the shared memory
  key = ftok("/tmp", 65);

  if (key == -1) {
    perror("ftok");
    exit(EXIT_FAILURE);
  }

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

  // Create a shared memory segment
  shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);
  if (shmid == -1) {
    perror("shmget failed");
    exit(EXIT_FAILURE);
  }

  // Attach to the shared memory segment
  data = (char *)shmat(shmid, NULL, 0);
  if (data == (char *)-1) {
    perror("shmat failed");
    exit(EXIT_FAILURE);
  }
  // Write to shared memory
  for (int i = 0; i < 10; i++) {
    sem_wait(semaphore_consumer);
    printf("Writer: Writing to shared memory: ");
    strcpy(data, argv[1]);
    printf("%s", data);
    printf("\n");
    sem_post(semaphore_producer);
  }
   
  sem_close(semaphore_consumer);
  sem_close(semaphore_producer);

  // Detach from shared memory
  shmdt(data);

  return 0;
}