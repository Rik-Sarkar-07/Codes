#include<iostream>
using namespace std;
void Print(int arr[],int size)
{
    cout<<"\t\nArray is ---- \n";
    for(int i=0;i<size;i++)
    cout<<arr[i]<<"\t";
    cout<<endl<<endl;
}
void Heapify(int arr[],int n,int i)
{
    int largest = i;        // current node
    int l = 2*i + 1;        // left child
    int r = 2*i + 2;        // right child

    if(l < n && arr[l] > arr[largest])
        largest = l;
    if(r < n && arr[r] > arr[largest])
        largest = r;
    if(largest != i)        // swap with largest value 
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        Heapify(arr,n,largest);
    }
}
void BuildHeap(int arr[],int n)
{
    for(int i=n/2 -1 ;i>=0;i--)     // call Heapify to organize the heap 
       Heapify(arr,n,i);
}
void HeapSort(int arr[],int n)
{
    BuildHeap(arr,n);
    for(int i=n-1;i>=0;i--)        
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        Heapify(arr,i,0);
    }
}
int main()
{
    int arr[] = {40,85,29,35,75,19,100};
    Print(arr,7);
    HeapSort(arr,7);
    Print(arr,7);
    return 0;
}
