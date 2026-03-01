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

//
void displayList(List * lptr, char huruf) {
    int count = 0;
    NodePtr current = lptr->head;
    
    if (current == NULL) {
        printf("Kata dengan huruf awal %c tidak ditemukan\n", huruf);
        return;
    }
    printf("\n");
    while (current != NULL && count < 25) {
        printf("%s -> ", current->kata);
        current = current->next;
        count++;
    }
    printf("null\n");
}

// 
void freeList(List * lptr) {
    NodePtr next=lptr->head;
    NodePtr current=next;
    while (current != NULL) {
        next = current->next;
        free(current->kata);
        free(current);
        current = next;
    }
    // Mereset metadata list
    lptr->head = NULL;
    lptr->size = 0;
}

// 
int deleteNode(List * lptr, char *target) {
    if (lptr->head == NULL) {
        printf("Kata '%s' tidak ditemukan\n", target);
        return 0;
    }
    NodePtr current = lptr->head;
    NodePtr previous = NULL;

    while (current != NULL) {
        if (strcmp(current->kata, target) == 0) {
            if (previous == NULL) {
                lptr->head = current->next;
            }
            else {
                previous->next = current->next;
            }
            free(current->kata);
            free(current);

            lptr->size--;
            printf("Kata '%s' berhasil dihapus\n", target);
            return 1;
        }
        previous = current;
        current = current->next;
    }
    printf("Kata '%s' tidak ditemukan\n", target);
    return 0;
}