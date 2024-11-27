// writer.c
#include <fcntl.h>  // For O_* constants
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024 * sizeof(char)  // Shared memory size

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
  printf("Writer: Writing to shared memory: ");
  strcpy(data, argv[1]);
  printf("%s", data);
  printf("\n");


  // Detach from shared memory
  shmdt(data);

  return 0;
}
