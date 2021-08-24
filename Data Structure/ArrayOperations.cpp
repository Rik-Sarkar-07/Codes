#include<iostream>
using namespace std;
void ArrayTraversal(int* A,int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<"\t"<<A[i];
    }
    cout<<endl;
}
void ArrayDeletion(int* A,int size,int index)
{
    size = size-1;
    for(int i=index;i<size;i++)
    {
        A[i] = A[i+1];
    }
    cout<<"After Delete the "<<index<<"th Element"<<endl;
    ArrayTraversal(A,size);
}
void MaxNumberInArray(int A[],int size)
{
    int max = A[0];


    for(int i=1;i<size;i++)
    {
        if(max<A[i])
        {
            max = A[i];
        }
    }
    cout<<"Maximum Number is => "<<max<<endl;
}
void MinNumberInArray(int A[],int size)
{
    int min = A[0];
    for(int i=1;i<size;i++)
    {
        if(min>A[i])
        {
            min = A[i];
        }
    }
    cout<<"Minimum Number is => "<<min<<endl;
}
void ArraySum(int A[],int size)
{
    int sum = A[0];
    for(int i=1;i<size;i++)
    {
        sum = A[i] + sum;
    }
    cout<<"Summation result is => "<<sum<<endl;
}
void ArrayProduct(int A[],int size)
{
    int mul = A[0];
    for(int i=1;i<size;i++)
    {
        mul = A[i] * mul;
    }
    cout<<"Product result is => "<<mul<<endl;
}
void PrintArray(int* A,int size){
    for(int i= 0;i<size;i++)
    {
        cout<<"\t"<<A[i];
    }
    cout<<endl;
}
void BubbleSort(int* A,int size){
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size-i-1;j++)
        {
            if(A[j]>A[j+1])
            {
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
    cout<<"After Bubble Sort\n";
    PrintArray(A,size);
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
int main(int argc, char *argv[])
{
    int Array[10] = {10,8,6,1,2,3,4,5,9,7};
    int size = 10;
    ArrayTraversal(Array,size);
    ArrayDeletion(Array,size,4);
    MaxNumberInArray(Array,size);
    MinNumberInArray(Array,size);
    ArraySum(Array,size);
    ArrayProduct(Array,size);
    LinearSearch(Array,size,3);
    BubbleSort(Array,size);
    return 0;
}
