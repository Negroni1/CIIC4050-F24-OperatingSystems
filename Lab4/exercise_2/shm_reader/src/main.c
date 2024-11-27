// reader.c
#include <fcntl.h>  // For O_* constants
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024 * sizeof(char)  // Shared memory size

int main() {
  key_t key;
  int shmid;
  char *data;

  // Create a unique key for the shared memory
  key = ftok("/tmp", 65);

  if (key == -1) {
    perror("ftok");
    return 1;
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

  printf("address of the block: %x\n", data);

  if (data == (char *)-1) {
    perror("shmat failed");
    exit(1);
  }

  // Read from shared memory

  while (1) {
    if (strlen(data) > 0) {
      printf("Reader: Reading from shared memory: %s\n", data);
      data[0] = 0;
    }
  }


  // Detach from shared memory
  shmdt(data);

  // Optionally, destroy the shared memory segment
  shmctl(shmid, IPC_RMID, NULL);

  return 0;
}
