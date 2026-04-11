#include <stdio.h>

void selectionsort (int arr[], int N) {
    int i,j;
    for (i = 0; i < N; i++) {
        int min = arr[i];
        int pos = i;
        for (j = i; j < N; j++) {
            if (arr[j] < min) {
                min = arr[j];
                pos = j;
            }
        }
        if (i!= pos) {
            int temp = arr[i];
            arr[i] = arr[pos];
            arr[pos] = temp;
        }
    }
}