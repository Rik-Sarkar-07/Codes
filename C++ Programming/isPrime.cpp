#include<iostream>
#include<math.h>
using namespace std;
int main(int argc, char const *argv[])
{
    cout<<"Enter the number = ";
    int n;
    cin>>n;
    int flag = 1;
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i == 0){
            cout<<"Prime\n";
            flag = 0;
            break;
        }
    }
    if(flag) cout<<"Not Prime \n";
    return 0;
}
