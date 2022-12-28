#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}

void sort(int arr[], int size)
{
    int temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {

            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int binarySearch(int arr[], int size, int key)
{
    sort(arr, size);
    int sp = 0;
    int ep = size - 1;
    while (sp < ep)
    {
        int mid = (sp + ep) / 2;
        if (key == arr[mid])
        {
            return mid;
        }
        else if (key < arr[mid])
        {
            ep = mid - 1;
        }
        else
        {
            sp = mid + 1;
        }
    }
    return -1;
}
void printdata(int arr[], int size)
{
    cout << "Elements are" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
}
int main()
{
    int size;
    cout << "Enter Size  " << endl;
    cin >> size;
    int arr[size];
    cout << "Enter elements" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    // printdata(arr, size);
    int key;
    cout << "Enter number to search in the array" << endl;
    cin >> key;
    cout << " Element " << key << " found on " << linearSearch(arr, size, key) << "th index";
    // cout <<" Element "<< key<<" found on "<< binarySearch(arr, size, key) <<"th index";
    return 0;
}