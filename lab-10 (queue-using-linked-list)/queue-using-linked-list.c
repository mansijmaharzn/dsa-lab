#include<stdio.h>
#include<stdlib.h>


struct NODE {
    int data;
    struct NODE* next;
};


typedef struct NODE node;

node* front = NULL; 
node* rear = NULL;


void enqueue(int val) {
    node* newNode;
    newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Error allocating memory!\n");
        return;
    }

    if (front == NULL || rear == NULL) {
        newNode->next = NULL;
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = rear->next;
        rear->next = NULL; // or newNode->next = NULL
    }

    newNode->data = val;
    printf("Enqueued: %d\n", val);
}


void dequeue() {
    node* deleteNode;
    if (front == NULL || rear == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    int val;
    if (front == rear) {
        deleteNode = front;
        front = rear = NULL; // queue is empty again
        val = deleteNode->data;
    } else {
        deleteNode = front;
        front = deleteNode->next;
        val = deleteNode->data;
    }

    free(deleteNode);
    printf("Dequeued: %d\n", val);
}


void display() {
    if (front == NULL || rear == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    node* temp = front;
    printf("Queue: ");
    while (temp != rear) {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}



int main() {
    int choice, val;

    do {
        printf("1. Enqueue\t2. Dequeue\n3. Display\t4. Exit\n> ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                enqueue(val);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
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