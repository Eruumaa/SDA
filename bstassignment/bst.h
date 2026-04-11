typedef struct intbstNode * instbstNodePtr;
typedef struct intbstNode {
    char kata;
    instbstNodePtr left;
    instbstNodePtr right;
} intbstNode;

typedef struct {
    instbstNodePtr root;
    int size;
} intbstree;

int makeIntBst (intbstree * );
int insertBst (intbstree * , char );
void freeBst (intbstree * );
void inOrder (intbstree * );