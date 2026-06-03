#include "sortingalgorithm.h"
#include <time.h>
#include <stdlib.h>
#include <string.h>

// Fungsi sorting Integer untuk problem 1
// Bubble Sort
Sortstats bubbleSortInt (int arr[], int n) {
    Sortstats stats = {0,0, 0.0};
    clock_t start = clock();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i; j++) {
            stats.comparison++;
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                stats.swap++;
            }
        }
    }
    stats.timeTaken = ((double)(clock() - start)) / CLOCKS_PER_SEC;
    return stats;
}

// Selection Sort
Sortstats selectionSortInt (int arr[], int n) {

}

// Insertion Sort
Sortstats insertionSortInt (int arr[], int n) {

}

// Merge Sort
Sortstats mergeSortInt (int arr[], int n) {

}

// Quick Sort
Sortstats quickSortInt (int arr[], int n) {

}

// Fungsi sorting string untuk problem 2
// Bubble Sort
Sortstats bubbleSortStr (char arr[][100], int n) {

}

// Selection Sort
Sortstats selectionSortStr (char arr[][100], int n) {

}

// Insertion Sort
Sortstats insertionSortStr (char arr[][100], int n) {

}

// Merge Sort
Sortstats mergeSortStr (char arr[][100], int n) {

}

// Quick Sort
Sortstats quickSortStr (char arr[][100], int n);