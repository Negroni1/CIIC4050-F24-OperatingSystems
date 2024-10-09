#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define SIZE 10 * sizeof(double)

void TimerHandler(int signum)
{
    printf("Timer expired\n");
}

int main() {

    timer_t timer_id;
    timer_create(CLOCK_REALTIME, NULL, &timer_id);

    struct sigaction action;

    action.sa_handler = TimerHandler;
    action.sa_flags = 0;
    sigaction(SIGALRM, &action, NULL);

    double time = 0;
    double p_x = 20;
    double p_y = 10;
    double v_x = 0;
    double v_y = 0; 
    double acc_x = 0.15;
    double acc_y = 0.16;

    // Create file imu_data.txt
    FILE *fp;
    fp = fopen("imu_data.txt", "w");

    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    fprintf(fp, "Time, p_x, p_y, v_x, v_y, acc_x, acc_y\n");
    char s_time[SIZE];
    char s_p_x[SIZE];
    char s_p_y[SIZE];
    char s_v_x[SIZE];
    char s_v_y[SIZE];
    char s_acc_x[SIZE];
    char s_acc_y[SIZE];
    // TODO: Add Timer 200s

    while (1){
        printf("\rTime: %.2f", time);
        fflush(stdout);
        if (time > 200) {
            time = 0;
            // printf("\nWriting data...\n");
            snprintf(s_time, SIZE, "%.2f", time);
            snprintf(s_p_x, SIZE, "%.4f", p_x);
            snprintf(s_p_y, SIZE, "%.4f", p_y);
            snprintf(s_v_x, SIZE, "%.4f", v_x);
            snprintf(s_v_y, SIZE, "%.4f", v_y);
            snprintf(s_acc_x, SIZE, "%.4f", acc_x);
            snprintf(s_acc_y, SIZE, "%.4f", acc_y);
            fprintf(fp, "%s, %s, %s, %s, %s, %s, %s\n", s_time, s_p_x, s_p_y, s_v_x, s_v_y, s_acc_x, s_acc_y);
        }
        // TODO: Verify actual math 
        // Update X Velocity
        v_x = v_x + acc_x * time;

        // Update X Position
        p_x = p_x + v_x * time;

        // Update Y Velocity
        v_y = v_y + acc_y * time;

        // Update Y Position
        p_y = p_y + v_y * time;

        time += 0.01; // Update time
        // sleep();
    }

    // Close the file
    fclose(fp);

    printf("Data written to imu_data.txt\n");
    return 0;
}