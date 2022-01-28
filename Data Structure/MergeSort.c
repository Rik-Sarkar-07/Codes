#include<stdio.h>
#include<stdlib.h>
void Print(int arr[],int size)
{
    for(int i=0;i<size;i++)
    printf("\t%d",arr[i]);
    printf("\n");
}
void Merge(int arr[],int l,int mid,int r)
{
    int n1 = mid-l+1;       // define the size of left sub array
    int n2 = r-mid;         //define the size of right sub array

    int a[n1],b[n2];        // here a[] is left and b[] is right sub array
    for(int i=0;i<n1;i++)
    a[i] = arr[i+l];        // push values on left sub array
    for(int j=0;j<n2;j++)
    b[j] = arr[mid+1+j];    //push vlues on right sub array

    int i=0,j=0,k=l;
    while(i<n1 && j<n2)
    {
        if(a[i]<=b[j])      // compair both sub array index by index to find smallest number
        {
            arr[k] = a[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = b[j];
            k++;
            j++;
        }
    }
    while(i<n1)         // after compair a[] is not empty then pop out the elements
    {
        arr[k] = a[i];
        k++;
        i++;
    }
    while(j<n2)         // after compair b[] is not empty then pop out the elements
    {
        arr[k] = b[j];
        k++;
        j++;
    }
}
void MergeSort(int arr[],int l,int r)
{
    if(r > l)                         // if array elements are more than 1 then only run
    {
        int mid = (r+l)/2;
        MergeSort(arr,l,mid);           //divide left sub array and provide Merge sort
        MergeSort(arr,mid+1,r);         //divide right sub array and provide Merge sort
        Merge(arr,l,mid,r);             // Merge both sub array
    }
}
int main(int argc, char const *argv[])
{
    int arr[8] = {4,1,2,3,8,7,6,5};
    Print(arr,8);
    MergeSort(arr,0,7);
    Print(arr,8);
    return 0;
}
