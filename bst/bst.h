typedef struct IntBSTNode {
    int data;
    struct IntBSTNode *left;
    struct IntBSTNode *right;
} IntBSTNode;

typedef IntBSTNode* IntBSTNodePtr;

typedef struct {
    IntBSTNodePtr root;
    int size;
} IntBSTree;