#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<ctime>
#include<time.h>
#include<string.h>
using namespace std;
void Print(int arr[],int size)
{
    for(int i=0;i<size;i++)
        cout<<arr[i]<<"\t";
    cout<<endl<<endl;
}
void BubbleSort(int arr[],int size)
{
    int i,j,temp;
    for(i=0;i<size;i++)
    {
        for(j=0;j<size-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main()
{
    ofstream fout;
    int k =1;
    int ch;
    fout.open("A:\\MY PROGGRAMINGS\\Qt\\build-GraphOfBubbleSort-Desktop_Qt_5_12_9_MinGW_32_bit-Debug\\test.txt");
    int size;
    while (true) {
        int j = 0;
        cout<<"Enter 1 to go = ";
        cin>>ch;
        if(ch == 1)
        {
        cout<<"Enter the size the array = ";
        cin>>size;
        int* arr = new int[size];
        for(int i=size-1;i>=0;i--)
            arr[j++] = i;
        clock_t st = clock();
        BubbleSort(arr,size);
        clock_t end = clock();
        clock_t t = end - st;
        fout<<size<<"\t"<<t<<endl;
        }
        else
         {
            cout<<"Good bye\n";
            break;
        }

    }

    char cmd[2000];
    strcpy(cmd,"gnuplot");
    system(cmd);

    fout.close();
    char cm[500];
    strcpy(cm,"plot \"test.txt\" withlines");
    system(cm);
    return 0;
}
