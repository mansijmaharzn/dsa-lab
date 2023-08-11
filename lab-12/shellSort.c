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


void shellSort(int arr[], int size) {
    for (int h=size/2; h>=1; h=h/2) {
        for (int j=h; j<size; j++) {
            for (int i=j-h; i>=0; i=i-h) {
                if (arr[i+h] > arr[i]) {
                    break;
                } else {
                    swap(&arr[i+h], &arr[i]);
                }
            }
        }
    }
}


int main() {
    int arr[5];

    getArray(arr, 5);

    shellSort(arr, 5);

    displayArray(arr, 5);

    return 0;
}