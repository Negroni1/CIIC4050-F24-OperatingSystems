#include "functions.h"

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Display the user interface and handle input
void show_menu(pid_t pids[], int num_pids) {
  int option, target_pid_index;

  while (1) {
    if (num_pids - 1 < 0) {
      printf(
          "No infinite-counter processes alive\nExiting counter_handler...\n");
      break;
    }
    printf("\n--- Counter Handler Menu ---\n");
    printf("Select an action:\n");
    printf("1. Stop a specific counter process\n");
    printf("2. Continue a specific counter process\n");
    printf("3. Change counting direction of a specific counter process\n");
    printf("4. Reset Counter\n");
    printf("5. Kill a specific counter process\n");
    printf("6. Exit\n");
    printf("-----------------------------\n");
    printf("Enter your choice: ");
    scanf("%d", &option);

    if (option == 6) {
      printf("Exiting counter_handler...\n");
      break;
    }

    printf("Available PIDs:\n");
    for (int i = 0; i < num_pids; i++) {
      if (kill(pids[i], 0) == 0) {
        printf("[%d] PID: %d\n", i, pids[i]);
      }
    }

    printf("Select the process index (0-%d): ", num_pids - 1);
    scanf("%d", &target_pid_index);

    pid_t target_pid = pids[target_pid_index];

    switch (option) {
      case 1:
        // Send SIGSTOP to stop the process
        kill(target_pid, SIGSTOP);
        printf("Process with PID %d stopped.\n", target_pid);
        break;

      case 2:
        // Send SIGCONT to continue the process
        kill(target_pid, SIGCONT);
        printf("Process with PID %d continued.\n", target_pid);
        break;

      case 3:
        // Send SIGUSR2 to reverse the counting direction
        kill(target_pid, SIGUSR2);
        printf("Counting direction changed for process with PID %d.\n",
               target_pid);
        break;

      case 4:
        // Send SIGUSR2 to reverse the counting direction
        kill(target_pid, SIGUSR1);
        printf("Reset counter for process with PID %d.\n", target_pid);
        break;

      case 5:
        // Send SIGKILL to kill the process
        kill(target_pid, SIGKILL);
        printf("Process with PID %d killed.\n", target_pid);
        num_pids--;
        break;
    }
  }
}