#define MAX 100 // Definisi maksimal array

// Definisi struct stack-array
typedef struct  {
    int data[MAX];
    int top;
} Stackarr;

// Fungsi-fungsi standar stack-array
int isEmptyArr(Stackarr);
int pushArr(Stackarr *ps, int);
int popArr(Stackarr *);
int getArr(Stackarr *);
int initStackArr(Stackarr *);