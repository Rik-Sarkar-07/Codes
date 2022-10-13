#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int year;
    cout<<"Enter the Year = ";
    cin>>year;
    if(year % 400 == 0)
        cout<<"Leap Year\n";
    else if(year % 100 != 0 && year % 4 == 0)
        cout<<"Leap Year\n";
    else 
        cout<<"Not Leap Year\n";
    return 0;
}
