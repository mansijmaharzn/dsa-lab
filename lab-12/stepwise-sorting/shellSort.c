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
    int step = 1;
    for (int h=size/2; h>=1; h=h/2) {
        for (int j=h; j<size; j++) {
            for (int i=j-h; i>=0; i=i-h) {
                if (arr[i+h] > arr[i]) {
                    break;
                } else {
                    swap(&arr[i+h], &arr[i]);
                }
                printf("%d: ", step);
                displayArray(arr, size);
                step++;
            }
        }
    }
}


int main() {
    int size = 7;

    int arr[size];

    getArray(arr, size);

    shellSort(arr, size);

    displayArray(arr, size);

    return 0;
}