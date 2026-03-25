typedef struct queuenode * QueueNodePtr;
typedef struct queuenode {
    int data;
    QueueNodePtr next;
} QueueNode;

typedef struct queueLinkedlist {
    QueueNodePtr front;
    QueueNodePtr rear;
    unsigned size;
} QueueLL;

void initQueueLL (QueueLL *queue);
void enqueueLL (QueueLL *queue, int data);
void displayLL (QueueLL *queue);
void freeQueueLL (QueueLL *queue);
int isEmptyLL (QueueLL *queue);
int dequeueLL (QueueLL *queue);
int peekLL (QueueLL *queue);