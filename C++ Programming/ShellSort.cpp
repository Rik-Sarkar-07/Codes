#include<iostream>
using namespace std;
void Print(int* arr,int size)
{
    cout<<"The array is ---- \n";
    for(int i=0;i<size;i++)
    cout<<"\t"<<arr[i];
    cout<<endl<<endl;
}
void ShellSort(int* arr,int size)
{
    int i,j,m,temp;
    while(m>0)
    {
        for(i=m;i<size;i++)
        {
            for(j=i-m;j>=0;j--)
            {
                if(arr[j]>arr[m+j])
                {
                    temp = arr[j];
                    arr[j] = arr[j+m];
                    arr[j+m] = temp;
                }
            }
        }


        m = m/2;
    }
}
int main(int argc, char const *argv[])
{
    int size;
    cout<<"Enter the Size = ";
    cin>>size;
    int* arr = new int[size];
    cout<<"Enter the Array Elements --- \n";
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    cout<<"Before shorting the Array \n";
    Print(arr,size);
    ShellSort(arr,size);
    cout<<"After Shorting the array \n";
    Print(arr,size);
    return 0;
}
