#include<iostream>
using namespace std;
int main()
{
    int vertex,edge;
    cout<<"Enter the vertex = ";
    cin>>vertex;
    cout<<"Enter the edges = ";
    cin>>edge;

    int** adj = (int**)calloc(sizeof(int*),vertex);
    for(int i=0;i<vertex;i++)
    adj[i] = (int*)calloc(sizeof(int),vertex);

    cout<<"\n\t Enter the edges between vertex with weights -- \n";
    for(int i=0;i<edge;i++)
    {
        cout<<"Enter the <"<<(i+1)<<"> egde with weight---\n";
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u][v] = wt;
        adj[v][u] = wt;
    }
    int total_cost = 0;
    cout<<"\n\tThe weight Matrix is ---\n\n";
    for(int i=0;i<vertex;i++)
    {
        for(int j=0;j<vertex;j++)
        {
            cout<<adj[i][j]<<"\t";
        }
        cout<<endl<<endl;
    }

    int *vist = (int*)calloc(sizeof(int),vertex);
    int i=0;
    vist[i] = 1;
    while(i< vertex-1)
    {
        int min = 9999999;
        int x = 0;
        int y = 0;

        for(int l=0;l<vertex;l++)
        {
            if(vist[l])
            {
                for(int j=0;j<vertex;j++)
                {
                    if(!vist[j] && adj[l][j])
                    {
                        if(min > adj[l][j])
                        {
                            min = adj[l][j];
                            x = l;
                            y = j;
                        }
                    }
                }
            }
        }
        cout<<x<<" <-- "<<min<<" --> "<<y<<endl;
        total_cost = total_cost + min;
        vist[y] = 1;
        i++;
    }
    cout<<"The Total Cost Of Minimum Spanning Tree = "<<total_cost<<"\n";

    return 0;
}

