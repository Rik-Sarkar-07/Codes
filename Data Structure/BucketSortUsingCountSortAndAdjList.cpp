#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
};
void CountSort(int arr[],int size)
{
    int max = arr[0];
    for(int i=1;i<size;i++)
    if(arr[i]>max)
    max = arr[i];

    int* count = (int*)calloc(sizeof(int),max+1);

    for(int i=0;i<size;i++)
        count[arr[i]]++;

    for(int i=1;i<max+1;i++)
    count[i] = count[i] + count[i-1];

    int output[size];

    for(int i=size-1;i>=0;i--)
    output[--count[arr[i]]] = arr[i];

    for(int i=0;i<size;i++)
    arr[i] = output[i];
}
void Print(node* head)
{
    node* p = head;
    if(p == NULL)
    return;
    else
    {
        while(p != NULL)
        {
            cout<<p->data<<"\t";
            p = p->next;
        }
    }
}
node* CreateNode(int data)
{
    node* n = new node;
    n->data = data;
    n->next = NULL;
    return n;
}
void Insertion(node** head,int data)
{
    if(*head == NULL)
    *head = CreateNode(data);
    else {
        node* n = CreateNode(data);
        n->next = *head;
        *head = n;
    }
}
node* adjList[10] = {NULL};
void CreateList(int arr[],int size)
{
    for(int i=0;i<size;i++)
        Insertion(&adjList[arr[i]/10],arr[i]);
}
int NoOfElemenet(node* head)
{
    if(head == NULL)
    return 0;
    else
    {
        int i = 0;
        node* p = head;
        while(p != NULL)
        {
            i++;
            p = p->next;
        }
        return i;
    }
}
void CountSortOnList()
{
    for(int i=0;i<10;i++)
    {
        int elements = NoOfElemenet(adjList[i]);
        node *p = adjList[i];
        if(p == NULL)
            continue;

        if(elements == 0 || elements == 1)
        continue;

        int* arr = (int*)calloc(sizeof(int),elements);
        int j=0;
        while(p != NULL)
        {
            arr[j++] = p->data;
            p = p->next;
        }
        CountSort(arr,elements);
        j = 0;
        p = adjList[i];
       while(j<elements && p != NULL)
       {
           p->data = arr[j++];
          p = p->next;
       }

       j = 0;
       elements = 0;
       p = NULL;
       delete []arr;
    }
}
void PrintArray()
{
    cout<<"\n The array is --\n";
    for(int i=0;i<10;i++)
    {
        Print(adjList[i]);
    }
    cout<<endl;
}
void BucketSort(int arr[],int size)
{
    CreateList(arr,size);
    CountSortOnList();
}
int main()
{
    int size = 0;
    cout<<"Enter the size of Array  = ";
    cin>>size;
    int arr[size];
    cout<<"Enter the elements in the array \n";
    for(int i=0;i<size;i++)
        cin>>arr[i];
    BucketSort(arr,size);
    PrintArray();
    return 0;
}
