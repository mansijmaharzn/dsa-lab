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


void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}


void heapSort(int arr[], int n) {
    for (int i=n/2-1; i>=0; i--)
        heapify(arr, n, i);

    for (int i=n-1; i>=0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int arr[5];

    getArray(arr, 5);

    heapSort(arr, 5);

    displayArray(arr, 5);
    
    return 0;
}