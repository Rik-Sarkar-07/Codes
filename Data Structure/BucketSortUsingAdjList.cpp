// Numbers Limit 0 to 99

#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
};
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
void Sort(node** head)
{
    if(*head == NULL)
    return;
    node* i = *head;
    node* j =i;
    for(i=*head;i->next != NULL;i = i->next)
    {
        for(j=*head;j->next != NULL;j=j->next)
        {
            if(j->data > (j->next)->data)
            {
                int temp = j->data;
                 j->data = j->next->data;
                j->next->data = temp;
            }
        }
    }
}
node* adjList[10] = {NULL};
void CreateList(int arr[],int size)
{
    for(int i=0;i<size;i++)
        Insertion(&adjList[arr[i]/10],arr[i]);
}
void Sort()
{
    for(int i=0;i<10;i++)
    Sort(&adjList[i]);
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
    Sort();
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
