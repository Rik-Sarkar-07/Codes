#include<iostream>
using namespace std;

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
void SelectionSort(int* A,int size)
{
    int i,j,temp,min;
    for(i=0;i<size-1;i++)
    {
        min = i;
        for(j=i+1;j<size;j++)
        {
            if(A[j]<A[min])
                min = j;
        }

        if(i != min){
        temp = A[min];
        A[min] = A[i];
        A[i] = temp;
        }
    }
    cout<<"After Selection Sort\n";
    PrintArray(A,size);
}
void InsertionSort(int* A,int size)
{
    int i,j,k;
    for(i=1;i<size;i++)
    {
        j = i-1;    k = A[i];
        while (j>=0 && k<A[j]) {
            A[j+1] = A[j];
            j--;
           }
        A[j+1] = k;
    }
    cout<<"After Insertion Sort \n";
    PrintArray(A,size);
}
void ShellSort(int* A,int size)
{
    int i,j,temp,  m = size/2;
    while (m>0) {
        for(j=m;j<size;j++)
        {
            for(i=j-m;i>=0;i--)
            {
                if(A[i]>A[i+m])
                {
                    temp = A[i];
                    A[i] = A[m+i];
                    A[m+i] = temp;
                }
                else {
                    break;
                }
            }
        }
         m = m /2;
    }
    cout<<"After Shell Sort\n";
    PrintArray(A,size);
}
int main(int argc, char *argv[])
{
    int size = 10;

    int Array[] = {1,4,2,3,5,7,6,9,8,0};  // size = 10

    PrintArray(Array,size);
    ShellSort(Array,size);

    return 0;
}
