#include <bits/stdc++.h>
using namespace std;
int main()
{
    set<int>s;     // set is sorted & distinct collections of object

    if(s.empty())
    cout<<"Empty\n";
    else
    cout<<"Not Empty\n";

    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(40);
    s.insert(50);
    s.insert(20);       // 20 is not come because it is duplicate value

    set<int> ::iterator it;
    for(it = s.begin();it != s.end();it++)
    cout<<*(it)<<"\t";

    auto p = s.find(40);        // return location pointer
    cout<<"Value of p = "<<*p<<endl;

   s.erase(s.begin());     // delete frist objects

    if(s.empty())
    cout<<"Empty\n";
    else
    cout<<"Not Empty\n";

    for(it = s.begin();it != s.end();it++)
    cout<<*(it)<<"\t";

    return 0;
}
