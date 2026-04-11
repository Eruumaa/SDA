typedef IntBSTNode* IntBSTNodePtr;
typedef struct IntBSTNode {
    int data;
    struct IntBSTNode *left;
    struct IntBSTNode *right;
} IntBSTNode;

typedef struct {
    IntBSTNodePtr root;
    int size;
} IntBSTree;