#include <iostream>
#include <string.h>
using namespace std;
int f[] = {0}; // Pi-Table Store longest prefix which is longest sufix also
void Pi_Table(char patt[])
{
    int m = strlen(patt);
    int i = 1, j = 0;
    f[m + 1];
    while (i < m)
    {
        if (patt[i] == patt[j]) // if match pattren increment both pi and it's value
            f[i++] = j++;
        else if (j > 0)
            j = f[j - 1]; // check others are same as to pattren or not
        else
            f[i++] = 0; // if non of them then fill 0
    }
}
int KMP(char str[], char patt[])
{
    int i = 0, j = 0;
    int n = strlen(str);
    int m = strlen(patt);
    Pi_Table(patt);
    while (i < n)
    {
        if (str[i] == patt[j]) // if match then
        {
            if (j == m - 1) // exact all match then return otherwise increment indexes
                return i - j;
            else
            {
                i++;
                j++;
            }
        }
        else if (j > 0)
            j = f[j - 1];
        else // non of them means increment str index
            i++;
    }
    return -1;
}
int main(int argc, char const *argv[])
{
    char str[] = "Sudipta";
    char patt[] = "ud";
    cout << "Index = " << KMP(str, patt) << endl;
    return 0;
}
