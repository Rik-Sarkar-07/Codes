#include <iostream>
using namespace std;
void Print(int *arr, int size)
{
    int i = 0;
    cout << "The Array is --- \n";
    for (i = 0; i < size; i++)
        cout << arr[i] << "\t";
    cout << endl
         << endl;
}
void SelectionSort(int *arr, int size)
{
    int i, j, min, temp;
    for (i = 0; i < size - 1; i++)
    {
        min = i;
        for (j = i + 1; j < size; j++)
            if (arr[min] > arr[j])
                min = j;
        if (arr[min] != arr[i])
        {
            temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}
int main(int argc, char const *argv[])
{
    int size = 10;
    int arr[size] = {1,56,23,12,5,67,321,567,53,20,37};
    Print(arr,size);
    cout<<"After the Selection sort \n";
    SelectionSort(arr,size);
    Print(arr,size);
    return 0;
}
