#include<stdio.h>


// common functions
void getArray(int arr[], int size) {
    printf("Enter values for array:\n");
    for (int i=0; i<size; i++) {
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
}


void cloneArray(int arr1[], int arr2[], int size) {
    for (int i=0; i<size; i++) {
        arr1[i] = arr2[i];
    }
}


void displayArray(int arr[], int size) {
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
// common functions


// selection sort
void selectionSort(int arr[], int size) {
    for (int i=0; i < size-1; i++) {
        int min = i;
        for (int j = i+1; j < size; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(&arr[min], &arr[i]);
    }
}
// selection sort


// insertion sort
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
// insertion sort


// exchange sort
void exchangeSort(int arr[], int size) {
    for (int i=0; i < (size-1); i++) {
        for (int j=i+1; j<size; j++) {
            if (arr[i] > arr[j]) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}
// exchange sort


// bubble sort
int bubbleSort(int arr[], int size) {
    for (int i=0; i<size-1; i++) {
        for (int j=0; j<size-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}
// bubble sort


// shell sort
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
// shell sort


// merge sort
void merge(int arr[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1], R[n2];

    for (int i=0; i<n1; i++)
        L[i] = arr[p+i];

    for (int j=0; j<n2; j++)
        R[j] = arr[q+1+j];

    int i=0, j=0, k=p;

    while(i<n1 && j<n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i<n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j<n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r-l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}
// merge sort


// heap sort
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
// heap sort


// quick sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i+1], &arr[high]);
    return i+1;
}


void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}
// quick sort


int main() {
    int size = 5, choice;
    int mainArray[size], tempArray[size];

    getArray(mainArray, size);

    do {
        printf("\nEntered Array: ");
        displayArray(mainArray, size);
        cloneArray(tempArray, mainArray, size);
        printf("Enter your prefered sorting algorithm:\n");
        printf("1. Selection Sort\t2. Insertion Sort\t3. Exchange Sort\n4. Bubble Sort\t5. Shell Sort\t6. Merge Sort\n7. Heap Sort\t8. Quick Sort\t9. Exit\n> ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                selectionSort(tempArray, size);
                displayArray(tempArray, size);
                break;

            case 2:
                insertionSort(tempArray, size);
                displayArray(tempArray, size);
                break;

            case 3:
                exchangeSort(tempArray, size);
                displayArray(tempArray, size);
                break;

            case 4:
                bubbleSort(tempArray, size);
                displayArray(tempArray, size);
                break;

            case 5:
                shellSort(tempArray, size);
                displayArray(tempArray, size);
                break;

            case 6:
                mergeSort(tempArray, 0, size-1); // arr[], L, R
                displayArray(tempArray, size);
                break;

            case 7:
                heapSort(tempArray, size);
                displayArray(tempArray, size);
                break;

            case 8:
                quickSort(tempArray, 0, size-1); // arr[], low, high
                displayArray(tempArray, size);
                break;

            case 9:
                printf("GoodBye!\n");
                break;

            default:
                printf("Invalid Input!\n");
                break;
        }
    } while(choice != 9);

    return 0;
}