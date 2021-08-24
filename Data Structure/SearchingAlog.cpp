#include<iostream>
using namespace std;

void PrintArray(int* A,int size){
    for(int i= 0;i<size;i++)
    {
        cout<<"\t"<<A[i];
    }
    cout<<endl;
}
void LinearSearch(int A[],int size,int data)
{
    int i;
     bool flag = false;
    for(i=0;i<size;i++)
    {
        if(A[i] == data)
        {
            flag = true;
            cout<<"The Index is => "<<i<<"\t The Position is => "<<(i+1)<<endl;
            break;
        }
    }
    if(!flag)
    {
        cout<<data<<" Element is not present\n";
    }
}
void BinarySearch(int A[],int size,int data)
{
    int low = 0;
    int high = size-1;
    int mid = (low+high)/2;
    bool flag = false;

    while (low<high) {
        mid = (low+high)/2;
        if(data==A[mid])
        {
            flag = true;
            cout<<"The Index is => "<<mid<<"\t The Position is => "<<(mid+1)<<endl;
            break;
        }
        else if(A[mid]>data)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    if(!flag)
    {
        cout<<data<<" Element is not present\n";
    }
}



int BinarySearchRecursion(int A[],int low,int high,int data)
{
    int mid = (low+high)/2;

    if(A[mid]==data)
    {
        return mid;
    }
    else if (data>A[mid])
    {
        return (BinarySearchRecursion(A,mid+1,high,data));
    }
    else
    {
         return (BinarySearchRecursion(A,low,mid-1,data));
    }
}


int main(int argc, char *argv[])
{
    int size = 10;

    int Array[] = {1,2,3,4,5,6,7,8,9,10};  //Binary Search applicable only sorted array....

    PrintArray(Array,size);
    cout<<"The index of 3 => "<<BinarySearchRecursion(Array,0,size-1,3)<<endl;
    LinearSearch(Array,size,6);


    return 0;
}
