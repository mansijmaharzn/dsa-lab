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


void insertionSort(int arr[], int size) {
    for (int i=1; i<size; i++) {
        int key = arr[i];
        int j = i - 1;

        while (key < arr[j] && j >= 0) {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
    }
}


int main() {
    int size = 5;
    int arr[size];

    getArray(arr, size);

    insertionSort(arr, size);

    displayArray(arr, size);

    return 0;
}