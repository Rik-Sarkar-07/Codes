// It is like a link list
#include<iostream>
#include<list>
using namespace std;
int main(int argc, char const *argv[])
{
    list<int>l;

    l.push_back(10);    // insert at end
    l.push_front(20);   // insert at frist
    l.push_back(30);
    l.push_back(68);
    l.push_front(83);
    l.push_front(9);

    cout<<"The frist value = "<<l.front()<<"\t The last value = "<<l.back()<<endl;

    cout<<"The list is -- \n";
    for(auto it = l.begin();it != l.end();it++)
    cout<<*(it)<<"\t";
    cout<<endl;

    list<int> ::iterator it;        // iterator is a pointer 
    cout<<"The list is -- \n";
    for(it = l.begin();it != l.end();it++)
    cout<<*(it)<<"\t";
    cout<<endl;

    l.reverse();            // reverse
    cout<<"After reverse\n";
    for(it = l.begin();it != l.end();it++)
    cout<<*(it)<<"\t";
    cout<<endl;


    l.sort();              // sort
    cout<<"After sort\n";
    for(it = l.begin();it != l.end();it++)
    cout<<*(it)<<"\t";
    cout<<endl;

    l.pop_back();   // delete at last
    l.pop_front();  // delete at frist

    cout<<"The list is -- \n";
    for(it = l.begin();it != l.end();it++)
    cout<<*(it)<<"\t";
    cout<<endl;
    return 0;
}
