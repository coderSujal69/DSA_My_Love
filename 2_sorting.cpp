#include <iostream>
using namespace std;

void bubbleSort(int arr[], int size)
{
    int temp;
    for (int i = 0; i < size - 1; i++)
    {
        // printf("Working on pass number %d\n", i+1);
        bool isSorted = true;
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                isSorted = false;
            }
        }
        if (isSorted)
        {
            // cout<<"Further Array is Already Sorted"<<endl;
            return;
        }
    }
}
void insersationSort(int arr[], int size)
{
    int key, j;
    // Loop for passes
    for (int i = 1; i <= size - 1; i++)
    {
        key = arr[i];
        j = i - 1;
        // Loop for each pass
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void selectionSort(int arr[], int n)
{
    int indexOfMin, temp;
    cout << "Running Selection sort...\n"
         << endl;
    for (int i = 0; i < n - 1; i++)
    {
        indexOfMin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[indexOfMin])
            {
                indexOfMin = j;
            }
        }
        // Swap A[i] and A[indexOfMin]
        temp = arr[i];
        arr[i] = arr[indexOfMin];
        arr[indexOfMin] = temp;
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int down = low + 1;
    int up = high;
    while (down <= up)
    {
        while (arr[down] <= pivot)
        {
            down++;
        }

        while (arr[up] > pivot)
        {
            up--;
        }
        if (up > down)
        {
            int temp = arr[up];
            arr[up] = arr[down];
            arr[down] = temp;
        }
    }
    arr[low] = arr[up];
    arr[up] = pivot;

    return high;
}

void quickSort(int A[], int down, int up)
{
    int partitionIndex; // Index of pivot after partition

    if (down < up)
    {
        partitionIndex = partition(A, down, up);
        quickSort(A, down, partitionIndex - 1); // sort left subarray
        quickSort(A, partitionIndex + 1, up);   // sort right subarray
    }
}

void merge(int a[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;
    int b[high+1];
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            i++;
            k++;
        }
        else
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        b[k] = a[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        b[k] = a[j];
        j++;
        k++;
    }
    for (int i = low; i <= high; i++)
    {
        a[i] = b[i];
    }
}

void mergeSort(int a[], int low, int high)
{
    int mid;
    if (low < high)
    { 
        mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

void printArray(int a[], int size)
{
    cout << " Elements of Array" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << endl;
    }
}

int main()
{
    int size;
    cout << "Enter size of Array  ";
    cin >> size;
    int arr[size];
    cout<<"Enter elements of Array   "<<endl;

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    printArray(arr, size);
    // bubbleSort(arr, size);
    // insersationSort(arr,size);
    // selectionSort(arr,size);
    // quickSort(arr, 0, size);
    mergeSort(arr,0,size);
    printArray(arr, size);

    return 0;
}
