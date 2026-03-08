#define MAX 100 // Definisi maksimal array

// Definisi struct stack-array
typedef struct  {
    int data[MAX];
    int top;
} Stack;

// Fungsi-fungsi standar stack-array
int isEmpty(Stack);
int push(Stack *ps, int);
int pop(Stack *);
int get(Stack *);
int initStack(Stack *);