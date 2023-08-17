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


void selectionSort(int arr[], int size) {
    int step = 1;
    for (int i=0; i < size-1; i++) {
        int min = i;
        for (int j = i+1; j < size; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(&arr[min], &arr[i]);
        printf("%d: ", step);
        displayArray(arr, size);
        step++;
    }
}


int main() {
    int size = 7;
    int arr[size];

    getArray(arr, size);

    selectionSort(arr, size);

    displayArray(arr, size);

    return 0;
}