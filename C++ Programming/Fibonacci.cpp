#include<iostream>
using namespace std;
int* memory = (int*)calloc(sizeof(int),100);
int Fibo(int n)
{
    if(n == 1 || n == 0){
    memory[n] = n;
    return n;
    }
    if(memory[n] != 0)    return (memory[n]);
    else
    {
        memory[n] = Fibo(n-1) + Fibo(n-2);
        return memory[n];
    } 
}
int Fibonacci(int n)
{
    if(n == 1 || n == 0)
    return n;
    else
 return (Fibonacci(n-1) + Fibonacci(n-2));
}
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int f1 = 0;
    int f2 = 1;
    cout<<f1<<"\t"<<f2;
    int i = 0;
    while (n-2 > i)
    {
        int f = f1+f2;
        cout<<"\t"<<f;
        f1 = f2;
        f2 = f;
        i++;
    }
    
    
    cout<<endl;

    return 0;
}
