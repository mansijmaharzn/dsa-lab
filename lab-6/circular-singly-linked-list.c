#include<stdio.h>
#include<stdlib.h>


struct NODE {
    int data;
    struct NODE* next; // self-refrencing
};


typedef struct NODE node;
node* head = NULL; // initializing head


// insert operations
void insertAtBeginning(int val) {
    node* newNode;
    newNode = (node*)malloc(sizeof(node));
    if(newNode == NULL) {
        printf("Failed to allocate memory!");
        return;
    }

    if (head==NULL) {
        newNode->next = newNode;
    } else {
        node* tempNode = head;

        while(tempNode->next != head) {
            tempNode = tempNode->next;
        }

        tempNode->next = newNode;
        newNode->next = head;
    }

    newNode->data = val;
    head = newNode;

    printf("Inserted %d at beginning!\n", val);
}


void insertAtEnd(int val) {
    node* newNode;
    newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Failed to allocate memory!");
        return;
    }

    if (head == NULL) {
        head = newNode;
    } else {
        node* temp = head;
        while(temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    newNode->data = val;
    newNode->next = head;
    printf("Inserted %d at end!\n", val);
}


void insertAtRandom(int val, int pos) {
    if (pos == 0) {
        insertAtBeginning(val);
        return;
    }

    node *newNode;
    newNode = (node*)malloc(sizeof(node));

    if(newNode == NULL) {
        printf("Failed to allocate memory!");
        return;
    }

    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
    } else {
        node* temp = head;
        for(int i=0; i<=pos-2; i++) {
            temp = temp->next;
            if(temp == head) {
                printf("Oops! Invalid Position!\n");
                return;
            }
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    newNode->data = val;
    printf("Inserted %d at position %d!\n", val, pos);
}
// insert operations


// delete operations
void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is Empty!\n");
        return;
    }

    node* deleteNode = head;
    node* tempNode = head;

    while(tempNode->next != head) {
        tempNode = tempNode->next;
    }
    tempNode->next = deleteNode->next;
    head = deleteNode->next;
    int val = deleteNode->data;
    free(deleteNode);

    printf("Deleted %d at beginning!\n", val);
}


void deleteAtEnd() {
    if (head == NULL) {
        printf("List is Empty!\n");
        return;
    }

    node* deleteNode;
    int val;
    if (head->next == head) { // if the list has only one node
        deleteNode = head;
        val = deleteNode->data;
        head = NULL; // now the list is empty
        free(deleteNode);
    } else {
        node* temp = head;

        while(temp->next->next != head) {
            temp = temp->next;
        }

        deleteNode = temp->next;
        val = deleteNode->data;
        temp->next = head;
        free(deleteNode);
    }

    printf("Deleted %d at end!\n", val);
}


void deleteAtRandom(int pos) {
    if (pos == 0) {
        deleteAtBeginning();
        return;
    }

    if (head == NULL) {
        printf("List is Empty!\n");
        return;
    }

    int val;
    node* deleteNode = head;
    if (head->next == head) {
        val = deleteNode->data; 
        head = NULL;
        free(deleteNode);
    } else {
        node* temp = head;
        for(int i=0; i < pos; i++) {
            temp = deleteNode;
            deleteNode = deleteNode->next;
            if(deleteNode == head) {
                printf("Oops! Invalid Position!\n");
                return;
            }
        }
        temp->next = deleteNode->next;
        val = deleteNode->data;
        free(deleteNode);
    }

    printf("Deleted %d at position %d!\n", val, pos);
}
// delete operations

void display() {
    if (head==NULL) {
        printf("List is Empty!\n");
        return;
    }

    node* temp;
    temp = head;

    printf("List contents:\t");
    while(temp->next != head) {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data); // printing the last data
}


int main() {
    int firstChoice, secondChoice, value, position;

    do {
        printf("1. Insert\t2. Delete\t3. Display\t4. Exit\n> ");
        scanf("%d", &firstChoice);

        switch(firstChoice) {
            // insert operations
            case 1:
                printf("1. At Beginning\t2. At Random\t3. At End\n> ");
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