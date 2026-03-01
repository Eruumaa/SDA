#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    int i, pick;
    char huruf;
    char kata[25];
    char buffer[100]; // temporary 
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
        // comment
        buffer[strcspn(buffer, "\r\n")] = 0;
        // comment
        if (strlen(buffer) > 0) {
            int index = tolower(buffer[0]) - 'a';
            if (index >= 0 && index < 26) {
                addList(&LL[index], buffer);
            }
        }
    }
    fclose(fp);
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
            if (idx >= 0 && idx < 26) displayList(&LL[idx], huruf);
        } 
        else if (pick == 2) {
            printf("Kata yang ingin dihapus: ");
            scanf("%s", kata);
            
            int idx = tolower(kata[0]) - 'a';
            
            if (idx >= 0 && idx < 26) {
                deleteNode(&LL[idx], kata);
            } 
            else {
                printf("Kata '%s' tidak ditemukan\n", kata);
            }
        }

    } while (pick != 3);
    
    for (i = 0; i < 26; i++) {
        freeList(&LL[i]);
    }

    printf("Program selesai\n");
    return EXIT_SUCCESS;
}