// Limit 0 to 99
#include <iostream>
#include <stdc.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
};
node *adj[10] = {NULL};
node *CreateNode(int data)
{
    node *n = new node;
    n->data = data;
    n->next = NULL;
    return n;
}
void InsertNode(node **head, int data)
{
    if (*head == NULL)
    {
        *head = CreateNode(data);
        return;
    }
    else
    {
        node *n = CreateNode(data);
        n->next = *head;
        *head = n;
    }
}
void CountSort(int arr[], int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
        if (max < arr[i])
            max = arr[i];

    int *count = (int *)calloc(sizeof(int), max + 1);

    for (int i = 0; i < size; i++)
        count[arr[i]]++;

    for (int i = 1; i < max + 1; i++)
        count[i] = count[i] + count[i - 1];

    int output[size];

    for (int i = size - 1; i >= 0; i--)
        output[--count[arr[i]]] = arr[i];

    for (int i = 0; i < size; i++)
        arr[i] = output[i];
}
int NumOfElements(node *head)
{
    if (head == NULL)
        return 0;
    node *p = head;
    int i = 0;
    while (p != NULL)
    {
        p = p->next;
        i++;
    }
    return i;
}
void ListTOArray(int arr[], node *head)
{
    int i = 0;
    node *p = head;
    while (p != NULL)
    {
        arr[i] = p->data;
        p = p->next;
        i++;
    }
}
void ArrayToList(int arr[], node *head)
{
    int i = 0;
    node *p = head;
    while (p != NULL)
    {
        p->data = arr[i];
        p = p->next;
        i++;
    }
}
void Build(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        InsertNode(&adj[arr[i] / 10], arr[i]);
}
void Sort()
{
    for (int i = 0; i < 10; i++)
    {
        node *p = adj[i];
        int n = NumOfElements(adj[i]);
        if (n == 0)
            continue;
        int *a = (int *)calloc(sizeof(int), n);
        ListTOArray(a, adj[i]);
        CountSort(a, n);
        ArrayToList(a, adj[i]);
    }
}
void BucketSort(int arr[], int size)
{
    Build(arr, size);
    Sort();
    int j = 0;
    for (int i = 0; i < 10; i++)
    {
        node *p = adj[i];
        while (p != NULL && j < size)
        {
            arr[j++] = p->data;
            p = p->next;
        }
    }
}
int main(int argc, char const *argv[])
{
    int arr[16] = {7, 4, 1, 8, 5, 2, 20, 36, 69, 21, 25, 26, 30, 37, 98, 99};
    BucketSort(arr, 16);
    for (int i : arr)
        cout << i << "\t";
    cout << endl;
    return 0;
}
