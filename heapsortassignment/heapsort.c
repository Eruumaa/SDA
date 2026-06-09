#include "heapsort.h"
#include <string.h>

void minHeapify(double arr[], int n, int i, long long *swapCount) {
    int smallest = 1;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest]) {
        smallest = left;
    }
    if (right < n && arr[right] < arr[smallest]) {
        smallest = right;
    }
    if (smallest != i) {
        double temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        (*swapCount)++;

        minHeapify (arr, n, smallest, swapCount);
    }
}

void maxHeapifyStr (char arr[][100], int n, int i, long long *swapCount) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && strcmp(arr[left], arr[largest]) > 0) {
        largest = left;
    }

    if (right < n && strcmp(arr[right], arr[largest]) > 0) {
        largest = right;
    }

    if (largest != i) {
        char temp[100];
        strcpy(temp, arr[i]);
        strcpy(arr[i], arr[largest]);
        strcpy(arr[largest], temp);
        (*swapCount)++;

        maxHeapifyStr (arr, n, largest, swapCount);
    }
}

void heapSortDesc (double arr[], int n, long long *swapCount) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        minHeapify (arr, n, i, swapCount);
    }

    for (int i = n - 1; i > 0; i--) {
        double temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        (*swapCount)++;
        
        minHeapify (arr, i, 0, swapCount);
    }
}

void heapSortStr (char arr[][100], int n, long long *swapCount) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapifyStr (arr, n, i, swapCount);
    }

    for (int i = n - 1; i > 0; i--) {
        char temp[100];
        strcpy (temp, arr[0]);
        strcpy(arr[0], arr[i]);
        strcpy(arr[i], temp);
        (*swapCount)++;

        maxHeapifyStr(arr, i, 0, swapCount);
    }
}
