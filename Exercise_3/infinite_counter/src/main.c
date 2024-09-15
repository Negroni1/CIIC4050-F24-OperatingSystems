#include <stdio.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int counter_value = 0;
int direction = 1;

/**
 * The reset_handler function sets the counter_value variable to 0.
 */
void reset_handler() {
    counter_value = 0;
}

/**
 * The function reverse_handler changes the direction variable to its opposite value.
 */
void reverse_handler() {
    direction *= -1;
}

int main() {

    // Set up signal handler for the `SIGUSR1` signal
    struct sigaction sa;
    sa.sa_handler = reset_handler;
    sigaction(SIGUSR1, &sa, NULL);

    // Set up signal handler for the `SIGUSR2` signal
    struct sigaction sa2;
    sa2.sa_handler = reverse_handler;
    sigaction(SIGUSR2, &sa2, NULL);
    
    while (1) {
        printf("I'm counting, and my count is %d my id is %d\n", counter_value, getpid());
        sleep(1);
        counter_value += direction;
    }

    return 0;
}