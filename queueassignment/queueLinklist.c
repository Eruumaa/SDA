#include "queueLinklist.h"
#include <stdio.h>
#include <stdlib.h>

// Fungsi inisialisasi Queue menggunakan implementasi Linked list
void initQueueLL (QueueLL *queue) {
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
}

// Fungsi mengecek elemen queue kosong 
int isEmptyLL (QueueLL *queue) {
    return (queue->front == NULL);
}

// Fungsi menambahkan node baru ke bagian belakang queue
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

// Fungsi menghapus node paling depan queue dan mengambil datanya
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

// Fungsi melihat data elemen pada queue
int peekLL (QueueLL *queue) {
    if (isEmptyLL(queue)) {
        return -1;
    }
    return queue->front->data;
}

// Fungsi mencetak seluruh data queue 
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

// Fungsi untuk membersihkan sisa memori di akhir program
void freeQueueLL (QueueLL *queue) {
    while (!isEmptyLL(queue)) {
        dequeueLL(queue);
    }
}


