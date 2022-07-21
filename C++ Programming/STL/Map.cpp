#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    map<int,string>m;       // here int-> key and string-> value sort with key value
    m[727] = "Sudipta";
    m[728] = "Anchal";
    m[734] = "Arokodip";
    m[724] = "Syantan";
    m[702] = "Jaidep";

    map<int,string>::iterator it;
    for(it = m.begin(); it != m.end();it++)
    cout<<"Name = "<<it->first<<"\t Roll = "<<it->second<<endl;

    m.insert({03,"Rik"});
    m.insert({01,"Ram"});

    cout<<"\n---------------\n";

    for(it = m.begin(); it != m.end();it++)
    cout<<"Name = "<<it->first<<"\t Roll = "<<it->second<<endl;
    return 0;
}
