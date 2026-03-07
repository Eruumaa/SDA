typedef struct stacknode * StackNodePtr;
typedef struct  stacknode {

    int elemen;
    StackNodePtr
    Next;
} StackNode;

typedef struct stack {
    StackNodePtr top;
    unsigned size;
}Stack;


