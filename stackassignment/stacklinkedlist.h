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
} StackLL;

// Fungsi-fungsi standar stack-linkedlist
int initStackLL(StackLL *);
int isEmptyLL(StackLL *);
int pushLL(StackLL *, char);
int popLL(StackLL *);
int getLL(StackLL *);