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
    return ((q->front == (q->rear + 1) % size));
}


int isEmpty(queue* q) {
    return (q->front == -1);
}


void enqueue(queue* q, int val) {
    if (isFull(q)) {
        printf("Queue is full!\n");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        
        q->rear = (q->rear + 1) % size;
        q->data[q->rear] = val;
        printf("Enqueued value: %d\n", val);
    }
}


void dequeue(queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
    } else {
        int val = q->data[q->front];
        q->front = (q->front + 1) % size;
        printf("Dequeued value: %d\n", val);
    }
}


void display(queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue:\t");
    
    /*if (q->front > q->rear) {
        for(int i=q->front; i < size; i++) {
            printf("%d\t", q->data[i]);
        }

        for(int i=0; i<=q->rear; i++) {
            printf("%d\t", q->data[i]);
        }
    } else {
        for(int i=q->front; i<=q->rear; i++) {
            printf("%d\t", q->data[i]);
        }
    }
    printf("\n");*/
    int i = q->front;
    do {
        printf("%d\t", q->data[i]);
        i = (i + 1) % size;
    } while (i != (q->rear + 1) % size);
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
                printf("GoodBye!\n");
                break;

            default:
                printf("Invalid Input!\n");
                break;
        }
    } while(choice != 4);

    return 0;
}