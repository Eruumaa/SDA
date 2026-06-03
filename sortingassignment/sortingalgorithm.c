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
    Sortstats stats = {0,0, 0.0};
    clock_t start = clock();

    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            stats.comparison++;
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            int temp = arr[minIdx];
            arr[minIdx] = arr[i];
            arr[i] = temp;
            stats.swap++;
        }
    }
    stats.timeTaken = ((double)(clock() - start)) / CLOCKS_PER_SEC;
    return stats;
}

// Insertion Sort
Sortstats insertionSortInt (int arr[], int n) {
    Sortstats stats = {0,0, 0.0};
    clock_t start = clock();

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0) {
            stats.comparison++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                stats.swap++;
                j = j - 1;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
    }
    stats.timeTaken = ((double)(clock() - start)) / CLOCKS_PER_SEC;
    return stats;
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