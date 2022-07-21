#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    queue<int>q;
    cout<<"The size of Queue = "<<q.size()<<endl;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
     cout<<"The size of Queue = "<<q.size()<<endl;
    cout<<"Front value = "<<q.front()<<"\t Rare Value = "<<q.back()<<endl;
     cout<<"The Queue is -- \n";

     queue<int> q1 = q;
     while(! q1.empty())
     {
         cout<<q1.front()<<"\t";
         q1.pop();
     }
    cout<<endl;
    cout<<"The size of Queue[q1] = "<<q1.size()<<"\t"<<"Size of Queue[q] = "<<q.size()<<endl;
    return 0;
}
