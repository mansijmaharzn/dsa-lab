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


int linearSearch(int arr[], int n, int key) {
    for (int i=0; i<n; i++) {
        if (arr[i] == key)
            return i;
    }

    return -1;
}


int main() {
    int size = 5;
    int arr[size], key;

    getArray(arr, size);
    displayArray(arr, size);

    printf("Enter the key to search: ");
    scanf("%d", &key);

    int index = linearSearch(arr, size, key);

    if (index != -1)
        printf("%d is in %d index of the array.\n", key, index);
    
    else
        printf("%d is in not in the array.\n", key);

    return 0;
}