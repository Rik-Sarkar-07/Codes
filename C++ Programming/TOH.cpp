#include <iostream>
using namespace std;
void TOH(int n,char s,char h,char d){
    if(n == 1){
       cout<<"The 1 Rod Move "<<s<<" to "<<d<<" with help of "<<d<<endl;
       return;
    }
    TOH(n-1,s,d,h);
    cout<<"The "<<n<<" Rod Move "<<s<<" to "<<d<<" with help of "<<d<<endl;
    TOH(n-1,h,s,d);
}
int main()
{
    TOH(3,'A','C','B');     // A to B help of C
    return 0;
}
