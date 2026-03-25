#include <stdio.h>
#include <stdlib.h>
#include "queuearr.h"
#include "queueLinklist.h"

void printerArray () {
    QueueArr printerQueue;
    initQueueArr (&printerQueue);
    int choice, progress;
    int idDocs = 1;

    do {
        printf("\n============= PRINTER QUEUE (ARRAY) =============\n");
        printf("1. Menambah dokumen ke antrian\n");
        printf("2. Mencetak dokumen berikutnya\n");
        printf("3. Menampilkan seluruh antrian\n");
        printf("4. Menampilkan dokumen yang akan dicetak berikutnya\n");
        printf("5. Kembali ke Menu Utama\n");
        printf("Pilih: ");
        scanf("%d", &choice);

        printf("\n");
        
        switch (choice) {
            case 1:
                enqueueArr(&printerQueue, idDocs);
                printf("Dokumen ID %d masuk antrian\n", idDocs);
                idDocs++;
                break;
            case 2:
                if (isEmptyArr(&printerQueue)) {
                    printf("Antrian kosong, tidak ada dokumen\n");
                } else {
                    progress = dequeueArr(&printerQueue);
                    printf("Mencetak dokumen ID %d....\n", progress);
                }
                break;
            case 3:
                displayArr(&printerQueue);
                break;
            case 4:
                if (isEmptyArr(&printerQueue)) {
                    printf("Queue Kosong\n");
                } else {
                    printf("Dokumen selanjutnya: ID %d\n", peekArr(&printerQueue));
                }
                break;
            case 5:
                printf("Keluar\n");
                break;
            default:
                printf("Pilihan tidak ada\n");
        }
    } while (choice != 5);
}

void printerLinkedList () {
    QueueLL printerQueue;
    initQueueLL (&printerQueue);
    int choice, progress;
    int idDocs = 1;

    do {
        printf("\n=========== PRINTER QUEUE (LINKEDLIST) ===========\n");
        printf("1. Menambah dokumen ke antrian\n");
        printf("2. Mencetak dokumen berikutnya\n");
        printf("3. Menampilkan seluruh antrian\n");
        printf("4. Menampilkan dokumen yang akan dicetak berikutnya\n");
        printf("5. Kembali ke Menu Utama\n");
        printf("Pilih: ");
        scanf("%d", &choice);

        printf("\n");
        
        switch (choice) {
            case 1:
                enqueueLL(&printerQueue, idDocs);
                printf("Dokumen ID %d masuk antrian\n", idDocs);
                idDocs++;
                break;
            case 2:
                if (isEmptyLL(&printerQueue)) {
                    printf("Antrian kosong, tidak ada dokumen\n");
                } else {
                    progress = dequeueLL(&printerQueue);
                    printf("Mencetak dokumen ID %d ", progress);
                }
                break;
            case 3:
                displayLL(&printerQueue);
                break;
            case 4:
                if (isEmptyLL(&printerQueue)) {
                    printf("Queue Kosong\n");
                } else {
                    printf("Dokumen selanjutnya: ID %d\n", peekLL(&printerQueue));
                }
                break;
            case 5:
                printf("Keluar\n");
                freeQueueLL(&printerQueue);
                break;
            default:
                printf("Pilihan tidak ada\n");
        }
    } while (choice != 5);
}

int main (void) {
    int implementasi;

    do {
        printf("\n========= IMPLEMENTASI QUEUE PRINTER =========\n");
        printf("1. Implementasi menggunakan Array\n");
        printf("2. Implementasi menggunakan Linked List\n");
        printf("3. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &implementasi);

        printf("\n");
        
        if (implementasi == 1) {
            printerArray();
        } else if (implementasi == 2) {
            printerLinkedList();
        } else if (implementasi != 3) {
            printf("Input tidak ada\n");
        }
    } while (implementasi != 3);

    printf ("Program berakhir");

    return 0;
}