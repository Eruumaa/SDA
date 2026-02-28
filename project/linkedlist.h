typedef struct node * NodePtr;
typedef struct node {
    char *kata;
    NodePtr next;
}Node;

typedef struct list {
    NodePtr head;
    unsigned size;
}List;

void initList(List * lptr);
void displayList(List * lptr, char huruf);
void freeList(List * lptr);
int addList(List *lptr, char *kataBaru);
int deleteNode(List * lptr, char *target);



