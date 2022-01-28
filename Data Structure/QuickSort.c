#include <stdio.h>
#include <stdlib.h>
void Print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("\t%d", arr[i]);
    printf("\n");
}
int Partition(int arr[], int low, int high)
{
    int pivot = arr[low];                // pivot position
    int i = low;
    int j = high;
    int temp;
    while (i < j)
    {
        while (pivot >= arr[i])         // find bigger then pivot,if find then stop loop     ------>>>>
            i++;
        while (pivot < arr[j])          // find lesser then pivot,if find then stop loop     <<<<-------
            j--;
        if (i < j)                      // if i is left side and j is right side then only swap
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } 

    // swap pivot and arr[j] to get pivot's original position

    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}
void QuickSort(int arr[], int low, int high)
{
    int partitionIndex;
    if(low < high)      // if array elements are more than 1 then only run
    {
        partitionIndex = Partition(arr,low,high);       // partition index should be currect position
        QuickSort(arr,low,partitionIndex-1);            // apply quick sort on left sub array
        QuickSort(arr,partitionIndex+1,high);           // apply quick sort on right sub array
    }
}
int main(int argc, char const *argv[])
{
    int arr[8] = {2,1,5,3,4,8,6,7};
    Print(arr,8);
    QuickSort(arr,0,7);
    Print(arr,8);
    return 0;
}
