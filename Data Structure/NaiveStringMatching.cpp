#include<iostream>
#include<string.h>
using namespace std;
int NaiveStringMatching(char* mainstr,char* pattren)
{
    int n = strlen(pattren);
    int m = strlen(mainstr);
    for(int i=0;i<=m-n;i++)
    {
        int j=0;
        while(j<n && pattren[j] == mainstr[i+j])    j++;
        if(j == n)
        {
            cout<<"The String have been Matched\n";
            return i;
        }
    }
    cout<<"String is not Matched\n";
    return -1;
}
int main(int argc, char const *argv[])
{
    char str[] = "Sudipta";
    char patt[] = "dei";
    cout<<"At index = "<<NaiveStringMatching(str,patt)<<endl;
    return 0;
}
