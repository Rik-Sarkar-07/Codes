#include <iostream>
#include<math.h>
using namespace std;
double f(double x){
    return (x*x - 2*x + 1);
}
double g(double x){
    return (2*x - 2);
}
int main()
{
    double x0,x1,err;
    int it = 0;
    cout<<"Enter the Initial value of x (initial root) : ";
    cin>>x0;
    cout<<"Enter the error :";
    cin>>err;
    x1 = x0 - (f(x0)/g(x0));
    while(fabs((x1-x0)/x1) > fabs(err)){
         x1 = x0 - f(x0)/g(x0);
         x0 = x1;
         it++;
    }
    cout<<"Root of the Equation is = "<<x0<<" (Approx.)\n";
    return 0;
}
