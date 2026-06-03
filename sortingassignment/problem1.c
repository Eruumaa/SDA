#define __USE_MINGW_ANSI_STDIO 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sortingalgorithm.h"

// Fungsi untuk duplikasi data
void copyArray(int source[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = source[i];
    }
}

// Fungsi mencetak array yang terurut yang dibatasi 15 agar terminal tidak crash
void printArray(int arr[], int n) {
    printf("Menampilkan hasil pengurutan: ");
    int limit = (n < 15) ? n : 15;
    for (int i = 0; i < limit; i++) {
        printf("%d ", arr[i]);
    }
    if (n > 15) {
        printf("... (dan seterusnya)");
    }
    printf("\n");
}

int main() {
    int n, choice;
    int *original_arr = NULL;
    int *temp_arr = NULL;
    
    srand(time(NULL));

    // Looping pengecekan n pertama kali
    while (1) {
        printf("Masukkan Jumlah Bilangan (n): ");
        if (scanf("%d", &n) != 1) {
            printf("Input tidak valid! Input hanya boleh angka.\n");
            while (getchar() != '\n'); // bersihkan memori keyboard
        } else if (n <= 1 || n > 5000000) {
            printf("Error: n harus > 1 dan <= 5000000.\n");
        } else {
            break; // Input aman, keluar dari loop
        }
    }

    original_arr = (int*)malloc(n * sizeof(int));
    temp_arr = (int*)malloc(n * sizeof(int));
    
    if (original_arr == NULL || temp_arr == NULL) {
        printf("Gagal mengalokasikan memori!\n");
        return 1;
    }

    // Acak data awal
    for (int i = 0; i < n; i++) {
        original_arr[i] = rand();
    }
    printf("Random data dalam array selesai\n");

    // Loop Menu Utama
    while (1) {
        printf("\nPilihan:\n");
        printf("1) Mengurutkan data dengan INSERTION SORT dan menampilkan hasil\n");
        printf("2) Mengurutkan data dengan BUBBLE SORT dan menampilkan hasil\n");
        printf("3) Mengurutkan data dengan SELECTION SORT dan menampilkan hasil\n");
        printf("4) Mengurutkan data dengan MERGE SORT dan menampilkan hasil\n");
        printf("5) Mengurutkan data dengan QUICK SORT dan menampilkan hasil\n");
        printf("6) Random ulang data dalam array\n");
        printf("7) Selesai\n");
        printf("Pilihan anda: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Input tidak valid! Harap masukkan pilihan berupa angka 1-7.\n");
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
                copyArray(original_arr, temp_arr, n);
                printf("Sedang memproses...\n");

                start_time = clock();
                if (choice == 1) insertionSortInt(temp_arr, n, &stats);
                else if (choice == 2) bubbleSortInt(temp_arr, n, &stats);
                else if (choice == 3) selectionSortInt(temp_arr, n, &stats);
                else if (choice == 4) mergeSortInt(temp_arr, 0, n - 1, &stats);
                else if (choice == 5) quickSortInt(temp_arr, 0, n - 1, &stats);
                
                stats.timeTaken = ((double)(clock() - start_time)) / CLOCKS_PER_SEC;

                printArray(temp_arr, n);
                printf("Jumlah perbandingan  : %lld\n", stats.comparison);
                printf("Jumlah pertukaran    : %lld\n", stats.swap);
                printf("Waktu yang dibutuhkan: %.6f detik\n", stats.timeTaken);
                break;

            case 6:
                while (1) {
                    printf("Masukkan Jumlah Bilangan (n): ");
                    if (scanf("%d", &n) != 1) {
                        printf("Input tidak valid! Input hanya boleh angka.\n");
                        while (getchar() != '\n');
                    } else if (n <= 1 || n > 5000000) {
                        printf("Error: n harus > 1 dan <= 5000000.\n");
                    } else {
                        break; 
                    }
                }
                
                free(original_arr);
                free(temp_arr);
                original_arr = (int*)malloc(n * sizeof(int));
                temp_arr = (int*)malloc(n * sizeof(int));
                
                if (original_arr == NULL || temp_arr == NULL) {
                    printf("Gagal mengalokasikan memori saat random ulang!\n");
                    return 1;
                }

                for (int i = 0; i < n; i++) {
                    original_arr[i] = rand();
                }
                printf("Random ulang data dalam array selesai\n");
                break;

            case 7:
                free(original_arr);
                free(temp_arr);
                printf("Program selesai.\n");
                return 0; // Mematikan program

            default:
                printf("Pilihan tidak valid. Silakan masukkan angka 1 hingga 7.\n");
                break;
        }
    }
    
    return 0;
}