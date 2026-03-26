#include <stdio.h>
#include <stdlib.h>
#include "queuearr.h"
#include "queueLinklist.h"

void bankArray () {
    QueueArr jalur1, jalur2;
    initQueueArr(&jalur1);
    initQueueArr(&jalur2);

    int choice, progress, way;
    int idNasabah = 1;

    do {
        printf("\n================ ANTRIAN BANK (ARRAY) ================\n");
        printf("1. Menambah nasabah ke jalur antrian terpendek\n");
        printf("2. Melayani nasabah berikutnya\n");
        printf("3. Menampilkan seluruh antrian nasabah\n");
        printf("4. Menampilkan jumlah nasabah yang menunggu\n");
        printf("5. Menampilkan ID Nasabah yang akan diproses\n");
        printf("6. Kembali ke Menu Utama\n");
        printf("Pilih: ");
        scanf("%d", &choice);

        printf("\n");

        switch (choice) {
        case 1:
            if (jalur1.count <= jalur2.count) {
                enqueueArr(&jalur1, idNasabah);
                printf("Nasabah ID %d masuk ke Jalur 1\n", idNasabah);
            } else {
                enqueueArr(&jalur2, idNasabah);
                printf("Nasabah ID %d masuk ke Jalur 2\n", idNasabah);
            }
            idNasabah++;
            break;
        case 2:
            printf("Pilih jalur yang akan dilayani: ");
            scanf("%d", &way);

            if (way == 1) {
                if (isEmptyArr(&jalur1)) {
                    printf("Jalur 1 kosong\n");
                } else {
                    progress = dequeueArr(&jalur1);
                    printf("Melayani Nasabah ID %d di Jalur 1\n", progress);
                }
            } else if (way == 2) {
                if (isEmptyArr(&jalur2)) {
                    printf("Jalur 2 Kosong\n");
                } else {
                    progress = dequeueArr(&jalur2);
                    printf("Melayani Nasabah ID %d di jalur 2\n", progress);
                }
            } else {
                printf("Jalur tidak ada\n");
            }
            break;

        case 3:
            printf("Jalur 1 - ");
            displayArr(&jalur1);
            printf("Jalur 2 - ");
            displayArr(&jalur2);
            break;
        case 4:
            printf("Jumlah menunggu di Jalur 1: %d orang\n", jalur1.count);
            printf("Jumlah menunggu di Jalur 2: %d orang\n", jalur2.count);
            break;
        case 5:
            printf("Nasabah berikutnya di jalur 1: ");
            if (isEmptyArr(&jalur1)) printf("kosong\n");
            else printf("ID %d\n", peekArr(&jalur1));

            printf("Nasabah berikutnya di jalur 2: ");
            if (isEmptyArr(&jalur2)) printf("kosong\n");
            else printf("ID %d\n", peekArr(&jalur2));
            break;
        case 6:
            printf("Keluar\n");
            break;
        default:
            printf("Pilihan tidak ada\n");
        }
    } while (choice != 6);
}

void bankLinkedList () {
    QueueLL jalur1, jalur2;
    initQueueLL(&jalur1);
    initQueueLL(&jalur2);

    int choice, progress, way;
    int idNasabah = 101;

    do {
        printf("\n================ ANTRIAN BANK (LINKED LIST) ================\n");
        printf("1. Menambah nasabah ke jalur antrian terpendek\n");
        printf("2. Melayani nasabah berikutnya\n");
        printf("3. Menampilkan seluruh antrian nasabah\n");
        printf("4. Menampilkan jumlah nasabah yang menunggu\n");
        printf("5. Menampilkan ID Nasabah yang akan diproses\n");
        printf("6. Kembali ke Menu Utama\n");
        printf("Pilih: ");
        scanf("%d", &choice);

        printf("\n");

        switch (choice) {
        case 1:
            if (jalur1.size <= jalur2.size) {
                enqueueLL(&jalur1, idNasabah);
                printf("Nasabah ID %d masuk ke Jalur 1\n", idNasabah);
            } else {
                enqueueLL(&jalur2, idNasabah);
                printf("Nasabah ID %d masuk ke Jalur 2\n", idNasabah);
            }
            idNasabah++;
            break;
        case 2:
            printf("Pilih jalur yang akan dilayani: ");
            scanf("%d", &way);

            if (way == 1) {
                if (isEmptyLL(&jalur1)) {
                    printf("Jalur 1 kosong\n");
                } else {
                    progress = dequeueLL(&jalur1);
                    printf("Melayani Nasabah ID %d di Jalur 1\n", progress);
                }
            } else if (way == 2) {
                if (isEmptyLL(&jalur2)) {
                    printf("Jalur 2 Kosong\n");
                } else {
                    progress = dequeueLL(&jalur2);
                    printf("Melayani Nasabah ID %d di jalur 2\n", progress);
                }
            } else {
                printf("Jalur tidak ada\n");
            }
            break;

        case 3:
            printf("Jalur 1 - ");
            displayLL(&jalur1);
            printf("Jalur 2 - ");
            displayLL(&jalur2);
            break;
        case 4:
            printf("Jumlah menunggu di Jalur 1: %d orang\n", jalur1.size);
            printf("Jumlah menunggu di Jalur 2: %d orang\n", jalur2.size);
            break;
        case 5:
            printf("Nasabah berikutnya di jalur 1: ");
            if (isEmptyLL(&jalur1)) printf("kosong\n");
            else printf("ID %d\n", peekLL(&jalur1));

            printf("Nasabah berikutnya di jalur 2: ");
            if (isEmptyLL(&jalur2)) printf("kosong\n");
            else printf("ID %d\n", peekLL(&jalur2));
            break;
        case 6:
            printf("Keluar\n");
            break;
        default:
            printf("Pilihan tidak ada\n");
        }
    } while (choice != 6);
}

int main(void) {
    int implementasi;

    do {
        printf("\n========= IMPLEMENTASI QUEUE BANK =========\n");
        printf("1. Implementasi menggunakan Array\n");
        printf("2. Implementasi menggunakan Linked List\n");
        printf("3. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &implementasi);

        printf("\n");

        if (implementasi == 1) {
            bankArray();
        } else if (implementasi == 2) {
            bankLinkedList();
        } else if (implementasi != 3) {
            printf("Input tidak ada\n");
        }
    } while (implementasi != 3);

    printf("Program berakhir\n");

    return 0;
}