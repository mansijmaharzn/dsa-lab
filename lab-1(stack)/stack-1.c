#include<stdio.h>
#include<stdlib.h> // for malloc

#define size 5


struct STACK {
    int data[size];
    int top;
};


typedef struct STACK stack;


void initStack(stack* s) {
    s->top = -1;
}


int isEmpty(stack* s) {
    if (s->top == -1)
        return 1; // true

    return 0; // false
}


int isFull(stack* s) {
    if(s->top == (size-1))
        return 1; // true
    
    return 0; // false
}


void push(stack* s, int val) {
    if(isFull(s)) {
        printf("Stack is Full\n");
    } else {
        s->top++;
        s->data[s->top] = val;
        printf("Push Successful!\n");
    }
}


void pop(stack* s) {
    if(isEmpty(s)) {
        printf("Stack is empty\n");
    } else {
        printf("Removed: %d\n", s->data[s->top]);
        s->top--;
    }
}


void display(stack* s) {
    for(int i=0; i <= s->top; i++) {
        printf("%d\t", s->data[i]);
    }
    printf("\n");
}


void peek(stack *s) {
    printf("Top: %d\n", s->data[s->top]);
}

int main() {
    stack* st;
    int choice, val;

    st = (stack*)malloc(sizeof(stack));

    initStack(st);
    
    // menu driven
    do {
        printf("1. Push\t\t2. Pop\n3. Display\t4. Peek\n5. Exit\t\t> ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &val);

                push(st, val);
                break;
            case 2:
                pop(st);
                break;
            case 3:
                display(st);
                break;
            case 4:
                peek(st);
                break;
            case 5:
                printf("Goodbye!");
                break;
            default:
                printf("Invalid Input!");
                break;
        }
    } while (choice != 5);


    return 0;
}