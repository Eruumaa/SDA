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

int initStack(Stack *);
int isEmpty(Stack *);
int push(Stack *);
int pop(Stack *);
int get(Stack *);