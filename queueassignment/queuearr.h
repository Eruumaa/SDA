#define MAX 100

typedef struct queue {
    int data[MAX];
    int front;
    int rear;
    int count;
} QueueArr;

void initQueueArr (QueueArr *queue);
void enqueueArr (QueueArr *queue, int data);
void displayArr (QueueArr *queue);
int isEmptyArr (QueueArr *queue);
int isFullArr (QueueArr *queue);
int dequeueArr (QueueArr *queue);
int peekArr (QueueArr *queue);

