#include<iostream>
using namespace std;
void Print(int arr[],int size)
{
    for(int i=0;i<size;i++)
    cout<<arr[i]<<"\t";
    cout<<endl<<endl;
}
int GetMax(int arr[],int size)
{
    int max = arr[0];
    for(int i=1;i<size;i++)
    if(arr[i]>max)
    max = arr[i];
    return max;
}
void CountSort(int arr[],int size,int pos)
{
   int count[10] = {0};

    for(int i=0;i<size;i++)
      count[(arr[i]/pos)%10]++;

    for(int i=1;i<10;i++)
    count[i] = count[i] + count[i-1];  

    int output[size];

    for(int i=size-1;i>=0;i--)
    output[--count[(arr[i] / pos) % 10]] = arr[i];

    for(int i=0;i<size;i++)
    arr[i] = output[i];
}
void RadixSort(int arr[],int size)
{
    int max = GetMax(arr,size);
    for(int pos=1;max/pos>0;pos = pos*10)
    CountSort(arr,size,pos);
}
int main(int argc, char const *argv[])
{
    int arr[] = {7,4,1,8,5,2,9,6,3,0};
    Print(arr,10);
    RadixSort(arr,10);
    Print(arr,10);
    return 0;
}
