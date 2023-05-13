#include <iostream>
using namespace std;
void printArray(int arr[], int size)
{
    if (size == 0)
        return;
    cout << "The Array is:- \n";
    for (int i = 0; i < size; i++)
        cout << arr[i] << "\t";
    cout << endl;
}
void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++)
            if (arr[j] < arr[min])
                min = j;
        if (min != i)
        {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}
void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int j = i - 1;
        int k = arr[i];
        while (j >= 0 && k < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = k;
    }
}
void shellSort(int arr[], int size)
{
    int m = size / 2;
    while (m > 0)
    {
        for (int i = m; i < size; i++)
        {
            for (int j = i - m; j >= 0; j--)
            {
                if (arr[j] < arr[j + m])
                {
                    int temp = arr[j];
                    arr[j] = arr[j + m];
                    arr[j + m] = temp;
                }
            }
        }
        m /= 2;
    }
}
void merge(int arr[], int l, int mid, int h)
{
    int n1 = mid - l + 1;
    int n2 = h - mid;
    int a[n1];
    int b[n2];

    for (int i = 0; i < n1; i++)
        a[i] = arr[l + i];

    for (int i = 0; i < n2; i++)
        b[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
            arr[k++] = a[i++];
        else
            arr[k++] = b[j++];
    }
    while (i < n1)
        arr[k++] = a[i++];
    while (j < n2)
        arr[k++] = b[j++];
}
void mergeSort(int arr[], int l, int h)
{
    if (l < h)
    {
        int mid = (l + h) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, h);
        merge(arr, l, mid, h);
    }
}
int pivotIndex(int arr[], int l, int h)
{
    int pivot = arr[l];
    int i = l;
    int j = h;
    int temp;
    while (i < j)
    {
        while (pivot >= arr[i])
            i++;
        while (pivot < arr[j])
            j--;
        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[j];
    arr[j] = arr[l];
    arr[l] = temp;
    return j;
}
void quickSort(int arr[], int l, int h)
{
    if (l < h)
    {
        int pi = pivotIndex(arr, l, h);
        quickSort(arr, l, pi - 1);
        quickSort(arr, pi + 1, h);
    }
}
void heapiy(int arr[], int size, int i)
{
    int large = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && arr[large] < arr[l])
        large = l;
    if (r < size && arr[large] < arr[r])
        large = r;
    if (large != i)
    {
        int temp = arr[i];
        arr[i] = arr[large];
        arr[large] = temp;
        heapiy(arr, size, large);
    }
}
void heapSort(int arr[], int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
        heapiy(arr, size, i);

    for (int i = size - 1; i >= 0; i--)
    {
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        heapiy(arr, i, 0);
    }
}
void countingSort(int arr[], int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }

    int *count = (int *)calloc(sizeof(int), (max + 1));

    for (int i = 0; i < size; i++)
        count[arr[i]]++;

    for (int i = 1; i < max + 1; i++)
        count[i] += count[i - 1];

    int output[size];

    for (int i = size - 1; i >= 0; i--)
        output[--count[arr[i]]] = arr[i];

    for (int i = 0; i < size; i++)
    {
        arr[i] = output[i];
    }
}
void cs(int arr[], int size, int pos)
{
    int count[10] = {0};
    for (int i = 0; i < 10; i++)
        count[(arr[i] / pos) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    int output[size];

    for (int i = size - 1; i >= 0; i--)
        output[--(count[(arr[i] / pos) % 10])] = arr[i];

    for (int i = 0; i < size; i++)
        arr[i] = output[i];
}
void radixSort(int arr[], int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
        if (max < arr[i])
            max = arr[i];

    for (int pos = 1; max / pos > 0; pos *= 10)
        cs(arr, size, pos);
}
int main(int argc, char const *argv[])
{
    int arr[] = {77, 54, 51, 8, 5, 2, 95, 96, 3, 50};
    radixSort(arr, 10);
    printArray(arr, 10);
    return 0;
}
