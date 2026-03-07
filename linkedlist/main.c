#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    int i, pick;
    char huruf;
    char kata[25];
    char buffer[100];
    List LL[26];
    FILE * fp;
    // Looping alamat LL pada initList
    for (i=0; i < 26; i++) {
        initList(&LL[i]);
    }
    // Membaca file 'dbterms.txt'
    fp = fopen ("dbterms.txt", "r");
    if (fp == NULL) {
        printf("File tidak ada!\n");
        return EXIT_FAILURE;
    }
    while (fgets(buffer, sizeof(buffer), fp)) {
        // Membersihkan enter 
        buffer[strcspn(buffer, "\r\n")] = 0;
        // Kondisi untuk memastikan program benar-benar punya karakter di dalamnya
        if (strlen(buffer) > 0) {
            // Menghitung aalamt index 
            int index = tolower(buffer[0]) - 'a';
            // Kondisi untuk menyambungkan node baru ke linked list 
            if (index >= 0 && index < 26) {
                addList(&LL[index], buffer);
            }
        }
    }
    fclose(fp);

    // Menu pilihan program
    printf("Pembacaan isi file teks dan pengelompokkan selesai...\n");
    do {
        printf("\nMenu Pilihan:\n");
        printf("1) Menampilkan kata-kata sesuai huruf pertama yang ditentukan\n");
        printf("2) Menghapus kata tertentu dalam linked list\n");
        printf("3) Selesai\n");
        printf("\nPilihan anda: ");
        
        if (scanf("%d", &pick) != 1) {
            printf("\nInput harus berupa angka!\n");
            while (getchar() != '\n');
            pick = 0;
            continue;
        }
        if (pick == 1) {
            printf("Huruf: ");
            scanf(" %c", &huruf);
            int idx = tolower(huruf) - 'a';
            // Kondisi untuk opsi ke-1 menampilkan list yang ada dari data "dbterms.txt"
            if (idx >= 0 && idx < 26) displayList(&LL[idx], huruf);
        } 
        else if (pick == 2) {
            printf("Kata yang ingin dihapus: ");
            scanf("%s", kata);
            int idx = tolower(kata[0]) - 'a';
            // Kondisi untuk opsi ke-2 men-delete kata yang diinginkan
            if (idx >= 0 && idx < 26) {
                deleteNode(&LL[idx], kata);
            } 
            else {
                printf("Kata '%s' tidak ditemukan\n", kata);
            }
        }
    // Opsi ke-3 keluar dari program
    } while (pick != 3);
    
    // Looping untuk membersihkan program agar tidak terjadi Memory Leak
    for (i = 0; i < 26; i++) {
        freeList(&LL[i]);
    }
    printf("Program selesai\n");
    return EXIT_SUCCESS;
}