typedef struct node * NodePtr;
typedef struct node {
    char *kata;
    NodePtr next;
} Node;

typedef struct list {
    NodePtr head;
    unsigned size;
} List;

void initList (List * lptr);
void displayList (List * lptr, char );
void freeList (List * lptr);
int addList (List *lptr, char *);
int deleteNode (List * lptr, char *);

