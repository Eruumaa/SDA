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
    
}

int dequeueLL (QueueLL *queue) {

}

int peekLL (QueueLL *queue) {

}

void displayLL (QueueLL *queue) {

}

void freeQueueLL (QueueLL *queue) {

}


