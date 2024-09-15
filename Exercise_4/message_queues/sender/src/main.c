#include <fcntl.h>
#include <mqueue.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#define QUEUE_NAME "/test_queue"
#define MAX_SIZE 1024
#define MSG_STOP "exit"

int main() {
  mqd_t mq;
  struct mq_attr attr;
  char buffer[MAX_SIZE];

  // Initialize the queue attributes
  attr.mq_flags = 0;
  attr.mq_maxmsg = 1000000;
  attr.mq_msgsize = MAX_SIZE;
  attr.mq_curmsgs = 0;

  // Create the message queue
  mq = mq_open(QUEUE_NAME, O_CREAT | O_WRONLY | O_NONBLOCK, 0644, &attr);
  if (mq == (mqd_t)-1) {
    perror("mq_open");
    exit(1);
  }

  // Send 1000000 messages
  for (int i = 1; i <= 1000000; ++i) {
    snprintf(buffer, MAX_SIZE, "%d", i);

    while (mq_send(mq, (const char*)&i, sizeof(int), 0) == -1)
      ;
    printf("\rSender: %s", buffer);
    fflush(stdout);  // Ensure the output is printed immediately
  }
  printf("\n");

  // Send a stop message to the receiver
  if (mq_send(mq, MSG_STOP, strlen(MSG_STOP) + 1, 0) == -1) {
    perror("mq_send");
    exit(1);
  }

  // Close the message queue
  if (mq_close(mq) == -1) {
    perror("mq_close");
    exit(1);
  }

  return 0;
}