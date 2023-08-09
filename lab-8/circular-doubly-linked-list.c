#include<stdio.h>
#include<stdlib.h>


struct NODE {
    struct NODE* prev;
    int data;
    struct NODE* next;
};


typedef struct NODE node;

node* head = NULL;


// insert operations
void insertAtBeginning(int val) {
    node* newNode;
    newNode = (node*)malloc(sizeof(node));

    if (newNode == NULL) {
        printf("Error allocating memory!\n");
        return;
    }

    if (head == NULL) {
        newNode->prev = newNode->next = newNode;
        head = newNode;
    } else {
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev = newNode;
        newNode->prev->next = newNode;
        head = newNode;
    }

    newNode->data = val;
    printf("Inserted %d at beginning!\n", val);
}


void insertAtEnd(int val) {
    node *newNode;
    newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Error allocating memory!\n");
        return;
    }

    if (head == NULL) {
        newNode->prev = newNode->next = head;
        head = newNode;
    } else {
        newNode->next = head;
        newNode->prev = head->prev;
        newNode->prev->next = newNode;
        head->prev = newNode;
    }

    newNode->data = val;
    printf("Inserted %d at end!\n", val);
}


void insertAtRandom(int val, int pos) {
    node *newNode;
    newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Error allocating memory!\n");
        return;
    }

    if (head == NULL) {
        newNode->prev = newNode->next = head;
        head = newNode;
    } else {
        node* temp = head;
        for (int i=0; i<=pos-2; i++) {
            temp = temp->next;
            if(temp == head) {
                printf("Oops! Invalid Position!\n");
                return;
            }
        }
        newNode->prev = temp;
        newNode->next = temp->next;
        temp->next = newNode;
        newNode->next->prev = newNode;
    }

    newNode->data = val;
    printf("Inserted %d at %d!\n", val, pos);
}
// insert operations


// delete operations
void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    node* deleteNode;
    int val;
    if (head->next == head) {
        deleteNode = head;
        head = NULL;
        val = deleteNode->data;
    } else {
        deleteNode = head;
        head = deleteNode->next;
        head->prev = deleteNode->prev;
        head->prev->next = head;
        val = deleteNode->data;
    }

    free(deleteNode);
    printf("Deleted %d from beginning!\n", val);
}


void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    node* deleteNode;
    int val;
    if (head->next == head) {
        deleteNode = head;
        head = NULL;
        val = deleteNode->data;
    } else {
        deleteNode = head->prev;
        
        deleteNode->prev->next = head;
        head->prev = deleteNode->prev;
        val = deleteNode->data;
    }

    free(deleteNode);
    printf("Deleted %d from end!\n", val);
}


void deleteAtRandom(int pos) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    node* deleteNode;
    int val;
    if (head->next == head) {
        deleteNode = head;
        head = NULL;
        val = deleteNode->data;
    } else {
        deleteNode = head;
        for (int i=0; i < pos; i++) {
            deleteNode = deleteNode->next;
            if (deleteNode == head) {
                printf("Oops! Invalid Position!\n");
                return;
            }
        }

        deleteNode->next->prev = deleteNode->prev;
        deleteNode->prev->next = deleteNode->next;
        val = deleteNode->data;
    }

    free(deleteNode);
    printf("Deleted %d from %d!\n", val, pos);
}
// delete operations


void display() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    node* temp = head;

    printf("List:\t");
    while(temp->next != head) {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}


int main() {
    int firstChoice, secondChoice, value, position;

    do {
        printf("1. Insert\t2. Delete\t3. Display\t4. Exit\n> ");
        scanf("%d", &firstChoice);

        switch(firstChoice) {
            // insert operations
            case 1:
                printf("1. At Beginning\t2. At Random\t3. At End\t4. Exit\n> ");
                scanf("%d", &secondChoice);
                
                printf("Enter value to insert: ");
                scanf("%d", &value);

                switch(secondChoice) {
                    case 1:
                        insertAtBeginning(value);
                        break;
                    case 2:
                        printf("Enter position to insert: ");
                        scanf("%d", &position);
                        insertAtRandom(value, position);
                        break;
                    case 3:
                        insertAtEnd(value);
                        break;
                }
                break;
            
            // delete operations
            case 2:
                printf("1. At Beginning\t2. At Random\t3. At End\n> ");
                scanf("%d", &secondChoice);

                switch(secondChoice) {
                    case 1:
                        deleteAtBeginning();
                        break;
                    case 2:
                        printf("Enter position to delete: ");
                        scanf("%d", &position);
                        deleteAtRandom(position);
                        break;
                    case 3:
                        deleteAtEnd();
                        break;
                }
                break;

            case 3:
                display();
                break;
            
            case 4:
                printf("GoodBye!");
                break;
            
            default:
                printf("Invalid Input!\n");
                break;
        }
    } while(firstChoice != 4);

    return 0;
}