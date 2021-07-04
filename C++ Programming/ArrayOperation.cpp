#include<iostream>
using namespace std;

void ArrayPrint(int A[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        cout<<"\t"<<A[i];
    }
    cout<<endl;
}

void DeleteElement(int A[],int n,int ele)
{
    int i =0;
    for(i=0;i<n;i++)
    {
        if(ele==A[i])
        {
            continue;
        }
        else
        {
            cout<<"\t"<<A[i];
        }
    }
    cout<<endl;
}

void DeleteIndex(int A[],int n,int ind)
{
    int i = 0;
    for(i=0;i<n;i++)
    {
        if(ind==i)
        {
            continue;
        }
        else
        {
            cout<<"\t"<<A[i];
        }
    }
    cout<<endl;
}

void ArraySummation(int A[],int n)
{
    int sum = A[0];

    for(int i=1;i<n;i++)
    {
        sum = A[i] + sum;
    }
    cout<<"The Summation of All Elements in This Array = "<<sum<<"\n";
}

void ArrayMultiplication(int A[],int n)
{
    double mul = A[0];

    for(int i=1;i<n;i++)
    {
        mul = A[i] * mul;
    }
    cout<<"The Multiplication of All Elements in This Array = "<<mul<<"\n";
}

void MaxMinElement(int A[],int n)
{
    int i=0,j=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(A[j]>A[j+1])
            {
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
    cout<<"Max Element in this Array = "<<A[n-1]<<endl;
    cout<<"Min Element in this Array = "<<A[0]<<endl;
}
void BinarySearch(int A[],int n,int data)
{
    int max = n-1;
    int min = 0;

    while (max>=min)
    {
        int mid = (max+min)/2;
        if(A[mid] == data)
        {
            cout<<"The Position of "<<data<<" in Array is = "<<(mid+1)<<" \t Index = "<<mid<<endl;
            break;
        }
        else if(A[mid]>data)
        {
           max = mid-1;
        }
        else
        {
          min = mid+1;
        }

    }
}

void LinearSearch(int A[],int n,int data)
{
    int i =0;
    for(i=0;i<n;i++)
    {
        if(data==A[i])
        {
           cout<<"The Position of "<<data<<" in Array is = "<<(i+1)<<" \t Index = "<<i<<endl;
            break;
        }
    }
}

void BubbleSort(int A[],int n)
{
    int i=0,j=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(A[j]>A[j+1])
            {
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }

   ArrayPrint(A,n);
}

void SelectionSort(int A[],int n)
{
    int i,j,min;
    for(i=0;i<n-1;i++)
    {
        min = i;

        for(j=i+1;j<n;j++)
        {
            if(A[j]<A[min])
            {
                min = j;
            }
        }
        int temp = A[i];
        A[i] = A[min];
        A[min] = temp;
    }

    ArrayPrint(A,n);
}


void InsertionSort(int A[],int n)
{
    int i,j,k;

    for(i=1;i<n;i++)
    {
        j = i-1;    k = A[i];

        while (j>=0 && k<A[j] )
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = k;
    }

    ArrayPrint(A,n);
}

int main(int argc, char *argv[])
{
    int n;
    cout<<"Enter the Size of Array = ";
    cin>>n;
    int Array[n];
    cout<<"Enter Elements in this Array --\n";
    for(int i=0;i<n;i++)
    {
        cin>>Array[i];
    }
    cout<<"\n \t Your Entered Array is ---\n\n";
    ArrayPrint(Array,n);
    cout<<"\n";

    cout<<"\t After Sorting \n";
    InsertionSort(Array,n);

    
    cout<<"\n\n";
    return 0;
}
