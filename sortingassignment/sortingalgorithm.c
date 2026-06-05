#include "sortingalgorithm.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Fungsi sorting Integer untuk problem 1
// Bubble Sort
void bubbleSortInt (int arr[], int n, Sortstats *stats) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i; j++) {
            stats->comparison++;
            if (arr[j] > arr[j+1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                stats->swap++;
            }
        }
    }
}

// Selection Sort
void selectionSortInt (int arr[], int n, Sortstats *stats) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            stats->comparison++;
            if (arr[j] < arr[minIdx]) {
                // Perbarui indeks nilai terkecil
                minIdx = j;
            }
        }
        // Tukar hanya jika nilai terkecil bukan di posisi aslinya
        if (minIdx != i) {
            int temp = arr[minIdx];
            arr[minIdx] = arr[i];
            arr[i] = temp;
            stats->swap++;
        }
    }
}

// Insertion Sort
void insertionSortInt (int arr[], int n, Sortstats *stats) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        // Geser elemen yang lebih besar dari key ke kanan
        while (j >= 0) {
            stats->comparison++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                stats->swap++;
                j = j - 1;
            } else {
                break;
            }
        }
        // Sisipkan key di posisi yang tepat
        arr[j + 1] = key;
    }
}

// Merge Sort
void mergeSortInt(int arr[], int left, int right, Sortstats *stats) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        // Fungsi rekursif untuk membelah array
        mergeSortInt(arr, left, mid, stats);
        mergeSortInt(arr, mid + 1, right, stats);
        
        int n1 = mid - left + 1;
        int n2 = right - mid;
        
        // Alokasi memori dinamis untuk subarray sementara
        int *leftArr = (int *)malloc(n1 * sizeof(*leftArr));
        int *rightArr = (int *)malloc(n2 * sizeof(*rightArr));

        if (leftArr == NULL || rightArr == NULL) {
            printf("\nERROR: Kehabisan memori saat Merge\n");
            if (leftArr) free(leftArr);
            if (rightArr) free(rightArr);
            return;
        }
        
        // Menyalin data ke array sementara
        for (int i = 0; i < n1; i++) leftArr[i] = arr[left + i];
        for (int j = 0; j < n2; j++) rightArr[j] = arr[mid + 1 + j];
        
        int i = 0, j = 0, k = left;
        
        // Proses merge kembali ke array utama
        while (i < n1 && j < n2) {
            stats->comparison++; 
            if (leftArr[i] <= rightArr[j]) { 
                arr[k] = leftArr[i];
                i++;
            } else {
                arr[k] = rightArr[j];
                j++;
            }
            stats->swap++; 
            k++;
        }
        
        // Menyalin sisa elemen di array kiri
        while (i < n1) {
            arr[k] = leftArr[i];
            stats->swap++;
            i++; k++;
        }
        
        // Menyalin sisa elemen di array kanan
        while (j < n2) {
            arr[k] = rightArr[j];
            stats->swap++;
            j++; k++;
        }
        
        // Free memori sementara
        free(leftArr);
        free(rightArr);
    }
}

// Quick Sort
void quickSortInt (int arr[], int low, int high, Sortstats *stats) {
    if (low < high) {
        int pivot = arr[low];
        int i = low - 1;
        int j = high + 1;
        int temp;

        while (1) {
            do {
                i++;
                stats->comparison++; 
            } while (arr[i] < pivot);

            do {
                j--;
                stats->comparison++; 
            } while (arr[j] > pivot);

            if (i >= j) break; 

            // Tukar elemen
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            stats->swap++;
        }
        
        // Titik potong partisi
        int pi = j;

        // Urutkan bagian kiri dan kanan pivot secara rekursif
        quickSortInt (arr, low, pi, stats);
        quickSortInt (arr, pi + 1, high, stats);
    }
}

// Fungsi sorting string untuk problem 2
// Bubble Sort
void bubbleSortStr (char arr[][100], int n, Sortstats *stats) {
    char temp[100];

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            stats->comparison++;
            if (strcmp(arr[j], arr[j+1]) > 0) {
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);
                stats->swap++;
            }
        }
    }
}

// Selection Sort
void selectionSortStr (char arr[][100], int n, Sortstats *stats) {
    char temp[100];

    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i; j < n; j++) {
            stats->comparison++;
            if (strcmp(arr[j], arr[minIdx]) < 0) {
                minIdx = j;
            }
        } 
        if (minIdx != i) {
            strcpy (temp, arr[minIdx]);
            strcpy (arr[minIdx], arr[i]);
            strcpy (arr[i], temp);
            stats->swap++;
        }
    }
}

// Insertion Sort
void insertionSortStr (char arr[][100], int n, Sortstats *stats) {
    char key[100];

    for (int i = 1; i < n; i++) {
        strcpy (key, arr[i]);
        int j = i - 1;

        while (j >= 0) {
            stats->comparison++;
            if (strcmp(arr[j], key) > 0) {
                strcpy(arr[j + 1], arr[j]);
                stats->swap++;
                j = j - 1;
            } else {
                break;
            }
        }
        strcpy(arr[j + 1], key);
    }
}

// Merge Sort 
void mergeSortStr (char arr[][100], int left, int right, Sortstats *stats) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        mergeSortStr (arr, left, mid, stats);
        mergeSortStr (arr, mid + 1, right, stats);
        
        int n1 = mid - left + 1;
        int n2 = right - mid;
        
        char (*leftArr)[100] = malloc(n1 * sizeof(*leftArr));
        char (*rightArr)[100] = malloc(n2 * sizeof(*rightArr));
        
        for (int i = 0; i < n1; i++) strcpy(leftArr[i], arr[left + i]);
        for (int j = 0; j < n2; j++) strcpy(rightArr[j], arr[mid + 1 + j]);
        
        int i = 0, j = 0, k = left;
        
        while (i < n1 && j < n2) {
            stats->comparison++; 
            if (strcmp(leftArr[i], rightArr[j]) <= 0) {
                strcpy(arr[k], leftArr[i]);
                i++;
            } else {
                strcpy(arr[k], rightArr[j]);
                j++;
            }
            stats->swap++; 
            k++;
        }
        
        while (i < n1) {
            strcpy(arr[k], leftArr[i]);
            stats->swap++;
            i++; k++;
        }
        
        while (j < n2) {
            strcpy(arr[k], rightArr[j]);
            stats->swap++;
            j++; k++;
        }
        
        free(leftArr);
        free(rightArr);
    }
}

// Quick Sort
void quickSortStr (char arr[][100], int low, int high, Sortstats *stats) {
    if (low < high) {
        char pivot[100];
        strcpy(pivot, arr[low]); 
        int i = low - 1;
        int j = high + 1;
        char temp[100]; 

        while (1) {
            do {
                i++;
                stats->comparison++; 
            } while (strcmp(arr[i], pivot) < 0); 

            do {
                j--;
                stats->comparison++; 
            } while (strcmp(arr[j], pivot) > 0); 

            if (i >= j) {
                break;
            }

            strcpy(temp, arr[i]);
            strcpy(arr[i], arr[j]);
            strcpy(arr[j], temp);
            stats->swap++;
        }
        
        int pi = j; 

        quickSortStr(arr, low, pi, stats);
        quickSortStr(arr, pi + 1, high, stats);
    }
}