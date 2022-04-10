#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void ReverseArray(int arr[],int l,int h)
{
    while(l<h)
    {
        int temp = arr[l];
        arr[l] = arr[h];
        arr[h] = temp;
        l++;
        h--;
    }
}
void Reverse(int arr[],int l,int h)
{
    if(l<h)
    {
        int temp = arr[l];
        arr[l] = arr[h];
        arr[h] = temp;
        Reverse(arr,l+1,h-1);
    }
}
void Print(int arr[],int size)
{
    for(int i=0;i<size;i++)
    cout<<arr[i]<<"\t";
    cout<<endl;
}
int main(int argc, char const *argv[])
{
    int arr[] = {7,4,1,8,5,2,9,6,3,0};
    Print(arr,10);
    Reverse(arr,0,9);
    Print(arr,10);
    return 0;
}
