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


void main(){

    struct implement_queue queue;
    init_queue(&queue);
    int peeked = peek(&queue);
    printf(peeked == -1 ? "\nQueue is Empty" : "\nPeeked Element: %d", peeked);
    for (int i = 0 ; i < MAX_SIZE ;i++){
        push(&queue,i);
    }
    printf("\nRemoved Element %d: ",remover(&queue));
    printf("\nRemoved Element %d: ",remover(&queue));
    push(&queue,45);
    push(&queue,55);
    push(&queue,135);  //queue is full it should indicate 
    peeked = peek(&queue);
    printf(peeked == -1 ? "Queue is Empty\n" : "\nPeeked Element: %d", peeked);

    //removed all element 
    while(remover(&queue)!= -1){
         printf("\nRemoved Element %d: ",remover(&queue));
    }

}
//inti function implementation 

void init_queue(struct implement_queue *q){
    q->start = -1;
    q->end = -1;
    return;
}

//function to add data in queue 
void push(struct implement_queue *q,int data){
    //condition for checking queue is full in circular queue is 
    if((q->end+1)%MAX_SIZE == q->start){
        printf("\nQueue is Full");
        return;
    }
    if(q->start == -1 && q->end == -1){
        q->start = 0;
        q->end = 0;
    }else{
        q->end = (q->end+1)%MAX_SIZE;
    }
    q->queue[q->end] = data;
    printf("\n%d Added Successfully",data);
}

//function to peek the data into the queue

int peek(struct implement_queue *q){
    return q->start!=-1?q->queue[q->start]:-1;
}
//removed function implementation 

int remover(struct implement_queue *q){
    if(q->start == -1){
        printf("Queue is Empty");
        return -1;
    }
    if(q->start == q->end){
        init_queue(q);
    }
    int removed = q->queue[q->start];
    q->start = (q->start+1)%MAX_SIZE;
    return removed;
}
