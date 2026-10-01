/*
⭐ Step 1 — QuickSort function

This is the main structure:

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);

        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}
Remember:
p = final position of pivot

Then:

left  = low → p-1
right = p+1 → high
⭐ Step 2 — Partition

We'll use the last element as pivot.

int pivot = arr[high];
int i = low - 1;

Then j scans the array.

for (int j = low; j < high; j++)

If the element is smaller than pivot:

if (arr[j] < pivot)
{
    i++;
    swap(arr[i], arr[j]);
}

Finally, put pivot in its correct position.
*/

#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    // Choose last element as pivot
    int pivot = arr[high];

    // Index of smaller element
    int i = low - 1;

    // Traverse the array
    for (int j = low; j < high; j++)
    {
        // If current element is smaller than pivot
        if (arr[j] < pivot)
        {
            i++;

            swap(&arr[i], &arr[j]);
        }
    }

    // Put pivot at correct position
    swap(&arr[i + 1], &arr[high]);

    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        // Find pivot position
        int p = partition(arr, low, high);

        // Sort left side
        quickSort(arr, low, p - 1);

        // Sort right side
        quickSort(arr, p + 1, high);
    }
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // QuickSort
    quickSort(arr, 0, n - 1);

    printf("Sorted array: ");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
/*

Example

Input:

Enter number of elements: 6
Enter elements:
10 7 8 9 1 5

Output:

Sorted array: 1 5 7 8 9 10


🧠 QuickSort — Parts that take time to remember
1. Pivot
int pivot = arr[high];

Remember:

Last element = pivot

2. i = low - 1 ⭐⭐⭐
int i = low - 1;

i keeps track of the boundary of elements smaller than the pivot.

3. j loop
for (int j = low; j < high; j++)

Remember:

j scans; i maintains the smaller-element boundary.

4. Condition
if (arr[j] < pivot)

If current element is smaller than pivot → move it to the left.

5. Final pivot swap ⭐⭐⭐⭐
swap(&arr[i + 1], &arr[high]);

This puts the pivot in its correct final position.

6. Recursive calls ⭐⭐⭐⭐
quickSort(arr, low, p - 1);
quickSort(arr, p + 1, high);

This is the heart of QuickSort.

🔥 Quick Revision Sheet
DFS
DFS(v)
 ↓
Print v
 ↓
visited[v] = 1
 ↓
Check every neighbour
 ↓
If connected + unvisited
 ↓
DFS(neighbour)
Code skeleton:
void DFS(int v, int n)
{
    printf("%d ", v);
    visited[v] = 1;

    for (int i = 0; i < n; i++)
    {
        if (graph[v][i] == 1 && visited[i] == 0)
        {
            DFS(i, n);
        }
    }
}
QuickSort
Choose Pivot
 ↓
Partition
 ↓
Get pivot position p
 ↓
Sort left
 ↓
Sort right
Code skeleton:
int p = partition(arr, low, high);

quickSort(arr, low, p - 1);
quickSort(arr, p + 1, high);
Partition skeleton:
int pivot = arr[high];
int i = low - 1;

for (int j = low; j < high; j++)
{
    if (arr[j] < pivot)
    {
        i++;
        swap(&arr[i], &arr[j]);
    }
}

swap(&arr[i + 1], &arr[high]);

return i + 1;*/