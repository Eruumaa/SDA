typedef struct {
    long long comparison;
    long long swap;
    double timeTaken;
} Sortstats;

// Fungsi sorting integer untuk problem 1
void bubbleSortInt (int arr[], int , Sortstats *stats);
void selectionSortInt (int arr[], int , Sortstats *stats);
void insertionSortInt (int arr[], int , Sortstats *stats);
void mergeSortInt (int arr[], int , int, Sortstats *stats);
void quickSortInt (int arr[], int , int , Sortstats *stats);

// Fungsi sorting string untuk problem 2
void bubbleSortStr (char arr[][100], int , Sortstats *stats);
void selectionSortStr (char arr[][100], int , Sortstats *stats);
void insertionSortStr (char arr[][100], int , Sortstats *stats);
void mergeSortStr (char arr[][100], int , int , Sortstats *stats);
void quickSortStr (char arr[][100], int , int , Sortstats *stats);