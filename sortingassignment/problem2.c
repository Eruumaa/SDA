#define __USE_MINGW_ANSI_STDIO 1

#include "sortingalgorithm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


// Fungsi untuk menduplikasi array string
void copyArrayStr(char source[][100], char dest[][100], int n) {
    for (int i = 0; i < n; i++) {
        strcpy(dest[i], source[i]);
    }
}

// Fungsi untuk mencetak hasil pengurutan string dengan batas aman layar tertminal
void printArrayStr(char arr[][100], int n) {
    printf("Menampilkan hasil pengurutan: \n");
    int limit = (n < 15) ? n : 15;
    for (int i = 0; i < limit; i++) {
        printf("%s ", arr[i]);
    }
    if (n > 15) {
        printf("... (dan seterusnya)");
    }
    printf("\n");
}

int main() {
    FILE *file;
    char filename[] = "dbterms.txt";
    int choice;
    int n = 0;

    // Membuka dan menghitung isi file
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Tidak dapat membuka file '%s'.\n", filename);
        printf("Pastikan file dbterms.txt berada di dalam satu folder dengan program!\n");
        return 1;
    }

    char buffer[100];
    // Menghitung jumlah kata secara otomatis sampai akhir file (EOF)
    while (fscanf(file, "%99s", buffer) == 1) {
        n++;
    }
    fclose(file); 

    if (n == 0) {
        printf("Error: File kosong atau format tidak sesuai.\n");
        return 1;
    }

    printf("Berhasil membaca %d kata dari file %s.\n", n, filename);

    char (*original_arr)[100] = malloc(n * sizeof(*original_arr));
    char (*temp_arr)[100] = malloc(n * sizeof(*temp_arr));

    if (original_arr == NULL || temp_arr == NULL) {
        printf("Gagal mengalokasikan memori!\n");
        return 1;
    }

    file = fopen(filename, "r");
    for (int i = 0; i < n; i++) {
        fscanf(file, "%99s", original_arr[i]);
    }
    fclose(file);
    printf("Data siap diproses!\n");

    // 4. MENU UTAMA
    while (1) {
        printf("\nPilihan:\n");
        printf("1) Mengurutkan data dengan INSERTION SORT dan menampilkan hasil\n");
        printf("2) Mengurutkan data dengan BUBBLE SORT dan menampilkan hasil\n");
        printf("3) Mengurutkan data dengan SELECTION SORT dan menampilkan hasil\n");
        printf("4) Mengurutkan data dengan MERGE SORT dan menampilkan hasil\n");
        printf("5) Mengurutkan data dengan QUICK SORT dan menampilkan hasil\n");
        printf("6) Selesai\n");
        printf("Pilihan anda: ");

        if (scanf("%d", &choice) != 1) {
            printf("Input tidak valid! Harap masukkan pilihan berupa angka 1-6.\n");
            while (getchar() != '\n'); 
            continue; 
        }

        Sortstats stats = {0, 0, 0.0};
        clock_t start_time;

        switch (choice) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
                copyArrayStr(original_arr, temp_arr, n);
                printf("Sedang memproses %d kata...\n", n);

                start_time = clock();
                if (choice == 1) insertionSortStr(temp_arr, n, &stats);
                else if (choice == 2) bubbleSortStr(temp_arr, n, &stats);
                else if (choice == 3) selectionSortStr(temp_arr, n, &stats);
                else if (choice == 4) mergeSortStr(temp_arr, 0, n - 1, &stats);
                else if (choice == 5) quickSortStr(temp_arr, 0, n - 1, &stats);
                
                stats.timeTaken = ((double)(clock() - start_time)) / CLOCKS_PER_SEC;

                printArrayStr(temp_arr, n);
                printf("Jumlah perbandingan  : %lld\n", stats.comparison);
                printf("Jumlah pertukaran    : %lld\n", stats.swap);
                printf("Waktu yang dibutuhkan: %.6f detik\n", stats.timeTaken);
                break;

            case 6:
                free(original_arr);
                free(temp_arr);
                printf("Program selesai.\n");
                return 0;

            default:
                printf("Pilihan tidak valid. Silakan masukkan angka 1 hingga 6.\n");
                break;
        }
    }
    
    return 0;
}