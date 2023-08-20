#include<stdio.h>


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


void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


// using bubbleSort to sort the array before using binarySearch
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


int main() {
    int size = 5;
    int arr[size], key;

    getArray(arr, size);

    printf("Sorting the entered array...\n");
    bubbleSort(arr, size);
    displayArray(arr, size);

    printf("Enter the key to search: ");
    scanf("%d", &key);

    int index = binarySearch(arr, key, 0, size-1);

    if (index != -1)
        printf("%d is in %d index of the array.\n", key, index);
    
    else
        printf("%d is in not in the array.\n", key);

    return 0;
}