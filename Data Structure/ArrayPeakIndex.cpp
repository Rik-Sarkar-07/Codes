#include<iostream>
using namespace std;
int PeakIndex(int arr[],int l,int h)
{
    int mid = (l+h)/2;
    if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1])
    return mid;
    else if(arr[mid] < arr[mid-1])
    return (PeakIndex(arr,l,mid-1));
    return(PeakIndex(arr,mid+1,h));

}
int main(int argc, char const *argv[])
{
    int arr[] = {2,3,4,21,43,52,18,11,9,6,5,1};
    cout<<"Peak Index = "<<PeakIndex(arr,0,11)<<endl;

    int a[] = {8,9,3};
    cout<<"Peak Index = "<<PeakIndex(a,0,2)<<endl;
    return 0;
}
