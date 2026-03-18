/* Program berikut disimpan dalam file stack.h */
typedef struct stacknode * StackNodePtr;
typedef struct stacknode{
int elemen;
StackNodePtr next;
}StackNode;

typedef struct stack{
StackNodePtr top;
unsigned size;
}Stack;

int makeStack(Stack *);
int emptyStack(Stack *);
int push(Stack *, int);
int pop(Stack *);
int get(Stack *);