#include <iostream>
using namespace std;
double f(double x,double y){
    return ((y*2)/x);
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
    double k,k1,k2,k3,k4,Y;

    while(x0 < X){
    k1 = h*f(x0,y0);
    k2 = h*f(x0+h/2,y0+k1/2);
    k3 = h*f(x0+h/2,y0+k2/2);
    k4 = h*f(x0+h/2,y0+k3/2);
    k = (k1+2*k2+2*k3+k4)/6;
    Y = y0 + k;

    x0 = x0+h;
    y0 = Y;
    cout<<"Y("<<x0<<") = "<<y0<<endl;
    }
    cout<<"The Result is => Y("<<X<<") = "<<y0<<endl;
    return 0;
}
