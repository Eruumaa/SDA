#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fungsi initList yang membuat list baru
void initList(List * lptr) {
    // Mereset head dan size untuk menetapkan titik awal 
    lptr->head = NULL;
    lptr->size = 0;
}

// Fungsi addList yang memasukkan kata baru ke dalam linked list
int addList(List * lptr, char *kataBaru) {
    NodePtr new;
    // Membuat wadah node untuk di isi pointer ke kata dan ke node selanjutnya
    new = malloc(sizeof(Node));
    if (new == NULL) {
        printf("Error dalam membuat alokasi memori\n");
        return 0;
    }
    // Membuat ruang memori untuk menyimpan kata
    new->kata = malloc(strlen(kataBaru)+ 1);
    if (new->kata == NULL) {
        // Mengalokasi memori untuk mencegah Memory Leak
        free(new);
        return 0;
    }
    // Menyalin data yang sudah ada di 'kataBaru' ke dalam 'new->kata'
    strcpy(new->kata, kataBaru);
    // Menghubungkan node sehingga head berpindah ke node baru
    new->next = lptr->head;
    lptr->head = new;
    // Menghitung otomatis jumlah elemen yang ada dalam linked list
    lptr->size++;
    return 1;
}

// Fungsi displayList untuk mencetak semua kata yang tersimpan dalam linked list
void displayList(List * lptr, char huruf) {
    int count = 0;
    NodePtr current = lptr->head;
    // Kondisi untuk pengecekan jika ada list yang kosong
    if (current == NULL) {
        printf("Kata dengan huruf awal %c tidak ditemukan\n", huruf);
        return;
    }
    printf("\n");
    while (current != NULL && count < 25) {
        printf("%s -> ", current->kata);
        // Perintah untuk memindahkan penunjuk  ke alamat node selanjutnya
        current = current->next;
        count++;
    }
    printf("null\n");
}

// Fungsi freeList yang berguna untuk membersihkan memori
void freeList(List * lptr) {
    NodePtr next=lptr->head;
    NodePtr current=next;
    while (current != NULL) {
        next = current->next;
        // Penghapusan pertama yaitu menghapus isi dalam node
        free(current->kata);
        // Penghapusan kedua yaitu menghapus node
        free(current);
        // Pindah ke node selanjutnya
        current = next;
    }
    // Mereset metadata pada list
    lptr->head = NULL;
    lptr->size = 0;
}

// Fungsi deleteNode untuk melepas node dan menyambungkan kembali ke sisa node lainnya
int deleteNode(List * lptr, char *target) {
    // Kondisi untuk mengecek jika ada list yang kosong
    if (lptr->head == NULL) {
        printf("Kata '%s' tidak ditemukan\n", target);
        return 0;
    }
    NodePtr current = lptr->head;
    NodePtr previous = NULL;

    // Looping untuk mencari dalam list selama belum sampai NULL
    while (current != NULL) {
        // Kondisi untuk mencocokkan kata di node
        if (strcmp(current->kata, target) == 0) {
            // Kondisi untuk menghapus node pertama jika kata yang dihapus di posisi paling depan
            if (previous == NULL) {
                lptr->head = current->next;
            }
            // Kondisi untuk menghapus node di tengah atau paling belakang
            else {
                previous->next = current->next;
            }
            // Dilakukannya memory cleanup agar tidak terjadi memory leak
            free(current->kata); 
            free(current); 
            // Karena satu kata sudah terbuang, jumlah total kata dalam list dikurang satu
            lptr->size--;
            printf("Kata '%s' berhasil dihapus\n", target);
            return 1;
        }
        // Menggeser kedua pointer maju satu langkah untuk memeriksa node selanjutnya
        previous = current;
        current = current->next;
    }
    printf("Kata '%s' tidak ditemukan\n", target);
    return 0;
}