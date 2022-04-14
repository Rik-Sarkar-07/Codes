#include<iostream>
using namespace std;
class Graph{
    public:
    int vertex;
    int edge;
    int **adjmatrix;
};
Graph* CreateGraph()
{
    Graph* g = new Graph;
    cout<<"Enter Total Numbers of Edges and Vertex = ";
    cin>>g->edge>>g->vertex;

    g->adjmatrix = (int**)calloc(sizeof(int*),g->vertex);
    for(int i=0;i<g->vertex;i++)
    g->adjmatrix[i] = (int*)calloc(sizeof(int),g->vertex);

    int u=0,v=0;

    for(int i=0;i<g->edge;i++)
    {
        cout<<"Enter the node no in pair [pair "<<(i+1)<<" ] = ";
        cin>>u>>v;
        g->adjmatrix[u][v] = g->adjmatrix[v][u] = 1;
    }
    return g;
}
int main()
{
    Graph* g = CreateGraph();
    cout<<"Adjency Matrix Representation of Graph\n\n";
    for(int i=0;i<g->vertex;i++){
    for(int j=0;j<g->vertex;j++)
    cout<<g->adjmatrix[i][j]<<"\t";
    cout<<"\n\n";
    }
    return 0;
}
