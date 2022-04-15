#include<iostream>
using namespace std;
class node{
public:
    int vertex;
    node* next;
};
node* adj[50];
void input(int num)
{
    node* ptr;
    int i;
    for(i=0;i<num;i++)
        adj[i] = NULL;
    for(i=0;i<num;i++)
    {
            cout<<"Number of nodes in adj list [ "<<i<<" ] = ";
            int m;
            cin>>m;
                for(int j=0;j<m;j++)
                {
                    ptr = new node;
                    int val;
                    cout<<"Enter the coonected node [ "<<(j+1)<<" ] = ";
                    cin>>val;
                    ptr->vertex = val;
                    ptr->next = NULL;
                    if(adj[i] == NULL)
                    {
                        adj[i] = ptr;
                    }
                    else
                    {
                        ptr->next = adj[i];
                        adj[i] = ptr;
                    }
                }
    }
}
void Print(int num)
{
    for(int i=0;i<num;i++)
    {
        node* t = adj[i];
        cout<<"[ "<<i<<" ]";
        while(t != NULL)
        {
            cout<<"-->>"<<t->vertex<<"\t";
            t = t->next;
        }
        cout<<endl<<endl;
    }
}
int main()
{
    int vertex;
    cout<<"Enter the Vertex = ";
    cin>>vertex;
    input(vertex);
    cout<<"\t--- The Graph is --- \n";
    Print(vertex);

    return 0;
}
