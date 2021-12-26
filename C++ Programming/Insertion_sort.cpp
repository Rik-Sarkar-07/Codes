#include <iostream>
using namespace std;
void Print(int *arr, int size)
{
    int i = 0;
    cout << "The Array is --- \n";
    for (i = 0; i < size; i++)
        cout << arr[i] << "\t";
    cout << endl<< endl;
}
void Insertionsort(int* arr,int size)
{
    int i,j,k,temp;
    for(i=1;i<size;i++)
    {
        j = i-1; k = arr[i];
        while(j >= 0 && k < arr[j])
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = k;
    }
}
int main(int argc, char const *argv[])
{
     int size = 10;
    int arr[size] = {1,56,23,12,5,67,321,567,53,20,37};
    Print(arr,size);
    cout<<"After the Selection sort \n";
    Insertionsort(arr,size);
    Print(arr,size);
    return 0;
}
