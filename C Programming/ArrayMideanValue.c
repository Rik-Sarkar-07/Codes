#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int* MideanValue(int arr[],int l,int h)
{
    int size = 0;
    if((l+h) % 2 == 0)
    {
        size = 1;
    }
    else
    {
        size = 2;
    }
    int* a = (int*)malloc(sizeof(int)*size);
    if(size == 1)
    {
        a[0] = arr[(l+h)/2];
        return a;
    }
    else
    {
        int mid1 = (l+h)/2;
        int mid2 = (l+h)/2 + 1;
        a[0] = arr[mid1];
        a[1] = arr[mid2];
        return a;
    }
}
int main(int argc, char const *argv[])
{
    int arr[] = {1,2,3,5,6};
    int* a = (int*)malloc(sizeof(int)*2);
    a = MideanValue(arr,0,4);
    for(int i=0;i<1;i++)
    printf("%d\t",a[i]);
    printf("\n\n");
    return 0;
}
