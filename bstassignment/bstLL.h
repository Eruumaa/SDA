// Struct Linked List
typedef struct node * NodePtr;
typedef struct node {
    char *kata;
    int nomor;
    NodePtr next;
} Node;

typedef struct list {
    NodePtr head;
    unsigned size;
} List;

// Struct BST
typedef struct intbstNode * instbstNodePtr;
typedef struct intbstNode {
    char kata;
    List list;
    instbstNodePtr left, right;
} intbstNode;

typedef struct {
    instbstNodePtr root;
    int size;
} intbstree;

// Fungsi Linked List 
void initList (List * lptr);
void displayList (List * lptr, char );
void freeList (List * lptr);
int addList (List *lptr, char *, int);
int deleteNode (List * lptr, char *);

// Fungsi BST
int makeIntBst (intbstree * pBst);
int insertBst (intbstree * pBst , char );
void freeBst (intbstree * pBst);
void inOrder (intbstree * pBst);


