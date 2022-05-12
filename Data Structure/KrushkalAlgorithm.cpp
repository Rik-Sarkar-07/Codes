#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define N 20000
int parent[N] = {0};
int size[N] = {0};
void make(int v)        //Add new distinct node
{
    parent[v] = v;
    size[v] = 1;
}
int find(int v)     // returns root of the tree
{
    if(v == parent[v]) return v;
    else{
        return(parent[v] = find(parent[v]));
    }
}
void Union(int a,int b)     // Add two graph
{
    a = find(a);
    b = find(b);
    if(a != b)
    {
        if(size[a] < size[b])
        swap(a,b);
    }
    parent[b] = a;
    size[a] = size[a] + size[b];
}
void Kruskal()
{
    vector<pair<int,pair<int,int>>> edges;          // <wt<vertex_1,vertex_2>>
    int E;
    int V;
    cout<<"Enter the vertex = ";
    cin>>V;
    cout<<"Enter the edges = ";
    cin>>E;

    for(int i=0;i<E;i++)
    {
        int u,v,w;
        cout<<"Enter Edge With Weight < "<<i+1<<" >\n";
        cin>>u>>v>>w;
        edges.push_back({w,{u,v}});
    }
    sort(edges.begin(),edges.end());

    for(int i=0;i<V;i++)
    make(i);

    int cost = 0;
    for(auto &edge : edges)
    {
        int wt = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        if(find(u) == find(v))      // if root of two sub-graph is same then skip because it make cycle
        continue;
        Union(u,v);                 // Otherwise add sub-graphs
        cost = cost + wt;           // add wt
        cout<<u<<"\t"<<v<<endl;
    }
    cout<<"The Minimum Cost is = "<<cost<<endl;
}
int main(int argc, char const *argv[])
{
    cout<<"Visited Edges are --\n";
    Kruskal();
    return 0;
}
