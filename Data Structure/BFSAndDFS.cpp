#include <iostream>
using namespace std;
class stack{
    public:
    int size;
    int *arr;
    int top;
};
int isEmpty(stack* s)
{
    if(s->top == -1)
    return 1;
    return 0;
}
void Push(stack* s,int data)
{
    if(s->top == s->size-1)
    return;
    else
    {
        s->top++;
        s->arr[s->top] = data;
    }
}
int Pop(stack* s)
{
    if(s->top == -1)
    return -999;
    else{
        int val = s->arr[s->top];
        s->top--;
        return val;
    }
}
class Queue
{
public:
    int f = -1;
    int r = -1;
    int size;
    int *arr;
};
int isEmpty(Queue *q)
{
    if (q->f == -1 || q->f > q->r)
        return 1;
    return 0;
}
void EnQueue(Queue *q, int data)
{
    if (q->r == q->size - 1)
        return;
    else
    {
        if (q->f == -1)
            q->f++;
        q->r++;
        q->arr[q->r] = data;
    }
}
int DeQueue(Queue *q)
{
    if (q->f == -1)
        return 0;
    else
    {
        int val = q->arr[q->f++];
        return val;
    }
}
void DFS(int** adj, int vertex, int start)
{
    stack* s = new stack;           // Create Stack
    s->size = 500;
    s->top = -1;
    s->arr = (int*)malloc(sizeof(int)*s->size);

    int* visited = (int*)calloc(sizeof(int),vertex);        // Visited array contains the visited node records
    Push(s,start);
    while (!isEmpty(s))
    {
        int v = Pop(s);
        if(!visited[v])                                      // Check either visited or not
        {
            cout<<v<<"\t";
            visited[v] = 1;                              //if not visit then print and assing to visit
        }
        for(int i=0;i<vertex;i++)
        if(adj[v][i] == 1 && !visited[i])                // that's node corresponding adj vertex are visited or not check if not then push into Stack
        Push(s,i);
    }
   cout<<"\n\n"; 
}
void BFS(int** adj,int vertex,int start)
{
    Queue *q = new Queue;
    q->size = 200;
    q->f = q->r = -1;
    q->arr = (int*)malloc(sizeof(int)*q->size);         //Create Queue 
    
    int* visited = (int*)calloc(sizeof(int),vertex);
    EnQueue(q,start);
    while (!isEmpty(q))         // Check either visited or not
    {
        int v = DeQueue(q);
        if(!visited[v])
        {
            cout<<v<<"\t";
            visited[v] = 1;          //if not visit then print and assing to visit
        }
        for(int j=0;j<vertex;j++)
        if(adj[v][j] == 1 && !visited[j])
        {
            EnQueue(q,j);            // that's node corresponding adj vertex are visited or not check if not then push into Queue
        }
    } 
}
int main(int argc, char const *argv[])
{
    // Create Adj Matrix For Graph

    cout << "Enter Vertex No = ";
    int vertex;
    cin >> vertex;

    int **adj = (int **)calloc(sizeof(int *), vertex);
    for (int i = 0; i < vertex; i++)
        adj[i] = (int *)calloc(sizeof(int), vertex);

    cout << "Enter Edge No = ";
    int edge;
    cin >> edge;
    for (int i = 0; i < edge; i++)
    {
        cout << "Enter Edge [" << (i + 1) << "] -- \n ";
        int x, y;
        cin >> x >> y;
        adj[x][y] = 1;
        adj[y][x] = 1;
    }

    // After Create Graph Graph status --
    cout << "The Adj Matrix of that Graph--- \n";

    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < vertex; j++)
            cout << adj[i][j] << "\t";
        cout << endl
             << endl;
    }

    cout<<"\nThe DFS Travertion -- \n";
    DFS(adj,vertex,0);
    return 0;
}
