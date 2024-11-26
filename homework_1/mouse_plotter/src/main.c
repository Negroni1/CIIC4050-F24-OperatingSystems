#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>

FILE *file;
int x, y;
int reading = 1;

void Handler(int param) {
	if (fread(&x, sizeof(int), 1, file) == 1 && fread(&y, sizeof(int), 1, file) == 1) {
		clear();
		//mvaddch(y, x, "*");
		mvprintw(y, x, "*");
		refresh();
	} else {
		reading = 0;
	}
}

int main() {
	// Setup file
	file = fopen("mouse_data.dat", "rb");
	if (file == -1) {
		perror("Error opening file\n");
		return -1;
	}
	
	// Setup ncurses
	initscr();
	noecho();
	curs_set(0);
	
	// Setup timer
	timer_t timer_id;
	timer_create(CLOCK_REALTIME, NULL, &timer_id);
	struct sigaction action;
	action.sa_handler = Handler;
	action.sa_flags = 0;
	sigaction(SIGALRM, &action, NULL);
	struct itimerspec timer_params;
	timer_params.it_value.tv_sec = 0;
	timer_params.it_value.tv_nsec = 10 * 1000000;
	timer_params.it_interval.tv_sec = 0;
	timer_params.it_interval.tv_nsec = 10 * 1000000;
	timer_settime(timer_id, 0, &timer_params, NULL);


	while (reading) {
		pause();
	}

	fclose(file);
	endwin();
	return 0;
}
