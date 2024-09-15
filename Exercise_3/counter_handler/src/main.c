#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Function to send a signal to a process
void send_signal(pid_t pid, int signal) {
    if (kill(pid, signal) == -1) {
        perror("Error sending signal");
    } else {
        printf("Signal %d sent to process with PID %d\n", signal, pid);
    }
}

// Function to check if a process is still running
int is_process_alive(pid_t pid) {
    return kill(pid, 0) == 0;
}

// Display the user interface and handle input
void show_menu(pid_t pids[], int num_pids) {
    int option, target_pid_index;

    while (1) {
        printf("\n--- Counter Handler Menu ---\n");
        printf("Select an action:\n");
        printf("1. Stop a specific counter process\n");
        printf("2. Continue a specific counter process\n");
        printf("3. Change counting direction of a specific counter process\n");
        printf("4. Kill a specific counter process\n");
        printf("5. Exit\n");
        printf("-----------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        if (option == 5) {
            printf("Exiting counter_handler...\n");
            break;
        }

        printf("Available PIDs:\n");
        for (int i = 0; i < num_pids; i++) {
            if (is_process_alive(pids[i])) {
                printf("[%d] PID: %d\n", i, pids[i]);
            }
        }

        printf("Select the process index (0-%d): ", num_pids - 1);
        scanf("%d", &target_pid_index);

        if (target_pid_index < 0 || target_pid_index >= num_pids || !is_process_alive(pids[target_pid_index])) {
            printf("Invalid selection. Try again.\n");
            continue;
        }

        pid_t target_pid = pids[target_pid_index];

        switch (option) {
            case 1:
                // Send SIGSTOP to stop the process
                send_signal(target_pid, SIGSTOP);
                printf("Process with PID %d stopped.\n", target_pid);
                break;

            case 2:
                // Send SIGCONT to continue the process
                send_signal(target_pid, SIGCONT);
                printf("Process with PID %d continued.\n", target_pid);
                break;

            case 3:
                // Send SIGUSR2 to reverse the counting direction
                send_signal(target_pid, SIGUSR2);
                printf("Counting direction changed for process with PID %d.\n", target_pid);
                break;

            case 4:
                // Send SIGKILL to kill the process
                send_signal(target_pid, SIGKILL);
                printf("Process with PID %d killed.\n", target_pid);

                // Check if all processes have been killed
                int alive_count = 0;
                for (int i = 0; i < num_pids; i++) {
                    if (is_process_alive(pids[i])) {
                        alive_count++;
                    }
                }
                if (alive_count == 0) {
                    printf("All infinite_counter processes have been killed. Exiting.\n");
                    return;
                }
                break;

            default:
                printf("Invalid option. Try again.\n");
                break;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 6) {
        fprintf(stderr, "Usage: %s <pid1> [pid2] [pid3] [pid4] [pid5]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Get the PIDs from the command-line arguments
    pid_t pids[5];
    int num_pids = argc - 1;
    for (int i = 0; i < num_pids; i++) {
        pids[i] = atoi(argv[i + 1]);
    }

    // Show the user interface and handle inputs
    show_menu(pids, num_pids);

    return 0;
}
