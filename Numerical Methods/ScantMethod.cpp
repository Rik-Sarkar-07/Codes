#include <iostream>
#include<math.h>
using namespace std;
double f(double x){
    return (x*x - 2*x + 1);
}
int main()
{
    double x1,x2,x3,err;
    int it = 0;
    cout<<"Enter the frist Initial value of x1 (initial root) : ";
    cin>>x1;
    cout<<"Enter the second Initial value of x2 (intial root) : ";
    cin>>x2;
    cout<<"Enter the error :";
    cin>>err;
    x3 = (x2 - (((x2-x1)*f(x2))/(f(x2)-f(x1))));
    while(fabs((x2-x1)/x2) > fabs(err)){
        x3 = (x2 - (((x2-x1)*f(x2))/(f(x2)-f(x1))));
         x1 = x2;
         x2 = x3;
         it++;
    }
    cout<<"Root of the Equation is = "<<x3<<" (Approx, After "<<it<<"Iteartion"<<")\n";
    return 0;
}
