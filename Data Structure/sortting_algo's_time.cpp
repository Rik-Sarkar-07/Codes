#include <iostream>
#include<time.h>
#include<bits/stdc++.h>
using namespace std;
int swap_count_bubble = 0;
int swap_count_insertion = 0;
int swap_count_selection = 0;
int swap_count_shell = 0;
int no_of_condition_check_bubble = 0;
int no_of_condition_check_insertion = 0;
int no_of_condition_check_selection = 0;
int no_of_condition_check_shell = 0;
void PrintArray(int arr[], int size)
{
    cout << "The Array is --- \n";
    for (int i = 0; i < size; i++)
        cout << "\t" << arr[i];
    cout << endl
         << endl;
}
void BubbleSort(int arr[], int size)
{
    int i, j, temp;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swap_count_bubble++;
                no_of_condition_check_bubble++;
            }
        }
    }
}
void SelectionSort(int arr[], int size)
{
    int i, j, min, temp;
    for (i = 0; i < size - 1; i++)
    {
        min = i;
        for (j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min])
            {
                 min = j;
                 no_of_condition_check_selection++;
            }
               
        }
        if (arr[min] != arr[i])
        {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
            swap_count_selection++;
            no_of_condition_check_selection++;
        }
    }
}
void InsertionSort(int arr[],int size)
{
    int i,j,key;
    for(i=1;i<size;i++)
    {
        j = i-1;    key = arr[i];
        while(j>=0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
            swap_count_insertion++;
            no_of_condition_check_insertion++;
        }
        arr[j+1] = key;
    }
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
                    swap_count_shell++;
                    no_of_condition_check_shell++;
                }
                else {
                    break;
                }
            }
        }
         m = m /2;
    }
}
int main(int argc, char const *argv[])
{
    int size = 0;
    cout << "Enter the size of array = ";
    cin >> size;
    int *arr = (int *)malloc(sizeof(int) * size);
     int *arr1 = (int *)malloc(sizeof(int) * size);
      int *arr2 = (int *)malloc(sizeof(int) * size);
      int *arr3 = (int *)malloc(sizeof(int) * size);
     srand(time(0));
    for(int i = 0; i<size; i++)
    {
        arr[i] = rand() % size;
        arr1[i] = rand() % size;
        arr2[i] = rand() % size;
        arr3[i] = rand() % size;
    }
       
    // PrintArray(arr, size);
    // cout << "After sorting \n";

    clock_t start_time = clock();
    InsertionSort(arr, size);
   // PrintArray(arr, size);
    clock_t end_time1 = clock();
    clock_t result = end_time1 - start_time;
	cout<<"The time taken by Insertion sort = "<<result<<" milliseconds"<<endl;
    cout << "The Number of Swap = " << swap_count_insertion << endl << endl;
    cout << "The Number of Condition Check = " << no_of_condition_check_insertion << endl << endl;


    clock_t start_time2 = clock();
    BubbleSort(arr1, size);
   // PrintArray(arr, size);
    clock_t end_time12 = clock();
    clock_t result2 = end_time12 - start_time2;
	cout<<"The time taken by Bubble sort = "<<result2<<" milliseconds"<<endl;
    cout << "The Number of Swap = " << swap_count_bubble << endl << endl;
    cout << "The Number of Condition Check = " << no_of_condition_check_bubble << endl << endl;

    clock_t start_time3 = clock();
    SelectionSort(arr2, size);
   // PrintArray(arr, size);
    clock_t end_time13 = clock();
    clock_t result3 = end_time13 - start_time3;
	cout<<"The time taken by Selection sort = "<<result3<<" milliseconds"<<endl;
    cout << "The Number of Swap = " << swap_count_selection << endl << endl;
    cout << "The Number of Condition Check = " << no_of_condition_check_selection << endl << endl;


clock_t start_time4 = clock();
    ShellSort(arr3, size);
   // PrintArray(arr, size);
    clock_t end_time14 = clock();
    clock_t result4 = end_time14 - start_time4;
	cout<<"The time taken by Shell sort = "<<result3<<" milliseconds"<<endl;
    cout << "The Number of Swap = " << swap_count_shell << endl << endl;
    cout << "The Number of Condition Check = " << no_of_condition_check_shell<< endl << endl;
    return 0;
}
