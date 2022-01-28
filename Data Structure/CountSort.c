#include<stdio.h>
#include<stdlib.h>
void Print(int arr[],int size)
{
    for(int i=0;i<size;i++)
    printf("\t%d",arr[i]);
    printf("\n\n");
}
int Max(int arr[],int size)
{
    int max = 0;
    for(int i=0;i<size;i++)
    {
        if(arr[i]>max)          // find the max element
        max = arr[i];
    }
    return max;
}
void CountSort(int arr[],int size)
{
    int max = Max(arr,size);        // find the maximum value
    int* count = (int*)malloc(sizeof(int)*(max+1));     // create the max+1 size array
    for(int i= 0;i<max+1;i++)
    count[i] = 0;               // initialize with 0 all elements of count array

    for(int k=0;k<size;k++)
    count[arr[k]] = count[arr[k]] + 1;      // arr array's value'th index of count is increment 0 --> 1
    int i=0,j=0;
    while(j<max+1)
    {
        if(count[j] > 0)            // if not zero the add the index value into arr array
        {
            arr[i] = j;             // put the non zero value'th index of count array in arr array as value
            i++;                    // arr array next position
            count[j]--;       // decrement the value
            continue;
        }
        else
        {
            j++;            // if count array is zero then move to next index
        }
    }

}
int main(int argc, char const *argv[])
{
    int arr[5] = {3,6,3,7,5};
    Print(arr,5);
    CountSort(arr,5);
    Print(arr,5);
    return 0;
}
