#include <iostream>
using namespace std;
class Queue
{
private:
    int f = -1;
    int r = -1;
    int size;
    int *arr = (int *)malloc(sizeof(int) * size);

public:
    Queue(int size)
    {
        this->size = size;
    }
    void EnQueue(int data);
    void DeQueue();
    void Print();
};
void Queue ::DeQueue()
{
    if (f == -1)
    {
        cout << "Queue is Empty \n";
    }
    else
    {
        int data = arr[f];
        f++;
        cout << "The Value of " << data << " is Deleted \n";
    }
}
void Queue ::EnQueue(int data)
{
    if (r == size - 1)
    {
        cout << "Queue is Full \n";
    }
    else
    {
        if (f == -1)
            f++;
        arr[++r] = data;
    }
}
void Queue ::Print()
{
    if (f == -1)
    {
        cout << "The Queue is Empty \n";
    }
    else
    {
        for (int i = f; i <= r; i++)
            cout << arr[i] << "\t";
        cout << endl
             << endl;
    }
}
int main(int argc, char const *argv[])
{
    Queue q(10);
    for (int i = 0; i <= 5; i++)
        q.EnQueue(10 + i);
    q.Print();
    q.DeQueue();
    q.DeQueue();
    return 0;
}
