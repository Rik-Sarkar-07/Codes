#include<iostream>
#include<string.h>
using namespace std;
#define N 2000
int Memorized[N][N];
int LCS(int i,int j,char *str1,char* str2)
{
    //  i = strlen(str1);
    // j = strlen(str2);
    if(i == 0 || j == 0)    return 0;
    if(Memorized[i][j] != 0)    return Memorized[i][j];
    // Remove Char from str 1
    int ans1 = LCS(i-1,j,str1,str2);
    // Remove Char from str 2
    int ans2 = LCS(i,j-1,str1,str2);
    // Find the maximum LCS
    int ans = max(ans1,ans2);

    // Remove Char from str 1 and str2 when same both then find max LCS
    ans = max(ans,LCS(i-1,j-1,str1,str2) + (str1[i] == str2[j]));

    return Memorized[i][j] = ans;
}
int main(int argc, char const *argv[])
{
   char str1[] = "ABCDEFGHY";
   char str2[] = "ACDTBUKGY";

   cout<<"Longest Common Subsequence is = "<<LCS(strlen(str1),strlen(str2),str1,str2)<<endl;

    return 0;
}
