#include<iostream>
#include<math.h>
using namespace std;
double f(double x){
    return (pow(x,4) + 1);
}
double g(double z,int a,int b){
    return (pow((((b-a)/2)*z + (b+a)/2),4)+1);
}
int main()
{
    double a=0,b=0,n=3;                 // We assume n = 3
    cout<<"Enter the Lower Limit = ";
    cin>>a;
    cout<<"Enter the upper Limit = ";
    cin>>b;

    double ig = 0,c;
    c = (b-a)/2;

    double* w = (double*)malloc(sizeof (double)*n);
    double* z = (double*)malloc(sizeof (double)*n);

    w[0] = 0.55556;         z[0] = -0.77460;
    w[1] = 0.88889;         z[1] = 0;
    w[2] = 0.55556;         z[2] = 0.77460;

   for(int i=0;i<3;i++)
       ig += w[i] * g(z[i],a,b);

    ig = c*ig;
    cout<<"The Result of Numerical Integration is = "<<ig<<"(Approx)."<<endl;
    return 0;
}
