#include <stdio.h>

void bubblesort (int arr[], int N) {
    int i,j;
    for (i = N; --i>= 0;) {
        for (j = 0; j < i; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+i] = temp;
            }
        }
    }
}
