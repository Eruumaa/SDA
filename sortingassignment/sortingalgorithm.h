typedef struct {
    long long comparison;
    long long swap;
    double timeTaken;
} Sortstats;

// Fungsi sorting integer untuk problem 1
Sortstats bubbleSortInt (int arr[], int n);
Sortstats selectionSortInt (int arr[], int n);
Sortstats insertionSortInt (int arr[], int n);
Sortstats mergeSortInt (int arr[], int n);
Sortstats quickSortInt (int arr[], int n);

// Fungsi sorting string untuk problem 2
Sortstats bubbleSortStr (char arr[][100], int n);
Sortstats selectionSortStr (char arr[][100], int n);
Sortstats insertionSortStr (char arr[][100], int n);
Sortstats mergeSortStr (char arr[][100], int n);
Sortstats quickSortStr (char arr[][100], int n);