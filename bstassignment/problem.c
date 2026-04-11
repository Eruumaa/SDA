#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "bstLL.h"


int main (void) {
    int i, pilih;
    int nomorBaris = 1;
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
            // Menghitung alamat index 
            int index = tolower(buffer[0]) - 'a';
            // Kondisi untuk menyambungkan node baru ke linked list 
            if (index >= 0 && index < 26) {
                addList(&LL[index], buffer, nomorBaris);
            }
        }
        nomorBaris++;
    }
    fclose(fp);


    return 0;
}