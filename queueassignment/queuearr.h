#define MAX 100

// Struct Queue menggunakan implementasi Array
typedef struct queue {
    int data[MAX];
    int front;
    int rear;
    int count;
} QueueArr;


// Fungsi-fungsi yang digunakan
void initQueueArr (QueueArr *queue);
void enqueueArr (QueueArr *queue, int data);
void displayArr (QueueArr *queue);
int isEmptyArr (QueueArr *queue);
int isFullArr (QueueArr *queue);
int dequeueArr (QueueArr *queue);
int peekArr (QueueArr *queue);

