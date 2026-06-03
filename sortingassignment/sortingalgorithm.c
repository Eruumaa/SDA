#include "sortingalgorithm.h"
#include <string.h>

// Fungsi sorting Integer untuk problem 1
// Bubble Sort
Sortstats bubbleSortInt (int arr[], int n) {
    Sortstats stats = {0,0, 0.0};

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
    return stats;
}

// Selection Sort
Sortstats selectionSortInt (int arr[], int n) {
    Sortstats stats = {0,0, 0.0};

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
    return stats;
}

// Insertion Sort
Sortstats insertionSortInt (int arr[], int n) {
    Sortstats stats = {0,0, 0.0};

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
    return stats;
}

// Merge Sort
// Merge Integer
void mergeint (int arr[], int left, int right, Sortstats *stats) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        mergeint (arr, left, mid, stats);
        mergeint (arr, mid + 1, right, stats);
        
        int n1 = mid - left + 1;
        int n2 = right - mid;
        
        int *leftArr =  (int *)malloc(n1 * sizeof(*leftArr));
        int *rightArr =  (int *)malloc(n2 * sizeof(*rightArr));
        
        for (int i = 0; i < n1; i++) leftArr[i] = arr[left + i];
        for (int j = 0; j < n2; j++) rightArr[j] =arr[mid + 1 + j];
        
        int i = 0, j = 0, k = left;
        
        while (i < n1 && j < n2) {
            stats->comparison++; 
            if (strcmp(leftArr[i], rightArr[j]) <= 0) {
                arr[k] = leftArr[i];
                i++;
            } else {
                arr[k] = rightArr[j];
                j++;
            }
            stats->swap++; 
            k++;
        }
        
        while (i < n1) {
            arr[k] = leftArr[i];
            stats->swap++;
            i++; k++;
        }
        
        while (j < n2) {
            arr[k] = rightArr[j];
            stats->swap++;
            j++; k++;
        }
        
        free(leftArr);
        free(rightArr);
    }
}

// Merge sort
Sortstats mergeSortInt (int arr[], int n) {
    Sortstats stats = {0,0, 0.0};

    mergeint(arr, 0, n - 1, &stats);

    return stats;
}

void partitionInt(int arr[], int low, int high, Sortstats *stats) {
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

            if (i >= j) {
                break; 
            }

            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            stats->swap++;
        }
        
        int pi = j; 

        partitionInt(arr, low, pi, stats);
        partitionInt(arr, pi + 1, high, stats);
    }
}

// Quick Sort
Sortstats quickSortInt (int arr[], int n) {
    Sortstats stats = {0,0, 0.0};

    partitionInt (arr, 0, n - 1, &stats);

    return stats;
}

// Fungsi sorting string untuk problem 2
// Bubble Sort
Sortstats bubbleSortStr (char arr[][100], int n) {
    Sortstats stats = {0,0, 0.0};
    char temp[100];

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i; j++) {
            stats.comparison++;
            if (strcmp(arr[j], arr[j+1]) > 0) {
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);
                stats.swap++;
            }
        }
    }
    return stats;
}

// Selection Sort
Sortstats selectionSortStr (char arr[][100], int n) {

}

// Insertion Sort
Sortstats insertionSortStr (char arr[][100], int n) {

}

void mergeStr (char arr[][100], int left, int right, Sortstats *stats) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        mergeStr (arr, left, mid, stats);
        mergeStr (arr, mid + 1, right, stats);
        
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

// Merge Sort
Sortstats mergeSortStr (char arr[][100], int n) {
    Sortstats stats = {0,0, 0.0};

    mergeStr(arr, 0, n - 1, &stats);

    return stats;
}

// Quick Sort
Sortstats quickSortStr (char arr[][100], int n);