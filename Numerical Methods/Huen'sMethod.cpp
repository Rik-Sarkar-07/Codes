#include <iostream>
#include<math.h>
using namespace std;
double f(double x,double y){
    return ((2*y)/x);
}
int main()
{
   double x0,y0;
   cout<<"Enter X0 (initial value of x) = ";
   cin>>x0;
   cout<<"Enter Y0 (initial value of y) = ";
   cin>>y0;

   double h;
   cout<<"Enter the value of h = ";
   cin>>h;
   double X;
   cout<<"Enter the finding Point Y(X) | X = ";
   cin>>X;
   double m1,m2,ye,yc,x1;


   while(x0 < X){
   x1 = x0 + h;
   m1 = f(x0,y0);
   ye = y0 + m1*h;
   m2 = f(x1,ye);
   yc = y0 + h*(m1+m2)/2;

   x0 += h;
   y0 = yc;
   cout<<"Y("<<x0<<") = "<<y0<<endl;

   }
   cout<<"The Result is => Y("<<X<<") = "<<y0<<endl;
   return 0;
}
