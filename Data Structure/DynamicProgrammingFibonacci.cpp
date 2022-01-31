#include <bits/stdc++.h>
using namespace std;
int term[1000];
// Fibonacci Series using memoized Recursion
int fib(int n)
{
    if (n <= 1)
        return n;
    if (term[n] != 0)
        return term[n];

    else
    {
        term[n] = fib(n - 1) + fib(n - 2);
        return term[n];
    }
}
// Fibonacci Series using Bottom-up DP algorithm
int Fib[1000];
int Fibo(int n)
{
    int f;
    for (int i = 1; i < n + 1; i++)
    {

        if (i <= 2)
            f = 1;
        else
            f = Fibo(i - 1) + Fibo(i - 2);

        Fib[i] = f;
    }
    return f;
}
int main()
{
    int n = 6;
    printf("%d", Fibo(n));
    return 0;
}
