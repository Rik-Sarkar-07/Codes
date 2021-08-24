#include<iostream>
using namespace std;
/*          #1. Sum of n Numbers   --------

            sum(n) = n + sum(n-1)
*/
int sum(int n)
{
    if(n==0)
    {
        return 0;
    }
    else
    {
        return (n+sum(n-1));
    }
}
/*          #2. Factorial of n Number   --------

            fact(n) = n * fact(n-1)
*/
int fact(int n)
{
    if(n<0)
    {
        return -1;
    }
   else if(n==0)
    {
        return 1;
    }
    else
    {
        return (n*fact(n-1));
    }
}
/*          #3. Fibonacci's n th Number   --------

           fibo(n) = fibo(n-1) + fibi(n-2)
*/
int fibo(int n)
{
    if(n==0 || n==1)
    {
        return n;
    }
    else
    {
        return (fibo(n-1) + fibo(n-2));
    }
}
/*          #4. Power of a number n^p  --------

            pow(n,p) = n * pow(n,p-1)
*/
int pow(int n,int p)
{
    if(p==0)
    {
        return 1;
    }
    if(n==0)
    {
        return 0;
    }
    else
    {
        return (n*pow(n,p-1));
    }
}
int main(int argc, char *argv[])
{
    cout<<"Sum of First 10 Numbers => "<<sum(10)<<endl;
    cout<<"Factorial of 5 => "<<fact(5)<<endl;
    cout<<"6 th point of Fibonacci Numbers => "<<fibo(6)<<endl;
    cout<<"The value of 4^3 => "<<pow(4,3)<<endl;
    return 0;
}
