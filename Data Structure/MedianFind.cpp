#include<iostream>
using namespace std;
void MedianFinding(int arr[],int size)
{
    int n = size;
    
    if(n % 2 == 0)              \\ if size is even then it means median will be two ....
    {
        int mid1 = arr[size/2 -1];
        int mid2 = arr[size/2];
        cout<<"The Medians are = "<<mid1<<"\t And \t"<<mid2<<endl;
    }
    else                           \\ if size is odd then it means median is uniqe .....
    cout<<"The Median is = "<<arr[size/2];
}
int PartitionIndex(int arr[],int l,int h)
{
    int pivot = arr[l];
    int i = l;
    int j = h;
    int temp;
    while(i < j)
    {
        while(pivot >= arr[i]) i++;
        while(pivot < arr[j]) j--;
        if(i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[l];
    arr[l] = arr[j];
    arr[j] = temp;
    return j;
}
void QuickSort(int arr[],int l,int h)
{
    int pi;
    if(l < h)
    {
        pi = PartitionIndex(arr,l,h);
        QuickSort(arr,l,pi-1);
        QuickSort(arr,pi+1,h);
    }
}
int RandomizedSelection(int arr[],int l,int h,int i)
{
    if(l == h)  return arr[l];              // if one element then returns that value
    int r = PartitionIndex(arr,l,h);        // find the perfact index value ...
    int k = r+1-l;                          // Rank the array ...
    if(k == i)  return arr[r];              // if the rank is equal to index then our index is return ...
    else if(k < i) return (RandomizedSelection(arr,r+1,h,i-k));     // search in right subarray
    else
    return (RandomizedSelection(arr,l,r-1,i));          // search in left aub array...
}
void PrintArray(int arr[],int size)
{
    for(int i=0;i<size;i++)
    cout<<"\t"<<arr[i];
    cout<<endl<<endl;
}
int main(int argc, char const *argv[])
{
    int arr[] = {1,20,3,4,50,60,7,80,9,10};
    QuickSort(arr,0,9);
    PrintArray(arr,10);

    MedianFinding(arr,10);
    cout<<"4th Index Element is = "<<RandomizedSelection(arr,0,9,4)<<endl;
    return 0;
}
