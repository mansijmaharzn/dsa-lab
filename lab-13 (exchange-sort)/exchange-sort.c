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


void exchangeSort(int arr[], int size) {
    for (int i=0; i < (size-1); i++) {
        for (int j=i+1; j<size; j++) {
            if (arr[i] > arr[j]) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}


int main() {
    int size = 5;
    int arr[size];

    getArray(arr, size);

    exchangeSort(arr, size);

    displayArray(arr, size);

    return 0;
}