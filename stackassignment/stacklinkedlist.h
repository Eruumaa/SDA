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
int initStack(Stack *);
int isEmpty(Stack *);
int push(Stack *, char);
int pop(Stack *);
int get(Stack *);