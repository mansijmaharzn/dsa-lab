#include<stdio.h>
#include<stdlib.h>


struct NODE {
    int data;
    struct NODE* next;
};


typedef struct NODE node;

node* top = NULL;


void push(int val) {
    node* newNode;
    newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Error allocating memory!\n");
        return;
    }

    if (top == NULL) {
        top = newNode;
        newNode->next = NULL;
    } else {
        newNode->next = top;
        top = newNode;
    }

    newNode->data = val;
    printf("Pushed: %d\n", val);
}


void pop() {
    if (top == NULL) {
        printf("Stack is empty!\n");
        return;
    }
    node* deleteNode = top;
    top = deleteNode->next;
    printf("Popped: %d\n", deleteNode->data);
    free(deleteNode);
}


void display() {
    if (top == NULL) {
        printf("Stack is empty!\n");
        return;
    }

    node* temp = top;
    printf("Stack:\t");
    while(temp != NULL) {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main() {
    int choice, val;

    do {
        printf("1. Push\t\t2. Pop\n3. Display\t4. Exit\n> ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &val);

                push(val);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid Input!\n");
                break;
        }
    } while (choice != 4);


    return 0;
}