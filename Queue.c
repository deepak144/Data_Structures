#include "stdio.h"
#define MAX_SIZE 5

struct implement_queue {
    int queue[MAX_SIZE];
    int end;
    int start;
};

// Function prototypes
void push(struct implement_queue *q, int data);
void init_queue(struct implement_queue *q);
int peek(struct implement_queue *q);
int remover(struct implement_queue *q);

void main() {
    // Define an instance of the structure to implement the queue
    struct implement_queue queue;

    // Initialize the queue before using it
    init_queue(&queue);

    // Add some data to the queue
    push(&queue, 1);
    push(&queue, 2);
    push(&queue, 3);

    // Peek the data in the queue
    printf("Peeking into the queue:\n");
    while (queue.end >= 0) {
        printf("\nData: %d\n", peek(&queue));
        remover(&queue);  // Remove the front element
    }

    printf("\nBasics implementation of queue is finish\n\n");
}

// Initialize the queue
void init_queue(struct implement_queue *q) {
    q->end = -1;
    q->start = -1;
}

// Add data in the queue
void push(struct implement_queue *q, int data) {
    if (q->end >= MAX_SIZE - 1) {
        printf("\nQueue is Full\n");
        return;
    }
    // If the queue is empty, set the start pointer to 0
    if (q->start == -1) {
        q->start = 0;
    }
    q->end++;
    q->queue[q->end] = data;
    printf("\n%d is added to the queue\n", data);
}

// Peek data from the queue (look at the front item without removing it)
int peek(struct implement_queue *q) {
    if (q->start == -1 || q->start > q->end) {
        printf("Queue is Empty\n");
        return -1;
    }
    return q->queue[q->start];
}

// Remove data from the queue (dequeue the front item)
int remover(struct implement_queue *q) {
    if (q->start == -1 || q->start > q->end) {
        printf("Queue is Empty\n");
        return -1;
    }
    
    int ret = q->queue[q->start];  // Get the front element
    
    // Shift all elements to the left to fill the gap
    for (int i = 0; i < q->end; i++) {
        q->queue[i] = q->queue[i + 1];
    }
    q->end--;  // Decrease the end pointer

    // If the queue becomes empty, reset both start and end
    if (q->end == -1) {
        q->start = -1;
    }
    return ret;
}
