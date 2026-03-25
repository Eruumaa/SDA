#include "queuearr.h"
#include <stdio.h>

void initQueueArr (QueueArr *queue) {
    queue->front = 0;
    queue->rear = -1;
    queue->count = 0;
}

int isEmptyArr(QueueArr *queue) {
    return (queue->count == 0);
}

int isFullArr(QueueArr *queue) {
    return (queue->count == MAX);
}

void enqueueArr(QueueArr *queue, int value) {
    if (isFullArr(queue)) {
        printf("Queue penuh\n");
        return;
    }
    queue->rear = (queue->rear + 1) % MAX;
    queue->data[queue->rear] = value;
    queue->count++;
}

int dequeueArr(QueueArr *queue) {
    if (isEmptyArr(queue)) {
        return -1;
    }
    int value = queue->data[queue->front];
    queue->front = (queue->front + 1) % MAX;
    queue->count--;
    return value;
}

int peekArr(QueueArr *queue) {
    if (isEmptyArr(queue)) {
        return -1;
    }
    return queue->data[queue->front];
}

void displayArr(QueueArr *queue) {
    if (isEmptyArr(queue)) {
        printf("Queue Kosong\n");
        return;
    }
    printf("Isi Queue: ");
    int i, index = queue->front;
    for (i = 0; i < queue->count; i++) {
        printf("[%d] ", queue->data[index]);
        index = (index + 1) % MAX;
    }
    printf("\n");
}