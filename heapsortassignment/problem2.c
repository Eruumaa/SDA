#define __USE_MINGW_ANSI_STDIO 1

#include "heapsort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORDS 26000
#define MAX_LEN 100

char words[MAX_WORDS][MAX_LEN];

int main() {
    int choice;
    int wordCount = 0;

    FILE *file = fopen("dbterms.txt", "r");
    if (file == NULL) {
        printf("Error: File 'dbterms.txt' tidak ditemukan.\n");
        return 1;
    }

    while (fscanf(file, "%99s", words[wordCount]) != EOF && wordCount < MAX_WORDS) {
        wordCount++;
    }
    fclose(file);
    printf("Berhasil memuat %d kata dari dbterms.txt...\n", wordCount);

    do {
        printf("\nPilihan:\n");
        printf("1) Mengurutkan kata dengan metode HEAP SORT, menyimpan ke teks, dan menampilkan waktu\n");
        printf("2) Selesai\n");
        printf("Pilihan anda: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Input harus angka\n");
            while (getchar() != '\n');
            continue;
        }

        if (choice == 1) {
            long long swapCount = 0;
            
            clock_t start = clock();
            heapSortStr(words, wordCount, &swapCount);
            clock_t end = clock();
            
            double time_spent = (double)(end - start) / CLOCKS_PER_SEC * 1000.0;

            FILE *f = fopen("hasilsortingproblem2.txt", "w");
            for (int i = 0; i < wordCount; i++) {
                fprintf(f, "%s\n", words[i]);
            }
            fclose(f);

            printf("\nData berhasil diurutkan dan disimpan di 'hasilsortingproblem2.txt'.\n");
            printf("Waktu pengurutan  : %.2f milidetik\n", time_spent);
            printf("Jumlah pertukaran : %lld kali\n", swapCount);
            
        } else if (choice == 2) {
            printf("Program Selesai.\n");
        } else {
            printf("Pilihan tidak valid. Silakan pilih 1 atau 2.\n");
        }

    } while (choice != 2);

    return 0;
}