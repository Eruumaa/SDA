#include "queueLinklist.h"
#include <stdio.h>
#include <stdlib.h>

void initQueueLL (QueueLL *queue) {
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
}

int isEmptyLL (QueueLL *queue) {
    return (queue->front == NULL);
}

void enqueueLL (QueueLL *queue, int data) {
    QueueNodePtr newNode = (QueueNodePtr)malloc(sizeof(QueueNode));

    if (newNode == NULL) {
        printf ("Gagal melakukan alokasi memori\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    
    if (isEmptyLL(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    queue->size++;
}

int dequeueLL (QueueLL *queue) {
    if (isEmptyLL(queue)) {
        return -1;
    }
    QueueNodePtr temp = queue->front;
    int dequeueData = temp->data;

    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    queue->size--;

    return dequeueData;
}

int peekLL (QueueLL *queue) {
    if (isEmptyLL(queue)) {
        return -1;
    }
    return queue->front->data;
}

void displayLL (QueueLL *queue) {
    if (isEmptyLL(queue)) {
        printf("Queue Kosong\n");
        return;
    }

    QueueNodePtr current = queue->front;
    printf("Isi queue: ");
    while (current != NULL) {
        printf("[%d] ", current->data);
        current = current->next;
    }
    printf("\n");
}

void freeQueueLL (QueueLL *queue) {
    while (!isEmptyLL(queue)) {
        dequeueLL(queue);
    }
}


