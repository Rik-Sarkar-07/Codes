#include<iostream>
#include<bits/stdc++.h>
using namespace std;
inline void PrintPair(pair<int,string> &p)
{
    cout<<"Frist Roll = "<<p.first<<"\t"<<"Second Name = "<<p.second<<"\n";
}
int main(int argc, char const *argv[])
{
    pair<int,string> p;
    p = {727,"Sudipta"};
    PrintPair(p);

    pair<int,string> p1;
    p1.first = 728;
    p1.second = "Anchal Bhaskar";
    PrintPair(p1);

    // Vectors for pair --- used in Graph

    vector<pair<int,int>> v;

    cout<<"Enter the size of vector [no of pairs] = ";
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }

    cout<<"Size of vector = "<<v.size()<<endl;

    for(int i=0;i<v.size();i++)
        cout<<v[i].first<<"\t"<<v[i].second<<"\n";
    return 0;
}
