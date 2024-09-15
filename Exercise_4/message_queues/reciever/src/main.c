#include <fcntl.h>
#include <mqueue.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#define QUEUE_NAME "/test_queue"
#define MAX_SIZE 1024
#define MSG_STOP "exit"

int main() {
  mqd_t mq;
  char buffer[MAX_SIZE];
  ssize_t bytes_read;
  long long sum = 0;

  struct mq_attr attr;

  // Initialize the queue attributes
  attr.mq_flags = 0;
  attr.mq_maxmsg = 7;
  attr.mq_msgsize = MAX_SIZE;
  attr.mq_curmsgs = 0;

  // Create the message queue
  mq = mq_open(QUEUE_NAME, O_CREAT | O_RDWR, 0644, &attr);
  if (mq == (mqd_t)-1) {
    perror("mq_open");
    exit(1);
  }

  // Receive messages
  while (1) {
    bytes_read = mq_receive(mq, buffer, MAX_SIZE, NULL);
    // If the message is the stop message, break
    if (strcmp(buffer, MSG_STOP) == 0) {
      break;
    }
    if (bytes_read != -1) {
     buffer[bytes_read] = '\0';
     
      int value = *((int *)buffer); 
        
      sum += value;
    }
  }

  printf("Receiver: Sum of received values = %llu\n", sum);
  // Close and unlink the message queue
  if (mq_close(mq) == -1) {
    perror("mq_close");
    exit(1);
  }

  if (mq_unlink(QUEUE_NAME) == -1) {
    perror("mq_unlink");
    exit(1);
  }

  return 0;
}
