#include<iostream>
#include<string>
#include<string.h>
using namespace std;
//Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, and Sunday,
int DayToNumber(string day)
{
    if("Monday" == day)
    return 1;
    else if("Tuesday" == day)
    return 2;
    else if("Wednesday" == day)
    return 3;
    else if("Thursday" == day)
    return 4;
    else if("Friday" == day)
    return 5;
    else if("Saturday" == day)
    return 6;
    else if("Sunday" == day)
    return 7;
    else
    return 100;
}
void BubbleSort(string* arr,int size)
{
    int i,j;
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size-1-i;j++)
        {
            if(DayToNumber(arr[j]) > DayToNumber(arr[j+1]))
            {
                string temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
int main(int argc, char const *argv[])
{int size = 7;
    string arr[] = {"Saturday","Tuesday","Monday","Thursday","Wednesday","Friday","Sunday"};
    for(int i=0;i<size;i++)
    cout<<arr[i]<<"\t";
    cout<<endl<<endl;
    BubbleSort(arr,size);
    for(int i=0;i<size;i++)
    cout<<arr[i]<<"\t";
    cout<<endl<<endl;
    return 0;
}
