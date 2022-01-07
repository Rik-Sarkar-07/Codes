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
    void EnQueue(int data)
    {
        if (r == size - 1 && f == 0)
        {
            cout << "Queue is Full \n";
        }
        else if (r == size && f != 0)
        {
            r = (r + 1) % size;
            arr[r] = data;
            r++;
            cout << "The " << data << " is EnQueue\n";
        }
        else
        {
            if (f == -1)
            {
                f++;
            }
            r++;
            arr[r] = data;
            cout << "The " << data << " is EnQueue\n";
        }
    }
    void DeQueue()
    {
        if (f == -1)
        {
            cout << "Queue UnderFlow \n";
        }
        else
        {
            int data = arr[f];
            f++;
            cout << "The " << data << " has been Deleted \n";
        }
    }
    void Print()
    {
        if (f == -1)
        {
            cout << "Queue Empty \n";
        }
        else
        {
            for (int i = f; i <= r; i++)
                cout << "\t" << arr[i];
            cout << endl;
        }
    }
};
int main(int argc, char const *argv[])
{
    Queue q(3);
    q.EnQueue(20);
    q.EnQueue(40);
    q.EnQueue(60);
    // q.EnQueue(640);
    q.Print();
    q.DeQueue();
    q.EnQueue(120);
    q.Print();
     
    return 0;
}
