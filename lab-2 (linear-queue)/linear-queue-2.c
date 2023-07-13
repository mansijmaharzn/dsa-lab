#include <stdio.h>
#include <stdlib.h>


#define size 5


struct QUEUE {
    int data[size];
    int front;
    int rear;
};


typedef struct QUEUE queue;


void initQueue(queue* q) {
    q->front = -1;
    q->rear = -1;
}


int isFull(queue* q) {
    if (q->rear == (size - 1)) {
        return 1; // true
    }
    return 0; // false
}


int isEmpty(queue* q) {
    if (q->rear == -1 || q->front > q->rear) {
        return 1; // true
    }
    return 0; // false
}


void enqueue(queue* q, int val) {
    if (isFull(q)) {
        printf("Queue is full!\n");
    } else {
        if (q->front == -1)
            q->front = 0;
        
        q->rear++;
        q->data[q->rear] = val;
        printf("Enqueued value: %d\n", val);
    }
}


void dequeue(queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
    } else {
        int val = q->data[q->front];
        q->front++;
        printf("Dequeued value: %d\n", val);
    }
}


void display(queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue:\t");
    for (int i=q->front; i<=q->rear; i++) {
        printf("%d\t", q->data[i]);
    }
    printf("\n");
}


int main() {
    queue* qu;
    int choice, val;

    qu = (queue*)malloc(sizeof(queue));
    initQueue(qu);

    do {
        printf("1. Enqueue\t2. Dequeue\n3. Display\t4. Exit\n> ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                enqueue(qu, val);
                break;

            case 2:
                dequeue(qu);
                break;

            case 3:
                display(qu);
                break;

            case 4:
                printf("Bye!\n");
                break;

            default:
                printf("Invalid Input!\n");
                break;
        }
    } while(choice != 4);

    return 0;
}