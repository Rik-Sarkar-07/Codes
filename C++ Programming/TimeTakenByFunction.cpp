#include<bits/stdc++.h>
using namespace std;
void BubbleSort(int*arr,int size)
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
int main(){
	int size;
	cout<<"Enter the size = ";
	cin>>size;
	int* arr = (int*)malloc(sizeof(int)*size);
	for(int i=size-1;i>=0;i--)
	arr[i] = i;
	clock_t start_time = clock();
	BubbleSort(arr,size);
	clock_t end_time1 = clock();
	clock_t result = end_time1 - start_time;
	cout<<result<<" milliseconds"<<endl;
	cout<<result/CLOCKS_PER_SEC<<" seconds"<<endl;
	return 0;
}
