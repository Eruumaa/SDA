// Definisi alias struct node dan stack
typedef struct stacknode * StackNodePtr;
typedef struct stacknode {
    char elemen;
    StackNodePtr
    next;
} StackNode;

typedef struct stack {
    StackNodePtr top;
    unsigned size;
} Stack;

// Fungsi-fungsi standar stack-linkedlist
int initStackLL(Stack *);
int isEmptyLL(Stack *);
int pushLL(Stack *, char);
int popLL(Stack *);
int getLL(Stack *);