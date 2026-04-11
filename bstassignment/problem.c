#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "bstLL.h"


int main (void) {
    int pilih;
    int nomorBaris = 1;
    char huruf;
    char buffer[100];
    
    FILE * fp;
    intbstree tree;
    makeIntBst (&tree);

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
            insertBst(&tree, buffer, nomorBaris);
        }
        nomorBaris++;
    }
    fclose(fp);

    printf("Pembacaan isi file teks dan pengelompokkan selesai...\n");
    do {
        printf("\nMenu Pilihan:\n");
        printf("1) Menampilkan kata-kata sesuai huruf pertama yang diinputkan\n");
        printf("2) Menampilkan statistik dari kata urut secara ascending berdasarkan huruf pertama dari kata\n");
        printf("3) Selesai\n");
        printf("\nPilihan anda: ");
        
        if (scanf("%d", &pilih) != 1) {
            printf("\nInput harus berupa angka!\n");
            while (getchar() != '\n');
            pilih = 0;
            continue;
        }
        if (pilih == 1) {
            printf("Huruf: ");
            scanf(" %c", &huruf);
            
            searchBst(&tree, huruf);
        } 
        else if (pilih == 2) {
            inOrder(&tree);
        }
    // Opsi ke-3 keluar dari program
    } while (pilih != 3);
    
    freeBst(&tree);
    
    printf("Program selesai\n");

    return 0;
}