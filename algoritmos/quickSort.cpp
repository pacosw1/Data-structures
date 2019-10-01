#include <iostream>
using namespace std;
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/* This function takes last element as pivot, places  
the pivot element at its correct position in sorted  
array, and places all smaller (smaller than pivot)  
to left of pivot and all greater elements to right  
of pivot */
int partition(int arr[], int low, int high)
{
    int leftPivot = arr[low];
    int rightPivot = arr[high]; // pivot

    if (leftPivot > rightPivot)
    {
        swap(&arr[low], &arr[high]);
        leftPivot = arr[low];
        rightPivot = arr[high];
    }
    else if (leftPivot == rightPivot)
    {
        while (leftPivot == rightPivot && low < high)
            ;
    }
    int i = (low - 1); // Index of smaller element
    int low = low + 1;
    int left = low + 1;
    int right = high - 1;
    while (low <= right)
    {
        if (arr[low] < leftPivot)
        {
        }
        else if (arr[low] > rightPivot)
        {
        }
        else
        {
            low++;
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort  
arr[] --> Array to be sorted,  
low --> Starting index,  
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now  
        at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition

        sort(input, lowIndex, lt - 1);
        sort(input, lt + 1, gt - 1);
        sort(input, gt + 1, highIndex);
    }
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver Code
int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}
