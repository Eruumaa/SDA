#include "queuearr.h"
#include <stdio.h>

// Fungsi inisialisasi Queue pakai Array
void initQueueArr (QueueArr *queue) {
    queue->front = 0;
    queue->rear = -1;
    queue->count = 0;
}

// Fungsi mengecek isi Array
int isEmptyArr(QueueArr *queue) {
    return (queue->count == 0);
}

// Fungsi apakah full pada Array
int isFullArr(QueueArr *queue) {
    return (queue->count == MAX);
}

// Fungsi untuk memasukkan data baru ke Queue
void enqueueArr(QueueArr *queue, int data) {
    if (isFullArr(queue)) {
        printf("Queue penuh\n");
        return;
    }
    // Menggunakan modulo max agar index balik ke 0 jika penuh
    queue->rear = (queue->rear + 1) % MAX;
    queue->data[queue->rear] = data;
    queue->count++;
}

// Fungsi untuk mengeluarkan data dari queue
int dequeueArr(QueueArr *queue) {
    if (isEmptyArr(queue)) {
        return -1;
    }
    int value = queue->data[queue->front];
    // Menggeser front ke elemen berikutnya
    queue->front = (queue->front + 1) % MAX;
    queue->count--;
    return value;
}

// Fungsi untuk melihat data paling depan
int peekArr(QueueArr *queue) {
    if (isEmptyArr(queue)) {
        return -1;
    }
    // Melihat nilai di index front
    return queue->data[queue->front];
}

// Fungsi untuk mencetak isi queue
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