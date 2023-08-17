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


int bubbleSort(int arr[], int size) {
    int step = 1;
    for (int i=0; i<size-1; i++) {
        for (int j=0; j<size-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
            printf("%d: ", step);
            displayArray(arr, size);
            step++;
        }
    }
}


int main() {
    int size = 7;
    int arr[size];

    getArray(arr, size);

    bubbleSort(arr, size);

    displayArray(arr, size);
    
    return 0;
}