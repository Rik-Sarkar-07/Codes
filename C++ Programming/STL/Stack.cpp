#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    stack<int> s;
    cout << "The Size = " << s.size() << endl;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);

    cout<<s.top()<<endl;
    cout<<s.top()<<endl;
    cout<<"Size = "<<s.size()<<endl;
    s.pop();
     cout<<"Size = "<<s.size()<<endl;
    cout<<s.top()<<endl;

    cout<<"The Stack is -- \n";

    while(!s.empty())
    {
        int val = s.top();
        cout<<val<<"\t";
        s.pop();
    }
    cout<<"\n";
    return 0;
}
