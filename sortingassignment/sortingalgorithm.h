typedef struct {
    long long comparison;
    long long swap;
    double timeTaken;
} Sortstats;

// Fungsi sorting integer untuk problem 1
void bubbleSortInt (int arr[], int , Sortstats *);
void selectionSortInt (int arr[], int , Sortstats *);
void insertionSortInt (int arr[], int , Sortstats *);
void mergeSortInt (int arr[], int , int, Sortstats *);
void quickSortInt (int arr[], int , int , Sortstats *);

// Fungsi sorting string untuk problem 2
void bubbleSortStr (char arr[][100], int , Sortstats *);
void selectionSortStr (char arr[][100], int , Sortstats *);
void insertionSortStr (char arr[][100], int , Sortstats *);
void mergeSortStr (char arr[][100], int , int , Sortstats *);
void quickSortStr (char arr[][100], int , int , Sortstats *);