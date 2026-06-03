typedef struct {
    long long comparison;
    long long swap;
    double timeTaken;
} Sortstats;

// Fungsi sorting integer untuk problem 1
Sortstats bubbleSortInt (int arr[], int );
Sortstats selectionSortInt (int arr[], int );
Sortstats insertionSortInt (int arr[], int );
Sortstats mergeSortInt (int arr[], int );
Sortstats quickSortInt (int arr[], int );

// Fungsi sorting string untuk problem 2
Sortstats bubbleSortStr (char arr[][100], int );
Sortstats selectionSortStr (char arr[][100], int );
Sortstats insertionSortStr (char arr[][100], int );
Sortstats mergeSortStr (char arr[][100], int );
Sortstats quickSortStr (char arr[][100], int );