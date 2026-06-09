#define __USE_MINGW_ANSI_STDIO 1

#include "heapsort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void randomRealNumb(double *arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = (double) rand() / RAND_MAX;
    }
    printf("Random bilangan real dalam array selesai...\n");
}

int main () {
    int n = 0;
    int choice;
    double *arr = NULL;
    srand(time(NULL)); 

    while (1) {
        printf("Masukkan Jumlah Bilangan (n): ");
        if (scanf("%d", &n) != 1) {
            printf("Input harus angka\n");
            while (getchar() != '\n');
            continue;
        }
        if (n <= 1 || n > 3000000) {
            printf("Error: n harus berada di antara 1 dan 3000000.\n");
            continue;
        }
        break;
    }

    arr = (double *)malloc(n * sizeof(double));
    if (arr == NULL) {
        printf("Gagal mengalokasikan memori.\n");
        return 1;
    }

    randomRealNumb(arr, n);

    do {
        printf("\nPilihan:\n");
        printf("1) Mengurutkan data bilangan real dengan metode HEAP SORT dan menyimpan hasil dalam file teks serta menampilkan waktu pengurutan\n");
        printf("2) Tentukan jumlah bilangan dan acak ulang bilangan real dalam array\n");
        printf("3) Selesai\n");
        printf("Pilihan anda: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Input harus angka\n");
            while (getchar() != '\n');
            continue;
        }

        if (choice == 1) {
            long long swapCount = 0;
            
            clock_t start = clock();
            heapSortDesc(arr, n, &swapCount);
            clock_t end = clock();
            
            double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

            FILE *f = fopen("hasilsortingproblem1.txt", "w");
            for (int i = 0; i < n; i++) {
                fprintf(f, "%f\n", arr[i]);
            }
            fclose(f);

            printf("\nData berhasil diurutkan secara Descending dan disimpan di 'hasilsortingproblem1.txt'.\n");
            printf("Waktu pengurutan  : %f detik\n", time_spent);
            printf("Jumlah pertukaran : %lld kali\n", swapCount);
            
        } else if (choice == 2) {
            free(arr);
            
            while (1) {
                printf("Masukkan Jumlah Bilangan (n) baru: ");
                if (scanf("%d", &n) != 1) {
                    printf("Input harus angka\n");
                    while (getchar() != '\n');
                    continue;
                }
                if (n <= 1 || n > 3000000) {
                    printf("Error: n harus berada di antara 1 dan 3000000.\n");
                    continue;
                }
                break;
            }
            
            arr = (double *)malloc(n * sizeof(double));
            randomRealNumb(arr, n);
            
        } else if (choice == 3) {
            printf("Program Selesai.\n");
        } else {
            printf("Pilihan tidak valid. Silakan pilih 1, 2, atau 3.\n");
        }

    } while (choice != 3);

    if (arr != NULL) free(arr);
    return 0;
}
    

