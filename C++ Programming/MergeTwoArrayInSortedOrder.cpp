#include<iostream>
using namespace std;
void Print(int arr[],int size)
{
    for(int i=0;i<size;i++)
    cout<<arr[i]<<"\t";
    cout<<endl;
}
void Sort(int arr[],int size)
{
    for(int i=0;i<size;i++)
    for(int j =0;j<size-i-1;j++)
    {
        if(arr[j] > arr[j+1])
        {
            int temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
        }
    }
}
int* Merge(int arr1[],int size1,int arr2[],int size2)
{
    int i=0,j=0;
   int *arr = (int*)malloc(sizeof(int)*(size1+size2));
Sort(arr1,size1);
Sort(arr2,size2);
int k = 0;
    while(i< size1 && j < size2)
    {
        if(arr1[i] <= arr2[j])
        {
            arr[k] = arr1[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = arr2[j];
            j++;
            k++;
        }
    }
    while(i < size1)
    {
        arr[k] = arr1[i];
            i++;
            k++;
    }
    while(j <size2)
    {
         arr[k] = arr2[j];
            j++;
            k++;
    }
    return (arr);

}
int main(int argc, char const *argv[])
{
    int arr1[5] = {10,20,30,05,1};
    int arr2[6] = {5,2,6,4,9,22};
    int *arr = (int*)malloc(sizeof(int)*(5+6));
    arr = Merge(arr1,5,arr2,6);
    Print(arr,(5+6));
    return 0;
}
