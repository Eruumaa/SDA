#define MAX 100 // Definisi maksimal array

// Definisi struct stack-array
typedef struct  {
    int data[MAX];
    int top;
} Stack;

// Fungsi-fungsi standar stack-array
int isEmptyArr(Stack);
int pushArr(Stack *ps, int);
int popArr(Stack *);
int getArr(Stack *);
int initStackArr(Stack *);