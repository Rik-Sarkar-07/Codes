#include<iostream>
using namespace std;
int main()
{
    int s[6] = {1,2,3,4,5,5};
    for(int e: s)
    {
        cout<<e<<endl;
    }

    cout<<"\n\n";

    int a[2][2] = { {1,2},{3,5} };


//    for(int e: a)
//    {
//        cout<<*e<<endl;
//    }

//    for(int e[]: a)
//    {                         // in java
//        cout<<*e<<endl;
//    }

     for(auto &c : a)
    {
        cout<<c<<endl;
    }

    cout<<"\n\n";

    for(int* e: a)
    {
        cout<<*e<<endl;
    }

    cout<<"\n\n";


    return 0;
}
