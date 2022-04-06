#include<iostream>
using namespace std;
void Print(int arr[],int size)
{
    cout<<"The Array is ---- \n";
    for(int i=0;i<size;i++)
    cout<<"\t"<<arr[i];
    cout<<"\n\n";
}
void CountSort(int arr[],int size)
{
    int max = arr[0];
    for(int i=1;i<size;i++)
    if(arr[i]>max)
    max = arr[i];

    int count[max+1] = {0};

    for(int i=0;i<size;i++)
        count[arr[i]]++;
    
    for(int i=1;i<max;i++)
    count[i] = count[i] + count[i-1];

    int output[size];

    for(int i=size-1;i>=0;i--)
    output[--count[arr[i]]] = arr[i];

    for(int i=0;i<size;i++)
    arr[i] = output[i];
}
int main(int argc, char const *argv[])
{
    int arr[] = {7,4,1,8,5,2,1,6,3,0,10};
    Print(arr,11);
    CountSort(arr,11);
    Print(arr,11);
    return 0;
}
