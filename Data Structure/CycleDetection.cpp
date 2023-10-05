#include<iostream>
using namespace std;
int isCycle(int **adjMat,int vertex){
    int representSet[vertex] = {0};
    for(int i=0;i<vertex;i++)   representSet[i] = i;

    for(int i=0;i<vertex;i++){
        for(int j = 0;j<vertex;j++){
            if(adjMat[i][j] && representSet[i] == representSet[j])
                return 1;
            if(adjMat[i][j] && representSet[i] != representSet[j])
                representSet[i] = representSet[j] = i;
        }
    }
    return 0;
}
int main(int argc, char const *argv[])
{
    int vertex,edges;
   
    cout<<"Enter the number of Vertex = ";
    cin>>vertex;
    cout<<"Enter the number of Edges = ";
    cin>>edges;

    if(vertex == edges){                // Mathematical intution
        cout<<"There is a Cycle\n";
        return 0;
    }

    int **adjMat = (int**)calloc(sizeof(int*),vertex);
    for(int i=0;i<vertex;i++)
    adjMat[i] = (int*)calloc(sizeof(int),vertex);

    cout<<"Enter the Edges \n";
    for(int i=0;i<edges;i++){
        int x,y;
        cout<<"Enter the edge ["<<i+1<<"] \n";
        cin>>x>>y;

        if(x>=vertex || y>=vertex){
            cout<<"Enter Currect Edge value\n";
            exit(1);
        }

        adjMat[x][y] = 1;
    }

    if(isCycle(adjMat,vertex)){
        cout<<"There is a Cycle\n";
    }
    else{
        cout<<"There is no Cycle\n";
    }
    return 0;
}
