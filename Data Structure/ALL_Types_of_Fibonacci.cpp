#include<iostream>
using namespace std;

// Normal Naive Reccursion Technique

int fibonacci(int n)
{
    if(n == 0 || n == 1) return n;
    return(fibonacci(n-1) + fibonacci(n-2));
}

// Dynamic programming [Memmorize Technique]

int *memo = (int*)calloc(sizeof(int),100);
int Fibonacci(int n)
{
    if(n == 1 || n == 0){
         memo[n] = n;
         return memo[n];
    }
    if(memo[n] != 0)    return memo[n];
    else
    {
        int f = Fibonacci(n-1) + Fibonacci(n-2);
        memo[n] = f;
        return memo[n];
    }
}

// Dynamic Programming [Bottom-up Approch]

int fibo[100];
int Fibo(int n)
{
    fibo[0] = 0;
    fibo[1] = 1;
  for(int i=2;i<=n;i++) 
         fibo[i] = fibo[i-1] + fibo[i-2];
  return (fibo[n]);
}
int main(int argc, char const *argv[])
{
    // Normal Iteration Technique
   cout<<"Enter the number = ";
   int n;
   cin>>n;
   int f1 = 0;
   int f2 = 1;
   cout<<f1<<"\t"<<f2<<"\t";
   int f;
   for(int i=2;i<n;i++)
   {
       f = f1+f2;
       cout<<f<<"\t";
       f1 = f2;
       f2 = f;
   }
   cout<<"\n\n";
}
