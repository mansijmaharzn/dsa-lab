#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100


struct List {
    int arr[MAX_SIZE];
    int size; // stores the number of current element(s) stored
};


typedef struct List list;


void initialize(list *list) {
    list->size = 0;
}


void insert(list *list, int value) {
    if (list->size < MAX_SIZE) {
        list->arr[list->size] = value;
        list->size++;
        printf("%d inserted successfully.\n", value);
    } else {
        printf("Oops! List is full\n");
    }
}


void deleteAtIndex(list *list, int index) {
    if (index >= 0 && index < list->size) { // should be between 0 - number of elements in the array

        /*
        updating the list from the index specified
        bringing the elements after the specified index, one step forward
        [1, 2, 3, 4, 5]
        if we delete the 2nd index, it changed to
        [1, 2, 4, 5]
        */
        for (int i = index; i < list->size - 1; i++) {
            list->arr[i] = list->arr[i + 1];
        }

        list->size--; // updating the new size of the array
        printf("Element at index %d deleted successfully.\n", index);
    } else {
        printf("Invalid index!\n");
    }
}


void display(list *list) {
    printf("List: ");
    for (int i = 0; i < list->size; i++) {
        printf("%d\t", list->arr[i]);
    }
    printf("\n");
}


int main() {
    list myList;
    initialize(&myList);

    int choice, value, index;

    do {
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insert(&myList, value);
                break;
            case 2:
                printf("Enter the index to delete: ");
                scanf("%d", &index);
                deleteAtIndex(&myList, index);
                break;
            case 3:
                display(&myList);
                break;
            case 4:
                printf("GoodBye!\n");
            default:
                printf("Invalid choice\n");
        }
    } while(choice != 4);

    return 0;
}
