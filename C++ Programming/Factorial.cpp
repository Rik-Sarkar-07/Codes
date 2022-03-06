#include <iostream>
using namespace std;

//Normal Reccursion Technique

int factorial(int n)
{
    if(n == 0 || n == 1) return 1;
    return (n*factorial(n-1));
}

//Dynamic Programming Memorized Technique

int memo[100];
int Factorial(int n)
{
    if(n == 0 || n == 1) { memo[n] = 1;
     return (1);
    }
    if(memo[n] != 0) return (memo[n]);
    else
    return (n*Factorial(n-1));
}

// Normal Iteration Tecnique 

int Fact(int n)
{
    int fact = 1;
    for(int i=n;i>0;i--)
        fact = fact*i;
    return fact;
}
int main(int argc, char const *argv[])
{
    cout<<Fact(5)<<endl;
    return 0;
}
