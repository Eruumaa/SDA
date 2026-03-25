typedef struct queuenode * QueueNodePtr;
typedef struct queuenode {
    int id;
    QueueNodePtr next;
} QueueNode;

typedef struct queueLinkedlist {
    QueueNodePtr front;
    QueueNodePtr rear;
    unsigned size;
} queueLinkedlist;