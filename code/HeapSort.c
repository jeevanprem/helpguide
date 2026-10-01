/*
9. Heap Sort
🧠 Core concept

Heap Sort uses a Max Heap for ascending order.

Remember:

BUILD MAX HEAP
       ↓
Swap root with last
       ↓
Reduce heap size
       ↓
Heapify
       ↓
Repeat
Max Heap property
Parent >= children

For array index i:

left  = 2*i + 1
right = 2*i + 2
⭐ Most important heapify code
largest = i;

if (left < n && arr[left] > arr[largest])
    largest = left;

if (right < n && arr[right] > arr[largest])
    largest = right;

if (largest != i) {
    swap(arr[i], arr[largest]);
    heapify(arr, n, largest);
}*/
#include <stdio.h>

void swap(int *a, int *b) {
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

    // Build Max Heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements
    for (int i = n - 1; i > 0; i--) {

        swap(&arr[0], &arr[i]);

        heapify(arr, i, 0);
    }
}

int main() {

    int n;

    printf("Enter size: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    heapSort(arr, n);

    printf("Sorted array:\n");

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}

/*
Enter size: 6
Enter elements:
12 11 13 5 6 7

Sorted array:
5 6 7 11 12 13
*/