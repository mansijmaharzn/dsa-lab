#include<stdio.h>


// common functions
void getArray(int arr[], int size) {
    printf("Enter values for array:\n");
    for (int i=0; i<size; i++) {
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
}


void displayArray(int arr[], int size) {
    printf("Array: ");
    for (int i=0; i<size; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}


void cloneArray(int arr1[], int arr2[], int size) {
    for (int i=0; i<size; i++) {
        arr1[i] = arr2[i];
    }
}
// common functions


// linear search
int linearSearch(int arr[], int n, int key) {
    for (int i=0; i<n; i++) {
        if (arr[i] == key)
            return i;
    }

    return -1;
}
// linear search


// binary search
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


int bubbleSort(int arr[], int size) {
    for (int i=0; i<size-1; i++) {
        for (int j=0; j<size-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}


int binarySearch(int arr[], int key, int low, int high) {
    while( low <= high ) {
        int mid = low + (high - low) / 2;
        if (key == arr[mid])
            return mid;
        else if (key < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}
// binary search


int main() {
    int size = 5, choice, key, index;
    int mainArray[size], tempArray[size];

    getArray(mainArray, size);

    do {
        printf("\nEntered Array:\n");
        displayArray(mainArray, size);
        cloneArray(tempArray, mainArray, size);
        
        printf("Enter the key to search: ");
        scanf("%d", &key);
        
        printf("Enter your prefered searching algorithm:\n");
        printf("1. Linear Search\t2. Binary Search\t3. Exit\n> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                index = linearSearch(tempArray, size, key);
                if (index != -1)
                    printf("%d is in %d index of the array.\n", key, index);
                
                else
                    printf("%d is in not in the array.\n", key);
                break;
            case 2:
                printf("Sorting the entered array...\n");
                bubbleSort(tempArray, size);
                displayArray(tempArray, size);

                index = binarySearch(tempArray, key, 0, size-1);

                if (index != -1)
                    printf("%d is in %d index of the array.\n", key, index);
                
                else
                    printf("%d is in not in the array.\n", key);
                break;
            case 3:
                printf("GoodBye!");
                break;
            default:
                printf("Invalid Input!");
                break;
        }
    } while(choice != 3);

    return 0;
}