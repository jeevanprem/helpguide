/*
🧠 Core concept

Merge Sort =

DIVIDE → SORT → MERGE

Example:

[38 12 27 43]

       ↓ divide

[38 12] [27 43]

       ↓ divide

[38] [12] [27] [43]

       ↓ merge

[12 38] [27 43]

       ↓

[12 27 38 43]
Algorithm
mergeSort(array, left, right)

if left < right:
    mid = (left + right)/2

    mergeSort(left half)
    mergeSort(right half)

    merge()
⭐ Difficult code to remember
while (i <= mid && j <= right) {
    if (arr[i] < arr[j])
        temp[k++] = arr[i++];
    else
        temp[k++] = arr[j++];
}

Then copy remaining elements.
*/

#include <stdio.h>

void merge(int arr[], int left, int mid, int right) {

    int i = left;
    int j = mid + 1;
    int k = 0;

    int temp[right - left + 1];

    while (i <= mid && j <= right) {

        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left, k = 0; i <= right; i++, k++)
        arr[i] = temp[k];
}

void mergeSort(int arr[], int left, int right) {

    if (left < right) {

        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);

        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
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

    mergeSort(arr, 0, n - 1);

    printf("Sorted array:\n");

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}

/*
Enter size: 6
Enter elements:
38 27 43 3 9 82

Sorted array:
3 9 27 38 43 82
*/