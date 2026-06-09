#include "heapsort.h"
#include <string.h>

void minHeapify(double arr[], int n, int i, long long *swapCount) {
    // Inisialisasi node terkecil sebagai root
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Cek apakah anak kiri lebih kecil dari root
    if (left < n && arr[left] < arr[smallest]) {
        smallest = left;
    }

    // Cek apakah anak kanan lebih kecil dari node terkecil saat ini
    if (right < n && arr[right] < arr[smallest]) {
        smallest = right;
    }

    // Jika node terkecil bukan root, lakukan pertukaran dan lanjut heapify 
    if (smallest != i) {
        double temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        (*swapCount)++;

        minHeapify (arr, n, smallest, swapCount);
    }
}

void maxHeapifyStr (char arr[][100], int n, int i, long long *swapCount) {
    // Inisialisasi node terbesar sebagai root
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Cek apakah child kiri secara alfabetis lebih besar dari root
    if (left < n && strcmp(arr[left], arr[largest]) > 0) {
        largest = left;
    }

    // Cek apakah child kanan lebih besar dari node terbesar saat ini
    if (right < n && strcmp(arr[right], arr[largest]) > 0) {
        largest = right;
    }

    // Jika node terbesar bukan root, tukar string dan  lanjut heapify
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
    // Bangun Min-Heap dari node non-leaf terakhir hingga root
    for (int i = n / 2 - 1; i >= 0; i--) {
        minHeapify (arr, n, i, swapCount);
    }

    // Ekstrak elemen satu per satu dari heap
    for (int i = n - 1; i > 0; i--) {
        // Pindahkan elemen root terkecil ke akhir array
        double temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        (*swapCount)++;
        
        // Memanggil minHeapify pada root yang baru untuk sisa heap
        minHeapify (arr, i, 0, swapCount);
    }
}

void heapSortStr (char arr[][100], int n, long long *swapCount) {
    // Buat Max-Heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapifyStr (arr, n, i, swapCount);
    }

    // Extract elemen string dengan satu per satu
    for (int i = n - 1; i > 0; i--) {
        // Pindahkan string terbesar "Z" ke akhir array
        char temp[100];
        strcpy (temp, arr[0]);
        strcpy(arr[0], arr[i]);
        strcpy(arr[i], temp);
        (*swapCount)++;

        // Restore properti Max-Heap pada elemen yang tersisa
        maxHeapifyStr(arr, i, 0, swapCount);
    }
}
