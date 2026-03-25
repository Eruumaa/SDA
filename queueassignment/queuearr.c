#include "queuearr.h"
#include <stdio.h>

void initQueueArr (QueueArr *queue) {
    queue->front = 0;
    queue->rear = -1;
    queue->count = 0;
}

int isFullArr(QueueArr *queue) {
    return (queue->count == MAX);
}

void enqueueArr(QueueArr *queue, int value) {
    if (isFullArr(queue)) {
        printf("Antrian penuh\n");
        return;
    }
    queue->rear = (queue->rear + 1) % MAX;
    queue->data[queue->rear] = value;
    queue->count++;
}
void displayArr(QueueArr *queue);
int isFullArr(QueueArr *queue);
int dequeueArr(QueueArr *queue);
int peekArr(QueueArr *queue);