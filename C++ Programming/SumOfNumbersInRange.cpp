#include<iostream>
using namespace std;
int Sum(int l,int h){
    if(h == l)
        return l;
    else 
        return (h + Sum(l,h-1));
}
int main(int argc, char const *argv[])
{
    int l,h;
    cout<<"Enter the Range: ";
    cin>>l>>h;
    cout<<"Sum of Numbers in Range: "<<Sum(l,h)<<endl;
    return 0;
}
