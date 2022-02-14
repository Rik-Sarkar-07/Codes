#include <iostream>

using namespace std;

int main()
{
    cout<<"Enter the number  = ";
    int n;
    cin>>n;
    int p = n;

    int sum = 0;
    int mul = 1;
    int rev = 0;
    while(n != 0)
    {
        sum = sum + n%10;
        n = n/10;
    }
    cout<<"Sum of Digits  = "<<sum<<endl;

    n = p;
    while(n != 0)
    {
        int rem = n % 10;
        mul = mul * rem;
        n = n/10;
    }
    cout<<"Product of Digits = "<<mul<<endl;

    n = p;
    while (n != 0) {
        int rem = n % 10;
        rev = rev*10 + rem;
        n = n / 10;
    }
    cout<<"Reverse of the Number  = "<<rev<<endl;
    if(rev == p)
        cout<<"The Number is Palindrome \n";
    else
        cout<<"Number is not palindrome \n";
    return 0;
}
