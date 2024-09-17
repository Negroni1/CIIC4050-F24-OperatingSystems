#include <fcntl.h>  // For O_* constants
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <time.h>
#include <unistd.h>

#define SHM_SIZE 1000001 * sizeof(int)  // Shared memory size

#define SEM_ANALYZER "/plot"
#define SEM_PLOT "/analyzer-plot"

/**
 * The program reads and sums up values from a shared memory segment using semaphores
 */
int main() {
  key_t key;
  int shmid;
  int* data;
  long long sum = 0;

  time_t start_time, finish_time;

  // Create a unique key for the shared memory
  key = ftok("/tmp", 65);

  sem_t* semaphore_analyzer = sem_open(SEM_ANALYZER, O_CREAT, 0666, 0);
  sem_t* semaphore_plot = sem_open(SEM_PLOT, O_CREAT, 0666, 1);

  // Locate the shared memory segment
  shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);

  // Map the block into the process address space
  data = (int*)shmat(shmid, NULL, 0);

  FILE *gnuplotPipe = popen("gnuplot -persistent", "w");
  // Gnuplot configuration
    fprintf(gnuplotPipe, "set title 'Real-Time Data Plot'\n");
    fprintf(gnuplotPipe, "set xlabel 'Index'\n");
    fprintf(gnuplotPipe, "set ylabel 'Value'\n");
    fprintf(gnuplotPipe, "plot '-' with lines\n");
  // Read and sum up from shared memory
  for (int i = 0; i <= 1000000; i++) {
    sem_wait(semaphore_analyzer);  // Wait for the producer to write data
    
    fprintf(gnuplotPipe, "%d %d\n", i, data[i]);  // Send index and data value
    fflush(gnuplotPipe);  // Flush to ensure real-time plotting             // Sum up the value
    usleep(1000);  // 1 millisecond delay

    sem_post(semaphore_plot);
    
  }
  time(&finish_time);

  // Close the semaphores
  sem_close(semaphore_analyzer);
  sem_close(semaphore_plot);
  sem_unlink(SEM_PLOT);
  sem_unlink(SEM_ANALYZER);

  // Detach from shared memory
  shmdt(data);

  // Optionally, destroy the shared memory segment if done
  shmctl(shmid, IPC_RMID, NULL);

  return 0;
}
