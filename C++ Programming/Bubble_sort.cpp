#include<iostream>
using namespace std;
void Print(int* arr,int size)
{
    int i=0;
    cout<<"The array is ---- \n";
    for(i=0;i<size;i++)
    cout<<arr[i]<<"\t";
    cout<<endl<<endl;
}
void Boublesort(int* arr,int size)
{
    int i,j,temp;
    for(i=0;i<size;i++)
    {
        for(j=0;j<size-1-i;j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    int size = 10;
    int arr[size] = {1,56,23,12,5,67,321,567,53,20,37};
    Print(arr,size);
    cout<<"After the Selection sort \n";
    Boublesort(arr,size);
    Print(arr,size);
    return 0;
}
